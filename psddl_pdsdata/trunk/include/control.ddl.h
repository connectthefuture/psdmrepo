#ifndef PSDDLPDS_CONTROL_DDL_H
#define PSDDLPDS_CONTROL_DDL_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include <cstddef>
#include "pdsdata/xtc/TypeId.hh"
#include "ndarray/ndarray.h"
#include "pdsdata/xtc/ClockTime.hh"
namespace PsddlPds {
namespace ControlData {

/** @class PVControl

  
*/

#pragma pack(push,4)

class PVControl {
public:
  enum { NameSize = 32 /**< Length of the name array. */ };
  enum { NoArray = 0xFFFFFFFF /**< Special value used for _index when PV is not an array */ };
  PVControl()
  {
  }
  PVControl(const char* arg__name, uint32_t arg__index, double arg__value)
    : _index(arg__index), _value(arg__value)
  {
    std::copy(arg__name, arg__name+(32), _name);
  }
  /** Name of the control. */
  const char* name() const { return _name; }
  /** Index of the control PV (for arrays) or NoArray. */
  uint32_t index() const { return _index; }
  /** Value for this control. */
  double value() const { return _value; }
  /** Returns true if the control is an array. */
  uint8_t array() const;
  static uint32_t _sizeof()  { return ((0+(1*(32)))+4)+8; }
private:
  char	_name[32];	/**< Name of the control. */
  uint32_t	_index;	/**< Index of the control PV (for arrays) or NoArray. */
  double	_value;	/**< Value for this control. */
};
#pragma pack(pop)

/** @class PVMonitor

  
*/

#pragma pack(push,4)

class PVMonitor {
public:
  enum { NameSize = 32 /**< Length of the name array. */ };
  enum { NoArray = 0xFFFFFFFF /**< Special value used for _index when PV is not an array */ };
  PVMonitor()
  {
  }
  PVMonitor(const char* arg__name, uint32_t arg__index, double arg__loValue, double arg__hiValue)
    : _index(arg__index), _loValue(arg__loValue), _hiValue(arg__hiValue)
  {
    std::copy(arg__name, arg__name+(32), _name);
  }
  /** Name of the control. */
  const char* name() const { return _name; }
  /** Index of the control PV (for arrays) or NoArray. */
  uint32_t index() const { return _index; }
  /** Lowest value for this monitor. */
  double loValue() const { return _loValue; }
  /** Highest value for this monitor. */
  double hiValue() const { return _hiValue; }
  /** Returns true if the monitor is an array. */
  uint8_t array() const;
  static uint32_t _sizeof()  { return (((0+(1*(32)))+4)+8)+8; }
private:
  char	_name[32];	/**< Name of the control. */
  uint32_t	_index;	/**< Index of the control PV (for arrays) or NoArray. */
  double	_loValue;	/**< Lowest value for this monitor. */
  double	_hiValue;	/**< Highest value for this monitor. */
};
#pragma pack(pop)

/** @class PVLabel

  
*/

#pragma pack(push,4)

class PVLabel {
public:
  enum { NameSize = 32 /**< Length of the PV name array. */ };
  enum { ValueSize = 64 /**< Length of the value array. */ };
  PVLabel()
  {
  }
  PVLabel(const char* arg__name, const char* arg__value)
  {
    std::copy(arg__name, arg__name+(32), _name);
    std::copy(arg__value, arg__value+(64), _value);
  }
  /** PV name. */
  const char* name() const { return _name; }
  /** Label value. */
  const char* value() const { return _value; }
  static uint32_t _sizeof()  { return (0+(1*(32)))+(1*(64)); }
private:
  char	_name[32];	/**< PV name. */
  char	_value[64];	/**< Label value. */
};
#pragma pack(pop)

/** @class ConfigV1

  
*/


class ConfigV1 {
public:
  enum { TypeId = Pds::TypeId::Id_ControlConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  /** Maximum number of events per scan. */
  uint32_t events() const { return uint32_t(this->_control & 0x3fffffff); }
  /** returns true if the configuration uses duration control. */
  uint8_t uses_duration() const { return uint8_t((this->_control>>30) & 0x1); }
  /** returns true if the configuration uses events limit. */
  uint8_t uses_events() const { return uint8_t((this->_control>>31) & 0x1); }
  /** Maximum duration of the scan. */
  const Pds::ClockTime& duration() const { return _duration; }
  /** Number of PVControl objects in this configuration. */
  uint32_t npvControls() const { return _npvControls; }
  /** Number of PVMonitor objects in this configuration. */
  uint32_t npvMonitors() const { return _npvMonitors; }
  /** PVControl configuration objects */
  ndarray<ControlData::PVControl, 1> pvControls() const { ptrdiff_t offset=24;
  ControlData::PVControl* data = (ControlData::PVControl*)(((const char*)this)+offset);
  return make_ndarray(data, this->_npvControls); }
  /** PVMonitor configuration objects */
  ndarray<ControlData::PVMonitor, 1> pvMonitors() const { ptrdiff_t offset=24+(44*(this->_npvControls));
  ControlData::PVMonitor* data = (ControlData::PVMonitor*)(((const char*)this)+offset);
  return make_ndarray(data, this->_npvMonitors); }
  uint32_t _sizeof() const { return (24+(ControlData::PVControl::_sizeof()*(this->_npvControls)))+(ControlData::PVMonitor::_sizeof()*(this->_npvMonitors)); }
private:
  uint32_t	_control;
  uint32_t	_reserved;
  Pds::ClockTime	_duration;	/**< Maximum duration of the scan. */
  uint32_t	_npvControls;	/**< Number of PVControl objects in this configuration. */
  uint32_t	_npvMonitors;	/**< Number of PVMonitor objects in this configuration. */
  //ControlData::PVControl	_pvControls[this->_npvControls];
  //ControlData::PVMonitor	_pvMonitors[this->_npvMonitors];
};

/** @class ConfigV2

  
*/


class ConfigV2 {
public:
  enum { TypeId = Pds::TypeId::Id_ControlConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 2 /**< XTC type version number */ };
  /** Maximum number of events per scan. */
  uint32_t events() const { return uint32_t(this->_control & 0x3fffffff); }
  /** returns true if the configuration uses duration control. */
  uint8_t uses_duration() const { return uint8_t((this->_control>>30) & 0x1); }
  /** returns true if the configuration uses events limit. */
  uint8_t uses_events() const { return uint8_t((this->_control>>31) & 0x1); }
  /** Maximum duration of the scan. */
  const Pds::ClockTime& duration() const { return _duration; }
  /** Number of PVControl objects in this configuration. */
  uint32_t npvControls() const { return _npvControls; }
  /** Number of PVMonitor objects in this configuration. */
  uint32_t npvMonitors() const { return _npvMonitors; }
  /** Number of PVLabel objects in this configuration. */
  uint32_t npvLabels() const { return _npvLabels; }
  /** PVControl configuration objects */
  ndarray<ControlData::PVControl, 1> pvControls() const { ptrdiff_t offset=28;
  ControlData::PVControl* data = (ControlData::PVControl*)(((const char*)this)+offset);
  return make_ndarray(data, this->_npvControls); }
  /** PVMonitor configuration objects */
  ndarray<ControlData::PVMonitor, 1> pvMonitors() const { ptrdiff_t offset=28+(44*(this->_npvControls));
  ControlData::PVMonitor* data = (ControlData::PVMonitor*)(((const char*)this)+offset);
  return make_ndarray(data, this->_npvMonitors); }
  /** PVLabel configuration objects */
  ndarray<ControlData::PVLabel, 1> pvLabels() const { ptrdiff_t offset=(28+(44*(this->_npvControls)))+(52*(this->_npvMonitors));
  ControlData::PVLabel* data = (ControlData::PVLabel*)(((const char*)this)+offset);
  return make_ndarray(data, this->_npvLabels); }
  uint32_t _sizeof() const { return ((28+(ControlData::PVControl::_sizeof()*(this->_npvControls)))+(ControlData::PVMonitor::_sizeof()*(this->_npvMonitors)))+(ControlData::PVLabel::_sizeof()*(this->_npvLabels)); }
private:
  uint32_t	_control;
  uint32_t	_reserved;
  Pds::ClockTime	_duration;	/**< Maximum duration of the scan. */
  uint32_t	_npvControls;	/**< Number of PVControl objects in this configuration. */
  uint32_t	_npvMonitors;	/**< Number of PVMonitor objects in this configuration. */
  uint32_t	_npvLabels;	/**< Number of PVLabel objects in this configuration. */
  //ControlData::PVControl	_pvControls[this->_npvControls];
  //ControlData::PVMonitor	_pvMonitors[this->_npvMonitors];
  //ControlData::PVLabel	_pvLabels[this->_npvLabels];
};
} // namespace ControlData
} // namespace PsddlPds
#endif // PSDDLPDS_CONTROL_DDL_H
