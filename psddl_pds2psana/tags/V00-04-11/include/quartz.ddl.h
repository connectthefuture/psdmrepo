#ifndef PSDDL_PDS2PSANA_QUARTZ_DDL_H
#define PSDDL_PDS2PSANA_QUARTZ_DDL_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include <boost/shared_ptr.hpp>
#include "psddl_psana/quartz.ddl.h"
#include "psddl_pdsdata/quartz.ddl.h"
#include "psddl_pds2psana/camera.ddl.h"
namespace psddl_pds2psana {
namespace Quartz {

class ConfigV1 : public Psana::Quartz::ConfigV1 {
public:
  typedef PsddlPds::Quartz::ConfigV1 XtcType;
  typedef Psana::Quartz::ConfigV1 PsanaType;
  ConfigV1(const boost::shared_ptr<const XtcType>& xtcPtr);
  virtual ~ConfigV1();
  virtual uint16_t black_level() const;
  virtual uint16_t gain_percent() const;
  virtual Psana::Quartz::ConfigV1::Depth output_resolution() const;
  virtual Psana::Quartz::ConfigV1::Binning horizontal_binning() const;
  virtual Psana::Quartz::ConfigV1::Binning vertical_binning() const;
  virtual Psana::Quartz::ConfigV1::Mirroring output_mirroring() const;
  virtual uint8_t output_lookup_table_enabled() const;
  virtual uint8_t defect_pixel_correction_enabled() const;
  virtual uint32_t number_of_defect_pixels() const;
  virtual ndarray<uint16_t, 1> output_lookup_table() const;
  virtual ndarray<Psana::Camera::FrameCoord, 1> defect_pixel_coordinates() const;
  virtual uint16_t output_offset() const;
  virtual uint32_t output_resolution_bits() const;
  const XtcType& _xtcObj() const { return *m_xtcObj; }
private:
  boost::shared_ptr<const XtcType> m_xtcObj;
  std::vector<Psana::Camera::FrameCoord> _defectPixels_ndarray_storage_;
  unsigned _defectPixels_ndarray_shape_[1];
};

} // namespace Quartz
} // namespace psddl_pds2psana
#endif // PSDDL_PDS2PSANA_QUARTZ_DDL_H
