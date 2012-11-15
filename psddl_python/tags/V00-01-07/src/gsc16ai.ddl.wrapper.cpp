/* Do not edit this file, as it is auto-generated */

#include <psddl_python/gsc16ai.ddl.wrapper.h> // inc_python
#include <cstddef>

namespace psddl_python {
namespace Gsc16ai {

void createWrappers() {
  _import_array();

#define _CLASS(n, policy) class_<n>(#n, no_init)\
    .def("voltageRange", &n::voltageRange)\
    .def("firstChan", &n::firstChan)\
    .def("lastChan", &n::lastChan)\
    .def("inputMode", &n::inputMode)\
    .def("triggerMode", &n::triggerMode)\
    .def("dataFormat", &n::dataFormat)\
    .def("fps", &n::fps)\
    .def("autocalibEnable", &n::autocalibEnable)\
    .def("timeTagEnable", &n::timeTagEnable)\
    .def("numChannels", &n::numChannels)\

  _CLASS(psddl_python::Gsc16ai::ConfigV1_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(ConfigV1_Wrapper);
#undef _CLASS
  ADD_ENV_OBJECT_STORE_GETTER(ConfigV1);


#define _CLASS(n, policy) class_<n>(#n, no_init)\
    .def("timestamp", &n::timestamp)\
    .def("channelValue", &n::channelValue)\

  _CLASS(psddl_python::Gsc16ai::DataV1_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(DataV1_Wrapper);
#undef _CLASS
  ADD_EVENT_GETTER(DataV1);


} // createWrappers()
} // namespace Gsc16ai
} // namespace psddl_python
