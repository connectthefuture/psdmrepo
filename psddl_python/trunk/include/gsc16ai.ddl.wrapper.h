#ifndef PSANA_GSC16AI_DDL_WRAPPER_H
#define PSANA_GSC16AI_DDL_WRAPPER_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include <ndarray/ndarray.h>
#include <pdsdata/xtc/TypeId.hh>
#include <psddl_python/DdlWrapper.h>
namespace Psana {
namespace Gsc16ai {

extern void createWrappers();


/** @class ConfigV1

  
*/


class ConfigV1_Wrapper {
  boost::shared_ptr<ConfigV1> _o;
  ConfigV1* o;
public:
  enum { TypeId = Pds::TypeId::Id_Gsc16aiConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  enum { LowestChannel = 0 };
  enum { HighestChannel = 15 };
  enum { LowestFps = 1 };
  enum { HighestFps = 120 };
  enum InputMode {
    InputMode_Differential = 0,
    InputMode_Zero = 1,
    InputMode_Vref = 2,
  };
  enum VoltageRange {
    VoltageRange_10V = 0,
    VoltageRange_5V,
    VoltageRange_2_5V,
  };
  enum TriggerMode {
    TriggerMode_ExtPos = 0,
    TriggerMode_ExtNeg,
    TriggerMode_IntClk,
  };
  enum DataFormat {
    DataFormat_TwosComplement = 0,
    DataFormat_OffsetBinary,
  };
  ConfigV1_Wrapper(boost::shared_ptr<ConfigV1> obj) : _o(obj), o(_o.get()) {}
  ConfigV1_Wrapper(ConfigV1* obj) : o(obj) {}
  bool operator==(const ConfigV1_Wrapper &t) const { return this == &t; }
  uint16_t voltageRange() const { return o->voltageRange(); }
  uint16_t firstChan() const { return o->firstChan(); }
  uint16_t lastChan() const { return o->lastChan(); }
  uint16_t inputMode() const { return o->inputMode(); }
  uint16_t triggerMode() const { return o->triggerMode(); }
  uint16_t dataFormat() const { return o->dataFormat(); }
  uint16_t fps() const { return o->fps(); }
  uint8_t autocalibEnable() const { return o->autocalibEnable(); }
  uint8_t timeTagEnable() const { return o->timeTagEnable(); }
  uint16_t numChannels() const { return o->numChannels(); }
};

/** @class DataV1

  
*/

class ConfigV1;

class DataV1_Wrapper {
  boost::shared_ptr<DataV1> _o;
  DataV1* o;
public:
  enum { TypeId = Pds::TypeId::Id_Gsc16aiData /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  DataV1_Wrapper(boost::shared_ptr<DataV1> obj) : _o(obj), o(_o.get()) {}
  DataV1_Wrapper(DataV1* obj) : o(obj) {}
  bool operator==(const DataV1_Wrapper &t) const { return this == &t; }
  std::vector<uint16_t> timestamp() const { VEC_CONVERT(o->timestamp(), uint16_t); }
  std::vector<uint16_t> channelValue() const { VEC_CONVERT(o->channelValue(), uint16_t); }
};

  class ConfigV1_Getter : public Psana::EnvGetter {
  public:
    const char* getTypeName() {
      return "Psana::Gsc16ai::ConfigV1";
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

  class DataV1_Getter : public Psana::EvtGetter {
  public:
    const char* getTypeName() {
      return "Psana::Gsc16ai::DataV1";
    }
    int getTypeId() {
      return DataV1::TypeId;
    }
    int getVersion() {
      return DataV1::Version;
    }
    boost::python::api::object get(PSEvt::Event& evt, const std::string& key=std::string(), Pds::Src* foundSrc=0) {
      return boost::python::api::object(DataV1_Wrapper(evt.get(key, foundSrc)));
    }
    boost::python::api::object get(PSEvt::Event& evt, Pds::Src& src, const std::string& key=std::string(), Pds::Src* foundSrc=0) {
      return boost::python::api::object(DataV1_Wrapper(evt.get(src, key, foundSrc)));
    }
    boost::python::api::object get(PSEvt::Event& evt, PSEvt::Source& source, const std::string& key=std::string(), Pds::Src* foundSrc=0) {
      return boost::python::api::object(DataV1_Wrapper(evt.get(source, key, foundSrc)));
    }
  };
} // namespace Gsc16ai
} // namespace Psana
#endif // PSANA_GSC16AI_DDL_WRAPPER_H
