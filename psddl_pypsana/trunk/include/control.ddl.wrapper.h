#ifndef PSANA_CONTROL_DDL_WRAPPER_H
#define PSANA_CONTROL_DDL_WRAPPER_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include "ndarray/ndarray.h"
#include "pdsdata/xtc/TypeId.hh"
#include "psddl_pyana/DdlWrapper.h"
#include "pdsdata/xtc/ClockTime.hh"
namespace Psana {
namespace ControlData {

extern void createWrappers();


/** @class PVControl

  
*/

#pragma pack(push,4)

class PVControl_Wrapper {
  boost::shared_ptr<PVControl> _o;
  PVControl* o;
public:
  enum { NameSize = 32 /**< Length of the name array. */ };
  enum { NoArray = 0xFFFFFFFF /**< Special value used for _index when PV is not an array */ };
  PVControl_Wrapper(boost::shared_ptr<PVControl> obj) : _o(obj), o(_o.get()) {}
  PVControl_Wrapper(PVControl* obj) : o(obj) {}
  bool operator==(const PVControl_Wrapper &t) const { return this == &t; }
  const char* name() const { return o->name(); }
  uint32_t index() const { return o->index(); }
  double value() const { return o->value(); }
  uint8_t array() const { return o->array(); }
  uint32_t _sizeof() const { return o->_sizeof(); }
private:
  char	_name[32];	/**< Name of the control. */
  uint32_t	_index;	/**< Index of the control PV (for arrays) or NoArray. */
  double	_value;	/**< Value for this control. */
};
#pragma pack(pop)

/** @class PVMonitor

  
*/

#pragma pack(push,4)

class PVMonitor_Wrapper {
  boost::shared_ptr<PVMonitor> _o;
  PVMonitor* o;
public:
  enum { NameSize = 32 /**< Length of the name array. */ };
  enum { NoArray = 0xFFFFFFFF /**< Special value used for _index when PV is not an array */ };
  PVMonitor_Wrapper(boost::shared_ptr<PVMonitor> obj) : _o(obj), o(_o.get()) {}
  PVMonitor_Wrapper(PVMonitor* obj) : o(obj) {}
  bool operator==(const PVMonitor_Wrapper &t) const { return this == &t; }
  const char* name() const { return o->name(); }
  uint32_t index() const { return o->index(); }
  double loValue() const { return o->loValue(); }
  double hiValue() const { return o->hiValue(); }
  uint8_t array() const { return o->array(); }
  uint32_t _sizeof() const { return o->_sizeof(); }
private:
  char	_name[32];	/**< Name of the control. */
  uint32_t	_index;	/**< Index of the control PV (for arrays) or NoArray. */
  double	_loValue;	/**< Lowest value for this monitor. */
  double	_hiValue;	/**< Highest value for this monitor. */
};
#pragma pack(pop)

/** @class ConfigV1

  
*/


class ConfigV1_Wrapper {
  boost::shared_ptr<ConfigV1> _o;
  ConfigV1* o;
public:
  enum { TypeId = Pds::TypeId::Id_ControlConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  ConfigV1_Wrapper(boost::shared_ptr<ConfigV1> obj) : _o(obj), o(_o.get()) {}
  ConfigV1_Wrapper(ConfigV1* obj) : o(obj) {}
  bool operator==(const ConfigV1_Wrapper &t) const { return this == &t; }
  uint32_t events() const { return o->events(); }
  uint8_t uses_duration() const { return o->uses_duration(); }
  uint8_t uses_events() const { return o->uses_events(); }
  const Pds::ClockTime* duration() const { return &o->duration(); }
  uint32_t npvControls() const { return o->npvControls(); }
  uint32_t npvMonitors() const { return o->npvMonitors(); }
  std::vector<ControlData::PVControl> pvControls() const { VEC_CONVERT(o->pvControls(), ControlData::PVControl); }
  std::vector<ControlData::PVMonitor> pvMonitors() const { VEC_CONVERT(o->pvMonitors(), ControlData::PVMonitor); }
};

  class ConfigV1_Getter : public Psana::EnvGetter {
  public:
    const char* getTypeName() {
      return "Psana::ControlData::ConfigV1";
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
} // namespace ControlData
} // namespace Psana
#endif // PSANA_CONTROL_DDL_WRAPPER_H
