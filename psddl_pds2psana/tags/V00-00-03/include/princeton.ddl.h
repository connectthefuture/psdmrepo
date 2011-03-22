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
  virtual ~FrameV1();
  virtual uint32_t shotIdStart() const;
  virtual float readoutTime() const;
  virtual const uint16_t* data() const;
  virtual std::vector<int> _data_shape() const;
  const XtcType& _xtcObj() const { return *m_xtcObj; }
private:
  boost::shared_ptr<const XtcType> m_xtcObj;
  boost::shared_ptr<const PsddlPds::Princeton::ConfigV1> m_cfgPtr0;
};

Psana::Princeton::InfoV1 pds_to_psana(PsddlPds::Princeton::InfoV1 pds);

} // namespace Princeton
} // namespace psddl_pds2psana
#endif // PSDDL_PDS2PSANA_PRINCETON_DDL_H
