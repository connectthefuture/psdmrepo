
// *** Do not edit this file, it is auto-generated ***

#include <cstddef>
#include "psddl_psana/evr.ddl.h" // inc_psana
#include "psddl_pypsana/evr.ddl.wrapper.h" // inc_pypsana
namespace Psana {
namespace EvrData {
using namespace boost::python;

void createWrappers() {

#define _CLASS(n, policy) class_<n>(#n, no_init)\
    .def("pulse", &n::pulse)\
    .def("_input_control_value", &n::_input_control_value)\
    .def("bf_trigger", &n::bf_trigger)\
    .def("bf_set", &n::bf_set)\
    .def("bf_clear", &n::bf_clear)\
    .def("_output_control_value", &n::_output_control_value)\
    .def("polarity", &n::polarity)\
    .def("map_set_enable", &n::map_set_enable)\
    .def("map_reset_enable", &n::map_reset_enable)\
    .def("map_trigger_enable", &n::map_trigger_enable)\
    .def("prescale", &n::prescale)\
    .def("delay", &n::delay)\
    .def("width", &n::width)\
    .def("trigger", &n::trigger)\
    .def("set", &n::set)\
    .def("clear", &n::clear)\
    .def("_sizeof", &n::_sizeof)\

  _CLASS(Psana::EvrData::PulseConfig, return_value_policy<copy_const_reference>());
  _CLASS(Psana::EvrData::PulseConfig_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(PulseConfig);
  std_vector_class_(PulseConfig_Wrapper);
#undef _CLASS


#define _CLASS(n, policy) class_<n>(#n, no_init)\
    .def("pulseId", &n::pulseId)\
    .def("polarity", &n::polarity)\
    .def("prescale", &n::prescale)\
    .def("delay", &n::delay)\
    .def("width", &n::width)\
    .def("_sizeof", &n::_sizeof)\

  _CLASS(Psana::EvrData::PulseConfigV3, return_value_policy<copy_const_reference>());
  _CLASS(Psana::EvrData::PulseConfigV3_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(PulseConfigV3);
  std_vector_class_(PulseConfigV3_Wrapper);
#undef _CLASS


#define _CLASS(n, policy) class_<n>(#n, no_init)\
    .def("code", &n::code)\
    .def("_u16MaskEventAttr_value", &n::_u16MaskEventAttr_value)\
    .def("isReadout", &n::isReadout)\
    .def("isTerminator", &n::isTerminator)\
    .def("maskTrigger", &n::maskTrigger)\
    .def("maskSet", &n::maskSet)\
    .def("maskClear", &n::maskClear)\
    .def("_sizeof", &n::_sizeof)\

  _CLASS(Psana::EvrData::EventCodeV3, return_value_policy<copy_const_reference>());
  _CLASS(Psana::EvrData::EventCodeV3_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(EventCodeV3);
  std_vector_class_(EventCodeV3_Wrapper);
#undef _CLASS


#define _CLASS(n, policy) class_<n>(#n, no_init)\
    .def("code", &n::code)\
    .def("_u16MaskEventAttr_value", &n::_u16MaskEventAttr_value)\
    .def("isReadout", &n::isReadout)\
    .def("isTerminator", &n::isTerminator)\
    .def("reportDelay", &n::reportDelay)\
    .def("reportWidth", &n::reportWidth)\
    .def("maskTrigger", &n::maskTrigger)\
    .def("maskSet", &n::maskSet)\
    .def("maskClear", &n::maskClear)\
    .def("_sizeof", &n::_sizeof)\

  _CLASS(Psana::EvrData::EventCodeV4, return_value_policy<copy_const_reference>());
  _CLASS(Psana::EvrData::EventCodeV4_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(EventCodeV4);
  std_vector_class_(EventCodeV4_Wrapper);
#undef _CLASS


#define _CLASS(n, policy) class_<n>(#n, no_init)\
    .def("code", &n::code)\
    .def("isReadout", &n::isReadout)\
    .def("isTerminator", &n::isTerminator)\
    .def("isLatch", &n::isLatch)\
    .def("reportDelay", &n::reportDelay)\
    .def("reportWidth", &n::reportWidth)\
    .def("maskTrigger", &n::maskTrigger)\
    .def("maskSet", &n::maskSet)\
    .def("maskClear", &n::maskClear)\
    .def("desc", &n::desc)\
    .def("_sizeof", &n::_sizeof)\
    .def("desc_shape", &n::desc_shape)\

  _CLASS(Psana::EvrData::EventCodeV5, return_value_policy<copy_const_reference>());
  _CLASS(Psana::EvrData::EventCodeV5_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(EventCodeV5);
  std_vector_class_(EventCodeV5_Wrapper);
#undef _CLASS


#define _CLASS(n, policy) class_<n>(#n, no_init)\
    .def("value", &n::value)\
    .def("source", &n::source)\
    .def("source_id", &n::source_id)\
    .def("conn", &n::conn)\
    .def("conn_id", &n::conn_id)\
    .def("_sizeof", &n::_sizeof)\

  _CLASS(Psana::EvrData::OutputMap, return_value_policy<copy_const_reference>());
  _CLASS(Psana::EvrData::OutputMap_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(OutputMap);
  std_vector_class_(OutputMap_Wrapper);
#undef _CLASS


#define _CLASS(n, policy) class_<n>(#n, no_init)\
    .def("value", &n::value)\
    .def("source", &n::source)\
    .def("source_id", &n::source_id)\
    .def("conn", &n::conn)\
    .def("conn_id", &n::conn_id)\
    .def("module", &n::module)\
    .def("_sizeof", &n::_sizeof)\

  _CLASS(Psana::EvrData::OutputMapV2, return_value_policy<copy_const_reference>());
  _CLASS(Psana::EvrData::OutputMapV2_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(OutputMapV2);
  std_vector_class_(OutputMapV2_Wrapper);
#undef _CLASS


#define _CLASS(n, policy) class_<n>(#n, no_init)\
    .def("npulses", &n::npulses)\
    .def("noutputs", &n::noutputs)\
    .def("pulses", &n::pulses)\
    .def("output_maps", &n::output_maps)\

  _CLASS(Psana::EvrData::ConfigV1_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(ConfigV1_Wrapper);
#undef _CLASS
  ADD_GETTER(ConfigV1);


#define _CLASS(n, policy) class_<n>(#n, no_init)\
    .def("opcode", &n::opcode)\
    .def("npulses", &n::npulses)\
    .def("noutputs", &n::noutputs)\
    .def("pulses", &n::pulses)\
    .def("output_maps", &n::output_maps)\
    .def("beam", &n::beam)\
    .def("rate", &n::rate)\

  _CLASS(Psana::EvrData::ConfigV2_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(ConfigV2_Wrapper);
#undef _CLASS
  ADD_GETTER(ConfigV2);


#define _CLASS(n, policy) class_<n>(#n, no_init)\
    .def("neventcodes", &n::neventcodes)\
    .def("npulses", &n::npulses)\
    .def("noutputs", &n::noutputs)\
    .def("eventcodes", &n::eventcodes)\
    .def("pulses", &n::pulses)\
    .def("output_maps", &n::output_maps)\

  _CLASS(Psana::EvrData::ConfigV3_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(ConfigV3_Wrapper);
#undef _CLASS
  ADD_GETTER(ConfigV3);


#define _CLASS(n, policy) class_<n>(#n, no_init)\
    .def("neventcodes", &n::neventcodes)\
    .def("npulses", &n::npulses)\
    .def("noutputs", &n::noutputs)\
    .def("eventcodes", &n::eventcodes)\
    .def("pulses", &n::pulses)\
    .def("output_maps", &n::output_maps)\

  _CLASS(Psana::EvrData::ConfigV4_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(ConfigV4_Wrapper);
#undef _CLASS
  ADD_GETTER(ConfigV4);


#define _CLASS(n, policy) class_<n>(#n, no_init)\
    .def("delay", &n::delay)\
    .def("eventcode", &n::eventcode)\
    .def("_sizeof", &n::_sizeof)\

  _CLASS(Psana::EvrData::SequencerEntry, return_value_policy<copy_const_reference>());
  _CLASS(Psana::EvrData::SequencerEntry_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(SequencerEntry);
  std_vector_class_(SequencerEntry_Wrapper);
#undef _CLASS


#define _CLASS(n, policy) class_<n>(#n, no_init)\
    .def("sync_source", &n::sync_source)\
    .def("beam_source", &n::beam_source)\
    .def("length", &n::length)\
    .def("cycles", &n::cycles)\
    .def("entries", &n::entries)\

  _CLASS(Psana::EvrData::SequencerConfigV1_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(SequencerConfigV1_Wrapper);
#undef _CLASS


#define _CLASS(n, policy) class_<n>(#n, no_init)\
    .def("neventcodes", &n::neventcodes)\
    .def("npulses", &n::npulses)\
    .def("noutputs", &n::noutputs)\
    .def("eventcodes", &n::eventcodes)\
    .def("pulses", &n::pulses)\
    .def("output_maps", &n::output_maps)\
    .def("seq_config", &n::seq_config, policy)\

  _CLASS(Psana::EvrData::ConfigV5_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(ConfigV5_Wrapper);
#undef _CLASS
  ADD_GETTER(ConfigV5);


#define _CLASS(n, policy) class_<n>(#n, no_init)\
    .def("neventcodes", &n::neventcodes)\
    .def("npulses", &n::npulses)\
    .def("noutputs", &n::noutputs)\
    .def("eventcodes", &n::eventcodes)\
    .def("pulses", &n::pulses)\
    .def("output_maps", &n::output_maps)\
    .def("seq_config", &n::seq_config, policy)\

  _CLASS(Psana::EvrData::ConfigV6_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(ConfigV6_Wrapper);
#undef _CLASS
  ADD_GETTER(ConfigV6);


#define _CLASS(n, policy) class_<n>(#n, no_init)\
    .def("timestampHigh", &n::timestampHigh)\
    .def("timestampLow", &n::timestampLow)\
    .def("eventCode", &n::eventCode)\
    .def("_sizeof", &n::_sizeof)\

  _CLASS(Psana::EvrData::FIFOEvent, return_value_policy<copy_const_reference>());
  _CLASS(Psana::EvrData::FIFOEvent_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(FIFOEvent);
  std_vector_class_(FIFOEvent_Wrapper);
#undef _CLASS


#define _CLASS(n, policy) class_<n>(#n, no_init)\
    .def("numFifoEvents", &n::numFifoEvents)\
    .def("fifoEvents", &n::fifoEvents)\

  _CLASS(Psana::EvrData::DataV3_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(DataV3_Wrapper);
#undef _CLASS
  ADD_GETTER(DataV3);


#define _CLASS(n, policy) class_<n>(#n, no_init)\
    .def("name", &n::name)\
    .def("ninfo", &n::ninfo)\
    .def("infos", &n::infos)\
    .def("_sizeof", &n::_sizeof)\
    .def("name_shape", &n::name_shape)\

  _CLASS(Psana::EvrData::IOChannel, return_value_policy<copy_const_reference>());
  _CLASS(Psana::EvrData::IOChannel_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(IOChannel);
  std_vector_class_(IOChannel_Wrapper);
#undef _CLASS


#define _CLASS(n, policy) class_<n>(#n, no_init)\
    .def("nchannels", &n::nchannels)\
    .def("channels", &n::channels)\
    .def("conn", &n::conn)\

  _CLASS(Psana::EvrData::IOConfigV1_Wrapper, return_value_policy<return_by_value>());
  std_vector_class_(IOConfigV1_Wrapper);
#undef _CLASS

}
} // namespace EvrData
} // namespace Psana
