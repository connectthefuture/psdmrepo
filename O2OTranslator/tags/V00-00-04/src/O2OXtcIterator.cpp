//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class O2OXtcIterator...
//
// Author List:
//      Andrei Salnikov
//
//------------------------------------------------------------------------
#include "Lusi/Lusi.h"

//-----------------------
// This Class's Header --
//-----------------------
#include "O2OTranslator/O2OXtcIterator.h"

//-----------------
// C/C++ Headers --
//-----------------

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "MsgLogger/MsgLogger.h"
#include "O2OTranslator/O2OXtcScannerI.h"
#include "pdsdata/xtc/Xtc.hh"

//-----------------------------------------------------------------------
// Local Macros, Typedefs, Structures, Unions and Forward Declarations --
//-----------------------------------------------------------------------

//		----------------------------------------
// 		-- Public Function Member Definitions --
//		----------------------------------------

namespace O2OTranslator {

//----------------
// Constructors --
//----------------
O2OXtcIterator::O2OXtcIterator ( Xtc* xtc, O2OXtcScannerI* scanner, bool ignoreUnknowXtc )
  : Pds::XtcIterator( xtc )
  , m_scanner( scanner )
  , m_ignore( ignoreUnknowXtc )
{
}

//--------------
// Destructor --
//--------------
O2OXtcIterator::~O2OXtcIterator ()
{
}

// process one sub-XTC, returns >0 for success, 0 for error
int
O2OXtcIterator::process(Xtc* xtc)
{

  Pds::TypeId::Type type = xtc->contains.id() ;
  uint32_t version = xtc->contains.version() ;

  MsgLogRoot( debug, "O2OXtcIterator::process -- new xtc: "
              << Pds::TypeId::name(type) << "/" << version ) ;

  switch ( type ) {

    case (Pds::TypeId::Id_Xtc) : {

      // say we are at the new XTC level
      if ( m_scanner ) m_scanner->levelStart ( xtc->src ) ;

      // scan all sub-xtcs
      O2OXtcIterator iter( xtc, m_scanner, m_ignore );
      iter.iterate();

      // say we are done with this XTC level
      if ( m_scanner ) m_scanner->levelEnd ( xtc->src ) ;

      return 1;
    }

    case (Pds::TypeId::Any) :
      // NOTE: I do not know yet what this type is supposed to do, for now just ignore it
      return 1 ;

    // Below are specific types wich are known to us
    case (Pds::TypeId::Id_Waveform) :
      switch ( version ) {
      case 0:
        if ( m_scanner ) m_scanner->dataObject( *(const WaveformV1*)(xtc->payload()), xtc->src );
        return 1 ;
      }
      break ;

    case (Pds::TypeId::Id_AcqConfig) : {
      switch ( version ) {
      case 1:
        if ( m_scanner ) m_scanner->dataObject( *(const Acqiris::ConfigV1*)(xtc->payload()), xtc->src );
        return 1 ;
      }
      break ;

    }

    default :

      break ;

  }

  if ( m_ignore ) {
    MsgLogRoot( warning, "O2OXtcIterator::process -- unexpected type or version: "
                << Pds::TypeId::name(type) << "/" << version ) ;
    return 1;
  } else {
    MsgLogRoot( error, "O2OXtcIterator::process -- unexpected type or version: "
                << Pds::TypeId::name(type) << "/" << version ) ;
    return 0;
  }

}

} // namespace O2OTranslator
