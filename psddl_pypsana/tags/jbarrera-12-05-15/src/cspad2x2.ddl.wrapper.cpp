
// *** Do not edit this file, it is auto-generated ***

#include <cstddef>
#include "psddl_psana/cspad2x2.ddl.h" // inc_psana
#include "psddl_pypsana/cspad2x2.ddl.wrapper.h" // inc_pypsana
namespace Psana {
namespace CsPad2x2 {
using namespace boost::python;

void createWrappers() {

#define _CLASS(n) class_<n>("Psana::CsPad2x2::CsPad2x2DigitalPotsCfg", no_init)\
    .def("pots", &CsPad2x2DigitalPotsCfg_Wrapper::pots)\

  _CLASS(CsPad2x2DigitalPotsCfg_Wrapper);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::CsPad2x2::CsPad2x2ReadOnlyCfg", no_init)\
    .def("shiftTest", &CsPad2x2ReadOnlyCfg_Wrapper::shiftTest)\
    .def("version", &CsPad2x2ReadOnlyCfg_Wrapper::version)\

  _CLASS(CsPad2x2ReadOnlyCfg_Wrapper);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::CsPad2x2::ProtectionSystemThreshold", no_init)\
    .def("adcThreshold", &ProtectionSystemThreshold_Wrapper::adcThreshold)\
    .def("pixelCountThreshold", &ProtectionSystemThreshold_Wrapper::pixelCountThreshold)\

  _CLASS(ProtectionSystemThreshold_Wrapper);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::CsPad2x2::CsPad2x2GainMapCfg", no_init)\
    .def("gainMap", &CsPad2x2GainMapCfg_Wrapper::gainMap)\

  _CLASS(CsPad2x2GainMapCfg_Wrapper);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::CsPad2x2::ConfigV1QuadReg", no_init)\
    .def("shiftSelect", &ConfigV1QuadReg_Wrapper::shiftSelect)\
    .def("edgeSelect", &ConfigV1QuadReg_Wrapper::edgeSelect)\
    .def("readClkSet", &ConfigV1QuadReg_Wrapper::readClkSet)\
    .def("readClkHold", &ConfigV1QuadReg_Wrapper::readClkHold)\
    .def("dataMode", &ConfigV1QuadReg_Wrapper::dataMode)\
    .def("prstSel", &ConfigV1QuadReg_Wrapper::prstSel)\
    .def("acqDelay", &ConfigV1QuadReg_Wrapper::acqDelay)\
    .def("intTime", &ConfigV1QuadReg_Wrapper::intTime)\
    .def("digDelay", &ConfigV1QuadReg_Wrapper::digDelay)\
    .def("ampIdle", &ConfigV1QuadReg_Wrapper::ampIdle)\
    .def("injTotal", &ConfigV1QuadReg_Wrapper::injTotal)\
    .def("rowColShiftPer", &ConfigV1QuadReg_Wrapper::rowColShiftPer)\
    .def("ampReset", &ConfigV1QuadReg_Wrapper::ampReset)\
    .def("digCount", &ConfigV1QuadReg_Wrapper::digCount)\
    .def("digPeriod", &ConfigV1QuadReg_Wrapper::digPeriod)\
    .def("PeltierEnable", &ConfigV1QuadReg_Wrapper::PeltierEnable)\
    .def("kpConstant", &ConfigV1QuadReg_Wrapper::kpConstant)\
    .def("kiConstant", &ConfigV1QuadReg_Wrapper::kiConstant)\
    .def("kdConstant", &ConfigV1QuadReg_Wrapper::kdConstant)\
    .def("humidThold", &ConfigV1QuadReg_Wrapper::humidThold)\
    .def("setPoint", &ConfigV1QuadReg_Wrapper::setPoint)\
    .def("ro", &ConfigV1QuadReg_Wrapper::ro)\
    .def("dp", &ConfigV1QuadReg_Wrapper::dp)\
    .def("gm", &ConfigV1QuadReg_Wrapper::gm)\

  _CLASS(ConfigV1QuadReg_Wrapper);
#undef _CLASS
  ENV_GETTER(ConfigV1QuadReg);


#define _CLASS(n) class_<n>("Psana::CsPad2x2::ConfigV1", no_init)\
    .def("concentratorVersion", &ConfigV1_Wrapper::concentratorVersion)\
    .def("protectionThreshold", &ConfigV1_Wrapper::protectionThreshold)\
    .def("protectionEnable", &ConfigV1_Wrapper::protectionEnable)\
    .def("inactiveRunMode", &ConfigV1_Wrapper::inactiveRunMode)\
    .def("activeRunMode", &ConfigV1_Wrapper::activeRunMode)\
    .def("tdi", &ConfigV1_Wrapper::tdi)\
    .def("payloadSize", &ConfigV1_Wrapper::payloadSize)\
    .def("badAsicMask", &ConfigV1_Wrapper::badAsicMask)\
    .def("asicMask", &ConfigV1_Wrapper::asicMask)\
    .def("roiMask", &ConfigV1_Wrapper::roiMask)\
    .def("quad", &ConfigV1_Wrapper::quad)\
    .def("numAsicsRead", &ConfigV1_Wrapper::numAsicsRead)\
    .def("numAsicsStored", &ConfigV1_Wrapper::numAsicsStored)\

  _CLASS(ConfigV1_Wrapper);
#undef _CLASS
  ENV_GETTER(ConfigV1);


#define _CLASS(n) class_<n>("Psana::CsPad2x2::ElementV1", no_init)\
    .def("virtual_channel", &ElementV1_Wrapper::virtual_channel)\
    .def("lane", &ElementV1_Wrapper::lane)\
    .def("tid", &ElementV1_Wrapper::tid)\
    .def("acq_count", &ElementV1_Wrapper::acq_count)\
    .def("op_code", &ElementV1_Wrapper::op_code)\
    .def("quad", &ElementV1_Wrapper::quad)\
    .def("seq_count", &ElementV1_Wrapper::seq_count)\
    .def("ticks", &ElementV1_Wrapper::ticks)\
    .def("fiducials", &ElementV1_Wrapper::fiducials)\
    .def("sb_temp", &ElementV1_Wrapper::sb_temp)\
    .def("frame_type", &ElementV1_Wrapper::frame_type)\
    .def("data", &ElementV1_Wrapper::data)\
    .def("common_mode", &ElementV1_Wrapper::common_mode)\

  _CLASS(ElementV1_Wrapper);
#undef _CLASS

}
} // namespace CsPad2x2
} // namespace Psana
