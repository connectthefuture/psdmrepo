//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class XtcStreamMerger...
//
// Author List:
//      Andrei Salnikov
//
//------------------------------------------------------------------------

//-----------------------
// This Class's Header --
//-----------------------
#include "XtcInput/XtcStreamMerger.h"

//-----------------
// C/C++ Headers --
//-----------------
#include <map>
#include <iomanip>
#include <boost/make_shared.hpp>

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "MsgLogger/MsgLogger.h"
#include "XtcInput/ChunkFileIterList.h"
#include "XtcInput/Exceptions.h"
#include "pdsdata/xtc/TransitionId.hh"

//-----------------------------------------------------------------------
// Local Macros, Typedefs, Structures, Unions and Forward Declarations --
//-----------------------------------------------------------------------

namespace {

  const char* logger = "XtcInput.XtcStreamMerger" ;

}

//		----------------------------------------
// 		-- Public Function Member Definitions --
//		----------------------------------------

namespace XtcInput {

//----------------
// Constructors --
//----------------
XtcStreamMerger::XtcStreamMerger(const boost::shared_ptr<StreamFileIterI>& streamIter,
        double l1OffsetSec)
  : m_streams()
  , m_dgrams()
  , m_l1OffsetSec(int(l1OffsetSec))
  , m_l1OffsetNsec(int((l1OffsetSec-m_l1OffsetSec)*1e9))
  , m_outputQueue()
{

  // create all streams
  while (true) {
    const boost::shared_ptr<ChunkFileIterI>& chunkFileIter = streamIter->next();
    if (not chunkFileIter) break;

    MsgLog(logger, trace, "XtcStreamMerger -- stream: " << streamIter->stream());

    // create new stream
    const boost::shared_ptr<XtcStreamDgIter>& stream = 
        boost::make_shared<XtcStreamDgIter>(chunkFileIter) ;
    m_streams.push_back(stream) ;
    Dgram dg(stream->next());
    if (not dg.empty()) updateDgramTime(*dg.dg());
    m_dgrams.push_back( dg ) ;

  }

}

//--------------
// Destructor --
//--------------
XtcStreamMerger::~XtcStreamMerger ()
{
}


// read next datagram, return zero pointer after last file has been read,
// throws exception for errors.
Dgram
XtcStreamMerger::next()
{

  if (m_outputQueue.empty()) {

    unsigned ns =  m_streams.size() ;

    // find datagram with lowest timestamp
    int stream = -1 ;
    for ( unsigned i = 0 ; i < ns ; ++ i ) {
      if (not m_dgrams[i].empty()) {
        if ( stream < 0 or m_dgrams[stream].dg()->seq.clock() > m_dgrams[i].dg()->seq.clock() ) {
          stream = i ;
        }
      }
    }

    MsgLog( logger, debug, "next -- stream: " << stream ) ;

    if (stream >= 0) {

      // send all datagrams with this timestamp to output queue
      Pds::ClockTime ts = m_dgrams[stream].dg()->seq.clock();
      for ( unsigned i = 0 ; i < ns ; ++ i ) {
        if (not m_dgrams[i].empty()) {
          if (m_dgrams[i].dg()->seq.clock() == ts) {

            m_outputQueue.push(m_dgrams[i]);

            // get next datagram from that stream
            Dgram ndg(m_streams[i]->next());
            MsgLog( logger, debug, "next -- read datagram from file: " << ndg.file().basename() ) ;
            if (not ndg.empty()) updateDgramTime(*ndg.dg());
            m_dgrams[i] = ndg ;

          }
        }
      }

    }

  }

  Dgram dg;
  if (not m_outputQueue.empty()) {
    // this datagram will be returned
    dg = m_outputQueue.front();
    m_outputQueue.pop();

    Dgram::ptr dgptr = dg.dg();
    MsgLog( logger, debug, "next -- m_dgrams[stream].clock: "
        << dgptr->seq.clock().seconds() << " sec " << dgptr->seq.clock().nanoseconds() << " nsec" ) ;
    MsgLog( logger, debug, "next -- m_dgrams[stream].service: " << Pds::TransitionId::name(dgptr->seq.service()) ) ;
  }

  return dg ;
}


void 
XtcStreamMerger::updateDgramTime(Pds::Dgram& dgram) const
{
  if ( dgram.seq.service() != Pds::TransitionId::L1Accept ) {

    // update clock values
    const Pds::ClockTime& time = dgram.seq.clock() ;
    int32_t sec = time.seconds() + m_l1OffsetSec;
    int32_t nsec = time.nanoseconds() + m_l1OffsetNsec;
    if (nsec < 0) {
        nsec += 1000000000;
        -- sec;
    } else if (nsec >= 1000000000) {
        nsec -= 1000000000;
        ++ sec;
    }      
    Pds::ClockTime newTime(sec, nsec) ;

    // there is no way to change clock field in datagram but there is 
    // an assignment operator
    dgram.seq = Pds::Sequence(newTime, dgram.seq.stamp());
  }
}

} // namespace XtcInput
