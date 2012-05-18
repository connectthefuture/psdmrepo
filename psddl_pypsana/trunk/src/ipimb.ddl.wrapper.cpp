
// *** Do not edit this file, it is auto-generated ***

#include <cstddef>
#include "psddl_psana/ipimb.ddl.h" // inc_psana
#include "psddl_pypsana/ipimb.ddl.wrapper.h" // inc_pypsana
namespace Psana {
namespace Ipimb {
using namespace boost::python;

void createWrappers() {

#define _CLASS(n, policy) class_<n>("Psana::Ipimb::ConfigV1", no_init)\
    .def("triggerCounter", &n::triggerCounter)\
    .def("serialID", &n::serialID)\
    .def("chargeAmpRange", &n::chargeAmpRange)\
    .def("calibrationRange", &n::calibrationRange)\
    .def("resetLength", &n::resetLength)\
    .def("resetDelay", &n::resetDelay)\
    .def("chargeAmpRefVoltage", &n::chargeAmpRefVoltage)\
    .def("calibrationVoltage", &n::calibrationVoltage)\
    .def("diodeBias", &n::diodeBias)\
    .def("status", &n::status)\
    .def("errors", &n::errors)\
    .def("calStrobeLength", &n::calStrobeLength)\
    .def("trigDelay", &n::trigDelay)\
    .def("diodeGain", &n::diodeGain)\

  _CLASS(ConfigV1_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(ConfigV1_Wrapper);
#undef _CLASS
  ENV_GETTER(ConfigV1);


#define _CLASS(n, policy) class_<n>("Psana::Ipimb::ConfigV2", no_init)\
    .def("triggerCounter", &n::triggerCounter)\
    .def("serialID", &n::serialID)\
    .def("chargeAmpRange", &n::chargeAmpRange)\
    .def("calibrationRange", &n::calibrationRange)\
    .def("resetLength", &n::resetLength)\
    .def("resetDelay", &n::resetDelay)\
    .def("chargeAmpRefVoltage", &n::chargeAmpRefVoltage)\
    .def("calibrationVoltage", &n::calibrationVoltage)\
    .def("diodeBias", &n::diodeBias)\
    .def("status", &n::status)\
    .def("errors", &n::errors)\
    .def("calStrobeLength", &n::calStrobeLength)\
    .def("trigDelay", &n::trigDelay)\
    .def("trigPsDelay", &n::trigPsDelay)\
    .def("adcDelay", &n::adcDelay)\
    .def("diodeGain", &n::diodeGain)\

  _CLASS(ConfigV2_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(ConfigV2_Wrapper);
#undef _CLASS
  ENV_GETTER(ConfigV2);


#define _CLASS(n, policy) class_<n>("Psana::Ipimb::DataV1", no_init)\
    .def("triggerCounter", &n::triggerCounter)\
    .def("config0", &n::config0)\
    .def("config1", &n::config1)\
    .def("config2", &n::config2)\
    .def("channel0", &n::channel0)\
    .def("channel1", &n::channel1)\
    .def("channel2", &n::channel2)\
    .def("channel3", &n::channel3)\
    .def("checksum", &n::checksum)\
    .def("channel0Volts", &n::channel0Volts)\
    .def("channel1Volts", &n::channel1Volts)\
    .def("channel2Volts", &n::channel2Volts)\
    .def("channel3Volts", &n::channel3Volts)\

  _CLASS(DataV1_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(DataV1_Wrapper);
#undef _CLASS
  EVT_GETTER(DataV1);


#define _CLASS(n, policy) class_<n>("Psana::Ipimb::DataV2", no_init)\
    .def("triggerCounter", &n::triggerCounter)\
    .def("config0", &n::config0)\
    .def("config1", &n::config1)\
    .def("config2", &n::config2)\
    .def("channel0", &n::channel0)\
    .def("channel1", &n::channel1)\
    .def("channel2", &n::channel2)\
    .def("channel3", &n::channel3)\
    .def("channel0ps", &n::channel0ps)\
    .def("channel1ps", &n::channel1ps)\
    .def("channel2ps", &n::channel2ps)\
    .def("channel3ps", &n::channel3ps)\
    .def("checksum", &n::checksum)\
    .def("channel0Volts", &n::channel0Volts)\
    .def("channel1Volts", &n::channel1Volts)\
    .def("channel2Volts", &n::channel2Volts)\
    .def("channel3Volts", &n::channel3Volts)\
    .def("channel0psVolts", &n::channel0psVolts)\
    .def("channel1psVolts", &n::channel1psVolts)\
    .def("channel2psVolts", &n::channel2psVolts)\
    .def("channel3psVolts", &n::channel3psVolts)\

  _CLASS(DataV2_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(DataV2_Wrapper);
#undef _CLASS
  EVT_GETTER(DataV2);

}
} // namespace Ipimb
} // namespace Psana
