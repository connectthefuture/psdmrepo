#ifndef PSANA_CONTROL_DDL_WRAPPER_H
#define PSANA_CONTROL_DDL_WRAPPER_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include <ndarray/ndarray.h>
#include <pdsdata/xtc/TypeId.hh>
#include <psddl_python/DdlWrapper.h>
#include <pdsdata/xtc/ClockTime.hh> // other included packages
namespace Psana {
  using boost::python::api::object;
  using boost::shared_ptr;
  using std::vector;
namespace ControlData {

extern void createWrappers();


/** @class PVControl

  
*/

#pragma pack(push,4)

class PVControl_Wrapper {
  shared_ptr<PVControl> _o;
  PVControl* o;
public:
  enum { NameSize = 32 /**< Length of the name array. */ };
  enum { NoArray = 0xFFFFFFFF /**< Special value used for _index when PV is not an array */ };
  PVControl_Wrapper(shared_ptr<PVControl> obj) : _o(obj), o(_o.get()) {}
  PVControl_Wrapper(PVControl* obj) : o(obj) {}
  const char* name() const { return o->name(); }
  uint32_t index() const { return o->index(); }
  double value() const { return o->value(); }
  uint8_t array() const { return o->array(); }
  uint32_t _sizeof() const { return o->_sizeof(); }
};
#pragma pack(pop)

/** @class PVMonitor

  
*/

#pragma pack(push,4)

class PVMonitor_Wrapper {
  shared_ptr<PVMonitor> _o;
  PVMonitor* o;
public:
  enum { NameSize = 32 /**< Length of the name array. */ };
  enum { NoArray = 0xFFFFFFFF /**< Special value used for _index when PV is not an array */ };
  PVMonitor_Wrapper(shared_ptr<PVMonitor> obj) : _o(obj), o(_o.get()) {}
  PVMonitor_Wrapper(PVMonitor* obj) : o(obj) {}
  const char* name() const { return o->name(); }
  uint32_t index() const { return o->index(); }
  double loValue() const { return o->loValue(); }
  double hiValue() const { return o->hiValue(); }
  uint8_t array() const { return o->array(); }
  uint32_t _sizeof() const { return o->_sizeof(); }
};
#pragma pack(pop)

/** @class ConfigV1

  
*/


class ConfigV1_Wrapper {
  shared_ptr<ConfigV1> _o;
  ConfigV1* o;
public:
  enum { TypeId = Pds::TypeId::Id_ControlConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  ConfigV1_Wrapper(shared_ptr<ConfigV1> obj) : _o(obj), o(_o.get()) {}
  ConfigV1_Wrapper(ConfigV1* obj) : o(obj) {}
  uint32_t events() const { return o->events(); }
  uint8_t uses_duration() const { return o->uses_duration(); }
  uint8_t uses_events() const { return o->uses_events(); }
  const Pds::ClockTime& duration() const { return o->duration(); }
  uint32_t npvControls() const { return o->npvControls(); }
  uint32_t npvMonitors() const { return o->npvMonitors(); }
  vector<ControlData::PVControl> pvControls() const { VEC_CONVERT(o->pvControls(), ControlData::PVControl); }
  vector<ControlData::PVMonitor> pvMonitors() const { VEC_CONVERT(o->pvMonitors(), ControlData::PVMonitor); }
};

  class ConfigV1_Getter : public Psana::EnvGetter {
  public:
    const std::type_info& getTypeInfo() {
      return typeid(Psana::ControlData::ConfigV1);
    }
    const char* getTypeName() {
      return "Psana::ControlData::ConfigV1";
    }
    int getTypeId() {
      return ConfigV1::TypeId;
    }
    int getVersion() {
      return ConfigV1::Version;
    }
    object get(PSEnv::EnvObjectStore& store, const PSEvt::Source& src, Pds::Src* foundSrc=0) {
      boost::shared_ptr<ConfigV1> result = store.get(src, 0);
      return result.get() ? object(ConfigV1_Wrapper(result)) : object();
    }
  };
} // namespace ControlData
} // namespace Psana
#endif // PSANA_CONTROL_DDL_WRAPPER_H
