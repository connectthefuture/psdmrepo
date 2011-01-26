//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class DgramReader...
//
// Author List:
//      Andrei Salnikov
//
//------------------------------------------------------------------------

//-----------------------
// This Class's Header --
//-----------------------
#include "PsXtcInput/DgramReader.h"

//-----------------
// C/C++ Headers --
//-----------------
#include <algorithm>

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "MsgLogger/MsgLogger.h"
#include "PsXtcInput/DgramQueue.h"
#include "PsXtcInput/XtcStreamMerger.h"
#include "pdsdata/xtc/Dgram.hh"

//-----------------------------------------------------------------------
// Local Macros, Typedefs, Structures, Unions and Forward Declarations --
//-----------------------------------------------------------------------

//		----------------------------------------
// 		-- Public Function Member Definitions --
//		----------------------------------------

namespace PsXtcInput {

//----------------
// Constructors --
//----------------
DgramReader::DgramReader ( const FileList& files,
                           DgramQueue& queue,
                           size_t maxDgSize,
                           XtcStreamMerger::MergeMode mode,
                           bool skipDamaged,
                           double l1OffsetSec )
  : m_files( files )
  , m_queue( queue )
  , m_maxDgSize( maxDgSize )
  , m_mode( mode )
  , m_skipDamaged( skipDamaged )
  , m_l1OffsetSec(l1OffsetSec)
{
}

//--------------
// Destructor --
//--------------
DgramReader::~DgramReader ()
{
}

// this is the "run" method used by the Boost.thread
void
DgramReader::operator() ()
{
  try {

    XtcStreamMerger iter(m_files, m_maxDgSize, m_mode, m_skipDamaged, m_l1OffsetSec);
    while ( Pds::Dgram* dg = iter.next() ) {

      // move it to the queue
      m_queue.push ( dg ) ;

    }

    // tell all we are done
    m_queue.push ( (Pds::Dgram*)0 ) ;

  } catch ( std::exception& e ) {

    MsgLogRoot( error, "exception caught while reading datagram: " << e.what() ) ;

    // TODO: there is no way yet to stop gracefully, will just abort
    throw;

  }
}


} // namespace PsXtcInput
