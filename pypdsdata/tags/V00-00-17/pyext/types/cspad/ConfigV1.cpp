//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class ConfigV1...
//
// Author List:
//      Andrei Salnikov
//
//------------------------------------------------------------------------
#include "SITConfig/SITConfig.h"

//-----------------------
// This Class's Header --
//-----------------------
#include "ConfigV1.h"

//-----------------
// C/C++ Headers --
//-----------------

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "ConfigV1QuadReg.h"
#include "../../EnumType.h"
#include "../../Exception.h"
#include "../TypeLib.h"

//-----------------------------------------------------------------------
// Local Macros, Typedefs, Structures, Unions and Forward Declarations --
//-----------------------------------------------------------------------

namespace {

  pypdsdata::EnumType::Enum runModesEnumValues[] = {
      { "NoRunning",                Pds::CsPad::NoRunning },
      { "RunButDrop",               Pds::CsPad::RunButDrop },
      { "RunAndSendToRCE",          Pds::CsPad::RunAndSendToRCE },
      { "RunAndSendTriggeredByTTL", Pds::CsPad::RunAndSendTriggeredByTTL },
      { "ExternalTriggerSendToRCE", Pds::CsPad::ExternalTriggerSendToRCE },
      { "ExternalTriggerDrop",      Pds::CsPad::ExternalTriggerDrop },
      { "NumberOfRunModes",         Pds::CsPad::NumberOfRunModes },
      { 0, 0 }
  };
  pypdsdata::EnumType runModesEnum ( "RunModes", runModesEnumValues );

  // methods
  PyObject* quads( PyObject* self, PyObject* );
  PyObject* numQuads( PyObject* self, PyObject* );
  FUN0_WRAPPER(pypdsdata::CsPad::ConfigV1, tdi)
  FUN0_WRAPPER(pypdsdata::CsPad::ConfigV1, quadMask)
  FUN0_WRAPPER(pypdsdata::CsPad::ConfigV1, runDelay)
  FUN0_WRAPPER(pypdsdata::CsPad::ConfigV1, eventCode)
  ENUM_FUN0_WRAPPER(pypdsdata::CsPad::ConfigV1, inactiveRunMode, runModesEnum)
  ENUM_FUN0_WRAPPER(pypdsdata::CsPad::ConfigV1, activeRunMode, runModesEnum)
  FUN0_WRAPPER(pypdsdata::CsPad::ConfigV1, payloadSize)
  FUN0_WRAPPER(pypdsdata::CsPad::ConfigV1, badAsicMask0)
  FUN0_WRAPPER(pypdsdata::CsPad::ConfigV1, badAsicMask1)
  FUN0_WRAPPER(pypdsdata::CsPad::ConfigV1, asicMask)
  FUN0_WRAPPER(pypdsdata::CsPad::ConfigV1, numAsicsRead)
  FUN0_WRAPPER(pypdsdata::CsPad::ConfigV1, concentratorVersion)

  PyMethodDef methods[] = {
    {"quads",               quads,               METH_NOARGS, "" },
    {"numQuads",            numQuads,            METH_NOARGS, "" },
    {"tdi",                 tdi,                 METH_NOARGS, "" },
    {"quadMask",            quadMask,            METH_NOARGS, "" },
    {"runDelay",            runDelay,            METH_NOARGS, "" },
    {"eventCode",           eventCode,           METH_NOARGS, "" },
    {"inactiveRunMode",     inactiveRunMode,     METH_NOARGS, "" },
    {"activeRunMode",       activeRunMode,       METH_NOARGS, "" },
    {"payloadSize",         payloadSize,         METH_NOARGS, "" },
    {"badAsicMask0",        badAsicMask0,        METH_NOARGS, "" },
    {"badAsicMask1",        badAsicMask1,        METH_NOARGS, "" },
    {"asicMask",            asicMask,            METH_NOARGS, "" },
    {"numAsicsRead",        numAsicsRead,        METH_NOARGS, "" },
    {"concentratorVersion", concentratorVersion, METH_NOARGS, "" },
    {0, 0, 0, 0}
   };

  char typedoc[] = "Python class wrapping C++ Pds::CsPad::ConfigV1 class.";
}

//              ----------------------------------------
//              -- Public Function Member Definitions --
//              ----------------------------------------

void
pypdsdata::CsPad::ConfigV1::initType( PyObject* module )
{
  PyTypeObject* type = BaseType::typeObject() ;
  type->tp_doc = ::typedoc;
  type->tp_methods = ::methods;

  // define class attributes for enums
  type->tp_dict = PyDict_New();
  PyDict_SetItemString( type->tp_dict, "RunModes", runModesEnum.type() );
  PyObject* val = PyInt_FromLong(Pds::CsPad::MaxQuadsPerSensor);
  PyDict_SetItemString( type->tp_dict, "MaxQuadsPerSensor", val );
  Py_XDECREF(val);

  BaseType::initType( "ConfigV1", module );
}

namespace {

PyObject*
quads( PyObject* self, PyObject* )
{
  Pds::CsPad::ConfigV1* obj = pypdsdata::CsPad::ConfigV1::pdsObject( self );
  if ( not obj ) return 0;

  PyObject* list = PyList_New( Pds::CsPad::MaxQuadsPerSensor );
  Pds::CsPad::ConfigV1QuadReg* quads = obj->quads();
  for ( unsigned i = 0 ; i < Pds::CsPad::MaxQuadsPerSensor ; ++ i ) {
    PyObject* q = pypdsdata::CsPad::ConfigV1QuadReg::PyObject_FromPds(
        &quads[i], self, sizeof(Pds::CsPad::ConfigV1QuadReg) );
    PyList_SET_ITEM( list, i, q );
  }

  return list;
}

PyObject*
numQuads( PyObject* self, PyObject* )
{
  const Pds::CsPad::ConfigV1* obj = pypdsdata::CsPad::ConfigV1::pdsObject( self );
  if ( not obj ) return 0;

  unsigned count = 0 ;
  unsigned mask = obj->quadMask();
  for ( unsigned i = Pds::CsPad::MaxQuadsPerSensor ; i ; -- i ) {
    if ( mask & 1 ) ++ count ;
    mask >>= 1 ;
  }
  
  return PyInt_FromLong(count);
}

}
