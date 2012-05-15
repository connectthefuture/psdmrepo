
// *** Do not edit this file, it is auto-generated ***

#include <cstddef>
#include "psddl_psana/epics.ddl.h" // inc_psana
#include "psddl_pypsana/epics.ddl.wrapper.h" // inc_pypsana
namespace Psana {
namespace Epics {
using namespace boost::python;

void createWrappers() {

#define _CLASS(n) class_<n>("Psana::Epics::epicsTimeStamp", no_init)\
    .def("sec", &epicsTimeStamp_Wrapper::sec)\
    .def("nsec", &epicsTimeStamp_Wrapper::nsec)\
    .def("_sizeof", &epicsTimeStamp_Wrapper::_sizeof)\

  _CLASS(epicsTimeStamp_Wrapper);
  _CLASS(epicsTimeStamp);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::dbr_time_string", no_init)\
    .def("status", &dbr_time_string_Wrapper::status)\
    .def("severity", &dbr_time_string_Wrapper::severity)\
    .def("stamp", &dbr_time_string_Wrapper::stamp)\
    .def("_sizeof", &dbr_time_string_Wrapper::_sizeof)\

  _CLASS(dbr_time_string_Wrapper);
  _CLASS(dbr_time_string);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::dbr_time_short", no_init)\
    .def("status", &dbr_time_short_Wrapper::status)\
    .def("severity", &dbr_time_short_Wrapper::severity)\
    .def("stamp", &dbr_time_short_Wrapper::stamp)\
    .def("_sizeof", &dbr_time_short_Wrapper::_sizeof)\

  _CLASS(dbr_time_short_Wrapper);
  _CLASS(dbr_time_short);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::dbr_time_float", no_init)\
    .def("status", &dbr_time_float_Wrapper::status)\
    .def("severity", &dbr_time_float_Wrapper::severity)\
    .def("stamp", &dbr_time_float_Wrapper::stamp)\
    .def("_sizeof", &dbr_time_float_Wrapper::_sizeof)\

  _CLASS(dbr_time_float_Wrapper);
  _CLASS(dbr_time_float);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::dbr_time_enum", no_init)\
    .def("status", &dbr_time_enum_Wrapper::status)\
    .def("severity", &dbr_time_enum_Wrapper::severity)\
    .def("stamp", &dbr_time_enum_Wrapper::stamp)\
    .def("_sizeof", &dbr_time_enum_Wrapper::_sizeof)\

  _CLASS(dbr_time_enum_Wrapper);
  _CLASS(dbr_time_enum);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::dbr_time_char", no_init)\
    .def("status", &dbr_time_char_Wrapper::status)\
    .def("severity", &dbr_time_char_Wrapper::severity)\
    .def("stamp", &dbr_time_char_Wrapper::stamp)\
    .def("_sizeof", &dbr_time_char_Wrapper::_sizeof)\

  _CLASS(dbr_time_char_Wrapper);
  _CLASS(dbr_time_char);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::dbr_time_long", no_init)\
    .def("status", &dbr_time_long_Wrapper::status)\
    .def("severity", &dbr_time_long_Wrapper::severity)\
    .def("stamp", &dbr_time_long_Wrapper::stamp)\
    .def("_sizeof", &dbr_time_long_Wrapper::_sizeof)\

  _CLASS(dbr_time_long_Wrapper);
  _CLASS(dbr_time_long);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::dbr_time_double", no_init)\
    .def("status", &dbr_time_double_Wrapper::status)\
    .def("severity", &dbr_time_double_Wrapper::severity)\
    .def("stamp", &dbr_time_double_Wrapper::stamp)\
    .def("_sizeof", &dbr_time_double_Wrapper::_sizeof)\

  _CLASS(dbr_time_double_Wrapper);
  _CLASS(dbr_time_double);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::dbr_sts_string", no_init)\
    .def("status", &dbr_sts_string_Wrapper::status)\
    .def("severity", &dbr_sts_string_Wrapper::severity)\
    .def("_sizeof", &dbr_sts_string_Wrapper::_sizeof)\

  _CLASS(dbr_sts_string_Wrapper);
  _CLASS(dbr_sts_string);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::dbr_ctrl_short", no_init)\
    .def("status", &dbr_ctrl_short_Wrapper::status)\
    .def("severity", &dbr_ctrl_short_Wrapper::severity)\
    .def("units", &dbr_ctrl_short_Wrapper::units)\
    .def("upper_disp_limit", &dbr_ctrl_short_Wrapper::upper_disp_limit)\
    .def("lower_disp_limit", &dbr_ctrl_short_Wrapper::lower_disp_limit)\
    .def("upper_alarm_limit", &dbr_ctrl_short_Wrapper::upper_alarm_limit)\
    .def("upper_warning_limit", &dbr_ctrl_short_Wrapper::upper_warning_limit)\
    .def("lower_warning_limit", &dbr_ctrl_short_Wrapper::lower_warning_limit)\
    .def("lower_alarm_limit", &dbr_ctrl_short_Wrapper::lower_alarm_limit)\
    .def("upper_ctrl_limit", &dbr_ctrl_short_Wrapper::upper_ctrl_limit)\
    .def("lower_ctrl_limit", &dbr_ctrl_short_Wrapper::lower_ctrl_limit)\
    .def("_sizeof", &dbr_ctrl_short_Wrapper::_sizeof)\
    .def("units_shape", &dbr_ctrl_short_Wrapper::units_shape)\

  _CLASS(dbr_ctrl_short_Wrapper);
  _CLASS(dbr_ctrl_short);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::dbr_ctrl_float", no_init)\
    .def("status", &dbr_ctrl_float_Wrapper::status)\
    .def("severity", &dbr_ctrl_float_Wrapper::severity)\
    .def("precision", &dbr_ctrl_float_Wrapper::precision)\
    .def("units", &dbr_ctrl_float_Wrapper::units)\
    .def("upper_disp_limit", &dbr_ctrl_float_Wrapper::upper_disp_limit)\
    .def("lower_disp_limit", &dbr_ctrl_float_Wrapper::lower_disp_limit)\
    .def("upper_alarm_limit", &dbr_ctrl_float_Wrapper::upper_alarm_limit)\
    .def("upper_warning_limit", &dbr_ctrl_float_Wrapper::upper_warning_limit)\
    .def("lower_warning_limit", &dbr_ctrl_float_Wrapper::lower_warning_limit)\
    .def("lower_alarm_limit", &dbr_ctrl_float_Wrapper::lower_alarm_limit)\
    .def("upper_ctrl_limit", &dbr_ctrl_float_Wrapper::upper_ctrl_limit)\
    .def("lower_ctrl_limit", &dbr_ctrl_float_Wrapper::lower_ctrl_limit)\
    .def("_sizeof", &dbr_ctrl_float_Wrapper::_sizeof)\
    .def("units_shape", &dbr_ctrl_float_Wrapper::units_shape)\

  _CLASS(dbr_ctrl_float_Wrapper);
  _CLASS(dbr_ctrl_float);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::dbr_ctrl_enum", no_init)\
    .def("status", &dbr_ctrl_enum_Wrapper::status)\
    .def("severity", &dbr_ctrl_enum_Wrapper::severity)\
    .def("no_str", &dbr_ctrl_enum_Wrapper::no_str)\
    .def("strings", &dbr_ctrl_enum_Wrapper::strings)\
    .def("_sizeof", &dbr_ctrl_enum_Wrapper::_sizeof)\
    .def("strings_shape", &dbr_ctrl_enum_Wrapper::strings_shape)\

  _CLASS(dbr_ctrl_enum_Wrapper);
  _CLASS(dbr_ctrl_enum);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::dbr_ctrl_char", no_init)\
    .def("status", &dbr_ctrl_char_Wrapper::status)\
    .def("severity", &dbr_ctrl_char_Wrapper::severity)\
    .def("units", &dbr_ctrl_char_Wrapper::units)\
    .def("upper_disp_limit", &dbr_ctrl_char_Wrapper::upper_disp_limit)\
    .def("lower_disp_limit", &dbr_ctrl_char_Wrapper::lower_disp_limit)\
    .def("upper_alarm_limit", &dbr_ctrl_char_Wrapper::upper_alarm_limit)\
    .def("upper_warning_limit", &dbr_ctrl_char_Wrapper::upper_warning_limit)\
    .def("lower_warning_limit", &dbr_ctrl_char_Wrapper::lower_warning_limit)\
    .def("lower_alarm_limit", &dbr_ctrl_char_Wrapper::lower_alarm_limit)\
    .def("upper_ctrl_limit", &dbr_ctrl_char_Wrapper::upper_ctrl_limit)\
    .def("lower_ctrl_limit", &dbr_ctrl_char_Wrapper::lower_ctrl_limit)\
    .def("_sizeof", &dbr_ctrl_char_Wrapper::_sizeof)\
    .def("units_shape", &dbr_ctrl_char_Wrapper::units_shape)\

  _CLASS(dbr_ctrl_char_Wrapper);
  _CLASS(dbr_ctrl_char);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::dbr_ctrl_long", no_init)\
    .def("status", &dbr_ctrl_long_Wrapper::status)\
    .def("severity", &dbr_ctrl_long_Wrapper::severity)\
    .def("units", &dbr_ctrl_long_Wrapper::units)\
    .def("upper_disp_limit", &dbr_ctrl_long_Wrapper::upper_disp_limit)\
    .def("lower_disp_limit", &dbr_ctrl_long_Wrapper::lower_disp_limit)\
    .def("upper_alarm_limit", &dbr_ctrl_long_Wrapper::upper_alarm_limit)\
    .def("upper_warning_limit", &dbr_ctrl_long_Wrapper::upper_warning_limit)\
    .def("lower_warning_limit", &dbr_ctrl_long_Wrapper::lower_warning_limit)\
    .def("lower_alarm_limit", &dbr_ctrl_long_Wrapper::lower_alarm_limit)\
    .def("upper_ctrl_limit", &dbr_ctrl_long_Wrapper::upper_ctrl_limit)\
    .def("lower_ctrl_limit", &dbr_ctrl_long_Wrapper::lower_ctrl_limit)\
    .def("_sizeof", &dbr_ctrl_long_Wrapper::_sizeof)\
    .def("units_shape", &dbr_ctrl_long_Wrapper::units_shape)\

  _CLASS(dbr_ctrl_long_Wrapper);
  _CLASS(dbr_ctrl_long);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::dbr_ctrl_double", no_init)\
    .def("status", &dbr_ctrl_double_Wrapper::status)\
    .def("severity", &dbr_ctrl_double_Wrapper::severity)\
    .def("precision", &dbr_ctrl_double_Wrapper::precision)\
    .def("units", &dbr_ctrl_double_Wrapper::units)\
    .def("upper_disp_limit", &dbr_ctrl_double_Wrapper::upper_disp_limit)\
    .def("lower_disp_limit", &dbr_ctrl_double_Wrapper::lower_disp_limit)\
    .def("upper_alarm_limit", &dbr_ctrl_double_Wrapper::upper_alarm_limit)\
    .def("upper_warning_limit", &dbr_ctrl_double_Wrapper::upper_warning_limit)\
    .def("lower_warning_limit", &dbr_ctrl_double_Wrapper::lower_warning_limit)\
    .def("lower_alarm_limit", &dbr_ctrl_double_Wrapper::lower_alarm_limit)\
    .def("upper_ctrl_limit", &dbr_ctrl_double_Wrapper::upper_ctrl_limit)\
    .def("lower_ctrl_limit", &dbr_ctrl_double_Wrapper::lower_ctrl_limit)\
    .def("_sizeof", &dbr_ctrl_double_Wrapper::_sizeof)\
    .def("units_shape", &dbr_ctrl_double_Wrapper::units_shape)\

  _CLASS(dbr_ctrl_double_Wrapper);
  _CLASS(dbr_ctrl_double);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::EpicsPvHeader", no_init)\
    .def("pvId", &EpicsPvHeader_Wrapper::pvId)\
    .def("dbrType", &EpicsPvHeader_Wrapper::dbrType)\
    .def("numElements", &EpicsPvHeader_Wrapper::numElements)\
    .def("print", &EpicsPvHeader_Wrapper::print)\
    .def("isCtrl", &EpicsPvHeader_Wrapper::isCtrl)\
    .def("isTime", &EpicsPvHeader_Wrapper::isTime)\
    .def("status", &EpicsPvHeader_Wrapper::status)\
    .def("severity", &EpicsPvHeader_Wrapper::severity)\

  _CLASS(EpicsPvHeader_Wrapper);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::EpicsPvCtrlHeader", no_init)\
    .def("pvName", &EpicsPvCtrlHeader_Wrapper::pvName)\
    .def("pvName_shape", &EpicsPvCtrlHeader_Wrapper::pvName_shape)\

  _CLASS(EpicsPvCtrlHeader_Wrapper);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::EpicsPvTimeHeader", no_init)\
    .def("stamp", &EpicsPvTimeHeader_Wrapper::stamp)\

  _CLASS(EpicsPvTimeHeader_Wrapper);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::EpicsPvCtrlString", no_init)\
    .def("dbr", &EpicsPvCtrlString_Wrapper::dbr)\
    .def("data", &EpicsPvCtrlString_Wrapper::data)\
    .def("value", &EpicsPvCtrlString_Wrapper::value)\
    .def("data_shape", &EpicsPvCtrlString_Wrapper::data_shape)\

  _CLASS(EpicsPvCtrlString_Wrapper);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::EpicsPvCtrlShort", no_init)\
    .def("dbr", &EpicsPvCtrlShort_Wrapper::dbr)\
    .def("data", &EpicsPvCtrlShort_Wrapper::data)\
    .def("value", &EpicsPvCtrlShort_Wrapper::value)\

  _CLASS(EpicsPvCtrlShort_Wrapper);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::EpicsPvCtrlFloat", no_init)\
    .def("dbr", &EpicsPvCtrlFloat_Wrapper::dbr)\
    .def("data", &EpicsPvCtrlFloat_Wrapper::data)\
    .def("value", &EpicsPvCtrlFloat_Wrapper::value)\

  _CLASS(EpicsPvCtrlFloat_Wrapper);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::EpicsPvCtrlEnum", no_init)\
    .def("dbr", &EpicsPvCtrlEnum_Wrapper::dbr)\
    .def("data", &EpicsPvCtrlEnum_Wrapper::data)\
    .def("value", &EpicsPvCtrlEnum_Wrapper::value)\

  _CLASS(EpicsPvCtrlEnum_Wrapper);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::EpicsPvCtrlChar", no_init)\
    .def("dbr", &EpicsPvCtrlChar_Wrapper::dbr)\
    .def("data", &EpicsPvCtrlChar_Wrapper::data)\
    .def("value", &EpicsPvCtrlChar_Wrapper::value)\

  _CLASS(EpicsPvCtrlChar_Wrapper);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::EpicsPvCtrlLong", no_init)\
    .def("dbr", &EpicsPvCtrlLong_Wrapper::dbr)\
    .def("data", &EpicsPvCtrlLong_Wrapper::data)\
    .def("value", &EpicsPvCtrlLong_Wrapper::value)\

  _CLASS(EpicsPvCtrlLong_Wrapper);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::EpicsPvCtrlDouble", no_init)\
    .def("dbr", &EpicsPvCtrlDouble_Wrapper::dbr)\
    .def("data", &EpicsPvCtrlDouble_Wrapper::data)\
    .def("value", &EpicsPvCtrlDouble_Wrapper::value)\

  _CLASS(EpicsPvCtrlDouble_Wrapper);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::EpicsPvTimeString", no_init)\
    .def("dbr", &EpicsPvTimeString_Wrapper::dbr)\
    .def("data", &EpicsPvTimeString_Wrapper::data)\
    .def("value", &EpicsPvTimeString_Wrapper::value)\
    .def("data_shape", &EpicsPvTimeString_Wrapper::data_shape)\

  _CLASS(EpicsPvTimeString_Wrapper);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::EpicsPvTimeShort", no_init)\
    .def("dbr", &EpicsPvTimeShort_Wrapper::dbr)\
    .def("data", &EpicsPvTimeShort_Wrapper::data)\
    .def("value", &EpicsPvTimeShort_Wrapper::value)\

  _CLASS(EpicsPvTimeShort_Wrapper);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::EpicsPvTimeFloat", no_init)\
    .def("dbr", &EpicsPvTimeFloat_Wrapper::dbr)\
    .def("data", &EpicsPvTimeFloat_Wrapper::data)\
    .def("value", &EpicsPvTimeFloat_Wrapper::value)\

  _CLASS(EpicsPvTimeFloat_Wrapper);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::EpicsPvTimeEnum", no_init)\
    .def("dbr", &EpicsPvTimeEnum_Wrapper::dbr)\
    .def("data", &EpicsPvTimeEnum_Wrapper::data)\
    .def("value", &EpicsPvTimeEnum_Wrapper::value)\

  _CLASS(EpicsPvTimeEnum_Wrapper);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::EpicsPvTimeChar", no_init)\
    .def("dbr", &EpicsPvTimeChar_Wrapper::dbr)\
    .def("data", &EpicsPvTimeChar_Wrapper::data)\
    .def("value", &EpicsPvTimeChar_Wrapper::value)\

  _CLASS(EpicsPvTimeChar_Wrapper);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::EpicsPvTimeLong", no_init)\
    .def("dbr", &EpicsPvTimeLong_Wrapper::dbr)\
    .def("data", &EpicsPvTimeLong_Wrapper::data)\
    .def("value", &EpicsPvTimeLong_Wrapper::value)\

  _CLASS(EpicsPvTimeLong_Wrapper);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::EpicsPvTimeDouble", no_init)\
    .def("dbr", &EpicsPvTimeDouble_Wrapper::dbr)\
    .def("data", &EpicsPvTimeDouble_Wrapper::data)\
    .def("value", &EpicsPvTimeDouble_Wrapper::value)\

  _CLASS(EpicsPvTimeDouble_Wrapper);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::PvConfigV1", no_init)\
    .def("pvId", &PvConfigV1_Wrapper::pvId)\
    .def("description", &PvConfigV1_Wrapper::description)\
    .def("interval", &PvConfigV1_Wrapper::interval)\

  _CLASS(PvConfigV1_Wrapper);
#undef _CLASS


#define _CLASS(n) class_<n>("Psana::Epics::ConfigV1", no_init)\
    .def("numPv", &ConfigV1_Wrapper::numPv)\
    .def("pvControls", &ConfigV1_Wrapper::pvControls)\
    .def("pvControls_shape", &ConfigV1_Wrapper::pvControls_shape)\

  _CLASS(ConfigV1_Wrapper);
#undef _CLASS
  ENV_GETTER(ConfigV1);

}
} // namespace Epics
} // namespace Psana
