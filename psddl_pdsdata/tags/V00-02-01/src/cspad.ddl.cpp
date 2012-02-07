
// *** Do not edit this file, it is auto-generated ***

#include "psddl_pdsdata/cspad.ddl.h"

namespace PsddlPds {
namespace CsPad {
uint32_t
ConfigV1::numAsicsRead() const {
  return (this->_AsicMask & 0xf)==1 ? 4 : 16;
}
uint32_t
ConfigV1::numQuads() const {
  return __builtin_popcount(this->_quadMask);
}
uint32_t
ConfigV1::numSect() const {
  return this->numAsicsRead()/2;
}
std::vector<int>
ConfigV1::quads_shape() const {
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(MaxQuadsPerSensor);
  return shape;
}
uint32_t
ConfigV2::numAsicsRead() const {
  return (this->_AsicMask & 0xf)==1 ? 4 : 16;
}
uint32_t
ConfigV2::roiMask(uint32_t iq) const {
  return (this->_roiMask >> (8*iq)) & 0xff;
}
uint32_t
ConfigV2::numAsicsStored(uint32_t iq) const {
  return __builtin_popcount(this->roiMask(iq))*2;
}
uint32_t
ConfigV2::numQuads() const {
  return __builtin_popcount(this->_quadMask);
}
uint32_t
ConfigV2::numSect() const {
  return __builtin_popcount(this->_roiMask);
}
std::vector<int>
ConfigV2::quads_shape() const {
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(MaxQuadsPerSensor);
  return shape;
}
uint32_t
ConfigV3::numAsicsRead() const {
  return (this->_AsicMask & 0xf)==1 ? 4 : 16;
}
uint32_t
ConfigV3::roiMask(uint32_t iq) const {
  return (this->_roiMask >> (8*iq)) & 0xff;
}
uint32_t
ConfigV3::numAsicsStored(uint32_t iq) const {
  return __builtin_popcount(this->roiMask(iq))*2;
}
uint32_t
ConfigV3::numQuads() const {
  return __builtin_popcount(this->_quadMask);
}
uint32_t
ConfigV3::numSect() const {
  return __builtin_popcount(this->_roiMask);
}
std::vector<int>
ConfigV3::protectionThresholds_shape() const {
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(MaxQuadsPerSensor);
  return shape;
}
std::vector<int>
ConfigV3::quads_shape() const {
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(MaxQuadsPerSensor);
  return shape;
}
uint32_t
ElementV1::sectionMask(const CsPad::ConfigV1& cfg) const {
  return (cfg.asicMask() & 0xf)==1 ? 0x3 : 0xff;
}
uint32_t
ElementV1::sectionMask(const CsPad::ConfigV2& cfg) const {
  return (cfg.asicMask() & 0xf)==1 ? 0x3 : 0xff;
}
float
ElementV1::common_mode(uint32_t section) const {
  return 0;
}
std::vector<int>
DataV1::quads_shape(const CsPad::ConfigV1& cfg) const {
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(cfg.numQuads());
  return shape;
}
std::vector<int>
DataV1::quads_shape(const CsPad::ConfigV2& cfg) const {
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(cfg.numQuads());
  return shape;
}
uint32_t
ElementV2::sectionMask(const CsPad::ConfigV2& cfg) const {
  return cfg.roiMask(this->quad());
}
uint32_t
ElementV2::sectionMask(const CsPad::ConfigV3& cfg) const {
  return cfg.roiMask(this->quad());
}
float
ElementV2::common_mode(uint32_t section) const {
  return 0;
}
std::vector<int>
DataV2::quads_shape(const CsPad::ConfigV2& cfg) const {
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(cfg.numQuads());
  return shape;
}
std::vector<int>
DataV2::quads_shape(const CsPad::ConfigV3& cfg) const {
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(cfg.numQuads());
  return shape;
}
} // namespace CsPad
} // namespace PsddlPds
