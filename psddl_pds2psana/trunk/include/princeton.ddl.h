#ifndef PSDDL_PDS2PSANA_PRINCETON_DDL_H
#define PSDDL_PDS2PSANA_PRINCETON_DDL_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include <boost/shared_ptr.hpp>
#include "psddl_psana/princeton.ddl.h"
#include "psddl_pdsdata/princeton.ddl.h"
namespace psddl_pds2psana {
namespace Princeton {

class ConfigV1 : public Psana::Princeton::ConfigV1 {
public:
  typedef PsddlPds::Princeton::ConfigV1 XtcType;
  typedef Psana::Princeton::ConfigV1 PsanaType;
  ConfigV1(const boost::shared_ptr<const XtcType>& xtcPtr);
  virtual ~ConfigV1();
  virtual uint32_t width() const;
  virtual uint32_t height() const;
  virtual uint32_t orgX() const;
  virtual uint32_t orgY() const;
  virtual uint32_t binX() const;
  virtual uint32_t binY() const;
  virtual float exposureTime() const;
  virtual float coolingTemp() const;
  virtual uint32_t readoutSpeedIndex() const;
  virtual uint16_t readoutEventCode() const;
  virtual uint16_t delayMode() const;
  virtual uint32_t frameSize() const;
  virtual uint32_t numPixelsX() const;
  virtual uint32_t numPixelsY() const;
  virtual uint32_t numPixels() const;
  const XtcType& _xtcObj() const { return *m_xtcObj; }
private:
  boost::shared_ptr<const XtcType> m_xtcObj;
};


class ConfigV2 : public Psana::Princeton::ConfigV2 {
public:
  typedef PsddlPds::Princeton::ConfigV2 XtcType;
  typedef Psana::Princeton::ConfigV2 PsanaType;
  ConfigV2(const boost::shared_ptr<const XtcType>& xtcPtr);
  virtual ~ConfigV2();
  virtual uint32_t width() const;
  virtual uint32_t height() const;
  virtual uint32_t orgX() const;
  virtual uint32_t orgY() const;
  virtual uint32_t binX() const;
  virtual uint32_t binY() const;
  virtual float exposureTime() const;
  virtual float coolingTemp() const;
  virtual uint16_t gainIndex() const;
  virtual uint16_t readoutSpeedIndex() const;
  virtual uint16_t readoutEventCode() const;
  virtual uint16_t delayMode() const;
  virtual uint32_t frameSize() const;
  virtual uint32_t numPixelsX() const;
  virtual uint32_t numPixelsY() const;
  virtual uint32_t numPixels() const;
  const XtcType& _xtcObj() const { return *m_xtcObj; }
private:
  boost::shared_ptr<const XtcType> m_xtcObj;
};


class ConfigV3 : public Psana::Princeton::ConfigV3 {
public:
  typedef PsddlPds::Princeton::ConfigV3 XtcType;
  typedef Psana::Princeton::ConfigV3 PsanaType;
  ConfigV3(const boost::shared_ptr<const XtcType>& xtcPtr);
  virtual ~ConfigV3();
  virtual uint32_t width() const;
  virtual uint32_t height() const;
  virtual uint32_t orgX() const;
  virtual uint32_t orgY() const;
  virtual uint32_t binX() const;
  virtual uint32_t binY() const;
  virtual float exposureTime() const;
  virtual float coolingTemp() const;
  virtual uint8_t gainIndex() const;
  virtual uint8_t readoutSpeedIndex() const;
  virtual uint16_t exposureEventCode() const;
  virtual uint32_t numDelayShots() const;
  virtual uint32_t frameSize() const;
  virtual uint32_t numPixelsX() const;
  virtual uint32_t numPixelsY() const;
  virtual uint32_t numPixels() const;
  const XtcType& _xtcObj() const { return *m_xtcObj; }
private:
  boost::shared_ptr<const XtcType> m_xtcObj;
};


class ConfigV4 : public Psana::Princeton::ConfigV4 {
public:
  typedef PsddlPds::Princeton::ConfigV4 XtcType;
  typedef Psana::Princeton::ConfigV4 PsanaType;
  ConfigV4(const boost::shared_ptr<const XtcType>& xtcPtr);
  virtual ~ConfigV4();
  virtual uint32_t width() const;
  virtual uint32_t height() const;
  virtual uint32_t orgX() const;
  virtual uint32_t orgY() const;
  virtual uint32_t binX() const;
  virtual uint32_t binY() const;
  virtual uint32_t maskedHeight() const;
  virtual uint32_t kineticHeight() const;
  virtual float vsSpeed() const;
  virtual float exposureTime() const;
  virtual float coolingTemp() const;
  virtual uint8_t gainIndex() const;
  virtual uint8_t readoutSpeedIndex() const;
  virtual uint16_t exposureEventCode() const;
  virtual uint32_t numDelayShots() const;
  virtual uint32_t frameSize() const;
  virtual uint32_t numPixelsX() const;
  virtual uint32_t numPixelsY() const;
  virtual uint32_t numPixels() const;
  const XtcType& _xtcObj() const { return *m_xtcObj; }
private:
  boost::shared_ptr<const XtcType> m_xtcObj;
};


class FrameV1 : public Psana::Princeton::FrameV1 {
public:
  typedef PsddlPds::Princeton::FrameV1 XtcType;
  typedef Psana::Princeton::FrameV1 PsanaType;
  FrameV1(const boost::shared_ptr<const XtcType>& xtcPtr, const boost::shared_ptr<const PsddlPds::Princeton::ConfigV1>& cfgPtr);
  FrameV1(const boost::shared_ptr<const XtcType>& xtcPtr, const boost::shared_ptr<const PsddlPds::Princeton::ConfigV2>& cfgPtr);
  FrameV1(const boost::shared_ptr<const XtcType>& xtcPtr, const boost::shared_ptr<const PsddlPds::Princeton::ConfigV3>& cfgPtr);
  FrameV1(const boost::shared_ptr<const XtcType>& xtcPtr, const boost::shared_ptr<const PsddlPds::Princeton::ConfigV4>& cfgPtr);
  virtual ~FrameV1();
  virtual uint32_t shotIdStart() const;
  virtual float readoutTime() const;
  virtual ndarray<uint16_t, 2> data() const;
  const XtcType& _xtcObj() const { return *m_xtcObj; }
private:
  boost::shared_ptr<const XtcType> m_xtcObj;
  boost::shared_ptr<const PsddlPds::Princeton::ConfigV1> m_cfgPtr0;
  boost::shared_ptr<const PsddlPds::Princeton::ConfigV2> m_cfgPtr1;
  boost::shared_ptr<const PsddlPds::Princeton::ConfigV3> m_cfgPtr2;
  boost::shared_ptr<const PsddlPds::Princeton::ConfigV4> m_cfgPtr3;
};

Psana::Princeton::InfoV1 pds_to_psana(PsddlPds::Princeton::InfoV1 pds);

} // namespace Princeton
} // namespace psddl_pds2psana
#endif // PSDDL_PDS2PSANA_PRINCETON_DDL_H
