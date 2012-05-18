#ifndef PSANA_FCCD_DDL_WRAPPER_H
#define PSANA_FCCD_DDL_WRAPPER_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include "ndarray/ndarray.h"
#include "pdsdata/xtc/TypeId.hh"
#include "psddl_pypsana/PyWrapper.h"
namespace Psana {
namespace FCCD {

extern void createWrappers();


/** @class FccdConfigV1

  
*/


class FccdConfigV1_Wrapper {
  boost::shared_ptr<FccdConfigV1> _o;
  FccdConfigV1* o;
public:
  enum { TypeId = Pds::TypeId::Id_FccdConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  enum { Row_Pixels = 500 };
  enum { Column_Pixels = 576 };
  enum { Trimmed_Row_Pixels = 480 };
  enum { Trimmed_Column_Pixels = 480 };
  enum Depth {
    Sixteen_bit = 16,
  };
  enum Output_Source {
    Output_FIFO = 0,
    Output_Pattern4 = 4,
  };
  FccdConfigV1_Wrapper(boost::shared_ptr<FccdConfigV1> obj) : _o(obj), o(_o.get()) {}
  FccdConfigV1_Wrapper(FccdConfigV1* obj) : o(obj) {}
  bool operator==(const FccdConfigV1_Wrapper &t) const { return this == &t; }
  uint16_t outputMode() const { return o->outputMode(); }
  uint32_t width() const { return o->width(); }
  uint32_t height() const { return o->height(); }
  uint32_t trimmedWidth() const { return o->trimmedWidth(); }
  uint32_t trimmedHeight() const { return o->trimmedHeight(); }
};

/** @class FccdConfigV2

  
*/


class FccdConfigV2_Wrapper {
  boost::shared_ptr<FccdConfigV2> _o;
  FccdConfigV2* o;
public:
  enum { TypeId = Pds::TypeId::Id_FccdConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 2 /**< XTC type version number */ };
  enum { Row_Pixels = 500 };
  enum { Column_Pixels = 576 * 2 };
  enum { Trimmed_Row_Pixels = 480 };
  enum { Trimmed_Column_Pixels = 480 };
  enum { NVoltages = 17 };
  enum { NWaveforms = 15 };
  enum Depth {
    Eight_bit = 8,
    Sixteen_bit = 16,
  };
  enum Output_Source {
    Output_FIFO = 0,
    Test_Pattern1 = 1,
    Test_Pattern2 = 2,
    Test_Pattern3 = 3,
    Test_Pattern4 = 4,
  };
  FccdConfigV2_Wrapper(boost::shared_ptr<FccdConfigV2> obj) : _o(obj), o(_o.get()) {}
  FccdConfigV2_Wrapper(FccdConfigV2* obj) : o(obj) {}
  bool operator==(const FccdConfigV2_Wrapper &t) const { return this == &t; }
  uint16_t outputMode() const { return o->outputMode(); }
  uint8_t ccdEnable() const { return o->ccdEnable(); }
  uint8_t focusMode() const { return o->focusMode(); }
  uint32_t exposureTime() const { return o->exposureTime(); }
  std::vector<float> dacVoltages() const { VEC_CONVERT(o->dacVoltages(), float); }
  std::vector<uint16_t> waveforms() const { VEC_CONVERT(o->waveforms(), uint16_t); }
  uint32_t width() const { return o->width(); }
  uint32_t height() const { return o->height(); }
  uint32_t trimmedWidth() const { return o->trimmedWidth(); }
  uint32_t trimmedHeight() const { return o->trimmedHeight(); }
};
} // namespace FCCD
} // namespace Psana
#endif // PSANA_FCCD_DDL_WRAPPER_H
