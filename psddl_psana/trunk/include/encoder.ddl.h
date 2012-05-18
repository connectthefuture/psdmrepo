#ifndef PSANA_ENCODER_DDL_H
#define PSANA_ENCODER_DDL_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include "ndarray/ndarray.h"
#include "pdsdata/xtc/TypeId.hh"
namespace Psana {
namespace Encoder {

/** @class ConfigV1

  
*/


class ConfigV1 {
public:
  enum { TypeId = Pds::TypeId::Id_EncoderConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  enum count_mode_type {
    WRAP_FULL,
    LIMIT,
    HALT,
    WRAP_PRESET,
    COUNT_END,
  };
  enum quad_mode {
    CLOCK_DIR,
    X1,
    X2,
    X4,
    QUAD_END,
  };
  virtual ~ConfigV1();
  bool operator==(const ConfigV1 &t) const { return this == &t; }
  virtual uint32_t chan_num() const = 0;
  virtual uint32_t count_mode() const = 0;
  virtual uint32_t quadrature_mode() const = 0;
  virtual uint32_t input_num() const = 0;
  virtual uint32_t input_rising() const = 0;
  virtual uint32_t ticks_per_sec() const = 0;
};

/** @class ConfigV2

  
*/


class ConfigV2 {
public:
  enum { TypeId = Pds::TypeId::Id_EncoderConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 2 /**< XTC type version number */ };
  enum count_mode_type {
    WRAP_FULL,
    LIMIT,
    HALT,
    WRAP_PRESET,
    COUNT_END,
  };
  enum quad_mode {
    CLOCK_DIR,
    X1,
    X2,
    X4,
    QUAD_END,
  };
  virtual ~ConfigV2();
  bool operator==(const ConfigV2 &t) const { return this == &t; }
  virtual uint32_t chan_mask() const = 0;
  virtual uint32_t count_mode() const = 0;
  virtual uint32_t quadrature_mode() const = 0;
  virtual uint32_t input_num() const = 0;
  virtual uint32_t input_rising() const = 0;
  virtual uint32_t ticks_per_sec() const = 0;
};

/** @class DataV1

  
*/


class DataV1 {
public:
  enum { TypeId = Pds::TypeId::Id_EncoderData /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  virtual ~DataV1();
  bool operator==(const DataV1 &t) const { return this == &t; }
  virtual uint32_t timestamp() const = 0;
  virtual uint32_t encoder_count() const = 0;
};

/** @class DataV2

  
*/


class DataV2 {
public:
  enum { TypeId = Pds::TypeId::Id_EncoderData /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 2 /**< XTC type version number */ };
  enum { NEncoders = 3 /**< Number of encoders. */ };
  virtual ~DataV2();
  bool operator==(const DataV2 &t) const { return this == &t; }
  virtual uint32_t timestamp() const = 0;
  virtual ndarray<uint32_t, 1> encoder_count() const = 0;
};
} // namespace Encoder
} // namespace Psana
#endif // PSANA_ENCODER_DDL_H
