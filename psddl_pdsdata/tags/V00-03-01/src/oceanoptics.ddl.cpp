
// *** Do not edit this file, it is auto-generated ***

#include "psddl_pdsdata/oceanoptics.ddl.h"

namespace PsddlPds {
namespace OceanOptics {
double
DataV1::nonlinerCorrected(const OceanOptics::ConfigV1& cfg, uint32_t iPixel) const {
  double fRawValue = (double) (this->lu16Spetra[iPixel] ^ 0x2000);       ndarray<double, 1> corr = cfg.nonlinCorrect();      return fRawValue / (          corr[0] + fRawValue *          (corr[1] + fRawValue *          (corr[2] + fRawValue *          (corr[3] + fRawValue *          (corr[4] + fRawValue *          (corr[5] + fRawValue *          (corr[6] + fRawValue *           corr[7])))))));
}
} // namespace OceanOptics
} // namespace PsddlPds
