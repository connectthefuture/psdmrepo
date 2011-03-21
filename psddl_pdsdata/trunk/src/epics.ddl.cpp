
// *** Do not edit this file, it is auto-generated ***

#include "psddl_pdsdata/epics.ddl.h"

namespace PsddlPds {
namespace Epics {
std::vector<int> dbr_ctrl_short::_units_shape() const
{
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(MAX_UNITS_SIZE);
  return shape;
}

std::vector<int> dbr_ctrl_float::_units_shape() const
{
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(MAX_UNITS_SIZE);
  return shape;
}

std::vector<int> dbr_ctrl_enum::_strs_shape() const
{
  std::vector<int> shape;
  shape.reserve(2);
  shape.push_back(MAX_ENUM_STATES);
  shape.push_back(MAX_ENUM_STRING_SIZE);
  return shape;
}

std::vector<int> dbr_ctrl_char::_units_shape() const
{
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(MAX_UNITS_SIZE);
  return shape;
}

std::vector<int> dbr_ctrl_long::_units_shape() const
{
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(MAX_UNITS_SIZE);
  return shape;
}

std::vector<int> dbr_ctrl_double::_units_shape() const
{
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(MAX_UNITS_SIZE);
  return shape;
}

std::vector<int> EpicsPvCtrlHeader::_sPvName_shape() const
{
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(iMaxPvNameLength);
  return shape;
}

const char*
EpicsPvCtrlString::value(uint32_t i) const {
  return data()+i*MAX_STRING_SIZE;
}
std::vector<int> EpicsPvCtrlString::_data_shape() const
{
  std::vector<int> shape;
  shape.reserve(2);
  shape.push_back(this->numElements());
  shape.push_back( MAX_STRING_SIZE);
  return shape;
}

int16_t
EpicsPvCtrlShort::value(uint32_t i) const {
  return data()[i];
}
std::vector<int> EpicsPvCtrlShort::_data_shape() const
{
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(this->numElements());
  return shape;
}

float
EpicsPvCtrlFloat::value(uint32_t i) const {
  return data()[i];
}
std::vector<int> EpicsPvCtrlFloat::_data_shape() const
{
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(this->numElements());
  return shape;
}

uint16_t
EpicsPvCtrlEnum::value(uint32_t i) const {
  return data()[i];
}
std::vector<int> EpicsPvCtrlEnum::_data_shape() const
{
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(this->numElements());
  return shape;
}

uint8_t
EpicsPvCtrlChar::value(uint32_t i) const {
  return data()[i];
}
std::vector<int> EpicsPvCtrlChar::_data_shape() const
{
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(this->numElements());
  return shape;
}

int32_t
EpicsPvCtrlLong::value(uint32_t i) const {
  return data()[i];
}
std::vector<int> EpicsPvCtrlLong::_data_shape() const
{
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(this->numElements());
  return shape;
}

double
EpicsPvCtrlDouble::value(uint32_t i) const {
  return data()[i];
}
std::vector<int> EpicsPvCtrlDouble::_data_shape() const
{
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(this->numElements());
  return shape;
}

const char*
EpicsPvTimeString::value(uint32_t i) const {
  return data()+MAX_STRING_SIZE*i;
}
std::vector<int> EpicsPvTimeString::_data_shape() const
{
  std::vector<int> shape;
  shape.reserve(2);
  shape.push_back(this->numElements());
  shape.push_back( MAX_STRING_SIZE);
  return shape;
}

int16_t
EpicsPvTimeShort::value(uint32_t i) const {
  return data()[i];
}
std::vector<int> EpicsPvTimeShort::_data_shape() const
{
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(this->numElements());
  return shape;
}

float
EpicsPvTimeFloat::value(uint32_t i) const {
  return data()[i];
}
std::vector<int> EpicsPvTimeFloat::_data_shape() const
{
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(this->numElements());
  return shape;
}

uint16_t
EpicsPvTimeEnum::value(uint32_t i) const {
  return data()[i];
}
std::vector<int> EpicsPvTimeEnum::_data_shape() const
{
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(this->numElements());
  return shape;
}

uint8_t
EpicsPvTimeChar::value(uint32_t i) const {
  return data()[i];
}
std::vector<int> EpicsPvTimeChar::_data_shape() const
{
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(this->numElements());
  return shape;
}

int32_t
EpicsPvTimeLong::value(uint32_t i) const {
  return data()[i];
}
std::vector<int> EpicsPvTimeLong::_data_shape() const
{
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(this->numElements());
  return shape;
}

double
EpicsPvTimeDouble::value(uint32_t i) const {
  return data()[i];
}
std::vector<int> EpicsPvTimeDouble::_data_shape() const
{
  std::vector<int> shape;
  shape.reserve(1);
  shape.push_back(this->numElements());
  return shape;
}

} // namespace Epics
} // namespace PsddlPds
