#ifndef PSANA_PNCCD_DDL_WRAPPER_H
#define PSANA_PNCCD_DDL_WRAPPER_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include <ndarray/ndarray.h>
#include <pdsdata/xtc/TypeId.hh>
#include <psddl_python/DdlWrapper.h>
namespace Psana {
namespace PNCCD {

extern void createWrappers();


/** @class ConfigV1

  pnCCD configuration class ConfigV1
*/


class ConfigV1_Wrapper {
  boost::shared_ptr<ConfigV1> _o;
  ConfigV1* o;
public:
  enum { TypeId = Pds::TypeId::Id_pnCCDconfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  ConfigV1_Wrapper(boost::shared_ptr<ConfigV1> obj) : _o(obj), o(_o.get()) {}
  ConfigV1_Wrapper(ConfigV1* obj) : o(obj) {}
  bool operator==(const ConfigV1_Wrapper &t) const { return this == &t; }
  uint32_t numLinks() const { return o->numLinks(); }
  uint32_t payloadSizePerLink() const { return o->payloadSizePerLink(); }
};

/** @class ConfigV2

  pnCCD configuration class ConfigV2
*/


class ConfigV2_Wrapper {
  boost::shared_ptr<ConfigV2> _o;
  ConfigV2* o;
public:
  enum { TypeId = Pds::TypeId::Id_pnCCDconfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 2 /**< XTC type version number */ };
  ConfigV2_Wrapper(boost::shared_ptr<ConfigV2> obj) : _o(obj), o(_o.get()) {}
  ConfigV2_Wrapper(ConfigV2* obj) : o(obj) {}
  bool operator==(const ConfigV2_Wrapper &t) const { return this == &t; }
  uint32_t numLinks() const { return o->numLinks(); }
  uint32_t payloadSizePerLink() const { return o->payloadSizePerLink(); }
  uint32_t numChannels() const { return o->numChannels(); }
  uint32_t numRows() const { return o->numRows(); }
  uint32_t numSubmoduleChannels() const { return o->numSubmoduleChannels(); }
  uint32_t numSubmoduleRows() const { return o->numSubmoduleRows(); }
  uint32_t numSubmodules() const { return o->numSubmodules(); }
  uint32_t camexMagic() const { return o->camexMagic(); }
  const char* info() const { return o->info(); }
  const char* timingFName() const { return o->timingFName(); }
  std::vector<int> info_shape() const { return o->info_shape(); }
  std::vector<int> timingFName_shape() const { return o->timingFName_shape(); }
};

/** @class FrameV1

  pnCCD configuration class FrameV1
*/

class ConfigV1;
class ConfigV2;

class FrameV1_Wrapper {
  boost::shared_ptr<FrameV1> _o;
  FrameV1* o;
public:
  enum { TypeId = Pds::TypeId::Id_pnCCDframe /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  FrameV1_Wrapper(boost::shared_ptr<FrameV1> obj) : _o(obj), o(_o.get()) {}
  FrameV1_Wrapper(FrameV1* obj) : o(obj) {}
  bool operator==(const FrameV1_Wrapper &t) const { return this == &t; }
  uint32_t specialWord() const { return o->specialWord(); }
  uint32_t frameNumber() const { return o->frameNumber(); }
  uint32_t timeStampHi() const { return o->timeStampHi(); }
  uint32_t timeStampLo() const { return o->timeStampLo(); }
  std::vector<uint16_t> data() const { VEC_CONVERT(o->data(), uint16_t); }
};

  class ConfigV1_Getter : public Psana::EnvGetter {
  public:
    const char* getTypeName() {
      return "Psana::PNCCD::ConfigV1";
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
      return "Psana::PNCCD::ConfigV2";
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
} // namespace PNCCD
} // namespace Psana
#endif // PSANA_PNCCD_DDL_WRAPPER_H
