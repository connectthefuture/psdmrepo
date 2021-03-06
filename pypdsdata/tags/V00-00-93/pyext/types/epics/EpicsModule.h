#ifndef PYPDSDATA_EPICSMODULE_H
#define PYPDSDATA_EPICSMODULE_H

//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class EpicsModule.
//
//------------------------------------------------------------------------

//-----------------
// C/C++ Headers --
//-----------------

//----------------------
// Base Class Headers --
//----------------------
#include "python/Python.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
#include "pdsdata/epics/EpicsPvData.hh"
#include "pdsdata/xtc/Xtc.hh"

//		---------------------
// 		-- Class Interface --
//		---------------------

namespace pypdsdata {

/**
 *
 *  This software was developed for the LUSI project.  If you use all or
 *  part of it, please give an appropriate acknowledgment.
 *
 *  @see AdditionalClass
 *
 *  @version $Id$
 *
 *  @author Andrei Salnikov
 */

class EpicsModule  {
public:

  // get the initialized module object
  static PyObject* getModule() ;

  // make Python object from Pds type
  static PyObject* PyObject_FromPds( Pds::EpicsPvHeader* pvHeader, PyObject* parent, size_t size );

  // helper method to avoid casting on client side
  static PyObject* PyObject_FromXtc( const Pds::Xtc& xtc, PyObject* parent ) {
    return PyObject_FromPds( static_cast<Pds::EpicsPvHeader*>((void*)xtc.payload()), parent, xtc.sizeofPayload() );
  }

protected:

  // Default constructor
  EpicsModule () {}

  // Destructor
  ~EpicsModule () {}

private:

  // Data members
  static PyObject* s_module;


  // Copy constructor and assignment are disabled by default
  EpicsModule ( const EpicsModule& ) ;
  EpicsModule& operator = ( const EpicsModule& ) ;

};

} // namespace pypdsdata

#endif // PYPDSDATA_EPICSMODULE_H
