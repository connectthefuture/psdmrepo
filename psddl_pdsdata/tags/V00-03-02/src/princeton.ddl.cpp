
// *** Do not edit this file, it is auto-generated ***

#include "psddl_pdsdata/princeton.ddl.h"

namespace PsddlPds {
namespace Princeton {
uint32_t
ConfigV1::frameSize() const {
  return sizeof(FrameV1) + this->numPixels()*2;
}
uint32_t
ConfigV2::frameSize() const {
  return sizeof(FrameV1) + this->numPixels()*2;
}
uint32_t
ConfigV3::frameSize() const {
  return sizeof(FrameV1) + this->numPixels()*2;
}
} // namespace Princeton
} // namespace PsddlPds
