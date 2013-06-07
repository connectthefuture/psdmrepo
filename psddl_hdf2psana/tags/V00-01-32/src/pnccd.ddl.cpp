
// *** Do not edit this file, it is auto-generated ***

#include "psddl_hdf2psana/pnccd.ddl.h"
#include "hdf5pp/ArrayType.h"
#include "hdf5pp/CompoundType.h"
#include "hdf5pp/EnumType.h"
#include "hdf5pp/VlenType.h"
#include "hdf5pp/Utils.h"
#include "PSEvt/DataProxy.h"
#include "psddl_hdf2psana/pnccd.h"
#include "psddl_hdf2psana/pnccd.h"
#include "psddl_hdf2psana/pnccd.h"
namespace psddl_hdf2psana {
namespace PNCCD {

hdf5pp::Type ns_ConfigV1_v0_dataset_config_stored_type()
{
  typedef ns_ConfigV1_v0::dataset_config DsType;
  hdf5pp::CompoundType type = hdf5pp::CompoundType::compoundType<DsType>();
  type.insert("numLinks", offsetof(DsType, numLinks), hdf5pp::TypeTraits<uint32_t>::stored_type());
  type.insert("payloadSizePerLink", offsetof(DsType, payloadSizePerLink), hdf5pp::TypeTraits<uint32_t>::stored_type());
  return type;
}

hdf5pp::Type ns_ConfigV1_v0::dataset_config::stored_type()
{
  static hdf5pp::Type type = ns_ConfigV1_v0_dataset_config_stored_type();
  return type;
}

hdf5pp::Type ns_ConfigV1_v0_dataset_config_native_type()
{
  typedef ns_ConfigV1_v0::dataset_config DsType;
  hdf5pp::CompoundType type = hdf5pp::CompoundType::compoundType<DsType>();
  type.insert("numLinks", offsetof(DsType, numLinks), hdf5pp::TypeTraits<uint32_t>::native_type());
  type.insert("payloadSizePerLink", offsetof(DsType, payloadSizePerLink), hdf5pp::TypeTraits<uint32_t>::native_type());
  return type;
}

hdf5pp::Type ns_ConfigV1_v0::dataset_config::native_type()
{
  static hdf5pp::Type type = ns_ConfigV1_v0_dataset_config_native_type();
  return type;
}
ns_ConfigV1_v0::dataset_config::dataset_config()
{
}
ns_ConfigV1_v0::dataset_config::~dataset_config()
{
}
uint32_t ConfigV1_v0::numLinks() const {
  if (not m_ds_config) read_ds_config();
  return uint32_t(m_ds_config->numLinks);
}
uint32_t ConfigV1_v0::payloadSizePerLink() const {
  if (not m_ds_config) read_ds_config();
  return uint32_t(m_ds_config->payloadSizePerLink);
}
void ConfigV1_v0::read_ds_config() const {
  m_ds_config = hdf5pp::Utils::readGroup<PNCCD::ns_ConfigV1_v0::dataset_config>(m_group, "config", m_idx);
}
boost::shared_ptr<PSEvt::Proxy<Psana::PNCCD::ConfigV1> > make_ConfigV1(int version, hdf5pp::Group group, hsize_t idx) {
  switch (version) {
  case 0:
    return boost::make_shared<PSEvt::DataProxy<Psana::PNCCD::ConfigV1> >(boost::make_shared<ConfigV1_v0>(group, idx));
  default:
    return boost::make_shared<PSEvt::DataProxy<Psana::PNCCD::ConfigV1> >(boost::shared_ptr<Psana::PNCCD::ConfigV1>());
  }
}

hdf5pp::Type ns_ConfigV2_v0_dataset_config_stored_type()
{
  typedef ns_ConfigV2_v0::dataset_config DsType;
  hdf5pp::CompoundType type = hdf5pp::CompoundType::compoundType<DsType>();
  type.insert("numLinks", offsetof(DsType, numLinks), hdf5pp::TypeTraits<uint32_t>::stored_type());
  type.insert("payloadSizePerLink", offsetof(DsType, payloadSizePerLink), hdf5pp::TypeTraits<uint32_t>::stored_type());
  type.insert("numChannels", offsetof(DsType, numChannels), hdf5pp::TypeTraits<uint32_t>::stored_type());
  type.insert("numRows", offsetof(DsType, numRows), hdf5pp::TypeTraits<uint32_t>::stored_type());
  type.insert("numSubmoduleChannels", offsetof(DsType, numSubmoduleChannels), hdf5pp::TypeTraits<uint32_t>::stored_type());
  type.insert("numSubmoduleRows", offsetof(DsType, numSubmoduleRows), hdf5pp::TypeTraits<uint32_t>::stored_type());
  type.insert("numSubmodules", offsetof(DsType, numSubmodules), hdf5pp::TypeTraits<uint32_t>::stored_type());
  type.insert("camexMagic", offsetof(DsType, camexMagic), hdf5pp::TypeTraits<uint32_t>::stored_type());
  type.insert("info", offsetof(DsType, info), hdf5pp::TypeTraits<const char*>::stored_type());
  type.insert("timingFName", offsetof(DsType, timingFName), hdf5pp::TypeTraits<const char*>::stored_type());
  return type;
}

hdf5pp::Type ns_ConfigV2_v0::dataset_config::stored_type()
{
  static hdf5pp::Type type = ns_ConfigV2_v0_dataset_config_stored_type();
  return type;
}

hdf5pp::Type ns_ConfigV2_v0_dataset_config_native_type()
{
  typedef ns_ConfigV2_v0::dataset_config DsType;
  hdf5pp::CompoundType type = hdf5pp::CompoundType::compoundType<DsType>();
  type.insert("numLinks", offsetof(DsType, numLinks), hdf5pp::TypeTraits<uint32_t>::native_type());
  type.insert("payloadSizePerLink", offsetof(DsType, payloadSizePerLink), hdf5pp::TypeTraits<uint32_t>::native_type());
  type.insert("numChannels", offsetof(DsType, numChannels), hdf5pp::TypeTraits<uint32_t>::native_type());
  type.insert("numRows", offsetof(DsType, numRows), hdf5pp::TypeTraits<uint32_t>::native_type());
  type.insert("numSubmoduleChannels", offsetof(DsType, numSubmoduleChannels), hdf5pp::TypeTraits<uint32_t>::native_type());
  type.insert("numSubmoduleRows", offsetof(DsType, numSubmoduleRows), hdf5pp::TypeTraits<uint32_t>::native_type());
  type.insert("numSubmodules", offsetof(DsType, numSubmodules), hdf5pp::TypeTraits<uint32_t>::native_type());
  type.insert("camexMagic", offsetof(DsType, camexMagic), hdf5pp::TypeTraits<uint32_t>::native_type());
  type.insert("info", offsetof(DsType, info), hdf5pp::TypeTraits<const char*>::native_type());
  type.insert("timingFName", offsetof(DsType, timingFName), hdf5pp::TypeTraits<const char*>::native_type());
  return type;
}

hdf5pp::Type ns_ConfigV2_v0::dataset_config::native_type()
{
  static hdf5pp::Type type = ns_ConfigV2_v0_dataset_config_native_type();
  return type;
}
ns_ConfigV2_v0::dataset_config::dataset_config()
{
}
ns_ConfigV2_v0::dataset_config::~dataset_config()
{
}
uint32_t ConfigV2_v0::numLinks() const {
  if (not m_ds_config) read_ds_config();
  return uint32_t(m_ds_config->numLinks);
}
uint32_t ConfigV2_v0::payloadSizePerLink() const {
  if (not m_ds_config) read_ds_config();
  return uint32_t(m_ds_config->payloadSizePerLink);
}
uint32_t ConfigV2_v0::numChannels() const {
  if (not m_ds_config) read_ds_config();
  return uint32_t(m_ds_config->numChannels);
}
uint32_t ConfigV2_v0::numRows() const {
  if (not m_ds_config) read_ds_config();
  return uint32_t(m_ds_config->numRows);
}
uint32_t ConfigV2_v0::numSubmoduleChannels() const {
  if (not m_ds_config) read_ds_config();
  return uint32_t(m_ds_config->numSubmoduleChannels);
}
uint32_t ConfigV2_v0::numSubmoduleRows() const {
  if (not m_ds_config) read_ds_config();
  return uint32_t(m_ds_config->numSubmoduleRows);
}
uint32_t ConfigV2_v0::numSubmodules() const {
  if (not m_ds_config) read_ds_config();
  return uint32_t(m_ds_config->numSubmodules);
}
uint32_t ConfigV2_v0::camexMagic() const {
  if (not m_ds_config) read_ds_config();
  return uint32_t(m_ds_config->camexMagic);
}
const char* ConfigV2_v0::info() const {
  if (not m_ds_config) read_ds_config();
  return (const char*)(m_ds_config->info);
}
const char* ConfigV2_v0::timingFName() const {
  if (not m_ds_config) read_ds_config();
  return (const char*)(m_ds_config->timingFName);
}
std::vector<int>
ConfigV2_v0::info_shape() const{ 
  int shape[] = { 256 };
  return std::vector<int>(shape, shape+1); 
}
std::vector<int>
ConfigV2_v0::timingFName_shape() const{ 
  int shape[] = { 256 };
  return std::vector<int>(shape, shape+1); 
}
void ConfigV2_v0::read_ds_config() const {
  m_ds_config = hdf5pp::Utils::readGroup<PNCCD::ns_ConfigV2_v0::dataset_config>(m_group, "config", m_idx);
}
boost::shared_ptr<PSEvt::Proxy<Psana::PNCCD::ConfigV2> > make_ConfigV2(int version, hdf5pp::Group group, hsize_t idx) {
  switch (version) {
  case 0:
    return boost::make_shared<PSEvt::DataProxy<Psana::PNCCD::ConfigV2> >(boost::make_shared<ConfigV2_v0>(group, idx));
  default:
    return boost::make_shared<PSEvt::DataProxy<Psana::PNCCD::ConfigV2> >(boost::shared_ptr<Psana::PNCCD::ConfigV2>());
  }
}
boost::shared_ptr<PSEvt::Proxy<Psana::PNCCD::FullFrameV1> > make_FullFrameV1(int version, hdf5pp::Group group, hsize_t idx) {
  switch (version) {
  case 0:
    return boost::make_shared<PSEvt::DataProxy<Psana::PNCCD::FullFrameV1> >(boost::make_shared<FullFrameV1_v0>(group, idx));
  default:
    return boost::make_shared<PSEvt::DataProxy<Psana::PNCCD::FullFrameV1> >(boost::shared_ptr<Psana::PNCCD::FullFrameV1>());
  }
}
boost::shared_ptr<PSEvt::Proxy<Psana::PNCCD::FramesV1> > make_FramesV1(int version, hdf5pp::Group group, hsize_t idx, const boost::shared_ptr<Psana::PNCCD::ConfigV1>& cfg) {
  switch (version) {
  case 0:
    return boost::make_shared<PSEvt::DataProxy<Psana::PNCCD::FramesV1> >(boost::make_shared<FramesV1_v0<Psana::PNCCD::ConfigV1> >(group, idx, cfg));
  default:
    return boost::make_shared<PSEvt::DataProxy<Psana::PNCCD::FramesV1> >(boost::shared_ptr<Psana::PNCCD::FramesV1>());
  }
}
boost::shared_ptr<PSEvt::Proxy<Psana::PNCCD::FramesV1> > make_FramesV1(int version, hdf5pp::Group group, hsize_t idx, const boost::shared_ptr<Psana::PNCCD::ConfigV2>& cfg) {
  switch (version) {
  case 0:
    return boost::make_shared<PSEvt::DataProxy<Psana::PNCCD::FramesV1> >(boost::make_shared<FramesV1_v0<Psana::PNCCD::ConfigV2> >(group, idx, cfg));
  default:
    return boost::make_shared<PSEvt::DataProxy<Psana::PNCCD::FramesV1> >(boost::shared_ptr<Psana::PNCCD::FramesV1>());
  }
}
} // namespace PNCCD
} // namespace psddl_hdf2psana