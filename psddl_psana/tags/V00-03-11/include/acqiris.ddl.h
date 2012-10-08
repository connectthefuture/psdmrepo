#ifndef PSANA_ACQIRIS_DDL_H
#define PSANA_ACQIRIS_DDL_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include "ndarray/ndarray.h"
#include "pdsdata/xtc/TypeId.hh"
namespace Psana {
namespace Acqiris {

/** @class VertV1

  Class containing Acqiris configuration data for vertical axis.
*/

#pragma pack(push,4)

class VertV1 {
public:
  enum { Version = 1 /**< XTC type version number */ };

  /** Coupling modes */
  enum Coupling {
    GND,
    DC,
    AC,
    DC50ohm,
    AC50ohm,
  };
  enum Bandwidth {
    None,
    MHz25,
    MHz700,
    MHz200,
    MHz20,
    MHz35,
  };
  VertV1()
  {
  }
  VertV1(double arg__fullScale, double arg__offset, uint32_t arg__coupling, uint32_t arg__bandwidth)
    : _fullScale(arg__fullScale), _offset(arg__offset), _coupling(arg__coupling), _bandwidth(arg__bandwidth)
  {
  }
  /** Full vertical scale. */
  double fullScale() const { return _fullScale; }
  /** Offset value. */
  double offset() const { return _offset; }
  /** Coupling mode. */
  uint32_t coupling() const { return _coupling; }
  /** Bandwidth enumeration. */
  uint32_t bandwidth() const { return _bandwidth; }
  /** Calculated slope. */
  double slope() const;
  static uint32_t _sizeof()  { return 24; }
private:
  double	_fullScale;	/**< Full vertical scale. */
  double	_offset;	/**< Offset value. */
  uint32_t	_coupling;	/**< Coupling mode. */
  uint32_t	_bandwidth;	/**< Bandwidth enumeration. */
};
#pragma pack(pop)

/** @class HorizV1

  Class containing Acqiris configuration data for horizontal axis.
*/

#pragma pack(push,4)

class HorizV1 {
public:
  enum { Version = 1 /**< XTC type version number */ };
  HorizV1()
  {
  }
  HorizV1(double arg__sampInterval, double arg__delayTime, uint32_t arg__nbrSamples, uint32_t arg__nbrSegments)
    : _sampInterval(arg__sampInterval), _delayTime(arg__delayTime), _nbrSamples(arg__nbrSamples), _nbrSegments(arg__nbrSegments)
  {
  }
  /** Interval for single sample. */
  double sampInterval() const { return _sampInterval; }
  /** Delay time. */
  double delayTime() const { return _delayTime; }
  /** Number of samples. */
  uint32_t nbrSamples() const { return _nbrSamples; }
  /** Number of segments. */
  uint32_t nbrSegments() const { return _nbrSegments; }
  static uint32_t _sizeof()  { return 24; }
private:
  double	_sampInterval;	/**< Interval for single sample. */
  double	_delayTime;	/**< Delay time. */
  uint32_t	_nbrSamples;	/**< Number of samples. */
  uint32_t	_nbrSegments;	/**< Number of segments. */
};
#pragma pack(pop)

/** @class TrigV1

  Class containing Acqiris configuration data for triggering.
*/

#pragma pack(push,4)

class TrigV1 {
public:
  enum { Version = 1 /**< XTC type version number */ };

  /** Trigger source. */
  enum Source {
    Internal = 1,
    External = -1,
  };
  enum Coupling {
    DC = 0,
    AC = 1,
    HFreject = 2,
    DC50ohm = 3,
    AC50ohm = 4,
  };

  /** Triggering slope. */
  enum Slope {
    Positive,
    Negative,
    OutOfWindow,
    IntoWindow,
    HFDivide,
    SpikeStretcher,
  };
  TrigV1()
  {
  }
  TrigV1(uint32_t arg__coupling, uint32_t arg__input, uint32_t arg__slope, double arg__level)
    : _coupling(arg__coupling), _input(arg__input), _slope(arg__slope), _level(arg__level)
  {
  }
  uint32_t coupling() const { return _coupling; }
  /** Trigger source */
  uint32_t input() const { return _input; }
  /** Triggering slope. */
  uint32_t slope() const { return _slope; }
  /** Trigger level. */
  double level() const { return _level; }
  static uint32_t _sizeof()  { return 20; }
private:
  uint32_t	_coupling;
  uint32_t	_input;	/**< Trigger source */
  uint32_t	_slope;	/**< Triggering slope. */
  double	_level;	/**< Trigger level. */
};
#pragma pack(pop)

/** @class ConfigV1

  Class containing all Acqiris configuration data.
*/


class ConfigV1 {
public:
  enum { TypeId = Pds::TypeId::Id_AcqConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  enum { MaxChan = 20 /**< Maximum number of the configured channels. */ };
  virtual ~ConfigV1();
  /** Number of ADCs per channel. */
  virtual uint32_t nbrConvertersPerChannel() const = 0;
  /** Bit mask for channels. */
  virtual uint32_t channelMask() const = 0;
  /** Total number of banks. */
  virtual uint32_t nbrBanks() const = 0;
  /** Trigger configuration. */
  virtual const Acqiris::TrigV1& trig() const = 0;
  /** Configuration for horizontal axis */
  virtual const Acqiris::HorizV1& horiz() const = 0;
  /** Configuration for vertical axis (one per channel). */
  virtual ndarray<Acqiris::VertV1, 1> vert() const = 0;
  /** Number of channels calculated from channel bit mask. */
  virtual uint32_t nbrChannels() const = 0;
};

/** @class TimestampV1

  Class representing Acqiris timestamp value.
*/

#pragma pack(push,4)

class TimestampV1 {
public:
  enum { Version = 1 /**< XTC type version number */ };
  TimestampV1()
  {
  }
  TimestampV1(double arg__horPos, uint32_t arg__timeStampLo, uint32_t arg__timeStampHi)
    : _horPos(arg__horPos), _timeStampLo(arg__timeStampLo), _timeStampHi(arg__timeStampHi)
  {
  }
  double pos() const { return _horPos; }
  uint32_t timeStampLo() const { return _timeStampLo; }
  uint32_t timeStampHi() const { return _timeStampHi; }
  /** Full timestamp as 64-bit number. */
  uint64_t value() const;
  static uint32_t _sizeof()  { return 16; }
private:
  double	_horPos;
  uint32_t	_timeStampLo;
  uint32_t	_timeStampHi;
};
#pragma pack(pop)

/** @class DataDescV1Elem

  Class representing Acqiris waveforms from single channel.
*/

class ConfigV1;

class DataDescV1Elem {
public:
  enum { Version = 1 /**< XTC type version number */ };
  enum { NumberOfBits = 10 };
  enum { BitShift = 6 };
  enum { _extraSize = 32 };
  virtual ~DataDescV1Elem();
  /** Number of samples in one segment. */
  virtual uint32_t nbrSamplesInSeg() const = 0;
  virtual uint32_t indexFirstPoint() const = 0;
  /** Number of segments. */
  virtual uint32_t nbrSegments() const = 0;
  /** Timestamps, one timestamp per segment. */
  virtual ndarray<Acqiris::TimestampV1, 1> timestamp() const = 0;
  /** Waveforms data, two-dimensional array [nbrSegments()]*[nbrSamplesInSeg()] */
  virtual ndarray<int16_t, 2> waveforms() const = 0;
};

/** @class DataDescV1

  Class containing waveform data (DataDescV1Elem) for all channels.
*/

class ConfigV1;

class DataDescV1 {
public:
  enum { TypeId = Pds::TypeId::Id_AcqWaveform /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  virtual ~DataDescV1();
  /** Waveform data, one object per channel. */
  virtual const Acqiris::DataDescV1Elem& data(uint32_t i0) const = 0;
  /** Method which returns the shape (dimensions) of the data returned by data() method. */
  virtual std::vector<int> data_shape() const = 0;
};

/** @class TdcChannel

  Configuration for Acqiris TDC channel.
*/

#pragma pack(push,4)

class TdcChannel {
public:

  /** Types of channels. */
  enum Channel {
    Veto = -2,
    Common = -1,
    Input1 = 1,
    Input2 = 2,
    Input3 = 3,
    Input4 = 4,
    Input5 = 5,
    Input6 = 6,
  };
  enum Mode {
    Active = 0,
    Inactive = 1,
  };
  enum Slope {
    Positive,
    Negative,
  };
  TdcChannel()
  {
  }
  TdcChannel(uint32_t arg__channel, Acqiris::TdcChannel::Slope arg_bf__bf_slope, Acqiris::TdcChannel::Mode arg_bf__bf_mode, double arg__level)
    : _channel(arg__channel), _mode((arg_bf__bf_slope & 0x1)|((arg_bf__bf_mode & 0x1)<<31)), _level(arg__level)
  {
  }
  /** Channel type as integer number, clients should use channel() method instead. */
  uint32_t _channel_int() const { return _channel; }
  /** Bitfield value, should not be used directly. Use mode() and slope()
                in the client code. */
  uint32_t _mode_int() const { return _mode; }
  Acqiris::TdcChannel::Slope slope() const { return Slope(this->_mode & 0x1); }
  Acqiris::TdcChannel::Mode mode() const { return Mode((this->_mode>>31) & 0x1); }
  double level() const { return _level; }
  Acqiris::TdcChannel::Channel channel() const { return Channel(this->_channel); }
  static uint32_t _sizeof()  { return 16; }
private:
  uint32_t	_channel;	/**< Channel type as integer number, clients should use channel() method instead. */
  uint32_t	_mode;	/**< Bitfield value, should not be used directly. Use mode() and slope()
                in the client code. */
  double	_level;
};
#pragma pack(pop)

/** @class TdcAuxIO

  configuration for auxiliary IO channel.
*/

#pragma pack(push,4)

class TdcAuxIO {
public:
  enum Channel {
    IOAux1 = 1,
    IOAux2 = 2,
  };
  enum Mode {
    BankSwitch = 1,
    Marker = 2,
    OutputLo = 32,
    OutputHi = 33,
  };
  enum Termination {
    ZHigh = 0,
    Z50 = 1,
  };
  TdcAuxIO()
  {
  }
  TdcAuxIO(uint32_t arg__channel, uint32_t arg__signal, uint32_t arg__qualifier)
    : _channel(arg__channel), _signal(arg__signal), _qualifier(arg__qualifier)
  {
  }
  /** Channel type as integer number, clients should use channel() method instead. */
  uint32_t channel_int() const { return _channel; }
  /** Mode as integer number, clients should use mode() method instead. */
  uint32_t signal_int() const { return _signal; }
  /** Termination as integer number, clients should use term() method instead. */
  uint32_t qualifier_int() const { return _qualifier; }
  Acqiris::TdcAuxIO::Channel channel() const { return Channel(this->_channel); }
  Acqiris::TdcAuxIO::Mode mode() const { return Mode(this->_signal); }
  Acqiris::TdcAuxIO::Termination term() const { return Termination(this->_qualifier); }
  static uint32_t _sizeof()  { return 12; }
private:
  uint32_t	_channel;	/**< Channel type as integer number, clients should use channel() method instead. */
  uint32_t	_signal;	/**< Mode as integer number, clients should use mode() method instead. */
  uint32_t	_qualifier;	/**< Termination as integer number, clients should use term() method instead. */
};
#pragma pack(pop)

/** @class TdcVetoIO

  Class with configuration data for Veto IO channel.
*/

#pragma pack(push,4)

class TdcVetoIO {
public:
  enum Channel {
    ChVeto = 13,
  };
  enum Mode {
    Veto = 1,
    SwitchVeto = 2,
    InvertedVeto = 3,
    InvertedSwitchVeto = 4,
  };
  enum Termination {
    ZHigh = 0,
    Z50 = 1,
  };
  TdcVetoIO()
  {
  }
  TdcVetoIO(uint32_t mode, uint32_t term)
    : _channel(ChVeto), _signal(mode), _qualifier(term)
  {
  }
  /** Mode as integer number, clients should use mode() method instead. */
  uint32_t signal_int() const { return _signal; }
  /** Termination as integer number, clients should use term() method instead. */
  uint32_t qualifier_int() const { return _qualifier; }
  Acqiris::TdcVetoIO::Channel channel() const { return Channel(this->_channel); }
  Acqiris::TdcVetoIO::Mode mode() const { return Mode(this->_signal); }
  Acqiris::TdcVetoIO::Termination term() const { return Termination(this->_qualifier); }
  static uint32_t _sizeof()  { return 12; }
private:
  uint32_t	_channel;	/**< Channel type as integer number, clients should use channel() method instead. */
  uint32_t	_signal;	/**< Mode as integer number, clients should use mode() method instead. */
  uint32_t	_qualifier;	/**< Termination as integer number, clients should use term() method instead. */
};
#pragma pack(pop)

/** @class TdcConfigV1

  Class with complete Acqiris TDC configuration.
*/


class TdcConfigV1 {
public:
  enum { TypeId = Pds::TypeId::Id_AcqTdcConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  enum { NChannels = 8 /**< Total number of channel configurations. */ };
  enum { NAuxIO = 2 /**< Total number of auxiliary IO configurations. */ };
  virtual ~TdcConfigV1();
  /** Channel configurations, one object per channel. */
  virtual ndarray<Acqiris::TdcChannel, 1> channels() const = 0;
  /** Axiliary configurations, one object per channel. */
  virtual ndarray<Acqiris::TdcAuxIO, 1> auxio() const = 0;
  virtual const Acqiris::TdcVetoIO& veto() const = 0;
};

/** @class TdcDataV1_Item

  Base class for all Acqiris TDC data objects.
*/


class TdcDataV1_Item {
public:

  /** Enum for types of data objects. Comm means data object has TdcDataV1Common
              type, AuxIO means TdcDataV1Marker class, all others are for TdcDataV1Channel. */
  enum Source {
    Comm,
    Chan1,
    Chan2,
    Chan3,
    Chan4,
    Chan5,
    Chan6,
    AuxIO,
  };
  TdcDataV1_Item()
  {
  }
  TdcDataV1_Item(uint32_t arg_bf__bf_val, Acqiris::TdcDataV1_Item::Source arg_bf__bf_source, uint8_t arg_bf__bf_ovf)
    : _value((arg_bf__bf_val & 0xfffffff)|((arg_bf__bf_source & 0x7)<<28)|((arg_bf__bf_ovf & 0x1)<<31))
  {
  }
  /** Value as integer number whiis composed of several bit fields. Do not use value directly,
                instead cast this object to one of the actual types and use corresponding methods. */
  uint32_t value() const { return _value; }
  uint32_t bf_val_() const { return uint32_t(this->_value & 0xfffffff); }
  /** Source of this data object, use returned enum to distinguish between actual 
                types of data objecs and cast appropriately. */
  Acqiris::TdcDataV1_Item::Source source() const { return Source((this->_value>>28) & 0x7); }
  uint8_t bf_ofv_() const { return uint8_t((this->_value>>31) & 0x1); }
  static uint32_t _sizeof()  { return 4; }
private:
  uint32_t	_value;	/**< Value as integer number whiis composed of several bit fields. Do not use value directly,
                instead cast this object to one of the actual types and use corresponding methods. */
};

/** @class TdcDataV1Common

  Class for the "common" TDC data object.
*/


class TdcDataV1Common: public TdcDataV1_Item {
public:
  /** Returns number of hits. */
  uint32_t nhits() const;
  /** Returns overflow status. */
  uint8_t overflow() const;
  static uint32_t _sizeof()  { return Acqiris::TdcDataV1_Item::_sizeof(); }
};

/** @class TdcDataV1Channel

  Class for the "channel" TDC data object.
*/


class TdcDataV1Channel: public TdcDataV1_Item {
public:
  /** Returns number of ticks. */
  uint32_t ticks() const;
  /** Returns overflow status. */
  uint8_t overflow() const;
  /** Ticks converted to time, tick resolution is 50 picosecond. */
  double time() const;
  static uint32_t _sizeof()  { return Acqiris::TdcDataV1_Item::_sizeof(); }
};

/** @class TdcDataV1Marker

  Class for the "marker" TDC data object.
*/


class TdcDataV1Marker: public TdcDataV1_Item {
public:

  /** Enum for the type of marker. */
  enum Type {
    AuxIOSwitch = 0,
    EventCntSwitch = 1,
    MemFullSwitch = 2,
    AuxIOMarker = 16,
  };
  /** Returns type of the marker. */
  Acqiris::TdcDataV1Marker::Type type() const;
  static uint32_t _sizeof()  { return Acqiris::TdcDataV1_Item::_sizeof(); }
};

/** @class TdcDataV1

  Acqiris TDS data object is a container for TdcDataV1_Item object (or their
            sub-types).
*/


class TdcDataV1 {
public:
  enum { TypeId = Pds::TypeId::Id_AcqTdcData /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  virtual ~TdcDataV1();
  /** Access TDC data items. The data_shape() method should be used to 
            obtain the number of elements. */
  virtual ndarray<Acqiris::TdcDataV1_Item, 1> data() const = 0;
};
} // namespace Acqiris
} // namespace Psana
#endif // PSANA_ACQIRIS_DDL_H
