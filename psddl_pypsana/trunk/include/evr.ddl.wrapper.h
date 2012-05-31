#ifndef PSANA_EVR_DDL_WRAPPER_H
#define PSANA_EVR_DDL_WRAPPER_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include "ndarray/ndarray.h"
#include "pdsdata/xtc/TypeId.hh"
#include "psddl_pyana/DdlWrapper.h"
#include "pdsdata/xtc/DetInfo.hh"
namespace Psana {
namespace EvrData {

extern void createWrappers();


/** @class PulseConfig

  
*/


class PulseConfig_Wrapper {
  boost::shared_ptr<PulseConfig> _o;
  PulseConfig* o;
public:
  enum { Trigger_Shift = 0 };
  enum { Set_Shift = 8 };
  enum { Clear_Shift = 16 };
  enum { Polarity_Shift = 0 };
  enum { Map_Set_Ena_Shift = 1 };
  enum { Map_Reset_Ena_Shift = 2 };
  enum { Map_Trigger_Ena_Shift = 3 };
  PulseConfig_Wrapper(boost::shared_ptr<PulseConfig> obj) : _o(obj), o(_o.get()) {}
  PulseConfig_Wrapper(PulseConfig* obj) : o(obj) {}
  bool operator==(const PulseConfig_Wrapper &t) const { return this == &t; }
  uint32_t pulse() const { return o->pulse(); }
  uint32_t _input_control_value() const { return o->_input_control_value(); }
  int16_t bf_trigger() const { return o->bf_trigger(); }
  int16_t bf_set() const { return o->bf_set(); }
  int16_t bf_clear() const { return o->bf_clear(); }
  uint32_t _output_control_value() const { return o->_output_control_value(); }
  uint8_t polarity() const { return o->polarity(); }
  uint8_t map_set_enable() const { return o->map_set_enable(); }
  uint8_t map_reset_enable() const { return o->map_reset_enable(); }
  uint8_t map_trigger_enable() const { return o->map_trigger_enable(); }
  uint32_t prescale() const { return o->prescale(); }
  uint32_t delay() const { return o->delay(); }
  uint32_t width() const { return o->width(); }
  int16_t trigger() const { return o->trigger(); }
  int16_t set() const { return o->set(); }
  int16_t clear() const { return o->clear(); }
  uint32_t _sizeof() const { return o->_sizeof(); }
private:
  uint32_t	_pulse;	/**< internal pulse generation channel */
  uint32_t	_input_control;	/**< Pulse input control */
  uint32_t	_output_control;	/**< Pulse output control */
  uint32_t	_prescale;	/**< pulse event prescale */
  uint32_t	_delay;	/**< delay in 119MHz clks */
  uint32_t	_width;	/**< width in 119MHz clks */
};

/** @class PulseConfigV3

  
*/

#pragma pack(push,4)

class PulseConfigV3_Wrapper {
  boost::shared_ptr<PulseConfigV3> _o;
  PulseConfigV3* o;
public:
  PulseConfigV3_Wrapper(boost::shared_ptr<PulseConfigV3> obj) : _o(obj), o(_o.get()) {}
  PulseConfigV3_Wrapper(PulseConfigV3* obj) : o(obj) {}
  bool operator==(const PulseConfigV3_Wrapper &t) const { return this == &t; }
  uint16_t pulseId() const { return o->pulseId(); }
  uint16_t polarity() const { return o->polarity(); }
  uint32_t prescale() const { return o->prescale(); }
  uint32_t delay() const { return o->delay(); }
  uint32_t width() const { return o->width(); }
  uint32_t _sizeof() const { return o->_sizeof(); }
private:
  uint16_t	_u16PulseId;
  uint16_t	_u16Polarity;	/**< 0 -> positive polarity , 1 -> negative polarity */
  uint32_t	_u32Prescale;	/**< Clock divider */
  uint32_t	_u32Delay;	/**< Delay in 119MHz clks */
  uint32_t	_u32Width;	/**< Width in 119MHz clks */
};
#pragma pack(pop)

/** @class EventCodeV3

  
*/

#pragma pack(push,4)

class EventCodeV3_Wrapper {
  boost::shared_ptr<EventCodeV3> _o;
  EventCodeV3* o;
public:
  EventCodeV3_Wrapper(boost::shared_ptr<EventCodeV3> obj) : _o(obj), o(_o.get()) {}
  EventCodeV3_Wrapper(EventCodeV3* obj) : o(obj) {}
  bool operator==(const EventCodeV3_Wrapper &t) const { return this == &t; }
  uint16_t code() const { return o->code(); }
  uint16_t _u16MaskEventAttr_value() const { return o->_u16MaskEventAttr_value(); }
  uint8_t isReadout() const { return o->isReadout(); }
  uint8_t isTerminator() const { return o->isTerminator(); }
  uint32_t maskTrigger() const { return o->maskTrigger(); }
  uint32_t maskSet() const { return o->maskSet(); }
  uint32_t maskClear() const { return o->maskClear(); }
  uint32_t _sizeof() const { return o->_sizeof(); }
private:
  uint16_t	_u16Code;
  uint16_t	_u16MaskEventAttr;
  uint32_t	_u32MaskTrigger;
  uint32_t	_u32MaskSet;
  uint32_t	_u32MaskClear;
};
#pragma pack(pop)

/** @class EventCodeV4

  
*/

#pragma pack(push,4)

class EventCodeV4_Wrapper {
  boost::shared_ptr<EventCodeV4> _o;
  EventCodeV4* o;
public:
  EventCodeV4_Wrapper(boost::shared_ptr<EventCodeV4> obj) : _o(obj), o(_o.get()) {}
  EventCodeV4_Wrapper(EventCodeV4* obj) : o(obj) {}
  bool operator==(const EventCodeV4_Wrapper &t) const { return this == &t; }
  uint16_t code() const { return o->code(); }
  uint16_t _u16MaskEventAttr_value() const { return o->_u16MaskEventAttr_value(); }
  uint8_t isReadout() const { return o->isReadout(); }
  uint8_t isTerminator() const { return o->isTerminator(); }
  uint32_t reportDelay() const { return o->reportDelay(); }
  uint32_t reportWidth() const { return o->reportWidth(); }
  uint32_t maskTrigger() const { return o->maskTrigger(); }
  uint32_t maskSet() const { return o->maskSet(); }
  uint32_t maskClear() const { return o->maskClear(); }
  uint32_t _sizeof() const { return o->_sizeof(); }
private:
  uint16_t	_u16Code;
  uint16_t	_u16MaskEventAttr;
  uint32_t	_u32ReportDelay;
  uint32_t	_u32ReportWidth;
  uint32_t	_u32MaskTrigger;
  uint32_t	_u32MaskSet;
  uint32_t	_u32MaskClear;
};
#pragma pack(pop)

/** @class EventCodeV5

  
*/

#pragma pack(push,4)

class EventCodeV5_Wrapper {
  boost::shared_ptr<EventCodeV5> _o;
  EventCodeV5* o;
public:
  enum { DescSize = 16 };
  EventCodeV5_Wrapper(boost::shared_ptr<EventCodeV5> obj) : _o(obj), o(_o.get()) {}
  EventCodeV5_Wrapper(EventCodeV5* obj) : o(obj) {}
  bool operator==(const EventCodeV5_Wrapper &t) const { return this == &t; }
  uint16_t code() const { return o->code(); }
  uint8_t isReadout() const { return o->isReadout(); }
  uint8_t isTerminator() const { return o->isTerminator(); }
  uint8_t isLatch() const { return o->isLatch(); }
  uint32_t reportDelay() const { return o->reportDelay(); }
  uint32_t reportWidth() const { return o->reportWidth(); }
  uint32_t maskTrigger() const { return o->maskTrigger(); }
  uint32_t maskSet() const { return o->maskSet(); }
  uint32_t maskClear() const { return o->maskClear(); }
  const char* desc() const { return o->desc(); }
  uint32_t _sizeof() const { return o->_sizeof(); }
  std::vector<int> desc_shape() const { return o->desc_shape(); }
private:
  uint16_t	_u16Code;
  uint16_t	_u16MaskEventAttr;
  uint32_t	_u32ReportDelay;
  uint32_t	_u32ReportWidth;
  uint32_t	_u32MaskTrigger;
  uint32_t	_u32MaskSet;
  uint32_t	_u32MaskClear;
  char	_desc[DescSize];
};
#pragma pack(pop)

/** @class OutputMap

  
*/


class OutputMap_Wrapper {
  boost::shared_ptr<OutputMap> _o;
  OutputMap* o;
public:
  enum Source {
    Pulse,
    DBus,
    Prescaler,
    Force_High,
    Force_Low,
  };
  enum Conn {
    FrontPanel,
    UnivIO,
  };
  OutputMap_Wrapper(boost::shared_ptr<OutputMap> obj) : _o(obj), o(_o.get()) {}
  OutputMap_Wrapper(OutputMap* obj) : o(obj) {}
  bool operator==(const OutputMap_Wrapper &t) const { return this == &t; }
  uint32_t value() const { return o->value(); }
  EvrData::OutputMap::Source source() const { return o->source(); }
  uint8_t source_id() const { return o->source_id(); }
  EvrData::OutputMap::Conn conn() const { return o->conn(); }
  uint8_t conn_id() const { return o->conn_id(); }
  uint32_t _sizeof() const { return o->_sizeof(); }
private:
  uint32_t	_v;
};

/** @class OutputMapV2

  
*/


class OutputMapV2_Wrapper {
  boost::shared_ptr<OutputMapV2> _o;
  OutputMapV2* o;
public:
  enum Source {
    Pulse,
    DBus,
    Prescaler,
    Force_High,
    Force_Low,
  };
  enum Conn {
    FrontPanel,
    UnivIO,
  };
  OutputMapV2_Wrapper(boost::shared_ptr<OutputMapV2> obj) : _o(obj), o(_o.get()) {}
  OutputMapV2_Wrapper(OutputMapV2* obj) : o(obj) {}
  bool operator==(const OutputMapV2_Wrapper &t) const { return this == &t; }
  uint32_t value() const { return o->value(); }
  EvrData::OutputMapV2::Source source() const { return o->source(); }
  uint8_t source_id() const { return o->source_id(); }
  EvrData::OutputMapV2::Conn conn() const { return o->conn(); }
  uint8_t conn_id() const { return o->conn_id(); }
  uint8_t module() const { return o->module(); }
  uint32_t _sizeof() const { return o->_sizeof(); }
private:
  uint32_t	_v;
};

/** @class ConfigV1

  
*/


class ConfigV1_Wrapper {
  boost::shared_ptr<ConfigV1> _o;
  ConfigV1* o;
public:
  enum { TypeId = Pds::TypeId::Id_EvrConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  ConfigV1_Wrapper(boost::shared_ptr<ConfigV1> obj) : _o(obj), o(_o.get()) {}
  ConfigV1_Wrapper(ConfigV1* obj) : o(obj) {}
  bool operator==(const ConfigV1_Wrapper &t) const { return this == &t; }
  uint32_t npulses() const { return o->npulses(); }
  uint32_t noutputs() const { return o->noutputs(); }
  std::vector<EvrData::PulseConfig> pulses() const { VEC_CONVERT(o->pulses(), EvrData::PulseConfig); }
  std::vector<EvrData::OutputMap> output_maps() const { VEC_CONVERT(o->output_maps(), EvrData::OutputMap); }
};

/** @class ConfigV2

  
*/


class ConfigV2_Wrapper {
  boost::shared_ptr<ConfigV2> _o;
  ConfigV2* o;
public:
  enum { TypeId = Pds::TypeId::Id_EvrConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 2 /**< XTC type version number */ };
  enum { beamOn = 100 };
  enum { baseRate = 40 };
  enum { singleShot = 150 };
  enum RateCode {
    r120Hz,
    r60Hz,
    r30Hz,
    r10Hz,
    r5Hz,
    r1Hz,
    r0_5Hz,
    Single,
    NumberOfRates,
  };
  enum BeamCode {
    Off,
    On,
  };
  ConfigV2_Wrapper(boost::shared_ptr<ConfigV2> obj) : _o(obj), o(_o.get()) {}
  ConfigV2_Wrapper(ConfigV2* obj) : o(obj) {}
  bool operator==(const ConfigV2_Wrapper &t) const { return this == &t; }
  uint32_t opcode() const { return o->opcode(); }
  uint32_t npulses() const { return o->npulses(); }
  uint32_t noutputs() const { return o->noutputs(); }
  std::vector<EvrData::PulseConfig> pulses() const { VEC_CONVERT(o->pulses(), EvrData::PulseConfig); }
  std::vector<EvrData::OutputMap> output_maps() const { VEC_CONVERT(o->output_maps(), EvrData::OutputMap); }
  EvrData::ConfigV2::BeamCode beam() const { return o->beam(); }
  EvrData::ConfigV2::RateCode rate() const { return o->rate(); }
};

/** @class ConfigV3

  
*/


class ConfigV3_Wrapper {
  boost::shared_ptr<ConfigV3> _o;
  ConfigV3* o;
public:
  enum { TypeId = Pds::TypeId::Id_EvrConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 3 /**< XTC type version number */ };
  ConfigV3_Wrapper(boost::shared_ptr<ConfigV3> obj) : _o(obj), o(_o.get()) {}
  ConfigV3_Wrapper(ConfigV3* obj) : o(obj) {}
  bool operator==(const ConfigV3_Wrapper &t) const { return this == &t; }
  uint32_t neventcodes() const { return o->neventcodes(); }
  uint32_t npulses() const { return o->npulses(); }
  uint32_t noutputs() const { return o->noutputs(); }
  std::vector<EvrData::EventCodeV3> eventcodes() const { VEC_CONVERT(o->eventcodes(), EvrData::EventCodeV3); }
  std::vector<EvrData::PulseConfigV3> pulses() const { VEC_CONVERT(o->pulses(), EvrData::PulseConfigV3); }
  std::vector<EvrData::OutputMap> output_maps() const { VEC_CONVERT(o->output_maps(), EvrData::OutputMap); }
};

/** @class ConfigV4

  
*/


class ConfigV4_Wrapper {
  boost::shared_ptr<ConfigV4> _o;
  ConfigV4* o;
public:
  enum { TypeId = Pds::TypeId::Id_EvrConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 4 /**< XTC type version number */ };
  ConfigV4_Wrapper(boost::shared_ptr<ConfigV4> obj) : _o(obj), o(_o.get()) {}
  ConfigV4_Wrapper(ConfigV4* obj) : o(obj) {}
  bool operator==(const ConfigV4_Wrapper &t) const { return this == &t; }
  uint32_t neventcodes() const { return o->neventcodes(); }
  uint32_t npulses() const { return o->npulses(); }
  uint32_t noutputs() const { return o->noutputs(); }
  std::vector<EvrData::EventCodeV4> eventcodes() const { VEC_CONVERT(o->eventcodes(), EvrData::EventCodeV4); }
  std::vector<EvrData::PulseConfigV3> pulses() const { VEC_CONVERT(o->pulses(), EvrData::PulseConfigV3); }
  std::vector<EvrData::OutputMap> output_maps() const { VEC_CONVERT(o->output_maps(), EvrData::OutputMap); }
};

/** @class SequencerEntry

  
*/


class SequencerEntry_Wrapper {
  boost::shared_ptr<SequencerEntry> _o;
  SequencerEntry* o;
public:
  SequencerEntry_Wrapper(boost::shared_ptr<SequencerEntry> obj) : _o(obj), o(_o.get()) {}
  SequencerEntry_Wrapper(SequencerEntry* obj) : o(obj) {}
  bool operator==(const SequencerEntry_Wrapper &t) const { return this == &t; }
  uint32_t delay() const { return o->delay(); }
  uint32_t eventcode() const { return o->eventcode(); }
  uint32_t _sizeof() const { return o->_sizeof(); }
private:
  uint32_t	_value;
};

/** @class SequencerConfigV1

  
*/


class SequencerConfigV1_Wrapper {
  boost::shared_ptr<SequencerConfigV1> _o;
  SequencerConfigV1* o;
public:
  enum Source {
    r120Hz,
    r60Hz,
    r30Hz,
    r10Hz,
    r5Hz,
    r1Hz,
    r0_5Hz,
    Disable,
  };
  SequencerConfigV1_Wrapper(boost::shared_ptr<SequencerConfigV1> obj) : _o(obj), o(_o.get()) {}
  SequencerConfigV1_Wrapper(SequencerConfigV1* obj) : o(obj) {}
  bool operator==(const SequencerConfigV1_Wrapper &t) const { return this == &t; }
  EvrData::SequencerConfigV1::Source sync_source() const { return o->sync_source(); }
  EvrData::SequencerConfigV1::Source beam_source() const { return o->beam_source(); }
  uint32_t length() const { return o->length(); }
  uint32_t cycles() const { return o->cycles(); }
  std::vector<EvrData::SequencerEntry> entries() const { VEC_CONVERT(o->entries(), EvrData::SequencerEntry); }
};

/** @class ConfigV5

  
*/


class ConfigV5_Wrapper {
  boost::shared_ptr<ConfigV5> _o;
  ConfigV5* o;
public:
  enum { TypeId = Pds::TypeId::Id_EvrConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 5 /**< XTC type version number */ };
  enum { MaxPulses = 32 };
  enum { EvrOutputs = 10 };
  ConfigV5_Wrapper(boost::shared_ptr<ConfigV5> obj) : _o(obj), o(_o.get()) {}
  ConfigV5_Wrapper(ConfigV5* obj) : o(obj) {}
  bool operator==(const ConfigV5_Wrapper &t) const { return this == &t; }
  uint32_t neventcodes() const { return o->neventcodes(); }
  uint32_t npulses() const { return o->npulses(); }
  uint32_t noutputs() const { return o->noutputs(); }
  std::vector<EvrData::EventCodeV5> eventcodes() const { VEC_CONVERT(o->eventcodes(), EvrData::EventCodeV5); }
  std::vector<EvrData::PulseConfigV3> pulses() const { VEC_CONVERT(o->pulses(), EvrData::PulseConfigV3); }
  std::vector<EvrData::OutputMap> output_maps() const { VEC_CONVERT(o->output_maps(), EvrData::OutputMap); }
  const SequencerConfigV1_Wrapper seq_config() const { return SequencerConfigV1_Wrapper((SequencerConfigV1*) &o->seq_config()); }
};

/** @class ConfigV6

  
*/


class ConfigV6_Wrapper {
  boost::shared_ptr<ConfigV6> _o;
  ConfigV6* o;
public:
  enum { TypeId = Pds::TypeId::Id_EvrConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 6 /**< XTC type version number */ };
  enum { MaxPulses = 256 /**< Maximum pulses in the system */ };
  enum { MaxOutputs = 256 /**< Maximum outputs in the system */ };
  ConfigV6_Wrapper(boost::shared_ptr<ConfigV6> obj) : _o(obj), o(_o.get()) {}
  ConfigV6_Wrapper(ConfigV6* obj) : o(obj) {}
  bool operator==(const ConfigV6_Wrapper &t) const { return this == &t; }
  uint32_t neventcodes() const { return o->neventcodes(); }
  uint32_t npulses() const { return o->npulses(); }
  uint32_t noutputs() const { return o->noutputs(); }
  std::vector<EvrData::EventCodeV5> eventcodes() const { VEC_CONVERT(o->eventcodes(), EvrData::EventCodeV5); }
  std::vector<EvrData::PulseConfigV3> pulses() const { VEC_CONVERT(o->pulses(), EvrData::PulseConfigV3); }
  std::vector<EvrData::OutputMapV2> output_maps() const { VEC_CONVERT(o->output_maps(), EvrData::OutputMapV2); }
  const SequencerConfigV1_Wrapper seq_config() const { return SequencerConfigV1_Wrapper((SequencerConfigV1*) &o->seq_config()); }
};

/** @class FIFOEvent

  
*/


class FIFOEvent_Wrapper {
  boost::shared_ptr<FIFOEvent> _o;
  FIFOEvent* o;
public:
  FIFOEvent_Wrapper(boost::shared_ptr<FIFOEvent> obj) : _o(obj), o(_o.get()) {}
  FIFOEvent_Wrapper(FIFOEvent* obj) : o(obj) {}
  bool operator==(const FIFOEvent_Wrapper &t) const { return this == &t; }
  uint32_t timestampHigh() const { return o->timestampHigh(); }
  uint32_t timestampLow() const { return o->timestampLow(); }
  uint32_t eventCode() const { return o->eventCode(); }
  uint32_t _sizeof() const { return o->_sizeof(); }
private:
  uint32_t	_timestampHigh;
  uint32_t	_timestampLow;
  uint32_t	_eventCode;
};

/** @class DataV3

  
*/


class DataV3_Wrapper {
  boost::shared_ptr<DataV3> _o;
  DataV3* o;
public:
  enum { TypeId = Pds::TypeId::Id_EvrData /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 3 /**< XTC type version number */ };
  DataV3_Wrapper(boost::shared_ptr<DataV3> obj) : _o(obj), o(_o.get()) {}
  DataV3_Wrapper(DataV3* obj) : o(obj) {}
  bool operator==(const DataV3_Wrapper &t) const { return this == &t; }
  uint32_t numFifoEvents() const { return o->numFifoEvents(); }
  std::vector<EvrData::FIFOEvent> fifoEvents() const { VEC_CONVERT(o->fifoEvents(), EvrData::FIFOEvent); }
};

/** @class IOChannel

  
*/


class IOChannel_Wrapper {
  boost::shared_ptr<IOChannel> _o;
  IOChannel* o;
public:
  enum { NameLength = 12 };
  enum { MaxInfos = 8 };
  IOChannel_Wrapper(boost::shared_ptr<IOChannel> obj) : _o(obj), o(_o.get()) {}
  IOChannel_Wrapper(IOChannel* obj) : o(obj) {}
  bool operator==(const IOChannel_Wrapper &t) const { return this == &t; }
  const char* name() const { return o->name(); }
  uint32_t ninfo() const { return o->ninfo(); }
  std::vector<Pds::DetInfo> infos() const { VEC_CONVERT(o->infos(), Pds::DetInfo); }
  uint32_t _sizeof() const { return o->_sizeof(); }
  std::vector<int> name_shape() const { return o->name_shape(); }
private:
  char	_name[NameLength];
  uint32_t	_ninfo;
  Pds::DetInfo	_info[MaxInfos];
};

/** @class IOConfigV1

  
*/


class IOConfigV1_Wrapper {
  boost::shared_ptr<IOConfigV1> _o;
  IOConfigV1* o;
public:
  enum { TypeId = Pds::TypeId::Id_EvrIOConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  IOConfigV1_Wrapper(boost::shared_ptr<IOConfigV1> obj) : _o(obj), o(_o.get()) {}
  IOConfigV1_Wrapper(IOConfigV1* obj) : o(obj) {}
  bool operator==(const IOConfigV1_Wrapper &t) const { return this == &t; }
  uint16_t nchannels() const { return o->nchannels(); }
  std::vector<EvrData::IOChannel> channels() const { VEC_CONVERT(o->channels(), EvrData::IOChannel); }
  EvrData::OutputMap::Conn conn() const { return o->conn(); }
};

  class ConfigV1_Getter : public Psana::EnvGetter {
  public:
    const char* getTypeName() {
      return "Psana::EvrData::ConfigV1";
    }
    int getTypeId() {
      return ConfigV1::TypeId;
    }
    int getVersion() {
      return ConfigV1::Version;
    }
    boost::python::api::object get(PSEnv::EnvObjectStore& store, const PSEvt::Source& src) {
      return boost::python::api::object(ConfigV1_Wrapper(store.get(src, 0)));
    }
  };

  class ConfigV2_Getter : public Psana::EnvGetter {
  public:
    const char* getTypeName() {
      return "Psana::EvrData::ConfigV2";
    }
    int getTypeId() {
      return ConfigV2::TypeId;
    }
    int getVersion() {
      return ConfigV2::Version;
    }
    boost::python::api::object get(PSEnv::EnvObjectStore& store, const PSEvt::Source& src) {
      return boost::python::api::object(ConfigV2_Wrapper(store.get(src, 0)));
    }
  };

  class ConfigV3_Getter : public Psana::EnvGetter {
  public:
    const char* getTypeName() {
      return "Psana::EvrData::ConfigV3";
    }
    int getTypeId() {
      return ConfigV3::TypeId;
    }
    int getVersion() {
      return ConfigV3::Version;
    }
    boost::python::api::object get(PSEnv::EnvObjectStore& store, const PSEvt::Source& src) {
      return boost::python::api::object(ConfigV3_Wrapper(store.get(src, 0)));
    }
  };

  class ConfigV4_Getter : public Psana::EnvGetter {
  public:
    const char* getTypeName() {
      return "Psana::EvrData::ConfigV4";
    }
    int getTypeId() {
      return ConfigV4::TypeId;
    }
    int getVersion() {
      return ConfigV4::Version;
    }
    boost::python::api::object get(PSEnv::EnvObjectStore& store, const PSEvt::Source& src) {
      return boost::python::api::object(ConfigV4_Wrapper(store.get(src, 0)));
    }
  };

  class ConfigV5_Getter : public Psana::EnvGetter {
  public:
    const char* getTypeName() {
      return "Psana::EvrData::ConfigV5";
    }
    int getTypeId() {
      return ConfigV5::TypeId;
    }
    int getVersion() {
      return ConfigV5::Version;
    }
    boost::python::api::object get(PSEnv::EnvObjectStore& store, const PSEvt::Source& src) {
      return boost::python::api::object(ConfigV5_Wrapper(store.get(src, 0)));
    }
  };

  class ConfigV6_Getter : public Psana::EnvGetter {
  public:
    const char* getTypeName() {
      return "Psana::EvrData::ConfigV6";
    }
    int getTypeId() {
      return ConfigV6::TypeId;
    }
    int getVersion() {
      return ConfigV6::Version;
    }
    boost::python::api::object get(PSEnv::EnvObjectStore& store, const PSEvt::Source& src) {
      return boost::python::api::object(ConfigV6_Wrapper(store.get(src, 0)));
    }
  };

  class DataV3_Getter : public Psana::EvtGetter {
  public:
    const char* getTypeName() {
      return "Psana::EvrData::DataV3";
    }
    int getTypeId() {
      return DataV3::TypeId;
    }
    int getVersion() {
      return DataV3::Version;
    }
    boost::python::api::object get(PSEvt::Event& evt, const std::string& key=std::string(), Pds::Src* foundSrc=0) {
      return boost::python::api::object(DataV3_Wrapper(evt.get(key, foundSrc)));
    }
    boost::python::api::object get(PSEvt::Event& evt, Pds::Src& src, const std::string& key=std::string(), Pds::Src* foundSrc=0) {
      return boost::python::api::object(DataV3_Wrapper(evt.get(src, key, foundSrc)));
    }
    boost::python::api::object get(PSEvt::Event& evt, PSEvt::Source& source, const std::string& key=std::string(), Pds::Src* foundSrc=0) {
      return boost::python::api::object(DataV3_Wrapper(evt.get(source, key, foundSrc)));
    }
  };
} // namespace EvrData
} // namespace Psana
#endif // PSANA_EVR_DDL_WRAPPER_H
