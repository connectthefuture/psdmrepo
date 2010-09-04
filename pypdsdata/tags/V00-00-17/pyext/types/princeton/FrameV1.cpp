//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class FrameV1...
//
// Author List:
//      Andrei Salnikov
//
//------------------------------------------------------------------------

//-----------------------
// This Class's Header --
//-----------------------
#include "FrameV1.h"

//-----------------
// C/C++ Headers --
//-----------------

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "ConfigV1.h"
#include "../../Exception.h"
#include "../TypeLib.h"
#include "../../pdsdata_numpy.h"

//-----------------------------------------------------------------------
// Local Macros, Typedefs, Structures, Unions and Forward Declarations --
//-----------------------------------------------------------------------
namespace {

  // type-specific methods
  FUN0_WRAPPER(pypdsdata::Princeton::FrameV1, shotIdStart)
  FUN0_WRAPPER(pypdsdata::Princeton::FrameV1, readoutTime)
  PyObject* data( PyObject* self, PyObject* args );

  PyMethodDef methods[] = {
    { "shotIdStart",    shotIdStart,    METH_NOARGS, "" },
    { "readoutTime",    readoutTime,    METH_NOARGS, "" },
    { "data",           data,           METH_VARARGS, "" },
    {0, 0, 0, 0}
   };

  char typedoc[] = "Python class wrapping C++ Pds::Princeton::FrameV1 class.";

}

//		----------------------------------------
// 		-- Public Function Member Definitions --
//		----------------------------------------

void
pypdsdata::Princeton::FrameV1::initType( PyObject* module )
{
  PyTypeObject* type = BaseType::typeObject() ;
  type->tp_doc = ::typedoc;
  type->tp_methods = ::methods;

  BaseType::initType( "FrameV1", module );
}

namespace {

PyObject*
data( PyObject* self, PyObject* args )
{
  Pds::Princeton::FrameV1* obj = pypdsdata::Princeton::FrameV1::pdsObject( self );
  if ( not obj ) return 0;

  // parse args
  PyObject* configObj ;
  if ( not PyArg_ParseTuple( args, "O:Princeton.FrameV1.data", &configObj ) ) return 0;

  // get config object
  if ( not pypdsdata::Princeton::ConfigV1::Object_TypeCheck( configObj ) ) {
    PyErr_SetString(PyExc_TypeError, "Error: parameter is not a PNCCD.ConfigV1 object");
    return 0;
  }
  Pds::Princeton::ConfigV1* config = pypdsdata::Princeton::ConfigV1::pdsObject( configObj );

  // NumPy type number
  int typenum = NPY_USHORT ;
  int flags = NPY_C_CONTIGUOUS ;

  // dimensions
  npy_intp dims[2] = { config->height(), config->width() };

  // make array
  PyObject* array = PyArray_New(&PyArray_Type, 2, dims, typenum, 0,
                                (void*)obj->data(), 0, flags, 0);

  // array does not own its data, set self as owner
  Py_INCREF(self);
  ((PyArrayObject*)array)->base = self ;

  return array;
}

}
