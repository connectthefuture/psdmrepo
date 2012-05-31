
// *** Do not edit this file, it is auto-generated ***

#include <cstddef>
#include <psddl_psana/pnccd.ddl.h> // inc_psana
#include <psddl_pyana/pnccd.ddl.wrapper.h> // inc_pyana
namespace Psana {
namespace PNCCD {
using namespace boost::python;

void createWrappers() {

#define _CLASS(n, policy) class_<n>(#n, no_init)\
    .def("numLinks", &n::numLinks)\
    .def("payloadSizePerLink", &n::payloadSizePerLink)\

  _CLASS(Psana::PNCCD::ConfigV1_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(ConfigV1_Wrapper);
#undef _CLASS
  ADD_GETTER(ConfigV1);


#define _CLASS(n, policy) class_<n>(#n, no_init)\
    .def("numLinks", &n::numLinks)\
    .def("payloadSizePerLink", &n::payloadSizePerLink)\
    .def("numChannels", &n::numChannels)\
    .def("numRows", &n::numRows)\
    .def("numSubmoduleChannels", &n::numSubmoduleChannels)\
    .def("numSubmoduleRows", &n::numSubmoduleRows)\
    .def("numSubmodules", &n::numSubmodules)\
    .def("camexMagic", &n::camexMagic)\
    .def("info", &n::info)\
    .def("timingFName", &n::timingFName)\
    .def("info_shape", &n::info_shape)\
    .def("timingFName_shape", &n::timingFName_shape)\

  _CLASS(Psana::PNCCD::ConfigV2_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(ConfigV2_Wrapper);
#undef _CLASS
  ADD_GETTER(ConfigV2);


#define _CLASS(n, policy) class_<n>(#n, no_init)\
    .def("specialWord", &n::specialWord)\
    .def("frameNumber", &n::frameNumber)\
    .def("timeStampHi", &n::timeStampHi)\
    .def("timeStampLo", &n::timeStampLo)\
    .def("data", &n::data)\

  _CLASS(Psana::PNCCD::FrameV1_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(FrameV1_Wrapper);
#undef _CLASS


} // createWrappers()
} // namespace PNCCD
} // namespace Psana
