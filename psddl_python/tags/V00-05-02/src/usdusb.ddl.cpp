/* Do not edit this file, as it is auto-generated */

#include <boost/python.hpp>
#include <boost/make_shared.hpp>
#include "ndarray/ndarray.h"
#include "pdsdata/xtc/TypeId.hh"
#include "psddl_psana/usdusb.ddl.h" // inc_psana
#include "psddl_python/Converter.h"
#include "psddl_python/DdlWrapper.h"
#include "psddl_python/ConverterMap.h"
#include "psddl_python/ConverterBoostDef.h"
#include "psddl_python/ConverterBoostDefSharedPtr.h"

namespace psddl_python {
namespace UsdUsb {

using namespace boost::python;
using boost::python::object;
using boost::shared_ptr;
using std::vector;

namespace {
template<typename T, std::vector<int> (T::*MF)() const>
PyObject* method_shape(const T *x) {
  return detail::vintToList((x->*MF)());
}
} // namespace

void createWrappers(PyObject* module) {
  PyObject* submodule = Py_InitModule3( "psana.UsdUsb", 0, "The Python wrapper module for UsdUsb types");
  Py_INCREF(submodule);
  PyModule_AddObject(module, "UsdUsb", submodule);
  scope mod = object(handle<>(borrowed(submodule)));
  class_<Psana::UsdUsb::ConfigV1, boost::shared_ptr<Psana::UsdUsb::ConfigV1>, boost::noncopyable >("ConfigV1", no_init)
    .def("counting_mode", &Psana::UsdUsb::ConfigV1::counting_mode)
    .def("quadrature_mode", &Psana::UsdUsb::ConfigV1::quadrature_mode)
  ;
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDefSharedPtr<Psana::UsdUsb::ConfigV1> >(Pds::TypeId::Id_UsdUsbConfig));

  class_<Psana::UsdUsb::DataV1, boost::shared_ptr<Psana::UsdUsb::DataV1>, boost::noncopyable >("DataV1", no_init)
    .def("digital_in", &Psana::UsdUsb::DataV1::digital_in)
    .def("timestamp", &Psana::UsdUsb::DataV1::timestamp)
    .def("status", &Psana::UsdUsb::DataV1::status)
    .def("analog_in", &Psana::UsdUsb::DataV1::analog_in)
    .def("encoder_count", &Psana::UsdUsb::DataV1::encoder_count)
  ;
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDefSharedPtr<Psana::UsdUsb::DataV1> >(Pds::TypeId::Id_UsdUsbData));

  {
    PyObject* unvlist = PyList_New(1);
    PyList_SET_ITEM(unvlist, 0, PyObject_GetAttrString(submodule, "DataV1"));
    PyObject_SetAttrString(submodule, "Data", unvlist);
    Py_CLEAR(unvlist);
  }
  {
    PyObject* unvlist = PyList_New(1);
    PyList_SET_ITEM(unvlist, 0, PyObject_GetAttrString(submodule, "ConfigV1"));
    PyObject_SetAttrString(submodule, "Config", unvlist);
    Py_CLEAR(unvlist);
  }
  detail::register_ndarray_to_numpy_cvt<const uint32_t, 1>();
  detail::register_ndarray_to_numpy_cvt<const uint16_t, 1>();
  detail::register_ndarray_to_numpy_cvt<const uint8_t, 1>();
  detail::register_ndarray_to_numpy_cvt<const int32_t, 1>();

} // createWrappers()
} // namespace UsdUsb
} // namespace psddl_python