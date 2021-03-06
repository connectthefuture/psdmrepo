/* Do not edit this file, as it is auto-generated */

#ifndef PSDDL_PYTHON_ENCODER_DDL_WRAPPER_H
#define PSDDL_PYTHON_ENCODER_DDL_WRAPPER_H 1

#include <psddl_python/DdlWrapper.h>
#include <vector>
#include <ndarray/ndarray.h>
#include <pdsdata/xtc/TypeId.hh>
#include <psddl_psana/encoder.ddl.h> // inc_psana

namespace psddl_python {
namespace Encoder {

using namespace boost::python;
using boost::python::api::object;
using boost::shared_ptr;
using std::vector;

void createWrappers(PyObject* module);

class ConfigV1_Wrapper {
  shared_ptr<Psana::Encoder::ConfigV1> _o;
  Psana::Encoder::ConfigV1* o;
public:
  enum { TypeId = Pds::TypeId::Id_EncoderConfig };
  enum { Version = 1 };
  ConfigV1_Wrapper(shared_ptr<Psana::Encoder::ConfigV1> obj) : _o(obj), o(_o.get()) {}
  ConfigV1_Wrapper(Psana::Encoder::ConfigV1* obj) : o(obj) {}
  uint32_t chan_num() const { return o->chan_num(); }
  uint32_t count_mode() const { return o->count_mode(); }
  uint32_t quadrature_mode() const { return o->quadrature_mode(); }
  uint32_t input_num() const { return o->input_num(); }
  uint32_t input_rising() const { return o->input_rising(); }
  uint32_t ticks_per_sec() const { return o->ticks_per_sec(); }
};

class ConfigV2_Wrapper {
  shared_ptr<Psana::Encoder::ConfigV2> _o;
  Psana::Encoder::ConfigV2* o;
public:
  enum { TypeId = Pds::TypeId::Id_EncoderConfig };
  enum { Version = 2 };
  ConfigV2_Wrapper(shared_ptr<Psana::Encoder::ConfigV2> obj) : _o(obj), o(_o.get()) {}
  ConfigV2_Wrapper(Psana::Encoder::ConfigV2* obj) : o(obj) {}
  uint32_t chan_mask() const { return o->chan_mask(); }
  uint32_t count_mode() const { return o->count_mode(); }
  uint32_t quadrature_mode() const { return o->quadrature_mode(); }
  uint32_t input_num() const { return o->input_num(); }
  uint32_t input_rising() const { return o->input_rising(); }
  uint32_t ticks_per_sec() const { return o->ticks_per_sec(); }
};

class DataV1_Wrapper {
  shared_ptr<Psana::Encoder::DataV1> _o;
  Psana::Encoder::DataV1* o;
public:
  enum { TypeId = Pds::TypeId::Id_EncoderData };
  enum { Version = 1 };
  DataV1_Wrapper(shared_ptr<Psana::Encoder::DataV1> obj) : _o(obj), o(_o.get()) {}
  DataV1_Wrapper(Psana::Encoder::DataV1* obj) : o(obj) {}
  uint32_t timestamp() const { return o->timestamp(); }
  uint32_t encoder_count() const { return o->encoder_count(); }
  int32_t value() const { return o->value(); }
};

class DataV2_Wrapper {
  shared_ptr<Psana::Encoder::DataV2> _o;
  Psana::Encoder::DataV2* o;
public:
  enum { TypeId = Pds::TypeId::Id_EncoderData };
  enum { Version = 2 };
  DataV2_Wrapper(shared_ptr<Psana::Encoder::DataV2> obj) : _o(obj), o(_o.get()) {}
  DataV2_Wrapper(Psana::Encoder::DataV2* obj) : o(obj) {}
  uint32_t timestamp() const { return o->timestamp(); }
  PyObject* encoder_count() const { ND_CONVERT(o->encoder_count(), uint32_t, 1); }
  int32_t value(uint32_t i) const { return o->value(i); }
};

  class ConfigV1_Getter : public psddl_python::Getter {
  public:
    const std::type_info& typeinfo() const { return typeid(Psana::Encoder::ConfigV1);}
    const char* getTypeName() const { return "Psana::Encoder::ConfigV1";}
    int getVersion() const { return Psana::Encoder::ConfigV1::Version; }
    object convert(const boost::shared_ptr<void>& vdata) const {
      shared_ptr<Psana::Encoder::ConfigV1> result = boost::static_pointer_cast<Psana::Encoder::ConfigV1>(vdata);
      return result.get() ? object(ConfigV1_Wrapper(result)) : object();
    }
  };

  class ConfigV2_Getter : public psddl_python::Getter {
  public:
    const std::type_info& typeinfo() const { return typeid(Psana::Encoder::ConfigV2);}
    const char* getTypeName() const { return "Psana::Encoder::ConfigV2";}
    int getVersion() const { return Psana::Encoder::ConfigV2::Version; }
    object convert(const boost::shared_ptr<void>& vdata) const {
      shared_ptr<Psana::Encoder::ConfigV2> result = boost::static_pointer_cast<Psana::Encoder::ConfigV2>(vdata);
      return result.get() ? object(ConfigV2_Wrapper(result)) : object();
    }
  };

  class DataV1_Getter : public psddl_python::Getter {
  public:
    const std::type_info& typeinfo() const { return typeid(Psana::Encoder::DataV1);}
    const char* getTypeName() const { return "Psana::Encoder::DataV1";}
    int getVersion() const { return Psana::Encoder::DataV1::Version; }
    object convert(const boost::shared_ptr<void>& vdata) const {
      shared_ptr<Psana::Encoder::DataV1> result = boost::static_pointer_cast<Psana::Encoder::DataV1>(vdata);
      return result.get() ? object(DataV1_Wrapper(result)) : object();
    }
  };

  class DataV2_Getter : public psddl_python::Getter {
  public:
    const std::type_info& typeinfo() const { return typeid(Psana::Encoder::DataV2);}
    const char* getTypeName() const { return "Psana::Encoder::DataV2";}
    int getVersion() const { return Psana::Encoder::DataV2::Version; }
    object convert(const boost::shared_ptr<void>& vdata) const {
      shared_ptr<Psana::Encoder::DataV2> result = boost::static_pointer_cast<Psana::Encoder::DataV2>(vdata);
      return result.get() ? object(DataV2_Wrapper(result)) : object();
    }
  };
} // namespace Encoder
} // namespace psddl_python
#endif // PSDDL_PYTHON_ENCODER_DDL_WRAPPER_H
