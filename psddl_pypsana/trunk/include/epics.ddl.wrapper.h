#ifndef PSANA_EPICS_DDL_WRAPPER_H
#define PSANA_EPICS_DDL_WRAPPER_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include "ndarray/ndarray.h"
#include "pdsdata/xtc/TypeId.hh"
#include "psddl_pypsana/PyWrapper.h"
namespace Psana {
namespace Epics {

extern void createWrappers();


/** @class epicsTimeStamp

  EPICS timestamp type, includes seconds and nanoseconds.
           EPICS epoch corresponds to 1990-01-01 00:00:00Z.
*/


class epicsTimeStamp_Wrapper {
  boost::shared_ptr<epicsTimeStamp> _o;
  epicsTimeStamp* o;
public:
  epicsTimeStamp_Wrapper(boost::shared_ptr<epicsTimeStamp> obj) : _o(obj), o(_o.get()) {}
  epicsTimeStamp_Wrapper(epicsTimeStamp* obj) : o(obj) {}
  bool operator==(const epicsTimeStamp_Wrapper &t) const { return this == &t; }
  uint32_t sec() const { return o->sec(); }
  uint32_t nsec() const { return o->nsec(); }
  uint32_t _sizeof() const { return o->_sizeof(); }
private:
  uint32_t	_secPastEpoch;	/**< Seconds since Jan 1, 1990 00:00 UTC */
  uint32_t	_nsec;	/**< Nanoseconds within second. */
};

/** @class dbr_time_string

  
*/


class dbr_time_string_Wrapper {
  boost::shared_ptr<dbr_time_string> _o;
  dbr_time_string* o;
public:
  enum { DBR_TYPE_ID = DBR_TIME_STRING };
  dbr_time_string_Wrapper(boost::shared_ptr<dbr_time_string> obj) : _o(obj), o(_o.get()) {}
  dbr_time_string_Wrapper(dbr_time_string* obj) : o(obj) {}
  bool operator==(const dbr_time_string_Wrapper &t) const { return this == &t; }
  int16_t status() const { return o->status(); }
  int16_t severity() const { return o->severity(); }
  const epicsTimeStamp_Wrapper stamp() const { return epicsTimeStamp_Wrapper((epicsTimeStamp*) &o->stamp()); }
  uint32_t _sizeof() const { return o->_sizeof(); }
private:
  int16_t	_status;
  int16_t	_severity;
  Epics::epicsTimeStamp	_stamp;
};

/** @class dbr_time_short

  
*/


class dbr_time_short_Wrapper {
  boost::shared_ptr<dbr_time_short> _o;
  dbr_time_short* o;
public:
  enum { DBR_TYPE_ID = DBR_TIME_SHORT };
  dbr_time_short_Wrapper(boost::shared_ptr<dbr_time_short> obj) : _o(obj), o(_o.get()) {}
  dbr_time_short_Wrapper(dbr_time_short* obj) : o(obj) {}
  bool operator==(const dbr_time_short_Wrapper &t) const { return this == &t; }
  int16_t status() const { return o->status(); }
  int16_t severity() const { return o->severity(); }
  const epicsTimeStamp_Wrapper stamp() const { return epicsTimeStamp_Wrapper((epicsTimeStamp*) &o->stamp()); }
  uint32_t _sizeof() const { return o->_sizeof(); }
private:
  int16_t	_status;
  int16_t	_severity;
  Epics::epicsTimeStamp	_stamp;
  int16_t	RISC_pad;
};

/** @class dbr_time_float

  
*/


class dbr_time_float_Wrapper {
  boost::shared_ptr<dbr_time_float> _o;
  dbr_time_float* o;
public:
  enum { DBR_TYPE_ID = DBR_TIME_FLOAT };
  dbr_time_float_Wrapper(boost::shared_ptr<dbr_time_float> obj) : _o(obj), o(_o.get()) {}
  dbr_time_float_Wrapper(dbr_time_float* obj) : o(obj) {}
  bool operator==(const dbr_time_float_Wrapper &t) const { return this == &t; }
  int16_t status() const { return o->status(); }
  int16_t severity() const { return o->severity(); }
  const epicsTimeStamp_Wrapper stamp() const { return epicsTimeStamp_Wrapper((epicsTimeStamp*) &o->stamp()); }
  uint32_t _sizeof() const { return o->_sizeof(); }
private:
  int16_t	_status;
  int16_t	_severity;
  Epics::epicsTimeStamp	_stamp;
};

/** @class dbr_time_enum

  
*/


class dbr_time_enum_Wrapper {
  boost::shared_ptr<dbr_time_enum> _o;
  dbr_time_enum* o;
public:
  enum { DBR_TYPE_ID = DBR_TIME_ENUM };
  dbr_time_enum_Wrapper(boost::shared_ptr<dbr_time_enum> obj) : _o(obj), o(_o.get()) {}
  dbr_time_enum_Wrapper(dbr_time_enum* obj) : o(obj) {}
  bool operator==(const dbr_time_enum_Wrapper &t) const { return this == &t; }
  int16_t status() const { return o->status(); }
  int16_t severity() const { return o->severity(); }
  const epicsTimeStamp_Wrapper stamp() const { return epicsTimeStamp_Wrapper((epicsTimeStamp*) &o->stamp()); }
  uint32_t _sizeof() const { return o->_sizeof(); }
private:
  int16_t	_status;
  int16_t	_severity;
  Epics::epicsTimeStamp	_stamp;
  int16_t	RISC_pad;
};

/** @class dbr_time_char

  
*/


class dbr_time_char_Wrapper {
  boost::shared_ptr<dbr_time_char> _o;
  dbr_time_char* o;
public:
  enum { DBR_TYPE_ID = DBR_TIME_CHAR };
  dbr_time_char_Wrapper(boost::shared_ptr<dbr_time_char> obj) : _o(obj), o(_o.get()) {}
  dbr_time_char_Wrapper(dbr_time_char* obj) : o(obj) {}
  bool operator==(const dbr_time_char_Wrapper &t) const { return this == &t; }
  int16_t status() const { return o->status(); }
  int16_t severity() const { return o->severity(); }
  const epicsTimeStamp_Wrapper stamp() const { return epicsTimeStamp_Wrapper((epicsTimeStamp*) &o->stamp()); }
  uint32_t _sizeof() const { return o->_sizeof(); }
private:
  int16_t	_status;
  int16_t	_severity;
  Epics::epicsTimeStamp	_stamp;
  int16_t	RISC_pad0;
  uint8_t	RISC_pad1;
};

/** @class dbr_time_long

  
*/


class dbr_time_long_Wrapper {
  boost::shared_ptr<dbr_time_long> _o;
  dbr_time_long* o;
public:
  enum { DBR_TYPE_ID = DBR_TIME_LONG };
  dbr_time_long_Wrapper(boost::shared_ptr<dbr_time_long> obj) : _o(obj), o(_o.get()) {}
  dbr_time_long_Wrapper(dbr_time_long* obj) : o(obj) {}
  bool operator==(const dbr_time_long_Wrapper &t) const { return this == &t; }
  int16_t status() const { return o->status(); }
  int16_t severity() const { return o->severity(); }
  const epicsTimeStamp_Wrapper stamp() const { return epicsTimeStamp_Wrapper((epicsTimeStamp*) &o->stamp()); }
  uint32_t _sizeof() const { return o->_sizeof(); }
private:
  int16_t	_status;
  int16_t	_severity;
  Epics::epicsTimeStamp	_stamp;
};

/** @class dbr_time_double

  
*/


class dbr_time_double_Wrapper {
  boost::shared_ptr<dbr_time_double> _o;
  dbr_time_double* o;
public:
  enum { DBR_TYPE_ID = DBR_TIME_DOUBLE };
  dbr_time_double_Wrapper(boost::shared_ptr<dbr_time_double> obj) : _o(obj), o(_o.get()) {}
  dbr_time_double_Wrapper(dbr_time_double* obj) : o(obj) {}
  bool operator==(const dbr_time_double_Wrapper &t) const { return this == &t; }
  int16_t status() const { return o->status(); }
  int16_t severity() const { return o->severity(); }
  const epicsTimeStamp_Wrapper stamp() const { return epicsTimeStamp_Wrapper((epicsTimeStamp*) &o->stamp()); }
  uint32_t _sizeof() const { return o->_sizeof(); }
private:
  int16_t	_status;
  int16_t	_severity;
  Epics::epicsTimeStamp	_stamp;
  int32_t	RISC_pad;
};

/** @class dbr_sts_string

  
*/


class dbr_sts_string_Wrapper {
  boost::shared_ptr<dbr_sts_string> _o;
  dbr_sts_string* o;
public:
  enum { DBR_TYPE_ID = DBR_CTRL_STRING };
  dbr_sts_string_Wrapper(boost::shared_ptr<dbr_sts_string> obj) : _o(obj), o(_o.get()) {}
  dbr_sts_string_Wrapper(dbr_sts_string* obj) : o(obj) {}
  bool operator==(const dbr_sts_string_Wrapper &t) const { return this == &t; }
  int16_t status() const { return o->status(); }
  int16_t severity() const { return o->severity(); }
  uint32_t _sizeof() const { return o->_sizeof(); }
private:
  int16_t	_status;
  int16_t	_severity;
};

/** @class dbr_ctrl_short

  
*/


class dbr_ctrl_short_Wrapper {
  boost::shared_ptr<dbr_ctrl_short> _o;
  dbr_ctrl_short* o;
public:
  enum { DBR_TYPE_ID = DBR_CTRL_SHORT };
  dbr_ctrl_short_Wrapper(boost::shared_ptr<dbr_ctrl_short> obj) : _o(obj), o(_o.get()) {}
  dbr_ctrl_short_Wrapper(dbr_ctrl_short* obj) : o(obj) {}
  bool operator==(const dbr_ctrl_short_Wrapper &t) const { return this == &t; }
  int16_t status() const { return o->status(); }
  int16_t severity() const { return o->severity(); }
  const char* units() const { return o->units(); }
  int16_t upper_disp_limit() const { return o->upper_disp_limit(); }
  int16_t lower_disp_limit() const { return o->lower_disp_limit(); }
  int16_t upper_alarm_limit() const { return o->upper_alarm_limit(); }
  int16_t upper_warning_limit() const { return o->upper_warning_limit(); }
  int16_t lower_warning_limit() const { return o->lower_warning_limit(); }
  int16_t lower_alarm_limit() const { return o->lower_alarm_limit(); }
  int16_t upper_ctrl_limit() const { return o->upper_ctrl_limit(); }
  int16_t lower_ctrl_limit() const { return o->lower_ctrl_limit(); }
  uint32_t _sizeof() const { return o->_sizeof(); }
  std::vector<int> units_shape() const { return o->units_shape(); }
private:
  int16_t	_status;
  int16_t	_severity;
  char	_units[MAX_UNITS_SIZE];
  int16_t	_upper_disp_limit;
  int16_t	_lower_disp_limit;
  int16_t	_upper_alarm_limit;
  int16_t	_upper_warning_limit;
  int16_t	_lower_warning_limit;
  int16_t	_lower_alarm_limit;
  int16_t	_upper_ctrl_limit;
  int16_t	_lower_ctrl_limit;
};

/** @class dbr_ctrl_float

  
*/


class dbr_ctrl_float_Wrapper {
  boost::shared_ptr<dbr_ctrl_float> _o;
  dbr_ctrl_float* o;
public:
  enum { DBR_TYPE_ID = DBR_CTRL_FLOAT };
  dbr_ctrl_float_Wrapper(boost::shared_ptr<dbr_ctrl_float> obj) : _o(obj), o(_o.get()) {}
  dbr_ctrl_float_Wrapper(dbr_ctrl_float* obj) : o(obj) {}
  bool operator==(const dbr_ctrl_float_Wrapper &t) const { return this == &t; }
  int16_t status() const { return o->status(); }
  int16_t severity() const { return o->severity(); }
  int16_t precision() const { return o->precision(); }
  const char* units() const { return o->units(); }
  float upper_disp_limit() const { return o->upper_disp_limit(); }
  float lower_disp_limit() const { return o->lower_disp_limit(); }
  float upper_alarm_limit() const { return o->upper_alarm_limit(); }
  float upper_warning_limit() const { return o->upper_warning_limit(); }
  float lower_warning_limit() const { return o->lower_warning_limit(); }
  float lower_alarm_limit() const { return o->lower_alarm_limit(); }
  float upper_ctrl_limit() const { return o->upper_ctrl_limit(); }
  float lower_ctrl_limit() const { return o->lower_ctrl_limit(); }
  uint32_t _sizeof() const { return o->_sizeof(); }
  std::vector<int> units_shape() const { return o->units_shape(); }
private:
  int16_t	_status;
  int16_t	_severity;
  int16_t	_precision;
  int16_t	RISC_pad;
  char	_units[MAX_UNITS_SIZE];
  float	_upper_disp_limit;
  float	_lower_disp_limit;
  float	_upper_alarm_limit;
  float	_upper_warning_limit;
  float	_lower_warning_limit;
  float	_lower_alarm_limit;
  float	_upper_ctrl_limit;
  float	_lower_ctrl_limit;
};

/** @class dbr_ctrl_enum

  
*/


class dbr_ctrl_enum_Wrapper {
  boost::shared_ptr<dbr_ctrl_enum> _o;
  dbr_ctrl_enum* o;
public:
  enum { DBR_TYPE_ID = DBR_CTRL_ENUM };
  dbr_ctrl_enum_Wrapper(boost::shared_ptr<dbr_ctrl_enum> obj) : _o(obj), o(_o.get()) {}
  dbr_ctrl_enum_Wrapper(dbr_ctrl_enum* obj) : o(obj) {}
  bool operator==(const dbr_ctrl_enum_Wrapper &t) const { return this == &t; }
  int16_t status() const { return o->status(); }
  int16_t severity() const { return o->severity(); }
  int16_t no_str() const { return o->no_str(); }
  const char* strings(uint32_t i0) const { return o->strings(i0); }
  uint32_t _sizeof() const { return o->_sizeof(); }
  std::vector<int> strings_shape() const { return o->strings_shape(); }
private:
  int16_t	_status;
  int16_t	_severity;
  int16_t	_no_str;
  char	_strs[MAX_ENUM_STATES][MAX_ENUM_STRING_SIZE];
};

/** @class dbr_ctrl_char

  
*/


class dbr_ctrl_char_Wrapper {
  boost::shared_ptr<dbr_ctrl_char> _o;
  dbr_ctrl_char* o;
public:
  enum { DBR_TYPE_ID = DBR_CTRL_CHAR };
  dbr_ctrl_char_Wrapper(boost::shared_ptr<dbr_ctrl_char> obj) : _o(obj), o(_o.get()) {}
  dbr_ctrl_char_Wrapper(dbr_ctrl_char* obj) : o(obj) {}
  bool operator==(const dbr_ctrl_char_Wrapper &t) const { return this == &t; }
  int16_t status() const { return o->status(); }
  int16_t severity() const { return o->severity(); }
  const char* units() const { return o->units(); }
  uint8_t upper_disp_limit() const { return o->upper_disp_limit(); }
  uint8_t lower_disp_limit() const { return o->lower_disp_limit(); }
  uint8_t upper_alarm_limit() const { return o->upper_alarm_limit(); }
  uint8_t upper_warning_limit() const { return o->upper_warning_limit(); }
  uint8_t lower_warning_limit() const { return o->lower_warning_limit(); }
  uint8_t lower_alarm_limit() const { return o->lower_alarm_limit(); }
  uint8_t upper_ctrl_limit() const { return o->upper_ctrl_limit(); }
  uint8_t lower_ctrl_limit() const { return o->lower_ctrl_limit(); }
  uint32_t _sizeof() const { return o->_sizeof(); }
  std::vector<int> units_shape() const { return o->units_shape(); }
private:
  int16_t	_status;
  int16_t	_severity;
  char	_units[MAX_UNITS_SIZE];
  uint8_t	_upper_disp_limit;
  uint8_t	_lower_disp_limit;
  uint8_t	_upper_alarm_limit;
  uint8_t	_upper_warning_limit;
  uint8_t	_lower_warning_limit;
  uint8_t	_lower_alarm_limit;
  uint8_t	_upper_ctrl_limit;
  uint8_t	_lower_ctrl_limit;
  uint8_t	RISC_pad;
};

/** @class dbr_ctrl_long

  
*/


class dbr_ctrl_long_Wrapper {
  boost::shared_ptr<dbr_ctrl_long> _o;
  dbr_ctrl_long* o;
public:
  enum { DBR_TYPE_ID = DBR_CTRL_LONG };
  dbr_ctrl_long_Wrapper(boost::shared_ptr<dbr_ctrl_long> obj) : _o(obj), o(_o.get()) {}
  dbr_ctrl_long_Wrapper(dbr_ctrl_long* obj) : o(obj) {}
  bool operator==(const dbr_ctrl_long_Wrapper &t) const { return this == &t; }
  int16_t status() const { return o->status(); }
  int16_t severity() const { return o->severity(); }
  const char* units() const { return o->units(); }
  int32_t upper_disp_limit() const { return o->upper_disp_limit(); }
  int32_t lower_disp_limit() const { return o->lower_disp_limit(); }
  int32_t upper_alarm_limit() const { return o->upper_alarm_limit(); }
  int32_t upper_warning_limit() const { return o->upper_warning_limit(); }
  int32_t lower_warning_limit() const { return o->lower_warning_limit(); }
  int32_t lower_alarm_limit() const { return o->lower_alarm_limit(); }
  int32_t upper_ctrl_limit() const { return o->upper_ctrl_limit(); }
  int32_t lower_ctrl_limit() const { return o->lower_ctrl_limit(); }
  uint32_t _sizeof() const { return o->_sizeof(); }
  std::vector<int> units_shape() const { return o->units_shape(); }
private:
  int16_t	_status;
  int16_t	_severity;
  char	_units[MAX_UNITS_SIZE];
  int32_t	_upper_disp_limit;
  int32_t	_lower_disp_limit;
  int32_t	_upper_alarm_limit;
  int32_t	_upper_warning_limit;
  int32_t	_lower_warning_limit;
  int32_t	_lower_alarm_limit;
  int32_t	_upper_ctrl_limit;
  int32_t	_lower_ctrl_limit;
};

/** @class dbr_ctrl_double

  
*/


class dbr_ctrl_double_Wrapper {
  boost::shared_ptr<dbr_ctrl_double> _o;
  dbr_ctrl_double* o;
public:
  enum { DBR_TYPE_ID = DBR_CTRL_DOUBLE };
  dbr_ctrl_double_Wrapper(boost::shared_ptr<dbr_ctrl_double> obj) : _o(obj), o(_o.get()) {}
  dbr_ctrl_double_Wrapper(dbr_ctrl_double* obj) : o(obj) {}
  bool operator==(const dbr_ctrl_double_Wrapper &t) const { return this == &t; }
  int16_t status() const { return o->status(); }
  int16_t severity() const { return o->severity(); }
  int16_t precision() const { return o->precision(); }
  const char* units() const { return o->units(); }
  double upper_disp_limit() const { return o->upper_disp_limit(); }
  double lower_disp_limit() const { return o->lower_disp_limit(); }
  double upper_alarm_limit() const { return o->upper_alarm_limit(); }
  double upper_warning_limit() const { return o->upper_warning_limit(); }
  double lower_warning_limit() const { return o->lower_warning_limit(); }
  double lower_alarm_limit() const { return o->lower_alarm_limit(); }
  double upper_ctrl_limit() const { return o->upper_ctrl_limit(); }
  double lower_ctrl_limit() const { return o->lower_ctrl_limit(); }
  uint32_t _sizeof() const { return o->_sizeof(); }
  std::vector<int> units_shape() const { return o->units_shape(); }
private:
  int16_t	_status;
  int16_t	_severity;
  int16_t	_precision;
  int16_t	RISC_pad0;
  char	_units[MAX_UNITS_SIZE];
  double	_upper_disp_limit;
  double	_lower_disp_limit;
  double	_upper_alarm_limit;
  double	_upper_warning_limit;
  double	_lower_warning_limit;
  double	_lower_alarm_limit;
  double	_upper_ctrl_limit;
  double	_lower_ctrl_limit;
};

/** @class EpicsPvHeader

  Base class for EPICS data types stored in XTC files.
*/


class EpicsPvHeader_Wrapper {
  boost::shared_ptr<EpicsPvHeader> _o;
  EpicsPvHeader* o;
public:
  EpicsPvHeader_Wrapper(boost::shared_ptr<EpicsPvHeader> obj) : _o(obj), o(_o.get()) {}
  EpicsPvHeader_Wrapper(EpicsPvHeader* obj) : o(obj) {}
  bool operator==(const EpicsPvHeader_Wrapper &t) const { return this == &t; }
  int16_t pvId() const { return o->pvId(); }
  int16_t dbrType() const { return o->dbrType(); }
  int16_t numElements() const { return o->numElements(); }
  void print() const { return o->print(); }
  uint8_t isCtrl() const { return o->isCtrl(); }
  uint8_t isTime() const { return o->isTime(); }
  uint16_t status() const { return o->status(); }
  uint16_t severity() const { return o->severity(); }
};

/** @class EpicsPvCtrlHeader

  Base class for all CTRL-type PV values.
*/


class EpicsPvCtrlHeader_Wrapper {
  boost::shared_ptr<EpicsPvCtrlHeader> _o;
  EpicsPvCtrlHeader* o;
public:
  EpicsPvCtrlHeader_Wrapper(boost::shared_ptr<EpicsPvCtrlHeader> obj) : _o(obj), o(_o.get()) {}
  EpicsPvCtrlHeader_Wrapper(EpicsPvCtrlHeader* obj) : o(obj) {}
  bool operator==(const EpicsPvCtrlHeader_Wrapper &t) const { return this == &t; }
  const char* pvName() const { return o->pvName(); }
  std::vector<int> pvName_shape() const { return o->pvName_shape(); }
};

/** @class EpicsPvTimeHeader

  Base class for all TIME-type PV values.
*/


class EpicsPvTimeHeader_Wrapper {
  boost::shared_ptr<EpicsPvTimeHeader> _o;
  EpicsPvTimeHeader* o;
public:
  EpicsPvTimeHeader_Wrapper(boost::shared_ptr<EpicsPvTimeHeader> obj) : _o(obj), o(_o.get()) {}
  EpicsPvTimeHeader_Wrapper(EpicsPvTimeHeader* obj) : o(obj) {}
  bool operator==(const EpicsPvTimeHeader_Wrapper &t) const { return this == &t; }
  Epics::epicsTimeStamp stamp() const { return o->stamp(); }
};

/** @class EpicsPvCtrlString

  
*/


class EpicsPvCtrlString_Wrapper {
  boost::shared_ptr<EpicsPvCtrlString> _o;
  EpicsPvCtrlString* o;
public:
  EpicsPvCtrlString_Wrapper(boost::shared_ptr<EpicsPvCtrlString> obj) : _o(obj), o(_o.get()) {}
  EpicsPvCtrlString_Wrapper(EpicsPvCtrlString* obj) : o(obj) {}
  bool operator==(const EpicsPvCtrlString_Wrapper &t) const { return this == &t; }
  const dbr_sts_string_Wrapper dbr() const { return dbr_sts_string_Wrapper((dbr_sts_string*) &o->dbr()); }
  const char* data(uint32_t i0) const { return o->data(i0); }
  const char* value(uint32_t i) const { return o->value(i); }
  std::vector<int> data_shape() const { return o->data_shape(); }
};

/** @class EpicsPvCtrlShort

  
*/


class EpicsPvCtrlShort_Wrapper {
  boost::shared_ptr<EpicsPvCtrlShort> _o;
  EpicsPvCtrlShort* o;
public:
  EpicsPvCtrlShort_Wrapper(boost::shared_ptr<EpicsPvCtrlShort> obj) : _o(obj), o(_o.get()) {}
  EpicsPvCtrlShort_Wrapper(EpicsPvCtrlShort* obj) : o(obj) {}
  bool operator==(const EpicsPvCtrlShort_Wrapper &t) const { return this == &t; }
  const dbr_ctrl_short_Wrapper dbr() const { return dbr_ctrl_short_Wrapper((dbr_ctrl_short*) &o->dbr()); }
  std::vector<int16_t> data() const { VEC_CONVERT(o->data(), int16_t); }
  int16_t value(uint32_t i) const { return o->value(i); }
};

/** @class EpicsPvCtrlFloat

  
*/


class EpicsPvCtrlFloat_Wrapper {
  boost::shared_ptr<EpicsPvCtrlFloat> _o;
  EpicsPvCtrlFloat* o;
public:
  EpicsPvCtrlFloat_Wrapper(boost::shared_ptr<EpicsPvCtrlFloat> obj) : _o(obj), o(_o.get()) {}
  EpicsPvCtrlFloat_Wrapper(EpicsPvCtrlFloat* obj) : o(obj) {}
  bool operator==(const EpicsPvCtrlFloat_Wrapper &t) const { return this == &t; }
  const dbr_ctrl_float_Wrapper dbr() const { return dbr_ctrl_float_Wrapper((dbr_ctrl_float*) &o->dbr()); }
  std::vector<float> data() const { VEC_CONVERT(o->data(), float); }
  float value(uint32_t i) const { return o->value(i); }
};

/** @class EpicsPvCtrlEnum

  
*/


class EpicsPvCtrlEnum_Wrapper {
  boost::shared_ptr<EpicsPvCtrlEnum> _o;
  EpicsPvCtrlEnum* o;
public:
  EpicsPvCtrlEnum_Wrapper(boost::shared_ptr<EpicsPvCtrlEnum> obj) : _o(obj), o(_o.get()) {}
  EpicsPvCtrlEnum_Wrapper(EpicsPvCtrlEnum* obj) : o(obj) {}
  bool operator==(const EpicsPvCtrlEnum_Wrapper &t) const { return this == &t; }
  const dbr_ctrl_enum_Wrapper dbr() const { return dbr_ctrl_enum_Wrapper((dbr_ctrl_enum*) &o->dbr()); }
  std::vector<uint16_t> data() const { VEC_CONVERT(o->data(), uint16_t); }
  uint16_t value(uint32_t i) const { return o->value(i); }
};

/** @class EpicsPvCtrlChar

  
*/


class EpicsPvCtrlChar_Wrapper {
  boost::shared_ptr<EpicsPvCtrlChar> _o;
  EpicsPvCtrlChar* o;
public:
  EpicsPvCtrlChar_Wrapper(boost::shared_ptr<EpicsPvCtrlChar> obj) : _o(obj), o(_o.get()) {}
  EpicsPvCtrlChar_Wrapper(EpicsPvCtrlChar* obj) : o(obj) {}
  bool operator==(const EpicsPvCtrlChar_Wrapper &t) const { return this == &t; }
  const dbr_ctrl_char_Wrapper dbr() const { return dbr_ctrl_char_Wrapper((dbr_ctrl_char*) &o->dbr()); }
  std::vector<uint8_t> data() const { VEC_CONVERT(o->data(), uint8_t); }
  uint8_t value(uint32_t i) const { return o->value(i); }
};

/** @class EpicsPvCtrlLong

  
*/


class EpicsPvCtrlLong_Wrapper {
  boost::shared_ptr<EpicsPvCtrlLong> _o;
  EpicsPvCtrlLong* o;
public:
  EpicsPvCtrlLong_Wrapper(boost::shared_ptr<EpicsPvCtrlLong> obj) : _o(obj), o(_o.get()) {}
  EpicsPvCtrlLong_Wrapper(EpicsPvCtrlLong* obj) : o(obj) {}
  bool operator==(const EpicsPvCtrlLong_Wrapper &t) const { return this == &t; }
  const dbr_ctrl_long_Wrapper dbr() const { return dbr_ctrl_long_Wrapper((dbr_ctrl_long*) &o->dbr()); }
  std::vector<int32_t> data() const { VEC_CONVERT(o->data(), int32_t); }
  int32_t value(uint32_t i) const { return o->value(i); }
};

/** @class EpicsPvCtrlDouble

  
*/


class EpicsPvCtrlDouble_Wrapper {
  boost::shared_ptr<EpicsPvCtrlDouble> _o;
  EpicsPvCtrlDouble* o;
public:
  EpicsPvCtrlDouble_Wrapper(boost::shared_ptr<EpicsPvCtrlDouble> obj) : _o(obj), o(_o.get()) {}
  EpicsPvCtrlDouble_Wrapper(EpicsPvCtrlDouble* obj) : o(obj) {}
  bool operator==(const EpicsPvCtrlDouble_Wrapper &t) const { return this == &t; }
  const dbr_ctrl_double_Wrapper dbr() const { return dbr_ctrl_double_Wrapper((dbr_ctrl_double*) &o->dbr()); }
  std::vector<double> data() const { VEC_CONVERT(o->data(), double); }
  double value(uint32_t i) const { return o->value(i); }
};

/** @class EpicsPvTimeString

  
*/


class EpicsPvTimeString_Wrapper {
  boost::shared_ptr<EpicsPvTimeString> _o;
  EpicsPvTimeString* o;
public:
  EpicsPvTimeString_Wrapper(boost::shared_ptr<EpicsPvTimeString> obj) : _o(obj), o(_o.get()) {}
  EpicsPvTimeString_Wrapper(EpicsPvTimeString* obj) : o(obj) {}
  bool operator==(const EpicsPvTimeString_Wrapper &t) const { return this == &t; }
  const dbr_time_string_Wrapper dbr() const { return dbr_time_string_Wrapper((dbr_time_string*) &o->dbr()); }
  const char* data(uint32_t i0) const { return o->data(i0); }
  const char* value(uint32_t i) const { return o->value(i); }
  std::vector<int> data_shape() const { return o->data_shape(); }
};

/** @class EpicsPvTimeShort

  
*/


class EpicsPvTimeShort_Wrapper {
  boost::shared_ptr<EpicsPvTimeShort> _o;
  EpicsPvTimeShort* o;
public:
  EpicsPvTimeShort_Wrapper(boost::shared_ptr<EpicsPvTimeShort> obj) : _o(obj), o(_o.get()) {}
  EpicsPvTimeShort_Wrapper(EpicsPvTimeShort* obj) : o(obj) {}
  bool operator==(const EpicsPvTimeShort_Wrapper &t) const { return this == &t; }
  const dbr_time_short_Wrapper dbr() const { return dbr_time_short_Wrapper((dbr_time_short*) &o->dbr()); }
  std::vector<int16_t> data() const { VEC_CONVERT(o->data(), int16_t); }
  int16_t value(uint32_t i) const { return o->value(i); }
};

/** @class EpicsPvTimeFloat

  
*/


class EpicsPvTimeFloat_Wrapper {
  boost::shared_ptr<EpicsPvTimeFloat> _o;
  EpicsPvTimeFloat* o;
public:
  EpicsPvTimeFloat_Wrapper(boost::shared_ptr<EpicsPvTimeFloat> obj) : _o(obj), o(_o.get()) {}
  EpicsPvTimeFloat_Wrapper(EpicsPvTimeFloat* obj) : o(obj) {}
  bool operator==(const EpicsPvTimeFloat_Wrapper &t) const { return this == &t; }
  const dbr_time_float_Wrapper dbr() const { return dbr_time_float_Wrapper((dbr_time_float*) &o->dbr()); }
  std::vector<float> data() const { VEC_CONVERT(o->data(), float); }
  float value(uint32_t i) const { return o->value(i); }
};

/** @class EpicsPvTimeEnum

  
*/


class EpicsPvTimeEnum_Wrapper {
  boost::shared_ptr<EpicsPvTimeEnum> _o;
  EpicsPvTimeEnum* o;
public:
  EpicsPvTimeEnum_Wrapper(boost::shared_ptr<EpicsPvTimeEnum> obj) : _o(obj), o(_o.get()) {}
  EpicsPvTimeEnum_Wrapper(EpicsPvTimeEnum* obj) : o(obj) {}
  bool operator==(const EpicsPvTimeEnum_Wrapper &t) const { return this == &t; }
  const dbr_time_enum_Wrapper dbr() const { return dbr_time_enum_Wrapper((dbr_time_enum*) &o->dbr()); }
  std::vector<uint16_t> data() const { VEC_CONVERT(o->data(), uint16_t); }
  uint16_t value(uint32_t i) const { return o->value(i); }
};

/** @class EpicsPvTimeChar

  
*/


class EpicsPvTimeChar_Wrapper {
  boost::shared_ptr<EpicsPvTimeChar> _o;
  EpicsPvTimeChar* o;
public:
  EpicsPvTimeChar_Wrapper(boost::shared_ptr<EpicsPvTimeChar> obj) : _o(obj), o(_o.get()) {}
  EpicsPvTimeChar_Wrapper(EpicsPvTimeChar* obj) : o(obj) {}
  bool operator==(const EpicsPvTimeChar_Wrapper &t) const { return this == &t; }
  const dbr_time_char_Wrapper dbr() const { return dbr_time_char_Wrapper((dbr_time_char*) &o->dbr()); }
  std::vector<uint8_t> data() const { VEC_CONVERT(o->data(), uint8_t); }
  uint8_t value(uint32_t i) const { return o->value(i); }
};

/** @class EpicsPvTimeLong

  
*/


class EpicsPvTimeLong_Wrapper {
  boost::shared_ptr<EpicsPvTimeLong> _o;
  EpicsPvTimeLong* o;
public:
  EpicsPvTimeLong_Wrapper(boost::shared_ptr<EpicsPvTimeLong> obj) : _o(obj), o(_o.get()) {}
  EpicsPvTimeLong_Wrapper(EpicsPvTimeLong* obj) : o(obj) {}
  bool operator==(const EpicsPvTimeLong_Wrapper &t) const { return this == &t; }
  const dbr_time_long_Wrapper dbr() const { return dbr_time_long_Wrapper((dbr_time_long*) &o->dbr()); }
  std::vector<int32_t> data() const { VEC_CONVERT(o->data(), int32_t); }
  int32_t value(uint32_t i) const { return o->value(i); }
};

/** @class EpicsPvTimeDouble

  
*/


class EpicsPvTimeDouble_Wrapper {
  boost::shared_ptr<EpicsPvTimeDouble> _o;
  EpicsPvTimeDouble* o;
public:
  EpicsPvTimeDouble_Wrapper(boost::shared_ptr<EpicsPvTimeDouble> obj) : _o(obj), o(_o.get()) {}
  EpicsPvTimeDouble_Wrapper(EpicsPvTimeDouble* obj) : o(obj) {}
  bool operator==(const EpicsPvTimeDouble_Wrapper &t) const { return this == &t; }
  const dbr_time_double_Wrapper dbr() const { return dbr_time_double_Wrapper((dbr_time_double*) &o->dbr()); }
  std::vector<double> data() const { VEC_CONVERT(o->data(), double); }
  double value(uint32_t i) const { return o->value(i); }
};

/** @class PvConfigV1

  
*/


class PvConfigV1_Wrapper {
  boost::shared_ptr<PvConfigV1> _o;
  PvConfigV1* o;
public:
  enum { iMaxPvDescLength = 64 };
  PvConfigV1_Wrapper(boost::shared_ptr<PvConfigV1> obj) : _o(obj), o(_o.get()) {}
  PvConfigV1_Wrapper(PvConfigV1* obj) : o(obj) {}
  bool operator==(const PvConfigV1_Wrapper &t) const { return this == &t; }
  int16_t pvId() const { return o->pvId(); }
  const char* description() const { return o->description(); }
  float interval() const { return o->interval(); }
};

/** @class ConfigV1

  
*/


class ConfigV1_Wrapper {
  boost::shared_ptr<ConfigV1> _o;
  ConfigV1* o;
public:
  enum { TypeId = Pds::TypeId::Id_EpicsConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  ConfigV1_Wrapper(boost::shared_ptr<ConfigV1> obj) : _o(obj), o(_o.get()) {}
  ConfigV1_Wrapper(ConfigV1* obj) : o(obj) {}
  bool operator==(const ConfigV1_Wrapper &t) const { return this == &t; }
  int32_t numPv() const { return o->numPv(); }
  const PvConfigV1_Wrapper pvControls(uint32_t i0) const { return PvConfigV1_Wrapper((PvConfigV1*) &o->pvControls(i0)); }
  std::vector<int> pvControls_shape() const { return o->pvControls_shape(); }
};

  class ConfigV1_EnvGetter : public Psana::EnvGetter {
  public:
    std::string getTypeName() {
      return "Psana::Epics::ConfigV1";
    }
    boost::python::api::object get(PSEnv::EnvObjectStore& store, const PSEvt::Source& src) {
      return boost::python::api::object(ConfigV1_Wrapper(store.get(src, 0)));
    }
  };
} // namespace Epics
} // namespace Psana
#endif // PSANA_EPICS_DDL_WRAPPER_H
