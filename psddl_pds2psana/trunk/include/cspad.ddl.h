#ifndef PSDDL_PDS2PSANA_CSPAD_DDL_H
#define PSDDL_PDS2PSANA_CSPAD_DDL_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include <boost/shared_ptr.hpp>
#include "psddl_psana/cspad.ddl.h"
#include "psddl_pdsdata/cspad.ddl.h"
namespace psddl_pds2psana {
namespace CsPad {

class CsPadDigitalPotsCfg : public Psana::CsPad::CsPadDigitalPotsCfg {
public:
  typedef PsddlPds::CsPad::CsPadDigitalPotsCfg XtcType;
  typedef Psana::CsPad::CsPadDigitalPotsCfg PsanaType;
  CsPadDigitalPotsCfg(const boost::shared_ptr<const XtcType>& xtcPtr);
  virtual ~CsPadDigitalPotsCfg();
  virtual const uint8_t* pots() const;
  virtual std::vector<int> pots_shape() const;
  const XtcType& _xtcObj() const { return *m_xtcObj; }
private:
  boost::shared_ptr<const XtcType> m_xtcObj;
};


class CsPadReadOnlyCfg : public Psana::CsPad::CsPadReadOnlyCfg {
public:
  typedef PsddlPds::CsPad::CsPadReadOnlyCfg XtcType;
  typedef Psana::CsPad::CsPadReadOnlyCfg PsanaType;
  CsPadReadOnlyCfg(const boost::shared_ptr<const XtcType>& xtcPtr);
  virtual ~CsPadReadOnlyCfg();
  virtual uint32_t shiftTest() const;
  virtual uint32_t version() const;
  const XtcType& _xtcObj() const { return *m_xtcObj; }
private:
  boost::shared_ptr<const XtcType> m_xtcObj;
};


class CsPadGainMapCfg : public Psana::CsPad::CsPadGainMapCfg {
public:
  typedef PsddlPds::CsPad::CsPadGainMapCfg XtcType;
  typedef Psana::CsPad::CsPadGainMapCfg PsanaType;
  CsPadGainMapCfg(const boost::shared_ptr<const XtcType>& xtcPtr);
  virtual ~CsPadGainMapCfg();
  virtual const uint16_t* gainMap() const;
  virtual std::vector<int> gainMap_shape() const;
  const XtcType& _xtcObj() const { return *m_xtcObj; }
private:
  boost::shared_ptr<const XtcType> m_xtcObj;
};


class ConfigV1QuadReg : public Psana::CsPad::ConfigV1QuadReg {
public:
  typedef PsddlPds::CsPad::ConfigV1QuadReg XtcType;
  typedef Psana::CsPad::ConfigV1QuadReg PsanaType;
  ConfigV1QuadReg(const boost::shared_ptr<const XtcType>& xtcPtr);
  virtual ~ConfigV1QuadReg();
  virtual const uint32_t* shiftSelect() const;
  virtual const uint32_t* edgeSelect() const;
  virtual uint32_t readClkSet() const;
  virtual uint32_t readClkHold() const;
  virtual uint32_t dataMode() const;
  virtual uint32_t prstSel() const;
  virtual uint32_t acqDelay() const;
  virtual uint32_t intTime() const;
  virtual uint32_t digDelay() const;
  virtual uint32_t ampIdle() const;
  virtual uint32_t injTotal() const;
  virtual uint32_t rowColShiftPer() const;
  virtual const Psana::CsPad::CsPadReadOnlyCfg& ro() const;
  virtual const Psana::CsPad::CsPadDigitalPotsCfg& dp() const;
  virtual const Psana::CsPad::CsPadGainMapCfg& gm() const;
  virtual std::vector<int> shiftSelect_shape() const;
  virtual std::vector<int> edgeSelect_shape() const;
  const XtcType& _xtcObj() const { return *m_xtcObj; }
private:
  boost::shared_ptr<const XtcType> m_xtcObj;
  psddl_pds2psana::CsPad::CsPadReadOnlyCfg _readOnly;
  psddl_pds2psana::CsPad::CsPadDigitalPotsCfg _digitalPots;
  psddl_pds2psana::CsPad::CsPadGainMapCfg _gainMap;
};


class ConfigV1 : public Psana::CsPad::ConfigV1 {
public:
  typedef PsddlPds::CsPad::ConfigV1 XtcType;
  typedef Psana::CsPad::ConfigV1 PsanaType;
  ConfigV1(const boost::shared_ptr<const XtcType>& xtcPtr);
  virtual ~ConfigV1();
  virtual uint32_t concentratorVersion() const;
  virtual uint32_t runDelay() const;
  virtual uint32_t eventCode() const;
  virtual uint32_t inactiveRunMode() const;
  virtual uint32_t activeRunMode() const;
  virtual uint32_t tdi() const;
  virtual uint32_t payloadSize() const;
  virtual uint32_t badAsicMask0() const;
  virtual uint32_t badAsicMask1() const;
  virtual uint32_t asicMask() const;
  virtual uint32_t quadMask() const;
  virtual const Psana::CsPad::ConfigV1QuadReg& quads(uint32_t i0) const;
  virtual uint32_t numAsicsRead() const;
  virtual uint32_t numQuads() const;
  virtual uint32_t numSect() const;
  virtual std::vector<int> quads_shape() const;
  const XtcType& _xtcObj() const { return *m_xtcObj; }
private:
  boost::shared_ptr<const XtcType> m_xtcObj;
  std::vector< psddl_pds2psana::CsPad::ConfigV1QuadReg > _quads;
};


class ConfigV2 : public Psana::CsPad::ConfigV2 {
public:
  typedef PsddlPds::CsPad::ConfigV2 XtcType;
  typedef Psana::CsPad::ConfigV2 PsanaType;
  ConfigV2(const boost::shared_ptr<const XtcType>& xtcPtr);
  virtual ~ConfigV2();
  virtual uint32_t concentratorVersion() const;
  virtual uint32_t runDelay() const;
  virtual uint32_t eventCode() const;
  virtual uint32_t inactiveRunMode() const;
  virtual uint32_t activeRunMode() const;
  virtual uint32_t tdi() const;
  virtual uint32_t payloadSize() const;
  virtual uint32_t badAsicMask0() const;
  virtual uint32_t badAsicMask1() const;
  virtual uint32_t asicMask() const;
  virtual uint32_t quadMask() const;
  virtual const Psana::CsPad::ConfigV1QuadReg& quads(uint32_t i0) const;
  virtual uint32_t numAsicsRead() const;
  virtual uint32_t roiMask(uint32_t iq) const;
  virtual uint32_t numAsicsStored(uint32_t iq) const;
  virtual uint32_t numQuads() const;
  virtual uint32_t numSect() const;
  virtual std::vector<int> quads_shape() const;
  const XtcType& _xtcObj() const { return *m_xtcObj; }
private:
  boost::shared_ptr<const XtcType> m_xtcObj;
  std::vector< psddl_pds2psana::CsPad::ConfigV1QuadReg > _quads;
};


class ElementV1 : public Psana::CsPad::ElementV1 {
public:
  typedef PsddlPds::CsPad::ElementV1 XtcType;
  typedef Psana::CsPad::ElementV1 PsanaType;
  ElementV1(const boost::shared_ptr<const XtcType>& xtcPtr, const boost::shared_ptr<const PsddlPds::CsPad::ConfigV1>& cfgPtr);
  ElementV1(const boost::shared_ptr<const XtcType>& xtcPtr, const boost::shared_ptr<const PsddlPds::CsPad::ConfigV2>& cfgPtr);
  virtual ~ElementV1();
  virtual uint32_t virtual_channel() const;
  virtual uint32_t lane() const;
  virtual uint32_t tid() const;
  virtual uint32_t acq_count() const;
  virtual uint32_t op_code() const;
  virtual uint32_t quad() const;
  virtual uint32_t seq_count() const;
  virtual uint32_t ticks() const;
  virtual uint32_t fiducials() const;
  virtual const uint16_t* sb_temp() const;
  virtual uint32_t frame_type() const;
  virtual const uint16_t* data() const;
  virtual std::vector<int> sb_temp_shape() const;
  virtual std::vector<int> data_shape() const;
  virtual std::vector<int> _extra_shape() const;
  const XtcType& _xtcObj() const { return *m_xtcObj; }
private:
  boost::shared_ptr<const XtcType> m_xtcObj;
  boost::shared_ptr<const PsddlPds::CsPad::ConfigV1> m_cfgPtr0;
  boost::shared_ptr<const PsddlPds::CsPad::ConfigV2> m_cfgPtr1;
};


class DataV1 : public Psana::CsPad::DataV1 {
public:
  typedef PsddlPds::CsPad::DataV1 XtcType;
  typedef Psana::CsPad::DataV1 PsanaType;
  DataV1(const boost::shared_ptr<const XtcType>& xtcPtr, const boost::shared_ptr<const PsddlPds::CsPad::ConfigV1>& cfgPtr);
  DataV1(const boost::shared_ptr<const XtcType>& xtcPtr, const boost::shared_ptr<const PsddlPds::CsPad::ConfigV2>& cfgPtr);
  virtual ~DataV1();
  virtual const Psana::CsPad::ElementV1& quads(uint32_t i0) const;
  virtual std::vector<int> quads_shape() const;
  const XtcType& _xtcObj() const { return *m_xtcObj; }
private:
  boost::shared_ptr<const XtcType> m_xtcObj;
  boost::shared_ptr<const PsddlPds::CsPad::ConfigV1> m_cfgPtr0;
  boost::shared_ptr<const PsddlPds::CsPad::ConfigV2> m_cfgPtr1;
  std::vector< psddl_pds2psana::CsPad::ElementV1 > _quads;
};


class ElementV2 : public Psana::CsPad::ElementV2 {
public:
  typedef PsddlPds::CsPad::ElementV2 XtcType;
  typedef Psana::CsPad::ElementV2 PsanaType;
  ElementV2(const boost::shared_ptr<const XtcType>& xtcPtr, const boost::shared_ptr<const PsddlPds::CsPad::ConfigV2>& cfgPtr);
  virtual ~ElementV2();
  virtual uint32_t virtual_channel() const;
  virtual uint32_t lane() const;
  virtual uint32_t tid() const;
  virtual uint32_t acq_count() const;
  virtual uint32_t op_code() const;
  virtual uint32_t quad() const;
  virtual uint32_t seq_count() const;
  virtual uint32_t ticks() const;
  virtual uint32_t fiducials() const;
  virtual const uint16_t* sb_temp() const;
  virtual uint32_t frame_type() const;
  virtual const uint16_t* data() const;
  virtual std::vector<int> sb_temp_shape() const;
  virtual std::vector<int> data_shape() const;
  virtual std::vector<int> _extra_shape() const;
  const XtcType& _xtcObj() const { return *m_xtcObj; }
private:
  boost::shared_ptr<const XtcType> m_xtcObj;
  boost::shared_ptr<const PsddlPds::CsPad::ConfigV2> m_cfgPtr0;
};


class DataV2 : public Psana::CsPad::DataV2 {
public:
  typedef PsddlPds::CsPad::DataV2 XtcType;
  typedef Psana::CsPad::DataV2 PsanaType;
  DataV2(const boost::shared_ptr<const XtcType>& xtcPtr, const boost::shared_ptr<const PsddlPds::CsPad::ConfigV2>& cfgPtr);
  virtual ~DataV2();
  virtual const Psana::CsPad::ElementV2& quads(uint32_t i0) const;
  virtual std::vector<int> quads_shape() const;
  const XtcType& _xtcObj() const { return *m_xtcObj; }
private:
  boost::shared_ptr<const XtcType> m_xtcObj;
  boost::shared_ptr<const PsddlPds::CsPad::ConfigV2> m_cfgPtr0;
  std::vector< psddl_pds2psana::CsPad::ElementV2 > _quads;
};

} // namespace CsPad
} // namespace psddl_pds2psana
#endif // PSDDL_PDS2PSANA_CSPAD_DDL_H
