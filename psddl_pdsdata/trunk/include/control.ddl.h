#ifndef PSDDLPDS_CONTROL_DDL_H
#define PSDDLPDS_CONTROL_DDL_H 1

// *** Do not edit this file, it is auto-generated ***

#include "pdsdata/xtc/TypeId.hh"

#include <vector>

#include <cstddef>

#include "pdsdata/xtc/ClockTime.hh"
namespace PsddlPds {
namespace ControlData {

/** Class: PVControl
  
*/

#pragma pack(push,4)

class PVControl {
public:
  enum {NameSize = 32};
  enum {NoArray = 0xFFFFFFFF};
  PVControl()
  {
  }
  PVControl(const char* arg__name, uint32_t arg__index, double arg__value)
    : _index(arg__index), _value(arg__value)
  {
    std::copy(arg__name, arg__name+(32), _name);
  }
  const char* name() const {return &_name[0];}
  uint32_t index() const {return _index;}
  double value() const {return _value;}
  uint8_t array() const;
  static uint32_t _sizeof()  {return ((0+(1*(32)))+4)+8;}
  std::vector<int> _name_shape() const;
private:
  char	_name[32];
  uint32_t	_index;
  double	_value;
};
#pragma pack(pop)

/** Class: PVMonitor
  
*/

#pragma pack(push,4)

class PVMonitor {
public:
  enum {NameSize = 32};
  enum {NoArray = 0xFFFFFFFF};
  PVMonitor()
  {
  }
  PVMonitor(const char* arg__name, uint32_t arg__index, double arg__loValue, double arg__hiValue)
    : _index(arg__index), _loValue(arg__loValue), _hiValue(arg__hiValue)
  {
    std::copy(arg__name, arg__name+(32), _name);
  }
  const char* name() const {return &_name[0];}
  uint32_t index() const {return _index;}
  double loValue() const {return _loValue;}
  double hiValue() const {return _hiValue;}
  uint8_t array() const;
  static uint32_t _sizeof()  {return (((0+(1*(32)))+4)+8)+8;}
  std::vector<int> _name_shape() const;
private:
  char	_name[32];
  uint32_t	_index;
  double	_loValue;
  double	_hiValue;
};
#pragma pack(pop)

/** Class: ConfigV1
  
*/


class ConfigV1 {
public:
  enum {Version = 1};
  enum {TypeId = Pds::TypeId::Id_ControlConfig};
  const Pds::ClockTime& duration() const {return _duration;}
  uint32_t npvControls() const {return _npvControls;}
  uint32_t npvMonitors() const {return _npvMonitors;}
  const ControlData::PVControl& pvControls(uint32_t i0) const {
    ptrdiff_t offset=24;
    const ControlData::PVControl* memptr = (const ControlData::PVControl*)(((const char*)this)+offset);
    return *(memptr + i0);
  }
  const ControlData::PVMonitor& pvMonitors(uint32_t i0) const {
    ptrdiff_t offset=24+(44*(this->_npvControls));
    const ControlData::PVMonitor* memptr = (const ControlData::PVMonitor*)(((const char*)this)+offset);
    return *(memptr + i0);
  }
  uint32_t _sizeof() const {return (24+(ControlData::PVControl::_sizeof()*(this->_npvControls)))+(ControlData::PVMonitor::_sizeof()*(this->_npvMonitors));}
  std::vector<int> _pvControls_shape() const;
  std::vector<int> _pvMonitors_shape() const;
private:
  uint32_t	_control;
  uint32_t	_reserved;
  Pds::ClockTime	_duration;
  uint32_t	_npvControls;
  uint32_t	_npvMonitors;
  //ControlData::PVControl	_pvControls[this->_npvControls];
  //ControlData::PVMonitor	_pvMonitors[this->_npvMonitors];
};
} // namespace ControlData
} // namespace PsddlPds
#endif // PSDDLPDS_CONTROL_DDL_H
