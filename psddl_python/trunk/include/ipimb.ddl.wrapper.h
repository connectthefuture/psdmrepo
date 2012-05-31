#ifndef PSANA_IPIMB_DDL_WRAPPER_H
#define PSANA_IPIMB_DDL_WRAPPER_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include <ndarray/ndarray.h>
#include <pdsdata/xtc/TypeId.hh>
#include <psddl_pyana/DdlWrapper.h>
namespace Psana {
namespace Ipimb {

extern void createWrappers();


/** @class ConfigV1

  
*/


class ConfigV1_Wrapper {
  boost::shared_ptr<ConfigV1> _o;
  ConfigV1* o;
public:
  enum { TypeId = Pds::TypeId::Id_IpimbConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  enum CapacitorValue {
    c_1pF,
    c_100pF,
    c_10nF,
  };
  ConfigV1_Wrapper(boost::shared_ptr<ConfigV1> obj) : _o(obj), o(_o.get()) {}
  ConfigV1_Wrapper(ConfigV1* obj) : o(obj) {}
  bool operator==(const ConfigV1_Wrapper &t) const { return this == &t; }
  uint64_t triggerCounter() const { return o->triggerCounter(); }
  uint64_t serialID() const { return o->serialID(); }
  uint16_t chargeAmpRange() const { return o->chargeAmpRange(); }
  uint16_t calibrationRange() const { return o->calibrationRange(); }
  uint32_t resetLength() const { return o->resetLength(); }
  uint32_t resetDelay() const { return o->resetDelay(); }
  float chargeAmpRefVoltage() const { return o->chargeAmpRefVoltage(); }
  float calibrationVoltage() const { return o->calibrationVoltage(); }
  float diodeBias() const { return o->diodeBias(); }
  uint16_t status() const { return o->status(); }
  uint16_t errors() const { return o->errors(); }
  uint16_t calStrobeLength() const { return o->calStrobeLength(); }
  uint32_t trigDelay() const { return o->trigDelay(); }
  Ipimb::ConfigV1::CapacitorValue diodeGain(uint32_t ch) const { return o->diodeGain(ch); }
};

/** @class ConfigV2

  
*/


class ConfigV2_Wrapper {
  boost::shared_ptr<ConfigV2> _o;
  ConfigV2* o;
public:
  enum { TypeId = Pds::TypeId::Id_IpimbConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 2 /**< XTC type version number */ };
  enum CapacitorValue {
    c_1pF,
    c_4p7pF,
    c_24pF,
    c_120pF,
    c_620pF,
    c_3p3nF,
    c_10nF,
    expert,
  };
  ConfigV2_Wrapper(boost::shared_ptr<ConfigV2> obj) : _o(obj), o(_o.get()) {}
  ConfigV2_Wrapper(ConfigV2* obj) : o(obj) {}
  bool operator==(const ConfigV2_Wrapper &t) const { return this == &t; }
  uint64_t triggerCounter() const { return o->triggerCounter(); }
  uint64_t serialID() const { return o->serialID(); }
  uint16_t chargeAmpRange() const { return o->chargeAmpRange(); }
  uint16_t calibrationRange() const { return o->calibrationRange(); }
  uint32_t resetLength() const { return o->resetLength(); }
  uint32_t resetDelay() const { return o->resetDelay(); }
  float chargeAmpRefVoltage() const { return o->chargeAmpRefVoltage(); }
  float calibrationVoltage() const { return o->calibrationVoltage(); }
  float diodeBias() const { return o->diodeBias(); }
  uint16_t status() const { return o->status(); }
  uint16_t errors() const { return o->errors(); }
  uint16_t calStrobeLength() const { return o->calStrobeLength(); }
  uint32_t trigDelay() const { return o->trigDelay(); }
  uint32_t trigPsDelay() const { return o->trigPsDelay(); }
  uint32_t adcDelay() const { return o->adcDelay(); }
  Ipimb::ConfigV2::CapacitorValue diodeGain(uint32_t ch) const { return o->diodeGain(ch); }
};

/** @class DataV1

  
*/


class DataV1_Wrapper {
  boost::shared_ptr<DataV1> _o;
  DataV1* o;
public:
  enum { TypeId = Pds::TypeId::Id_IpimbData /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  DataV1_Wrapper(boost::shared_ptr<DataV1> obj) : _o(obj), o(_o.get()) {}
  DataV1_Wrapper(DataV1* obj) : o(obj) {}
  bool operator==(const DataV1_Wrapper &t) const { return this == &t; }
  uint64_t triggerCounter() const { return o->triggerCounter(); }
  uint16_t config0() const { return o->config0(); }
  uint16_t config1() const { return o->config1(); }
  uint16_t config2() const { return o->config2(); }
  uint16_t channel0() const { return o->channel0(); }
  uint16_t channel1() const { return o->channel1(); }
  uint16_t channel2() const { return o->channel2(); }
  uint16_t channel3() const { return o->channel3(); }
  uint16_t checksum() const { return o->checksum(); }
  float channel0Volts() const { return o->channel0Volts(); }
  float channel1Volts() const { return o->channel1Volts(); }
  float channel2Volts() const { return o->channel2Volts(); }
  float channel3Volts() const { return o->channel3Volts(); }
};

/** @class DataV2

  
*/


class DataV2_Wrapper {
  boost::shared_ptr<DataV2> _o;
  DataV2* o;
public:
  enum { TypeId = Pds::TypeId::Id_IpimbData /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 2 /**< XTC type version number */ };
  enum { ipimbAdcRange = 5 };
  enum { ipimbAdcSteps = 65536 };
  DataV2_Wrapper(boost::shared_ptr<DataV2> obj) : _o(obj), o(_o.get()) {}
  DataV2_Wrapper(DataV2* obj) : o(obj) {}
  bool operator==(const DataV2_Wrapper &t) const { return this == &t; }
  uint64_t triggerCounter() const { return o->triggerCounter(); }
  uint16_t config0() const { return o->config0(); }
  uint16_t config1() const { return o->config1(); }
  uint16_t config2() const { return o->config2(); }
  uint16_t channel0() const { return o->channel0(); }
  uint16_t channel1() const { return o->channel1(); }
  uint16_t channel2() const { return o->channel2(); }
  uint16_t channel3() const { return o->channel3(); }
  uint16_t channel0ps() const { return o->channel0ps(); }
  uint16_t channel1ps() const { return o->channel1ps(); }
  uint16_t channel2ps() const { return o->channel2ps(); }
  uint16_t channel3ps() const { return o->channel3ps(); }
  uint16_t checksum() const { return o->checksum(); }
  float channel0Volts() const { return o->channel0Volts(); }
  float channel1Volts() const { return o->channel1Volts(); }
  float channel2Volts() const { return o->channel2Volts(); }
  float channel3Volts() const { return o->channel3Volts(); }
  float channel0psVolts() const { return o->channel0psVolts(); }
  float channel1psVolts() const { return o->channel1psVolts(); }
  float channel2psVolts() const { return o->channel2psVolts(); }
  float channel3psVolts() const { return o->channel3psVolts(); }
};

  class ConfigV1_Getter : public Psana::EnvGetter {
  public:
    const char* getTypeName() {
      return "Psana::Ipimb::ConfigV1";
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
      return "Psana::Ipimb::ConfigV2";
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

  class DataV1_Getter : public Psana::EvtGetter {
  public:
    const char* getTypeName() {
      return "Psana::Ipimb::DataV1";
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

  class DataV2_Getter : public Psana::EvtGetter {
  public:
    const char* getTypeName() {
      return "Psana::Ipimb::DataV2";
    }
    int getTypeId() {
      return DataV2::TypeId;
    }
    int getVersion() {
      return DataV2::Version;
    }
    boost::python::api::object get(PSEvt::Event& evt, const std::string& key=std::string(), Pds::Src* foundSrc=0) {
      return boost::python::api::object(DataV2_Wrapper(evt.get(key, foundSrc)));
    }
    boost::python::api::object get(PSEvt::Event& evt, Pds::Src& src, const std::string& key=std::string(), Pds::Src* foundSrc=0) {
      return boost::python::api::object(DataV2_Wrapper(evt.get(src, key, foundSrc)));
    }
    boost::python::api::object get(PSEvt::Event& evt, PSEvt::Source& source, const std::string& key=std::string(), Pds::Src* foundSrc=0) {
      return boost::python::api::object(DataV2_Wrapper(evt.get(source, key, foundSrc)));
    }
  };
} // namespace Ipimb
} // namespace Psana
#endif // PSANA_IPIMB_DDL_WRAPPER_H
