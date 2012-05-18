#ifndef PSANA_EVR_DDL_H
#define PSANA_EVR_DDL_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include "ndarray/ndarray.h"
#include "pdsdata/xtc/TypeId.hh"
#include "pdsdata/xtc/DetInfo.hh"
namespace Psana {
namespace EvrData {

/** @class PulseConfig

  
*/


class PulseConfig {
public:
  enum { Trigger_Shift = 0 };
  enum { Set_Shift = 8 };
  enum { Clear_Shift = 16 };
  enum { Polarity_Shift = 0 };
  enum { Map_Set_Ena_Shift = 1 };
  enum { Map_Reset_Ena_Shift = 2 };
  enum { Map_Trigger_Ena_Shift = 3 };
  PulseConfig()
  {
  }
  PulseConfig(uint32_t arg__pulse, int16_t arg_bf__bf_trigger, int16_t arg_bf__bf_set, int16_t arg_bf__bf_clear, uint8_t arg_bf__bf_polarity, uint8_t arg_bf__bf_map_set_enable, uint8_t arg_bf__bf_map_reset_enable, uint8_t arg_bf__bf_map_trigger_enable, uint32_t arg__prescale, uint32_t arg__delay, uint32_t arg__width)
    : _pulse(arg__pulse), _input_control((arg_bf__bf_trigger & 0xff)|((arg_bf__bf_set & 0xff)<<8)|((arg_bf__bf_clear & 0xff)<<16)), _output_control((arg_bf__bf_polarity & 0x1)|((arg_bf__bf_map_set_enable & 0x1)<<1)|((arg_bf__bf_map_reset_enable & 0x1)<<2)|((arg_bf__bf_map_trigger_enable & 0x1)<<3)), _prescale(arg__prescale), _delay(arg__delay), _width(arg__width)
  {
  }
  bool operator==(const PulseConfig &t) const { return this == &t; }
  /** internal pulse generation channel */
  uint32_t pulse() const { return _pulse; }
  /** Pulse input control */
  uint32_t _input_control_value() const { return _input_control; }
  int16_t bf_trigger() const { return int16_t(this->_input_control & 0xff); }
  int16_t bf_set() const { return int16_t((this->_input_control>>8) & 0xff); }
  int16_t bf_clear() const { return int16_t((this->_input_control>>16) & 0xff); }
  /** Pulse output control */
  uint32_t _output_control_value() const { return _output_control; }
  uint8_t polarity() const { return uint8_t(this->_output_control & 0x1); }
  uint8_t map_set_enable() const { return uint8_t((this->_output_control>>1) & 0x1); }
  uint8_t map_reset_enable() const { return uint8_t((this->_output_control>>2) & 0x1); }
  uint8_t map_trigger_enable() const { return uint8_t((this->_output_control>>3) & 0x1); }
  /** pulse event prescale */
  uint32_t prescale() const { return _prescale; }
  /** delay in 119MHz clks */
  uint32_t delay() const { return _delay; }
  /** width in 119MHz clks */
  uint32_t width() const { return _width; }
  int16_t trigger() const;
  int16_t set() const;
  int16_t clear() const;
  static uint32_t _sizeof()  { return 24; }
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

class PulseConfigV3 {
public:
  PulseConfigV3()
  {
  }
  PulseConfigV3(uint16_t arg__u16PulseId, uint16_t arg__u16Polarity, uint32_t arg__u32Prescale, uint32_t arg__u32Delay, uint32_t arg__u32Width)
    : _u16PulseId(arg__u16PulseId), _u16Polarity(arg__u16Polarity), _u32Prescale(arg__u32Prescale), _u32Delay(arg__u32Delay), _u32Width(arg__u32Width)
  {
  }
  bool operator==(const PulseConfigV3 &t) const { return this == &t; }
  uint16_t pulseId() const { return _u16PulseId; }
  /** 0 -> positive polarity , 1 -> negative polarity */
  uint16_t polarity() const { return _u16Polarity; }
  /** Clock divider */
  uint32_t prescale() const { return _u32Prescale; }
  /** Delay in 119MHz clks */
  uint32_t delay() const { return _u32Delay; }
  /** Width in 119MHz clks */
  uint32_t width() const { return _u32Width; }
  static uint32_t _sizeof()  { return 16; }
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

class EventCodeV3 {
public:
  EventCodeV3()
  {
  }
  EventCodeV3(uint16_t arg__u16Code, uint8_t arg_bf__bf_isReadout, uint8_t arg_bf__bf_isTerminator, uint32_t arg__u32MaskTrigger, uint32_t arg__u32MaskSet, uint32_t arg__u32MaskClear)
    : _u16Code(arg__u16Code), _u16MaskEventAttr((arg_bf__bf_isReadout & 0x1)|((arg_bf__bf_isTerminator & 0x1)<<1)), _u32MaskTrigger(arg__u32MaskTrigger), _u32MaskSet(arg__u32MaskSet), _u32MaskClear(arg__u32MaskClear)
  {
  }
  bool operator==(const EventCodeV3 &t) const { return this == &t; }
  uint16_t code() const { return _u16Code; }
  uint16_t _u16MaskEventAttr_value() const { return _u16MaskEventAttr; }
  uint8_t isReadout() const { return uint8_t(this->_u16MaskEventAttr & 0x1); }
  uint8_t isTerminator() const { return uint8_t((this->_u16MaskEventAttr>>1) & 0x1); }
  uint32_t maskTrigger() const { return _u32MaskTrigger; }
  uint32_t maskSet() const { return _u32MaskSet; }
  uint32_t maskClear() const { return _u32MaskClear; }
  static uint32_t _sizeof()  { return 16; }
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

class EventCodeV4 {
public:
  EventCodeV4()
  {
  }
  EventCodeV4(uint16_t arg__u16Code, uint8_t arg_bf__bf_isReadout, uint8_t arg_bf__bf_isTerminator, uint32_t arg__u32ReportDelay, uint32_t arg__u32ReportWidth, uint32_t arg__u32MaskTrigger, uint32_t arg__u32MaskSet, uint32_t arg__u32MaskClear)
    : _u16Code(arg__u16Code), _u16MaskEventAttr((arg_bf__bf_isReadout & 0x1)|((arg_bf__bf_isTerminator & 0x1)<<1)), _u32ReportDelay(arg__u32ReportDelay), _u32ReportWidth(arg__u32ReportWidth), _u32MaskTrigger(arg__u32MaskTrigger), _u32MaskSet(arg__u32MaskSet), _u32MaskClear(arg__u32MaskClear)
  {
  }
  bool operator==(const EventCodeV4 &t) const { return this == &t; }
  uint16_t code() const { return _u16Code; }
  uint16_t _u16MaskEventAttr_value() const { return _u16MaskEventAttr; }
  uint8_t isReadout() const { return uint8_t(this->_u16MaskEventAttr & 0x1); }
  uint8_t isTerminator() const { return uint8_t((this->_u16MaskEventAttr>>1) & 0x1); }
  uint32_t reportDelay() const { return _u32ReportDelay; }
  uint32_t reportWidth() const { return _u32ReportWidth; }
  uint32_t maskTrigger() const { return _u32MaskTrigger; }
  uint32_t maskSet() const { return _u32MaskSet; }
  uint32_t maskClear() const { return _u32MaskClear; }
  static uint32_t _sizeof()  { return 24; }
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

class EventCodeV5 {
public:
  enum { DescSize = 16 };
  EventCodeV5()
  {
  }
  EventCodeV5(uint16_t arg__u16Code, uint8_t arg_bf__bf_isReadout, uint8_t arg_bf__bf_isTerminator, uint8_t arg_bf__bf_isLatch, uint32_t arg__u32ReportDelay, uint32_t arg__u32ReportWidth, uint32_t arg__u32MaskTrigger, uint32_t arg__u32MaskSet, uint32_t arg__u32MaskClear, const char* arg__desc)
    : _u16Code(arg__u16Code), _u16MaskEventAttr((arg_bf__bf_isReadout & 0x1)|((arg_bf__bf_isTerminator & 0x1)<<1)|((arg_bf__bf_isLatch & 0x1)<<2)), _u32ReportDelay(arg__u32ReportDelay), _u32ReportWidth(arg__u32ReportWidth), _u32MaskTrigger(arg__u32MaskTrigger), _u32MaskSet(arg__u32MaskSet), _u32MaskClear(arg__u32MaskClear)
  {
    std::copy(arg__desc, arg__desc+(16), _desc);
  }
  bool operator==(const EventCodeV5 &t) const { return this == &t; }
  uint16_t code() const { return _u16Code; }
  uint8_t isReadout() const { return uint8_t(this->_u16MaskEventAttr & 0x1); }
  uint8_t isTerminator() const { return uint8_t((this->_u16MaskEventAttr>>1) & 0x1); }
  uint8_t isLatch() const { return uint8_t((this->_u16MaskEventAttr>>2) & 0x1); }
  uint32_t reportDelay() const { return _u32ReportDelay; }
  uint32_t reportWidth() const { return _u32ReportWidth; }
  uint32_t maskTrigger() const { return _u32MaskTrigger; }
  uint32_t maskSet() const { return _u32MaskSet; }
  uint32_t maskClear() const { return _u32MaskClear; }
  const char* desc() const { return _desc; }
  static uint32_t _sizeof()  { return 24+(1*(DescSize)); }
  /** Method which returns the shape (dimensions) of the data returned by desc() method. */
  std::vector<int> desc_shape() const;
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


class OutputMap {
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
  OutputMap()
  {
  }
  OutputMap(EvrData::OutputMap::Source arg_bf__bf_source, uint8_t arg_bf__bf_source_id, EvrData::OutputMap::Conn arg_bf__bf_conn, uint8_t arg_bf__bf_conn_id)
    : _v((arg_bf__bf_source & 0xff)|((arg_bf__bf_source_id & 0xff)<<8)|((arg_bf__bf_conn & 0xff)<<16)|((arg_bf__bf_conn_id & 0xff)<<24))
  {
  }
  bool operator==(const OutputMap &t) const { return this == &t; }
  uint32_t value() const { return _v; }
  EvrData::OutputMap::Source source() const { return Source(this->_v & 0xff); }
  uint8_t source_id() const { return uint8_t((this->_v>>8) & 0xff); }
  EvrData::OutputMap::Conn conn() const { return Conn((this->_v>>16) & 0xff); }
  uint8_t conn_id() const { return uint8_t((this->_v>>24) & 0xff); }
  static uint32_t _sizeof()  { return 4; }
private:
  uint32_t	_v;
};

/** @class OutputMapV2

  
*/


class OutputMapV2 {
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
  OutputMapV2()
  {
  }
  OutputMapV2(EvrData::OutputMapV2::Source arg_bf__bf_source, uint8_t arg_bf__bf_source_id, EvrData::OutputMapV2::Conn arg_bf__bf_conn, uint8_t arg_bf__bf_conn_id, uint8_t arg_bf__bf_module)
    : _v((arg_bf__bf_source & 0xf)|((arg_bf__bf_source_id & 0xff)<<4)|((arg_bf__bf_conn & 0xf)<<12)|((arg_bf__bf_conn_id & 0xff)<<16)|((arg_bf__bf_module & 0xff)<<24))
  {
  }
  bool operator==(const OutputMapV2 &t) const { return this == &t; }
  uint32_t value() const { return _v; }
  EvrData::OutputMapV2::Source source() const { return Source(this->_v & 0xf); }
  uint8_t source_id() const { return uint8_t((this->_v>>4) & 0xff); }
  EvrData::OutputMapV2::Conn conn() const { return Conn((this->_v>>12) & 0xf); }
  uint8_t conn_id() const { return uint8_t((this->_v>>16) & 0xff); }
  uint8_t module() const { return uint8_t((this->_v>>24) & 0xff); }
  static uint32_t _sizeof()  { return 4; }
private:
  uint32_t	_v;
};

/** @class ConfigV1

  
*/


class ConfigV1 {
public:
  enum { TypeId = Pds::TypeId::Id_EvrConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  virtual ~ConfigV1();
  bool operator==(const ConfigV1 &t) const { return this == &t; }
  virtual uint32_t npulses() const = 0;
  virtual uint32_t noutputs() const = 0;
  virtual ndarray<EvrData::PulseConfig, 1> pulses() const = 0;
  virtual ndarray<EvrData::OutputMap, 1> output_maps() const = 0;
};

/** @class ConfigV2

  
*/


class ConfigV2 {
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
  virtual ~ConfigV2();
  bool operator==(const ConfigV2 &t) const { return this == &t; }
  virtual uint32_t opcode() const = 0;
  virtual uint32_t npulses() const = 0;
  virtual uint32_t noutputs() const = 0;
  virtual ndarray<EvrData::PulseConfig, 1> pulses() const = 0;
  virtual ndarray<EvrData::OutputMap, 1> output_maps() const = 0;
  virtual EvrData::ConfigV2::BeamCode beam() const = 0;
  virtual EvrData::ConfigV2::RateCode rate() const = 0;
};

/** @class ConfigV3

  
*/


class ConfigV3 {
public:
  enum { TypeId = Pds::TypeId::Id_EvrConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 3 /**< XTC type version number */ };
  virtual ~ConfigV3();
  bool operator==(const ConfigV3 &t) const { return this == &t; }
  virtual uint32_t neventcodes() const = 0;
  virtual uint32_t npulses() const = 0;
  virtual uint32_t noutputs() const = 0;
  virtual ndarray<EvrData::EventCodeV3, 1> eventcodes() const = 0;
  virtual ndarray<EvrData::PulseConfigV3, 1> pulses() const = 0;
  virtual ndarray<EvrData::OutputMap, 1> output_maps() const = 0;
};

/** @class ConfigV4

  
*/


class ConfigV4 {
public:
  enum { TypeId = Pds::TypeId::Id_EvrConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 4 /**< XTC type version number */ };
  virtual ~ConfigV4();
  bool operator==(const ConfigV4 &t) const { return this == &t; }
  virtual uint32_t neventcodes() const = 0;
  virtual uint32_t npulses() const = 0;
  virtual uint32_t noutputs() const = 0;
  virtual ndarray<EvrData::EventCodeV4, 1> eventcodes() const = 0;
  virtual ndarray<EvrData::PulseConfigV3, 1> pulses() const = 0;
  virtual ndarray<EvrData::OutputMap, 1> output_maps() const = 0;
};

/** @class SequencerEntry

  
*/


class SequencerEntry {
public:
  SequencerEntry()
  {
  }
  SequencerEntry(uint32_t eventcode, uint32_t delay)
    : _value((delay & 0xffffff)|((eventcode & 0xff)<<24))
  {
  }
  bool operator==(const SequencerEntry &t) const { return this == &t; }
  uint32_t delay() const { return uint32_t(this->_value & 0xffffff); }
  uint32_t eventcode() const { return uint32_t((this->_value>>24) & 0xff); }
  static uint32_t _sizeof()  { return 4; }
private:
  uint32_t	_value;
};

/** @class SequencerConfigV1

  
*/


class SequencerConfigV1 {
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
  virtual ~SequencerConfigV1();
  bool operator==(const SequencerConfigV1 &t) const { return this == &t; }
  virtual EvrData::SequencerConfigV1::Source sync_source() const = 0;
  virtual EvrData::SequencerConfigV1::Source beam_source() const = 0;
  virtual uint32_t length() const = 0;
  virtual uint32_t cycles() const = 0;
  virtual ndarray<EvrData::SequencerEntry, 1> entries() const = 0;
};

/** @class ConfigV5

  
*/


class ConfigV5 {
public:
  enum { TypeId = Pds::TypeId::Id_EvrConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 5 /**< XTC type version number */ };
  enum { MaxPulses = 32 };
  enum { EvrOutputs = 10 };
  virtual ~ConfigV5();
  bool operator==(const ConfigV5 &t) const { return this == &t; }
  virtual uint32_t neventcodes() const = 0;
  virtual uint32_t npulses() const = 0;
  virtual uint32_t noutputs() const = 0;
  virtual ndarray<EvrData::EventCodeV5, 1> eventcodes() const = 0;
  virtual ndarray<EvrData::PulseConfigV3, 1> pulses() const = 0;
  virtual ndarray<EvrData::OutputMap, 1> output_maps() const = 0;
  virtual const EvrData::SequencerConfigV1& seq_config() const = 0;
};

/** @class ConfigV6

  
*/


class ConfigV6 {
public:
  enum { TypeId = Pds::TypeId::Id_EvrConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 6 /**< XTC type version number */ };
  enum { MaxPulses = 256 /**< Maximum pulses in the system */ };
  enum { MaxOutputs = 256 /**< Maximum outputs in the system */ };
  virtual ~ConfigV6();
  bool operator==(const ConfigV6 &t) const { return this == &t; }
  virtual uint32_t neventcodes() const = 0;
  virtual uint32_t npulses() const = 0;
  virtual uint32_t noutputs() const = 0;
  virtual ndarray<EvrData::EventCodeV5, 1> eventcodes() const = 0;
  virtual ndarray<EvrData::PulseConfigV3, 1> pulses() const = 0;
  virtual ndarray<EvrData::OutputMapV2, 1> output_maps() const = 0;
  virtual const EvrData::SequencerConfigV1& seq_config() const = 0;
};

/** @class FIFOEvent

  
*/


class FIFOEvent {
public:
  FIFOEvent()
  {
  }
  FIFOEvent(uint32_t arg__timestampHigh, uint32_t arg__timestampLow, uint32_t arg__eventCode)
    : _timestampHigh(arg__timestampHigh), _timestampLow(arg__timestampLow), _eventCode(arg__eventCode)
  {
  }
  bool operator==(const FIFOEvent &t) const { return this == &t; }
  uint32_t timestampHigh() const { return _timestampHigh; }
  uint32_t timestampLow() const { return _timestampLow; }
  uint32_t eventCode() const { return _eventCode; }
  static uint32_t _sizeof()  { return 12; }
private:
  uint32_t	_timestampHigh;
  uint32_t	_timestampLow;
  uint32_t	_eventCode;
};

/** @class DataV3

  
*/


class DataV3 {
public:
  enum { TypeId = Pds::TypeId::Id_EvrData /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 3 /**< XTC type version number */ };
  virtual ~DataV3();
  bool operator==(const DataV3 &t) const { return this == &t; }
  virtual uint32_t numFifoEvents() const = 0;
  virtual ndarray<EvrData::FIFOEvent, 1> fifoEvents() const = 0;
};

/** @class IOChannel

  
*/


class IOChannel {
public:
  enum { NameLength = 12 };
  enum { MaxInfos = 8 };
  IOChannel()
  {
  }
  IOChannel(const char* arg__name, uint32_t arg__ninfo, const Pds::DetInfo* arg__info)
    : _ninfo(arg__ninfo)
  {
    std::copy(arg__name, arg__name+(12), _name);
    std::copy(arg__info, arg__info+(8), _info);
  }
  bool operator==(const IOChannel &t) const { return this == &t; }
  const char* name() const { return _name; }
  uint32_t ninfo() const { return _ninfo; }
  ndarray<Pds::DetInfo, 1> infos() const { return make_ndarray(&_info[0], MaxInfos); }
  static uint32_t _sizeof()  { return ((0+(1*(NameLength)))+4)+(8*(MaxInfos)); }
  /** Method which returns the shape (dimensions) of the data returned by name() method. */
  std::vector<int> name_shape() const;
private:
  char	_name[NameLength];
  uint32_t	_ninfo;
  Pds::DetInfo	_info[MaxInfos];
};

/** @class IOConfigV1

  
*/


class IOConfigV1 {
public:
  enum { TypeId = Pds::TypeId::Id_EvrIOConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  virtual ~IOConfigV1();
  bool operator==(const IOConfigV1 &t) const { return this == &t; }
  virtual uint16_t nchannels() const = 0;
  virtual ndarray<EvrData::IOChannel, 1> channels() const = 0;
  virtual EvrData::OutputMap::Conn conn() const = 0;
};
} // namespace EvrData
} // namespace Psana
#endif // PSANA_EVR_DDL_H
