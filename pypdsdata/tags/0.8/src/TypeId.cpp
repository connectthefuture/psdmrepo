//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class TypeId...
//
// Author List:
//      Andrei Salnikov
//
//------------------------------------------------------------------------

//-----------------------
// This Class's Header --
//-----------------------
#include "TypeId.h"

//-----------------
// C/C++ Headers --
//-----------------
#include <string>
#include <new>

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "EnumType.h"
#include "types/TypeLib.h"

//-----------------------------------------------------------------------
// Local Macros, Typedefs, Structures, Unions and Forward Declarations --
//-----------------------------------------------------------------------

namespace {

  pypdsdata::EnumType::Enum typeEnumValues[] = {
      { "Any",                Pds::TypeId::Any },
      { "Id_Xtc",             Pds::TypeId::Id_Xtc },
      { "Id_Frame",           Pds::TypeId::Id_Frame },
      { "Id_AcqWaveform",     Pds::TypeId::Id_AcqWaveform },
      { "Id_AcqConfig",        Pds::TypeId::Id_AcqConfig },
      { "Id_TwoDGaussian",    Pds::TypeId::Id_TwoDGaussian },
      { "Id_Opal1kConfig",     Pds::TypeId::Id_Opal1kConfig },
      { "Id_FrameFexConfig",   Pds::TypeId::Id_FrameFexConfig },
      { "Id_EvrConfig",        Pds::TypeId::Id_EvrConfig },
      { "Id_TM6740Config",     Pds::TypeId::Id_TM6740Config },
      { "Id_ControlConfig",    Pds::TypeId::Id_ControlConfig },
      { "Id_pnCCDframe",      Pds::TypeId::Id_pnCCDframe },
      { "Id_pnCCDconfig",      Pds::TypeId::Id_pnCCDconfig },
      { "Id_Epics",           Pds::TypeId::Id_Epics },
      { "Id_FEEGasDetEnergy", Pds::TypeId::Id_FEEGasDetEnergy },
      { "Id_EBeam",           Pds::TypeId::Id_EBeam },
      { "Id_PhaseCavity",     Pds::TypeId::Id_PhaseCavity },
      { "NumberOf",           Pds::TypeId::NumberOf },
      { 0, 0 }
  };
  pypdsdata::EnumType typeEnum ( "Type", typeEnumValues );

  // standard Python stuff
  int TypeId_init( PyObject* self, PyObject* args, PyObject* kwds );
  PyObject* TypeId_str( PyObject* self );
  PyObject* TypeId_repr( PyObject* self );
  long TypeId_hash( PyObject* self );
  int TypeId_compare( PyObject *self, PyObject *other);

  // type-specific methods
  FUN0_WRAPPER_EMBEDDED(pypdsdata::TypeId, value);
  ENUM_FUN0_WRAPPER_EMBEDDED(pypdsdata::TypeId, id, typeEnum);
  FUN0_WRAPPER_EMBEDDED(pypdsdata::TypeId, version);

  PyMethodDef methods[] = {
    { "value",    value,   METH_NOARGS, "Returns the whole type ID number including version" },
    { "id",       id,      METH_NOARGS, "Returns the type ID number without version" },
    { "version",  version, METH_NOARGS, "Returns the type ID version number" },
    {0, 0, 0, 0}
   };

  char typedoc[] = "Python class wrapping C++ Pds::TypeId class.\n\n"
      "This class inherits from a int type, the instances of this class\n"
      "are regular numbers with some additional niceties: repr() and str()\n"
      "functions witll print string representaion of the enum values.\n"
      "Class defines several attributes which correspond to the C++ enum values.\n\n"
      "Class constructor takes teo optional positional arguments - type id and\n"
      "version number. If missing the values are initialized with 0.";

}

//		----------------------------------------
// 		-- Public Function Member Definitions --
//		----------------------------------------

void
pypdsdata::TypeId::initType( PyObject* module )
{
  PyTypeObject* type = BaseType::typeObject() ;
  type->tp_doc = ::typedoc;
  type->tp_methods = ::methods;
  type->tp_init = TypeId_init;
  type->tp_hash = TypeId_hash;
  type->tp_compare = TypeId_compare;
  type->tp_str = TypeId_str;
  type->tp_repr = TypeId_repr;

  // define class attributes for enums
  PyObject* tp_dict = PyDict_New();
  PyDict_SetItemString( tp_dict, "Type", typeEnum.type() );
  type->tp_dict = tp_dict;

  BaseType::initType( "TypeId", module );
}


namespace {

int
TypeId_init(PyObject* self, PyObject* args, PyObject* kwds)
{
  pypdsdata::TypeId* py_this = (pypdsdata::TypeId*) self;
  if ( not py_this ) {
    PyErr_SetString(PyExc_RuntimeError, "Error: self is NULL");
    return -1;
  }

  // parse arguments
  unsigned val = Pds::TypeId::Any;
  unsigned version = 0;
  if ( not PyArg_ParseTuple( args, "|II:TypeId", &val, &version ) ) return -1;

  if ( val >= Pds::TypeId::NumberOf ) {
    PyErr_SetString(PyExc_TypeError, "Error: TypeId out of range");
    return -1;
  }

  new(&py_this->m_obj) Pds::TypeId( Pds::TypeId::Type(val), version );

  return 0;
}

long
TypeId_hash( PyObject* self )
{
  pypdsdata::TypeId* py_this = (pypdsdata::TypeId*) self;
  long hash = py_this->m_obj.value();
  return hash;
}

int
TypeId_compare( PyObject* self, PyObject* other )
{
  pypdsdata::TypeId* py_this = (pypdsdata::TypeId*) self;
  pypdsdata::TypeId* py_other = (pypdsdata::TypeId*) other;
  if ( py_this->m_obj.value() > py_other->m_obj.value() ) return 1 ;
  if ( py_this->m_obj.value() == py_other->m_obj.value() ) return 0 ;
  return -1 ;
}

PyObject*
TypeId_str( PyObject* self )
{
  pypdsdata::TypeId* py_this = (pypdsdata::TypeId*) self;
  if ( py_this->m_obj.version() ) {
    return PyString_FromFormat("%s_V%d", Pds::TypeId::name(py_this->m_obj.id()),
        py_this->m_obj.version() );
  } else {
    return PyString_FromString( Pds::TypeId::name(py_this->m_obj.id()) );
  }
}

PyObject*
TypeId_repr( PyObject* self )
{
  pypdsdata::TypeId* py_this = (pypdsdata::TypeId*) self;
  return PyString_FromFormat("<TypeId(%s,%d)>", Pds::TypeId::name(py_this->m_obj.id()),
      py_this->m_obj.version() );
}

}
