#ifndef PSANA_PRINCETON_DDL_WRAPPER_H
#define PSANA_PRINCETON_DDL_WRAPPER_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include "ndarray/ndarray.h"
#include "pdsdata/xtc/TypeId.hh"
#include "psddl_pypsana/PyWrapper.h"
namespace Psana {
namespace Princeton {

extern void createWrappers();


/** @class ConfigV1

  
*/


class ConfigV1_Wrapper {
  boost::shared_ptr<ConfigV1> _o;
  ConfigV1* o;
public:
  enum { TypeId = Pds::TypeId::Id_PrincetonConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  ConfigV1_Wrapper(boost::shared_ptr<ConfigV1> obj) : _o(obj), o(_o.get()) {}
  ConfigV1_Wrapper(ConfigV1* obj) : o(obj) {}
  uint32_t width() const { return o->width(); }
  uint32_t height() const { return o->height(); }
  uint32_t orgX() const { return o->orgX(); }
  uint32_t orgY() const { return o->orgY(); }
  uint32_t binX() const { return o->binX(); }
  uint32_t binY() const { return o->binY(); }
  float exposureTime() const { return o->exposureTime(); }
  float coolingTemp() const { return o->coolingTemp(); }
  uint32_t readoutSpeedIndex() const { return o->readoutSpeedIndex(); }
  uint16_t readoutEventCode() const { return o->readoutEventCode(); }
  uint16_t delayMode() const { return o->delayMode(); }
  uint32_t frameSize() const { return o->frameSize(); }
  uint32_t numPixelsX() const { return o->numPixelsX(); }
  uint32_t numPixelsY() const { return o->numPixelsY(); }
  uint32_t numPixels() const { return o->numPixels(); }
};

/** @class ConfigV2

  
*/


class ConfigV2_Wrapper {
  boost::shared_ptr<ConfigV2> _o;
  ConfigV2* o;
public:
  enum { TypeId = Pds::TypeId::Id_PrincetonConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 2 /**< XTC type version number */ };
  ConfigV2_Wrapper(boost::shared_ptr<ConfigV2> obj) : _o(obj), o(_o.get()) {}
  ConfigV2_Wrapper(ConfigV2* obj) : o(obj) {}
  uint32_t width() const { return o->width(); }
  uint32_t height() const { return o->height(); }
  uint32_t orgX() const { return o->orgX(); }
  uint32_t orgY() const { return o->orgY(); }
  uint32_t binX() const { return o->binX(); }
  uint32_t binY() const { return o->binY(); }
  float exposureTime() const { return o->exposureTime(); }
  float coolingTemp() const { return o->coolingTemp(); }
  uint16_t gainIndex() const { return o->gainIndex(); }
  uint16_t readoutSpeedIndex() const { return o->readoutSpeedIndex(); }
  uint16_t readoutEventCode() const { return o->readoutEventCode(); }
  uint16_t delayMode() const { return o->delayMode(); }
  uint32_t frameSize() const { return o->frameSize(); }
  uint32_t numPixelsX() const { return o->numPixelsX(); }
  uint32_t numPixelsY() const { return o->numPixelsY(); }
  uint32_t numPixels() const { return o->numPixels(); }
};

/** @class ConfigV3

  
*/


class ConfigV3_Wrapper {
  boost::shared_ptr<ConfigV3> _o;
  ConfigV3* o;
public:
  enum { TypeId = Pds::TypeId::Id_PrincetonConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 3 /**< XTC type version number */ };
  ConfigV3_Wrapper(boost::shared_ptr<ConfigV3> obj) : _o(obj), o(_o.get()) {}
  ConfigV3_Wrapper(ConfigV3* obj) : o(obj) {}
  uint32_t width() const { return o->width(); }
  uint32_t height() const { return o->height(); }
  uint32_t orgX() const { return o->orgX(); }
  uint32_t orgY() const { return o->orgY(); }
  uint32_t binX() const { return o->binX(); }
  uint32_t binY() const { return o->binY(); }
  float exposureTime() const { return o->exposureTime(); }
  float coolingTemp() const { return o->coolingTemp(); }
  uint8_t gainIndex() const { return o->gainIndex(); }
  uint8_t readoutSpeedIndex() const { return o->readoutSpeedIndex(); }
  uint16_t exposureEventCode() const { return o->exposureEventCode(); }
  uint32_t numDelayShots() const { return o->numDelayShots(); }
  uint32_t frameSize() const { return o->frameSize(); }
  uint32_t numPixelsX() const { return o->numPixelsX(); }
  uint32_t numPixelsY() const { return o->numPixelsY(); }
  uint32_t numPixels() const { return o->numPixels(); }
};

/** @class FrameV1

  
*/

class ConfigV1;
class ConfigV2;
class ConfigV3;

class FrameV1_Wrapper {
  boost::shared_ptr<FrameV1> _o;
  FrameV1* o;
public:
  enum { TypeId = Pds::TypeId::Id_PrincetonFrame /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  FrameV1_Wrapper(boost::shared_ptr<FrameV1> obj) : _o(obj), o(_o.get()) {}
  FrameV1_Wrapper(FrameV1* obj) : o(obj) {}
  uint32_t shotIdStart() const { return o->shotIdStart(); }
  float readoutTime() const { return o->readoutTime(); }
  PyObject* data() const { ND_CONVERT(o->data(), uint16_t, 2); }
};

/** @class InfoV1

  
*/


class InfoV1_Wrapper {
  boost::shared_ptr<InfoV1> _o;
  InfoV1* o;
public:
  enum { TypeId = Pds::TypeId::Id_PrincetonInfo /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  InfoV1_Wrapper(boost::shared_ptr<InfoV1> obj) : _o(obj), o(_o.get()) {}
  InfoV1_Wrapper(InfoV1* obj) : o(obj) {}
  float temperature() const { return o->temperature(); }
  uint32_t _sizeof() const { return o->_sizeof(); }
private:
  float	_fTemperature;
};

  class ConfigV1_EnvGetter : public Psana::EnvGetter {
  public:
    std::string getTypeName() {
      return "Psana::Princeton::ConfigV1";
    }
    boost::python::api::object get(PSEnv::EnvObjectStore& store, const PSEvt::Source& src) {
      return boost::python::api::object(ConfigV1_Wrapper(store.get(src, 0)));
    }
  };

  class ConfigV2_EnvGetter : public Psana::EnvGetter {
  public:
    std::string getTypeName() {
      return "Psana::Princeton::ConfigV2";
    }
    boost::python::api::object get(PSEnv::EnvObjectStore& store, const PSEvt::Source& src) {
      return boost::python::api::object(ConfigV2_Wrapper(store.get(src, 0)));
    }
  };

  class ConfigV3_EnvGetter : public Psana::EnvGetter {
  public:
    std::string getTypeName() {
      return "Psana::Princeton::ConfigV3";
    }
    boost::python::api::object get(PSEnv::EnvObjectStore& store, const PSEvt::Source& src) {
      return boost::python::api::object(ConfigV3_Wrapper(store.get(src, 0)));
    }
  };
} // namespace Princeton
} // namespace Psana
#endif // PSANA_PRINCETON_DDL_WRAPPER_H
