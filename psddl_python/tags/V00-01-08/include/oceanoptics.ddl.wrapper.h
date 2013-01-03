/* Do not edit this file, as it is auto-generated */

#ifndef PSDDL_PYTHON_OCEANOPTICS_DDL_WRAPPER_H
#define PSDDL_PYTHON_OCEANOPTICS_DDL_WRAPPER_H 1

#include <psddl_python/DdlWrapper.h>
#include <vector>
#include <ndarray/ndarray.h>
#include <pdsdata/xtc/TypeId.hh>
#include <psddl_psana/oceanoptics.ddl.h> // inc_psana

namespace psddl_python {
namespace OceanOptics {

using namespace boost::python;
using boost::python::api::object;
using boost::shared_ptr;
using std::vector;

extern void createWrappers();

class ConfigV1_Wrapper {
  shared_ptr<Psana::OceanOptics::ConfigV1> _o;
  Psana::OceanOptics::ConfigV1* o;
public:
  enum { TypeId = Pds::TypeId::Id_OceanOpticsConfig };
  enum { Version = 1 };
  ConfigV1_Wrapper(shared_ptr<Psana::OceanOptics::ConfigV1> obj) : _o(obj), o(_o.get()) {}
  ConfigV1_Wrapper(Psana::OceanOptics::ConfigV1* obj) : o(obj) {}
  float exposureTime() const { return o->exposureTime(); }
  PyObject* waveLenCalib() const { ND_CONVERT(o->waveLenCalib(), double, 1); }
  PyObject* nonlinCorrect() const { ND_CONVERT(o->nonlinCorrect(), double, 1); }
  double strayLightConstant() const { return o->strayLightConstant(); }
};

class timespec64_Wrapper {
  shared_ptr<Psana::OceanOptics::timespec64> _o;
  Psana::OceanOptics::timespec64* o;
public:
  timespec64_Wrapper(shared_ptr<Psana::OceanOptics::timespec64> obj) : _o(obj), o(_o.get()) {}
  timespec64_Wrapper(Psana::OceanOptics::timespec64* obj) : o(obj) {}
  uint64_t tv_sec() const { return o->tv_sec(); }
  uint64_t tv_nsec() const { return o->tv_nsec(); }
  uint32_t _sizeof() const { return o->_sizeof(); }
};
class ConfigV1;

class DataV1_Wrapper {
  shared_ptr<Psana::OceanOptics::DataV1> _o;
  Psana::OceanOptics::DataV1* o;
public:
  enum { TypeId = Pds::TypeId::Id_OceanOpticsData };
  enum { Version = 1 };
  DataV1_Wrapper(shared_ptr<Psana::OceanOptics::DataV1> obj) : _o(obj), o(_o.get()) {}
  DataV1_Wrapper(Psana::OceanOptics::DataV1* obj) : o(obj) {}
  PyObject* data() const { ND_CONVERT(o->data(), uint16_t, 1); }
  uint64_t frameCounter() const { return o->frameCounter(); }
  uint64_t numDelayedFrames() const { return o->numDelayedFrames(); }
  uint64_t numDiscardFrames() const { return o->numDiscardFrames(); }
  const timespec64_Wrapper timeFrameStart() const { return timespec64_Wrapper(const_cast<Psana::OceanOptics::timespec64*>(&o->timeFrameStart())); }
  const timespec64_Wrapper timeFrameFirstData() const { return timespec64_Wrapper(const_cast<Psana::OceanOptics::timespec64*>(&o->timeFrameFirstData())); }
  const timespec64_Wrapper timeFrameEnd() const { return timespec64_Wrapper(const_cast<Psana::OceanOptics::timespec64*>(&o->timeFrameEnd())); }
  int32_t version() const { return o->version(); }
  int8_t numSpectraInData() const { return o->numSpectraInData(); }
  int8_t numSpectraInQueue() const { return o->numSpectraInQueue(); }
  int8_t numSpectraUnused() const { return o->numSpectraUnused(); }
  double durationOfFrame() const { return o->durationOfFrame(); }
  double nonlinerCorrected(uint32_t iPixel) const { return o->nonlinerCorrected(iPixel); }
};

  class ConfigV1_Getter : public psddl_python::EnvObjectStoreGetter {
  public:
  const char* getTypeName() { return "Psana::OceanOptics::ConfigV1";}
  const char* getGetterClassName() { return "psddl_python::EnvObjectStoreGetter";}
    int getVersion() {
      return Psana::OceanOptics::ConfigV1::Version;
    }
    object get(PSEnv::EnvObjectStore& store, const PSEvt::Source& source, Pds::Src* foundSrc) {
      boost::shared_ptr<Psana::OceanOptics::ConfigV1> result = store.get(source, foundSrc);
      return result.get() ? object(ConfigV1_Wrapper(result)) : object();
    }
  };

  class timespec64_Getter : public psddl_python::EventGetter {
  public:
  const char* getTypeName() { return "Psana::OceanOptics::timespec64";}
  const char* getGetterClassName() { return "psddl_python::EventGetter";}
    object get(PSEvt::Event& evt, PSEvt::Source& source, const std::string& key, Pds::Src* foundSrc) {
      shared_ptr<Psana::OceanOptics::timespec64> result = evt.get(source, key, foundSrc);
      return result.get() ? object(timespec64_Wrapper(result)) : object();
    }
  };

  class DataV1_Getter : public psddl_python::EventGetter {
  public:
  const char* getTypeName() { return "Psana::OceanOptics::DataV1";}
  const char* getGetterClassName() { return "psddl_python::EventGetter";}
    int getVersion() {
      return Psana::OceanOptics::DataV1::Version;
    }
    object get(PSEvt::Event& evt, PSEvt::Source& source, const std::string& key, Pds::Src* foundSrc) {
      shared_ptr<Psana::OceanOptics::DataV1> result = evt.get(source, key, foundSrc);
      return result.get() ? object(DataV1_Wrapper(result)) : object();
    }
  };
} // namespace OceanOptics
} // namespace psddl_python
#endif // PSDDL_PYTHON_OCEANOPTICS_DDL_WRAPPER_H
