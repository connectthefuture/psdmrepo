#ifndef PSDDL_PDS2PSANA_EPIXSAMPLER_DDL_H
#define PSDDL_PDS2PSANA_EPIXSAMPLER_DDL_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include <boost/shared_ptr.hpp>
#include "psddl_psana/epixsampler.ddl.h"
#include "pdsdata/psddl/epixsampler.ddl.h"
namespace psddl_pds2psana {
namespace EpixSampler {

class ConfigV1 : public Psana::EpixSampler::ConfigV1 {
public:
  typedef Pds::EpixSampler::ConfigV1 XtcType;
  typedef Psana::EpixSampler::ConfigV1 PsanaType;
  ConfigV1(const boost::shared_ptr<const XtcType>& xtcPtr);
  virtual ~ConfigV1();
  virtual uint32_t version() const;
  virtual uint32_t runTrigDelay() const;
  virtual uint32_t daqTrigDelay() const;
  virtual uint32_t daqSetting() const;
  virtual uint32_t adcClkHalfT() const;
  virtual uint32_t adcPipelineDelay() const;
  virtual uint32_t digitalCardId0() const;
  virtual uint32_t digitalCardId1() const;
  virtual uint32_t analogCardId0() const;
  virtual uint32_t analogCardId1() const;
  virtual uint32_t numberOfChannels() const;
  virtual uint32_t samplesPerChannel() const;
  virtual uint32_t baseClockFrequency() const;
  virtual uint8_t testPatternEnable() const;
  virtual double sampleInterval_sec() const;
  const XtcType& _xtcObj() const { return *m_xtcObj; }
private:
  boost::shared_ptr<const XtcType> m_xtcObj;
};


template <typename Config>
class ElementV1 : public Psana::EpixSampler::ElementV1 {
public:
  typedef Pds::EpixSampler::ElementV1 XtcType;
  typedef Psana::EpixSampler::ElementV1 PsanaType;
  ElementV1(const boost::shared_ptr<const XtcType>& xtcPtr, const boost::shared_ptr<const Config>& cfgPtr);
  virtual ~ElementV1();
  virtual uint8_t vc() const;
  virtual uint8_t lane() const;
  virtual uint16_t acqCount() const;
  virtual uint32_t frameNumber() const;
  virtual uint32_t ticks() const;
  virtual uint32_t fiducials() const;
  virtual ndarray<const uint16_t, 2> frame() const;
  virtual ndarray<const uint16_t, 1> temperatures() const;
  virtual uint32_t lastWord() const;
  const XtcType& _xtcObj() const { return *m_xtcObj; }
private:
  boost::shared_ptr<const XtcType> m_xtcObj;
  boost::shared_ptr<const Config> m_cfgPtr;
};

} // namespace EpixSampler
} // namespace psddl_pds2psana
#endif // PSDDL_PDS2PSANA_EPIXSAMPLER_DDL_H
