#ifndef PSDDL_PDS2PSANA_LUSI_DDL_H
#define PSDDL_PDS2PSANA_LUSI_DDL_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include <boost/shared_ptr.hpp>
#include "psddl_psana/lusi.ddl.h"
#include "psddl_pdsdata/lusi.ddl.h"
namespace psddl_pds2psana {
namespace Lusi {
Psana::Lusi::DiodeFexConfigV1 pds_to_psana(PsddlPds::Lusi::DiodeFexConfigV1 pds);

Psana::Lusi::DiodeFexV1 pds_to_psana(PsddlPds::Lusi::DiodeFexV1 pds);


class IpmFexConfigV1 : public Psana::Lusi::IpmFexConfigV1 {
public:
  typedef PsddlPds::Lusi::IpmFexConfigV1 XtcType;
  typedef Psana::Lusi::IpmFexConfigV1 PsanaType;
  IpmFexConfigV1(const boost::shared_ptr<const XtcType>& xtcPtr);
  virtual ~IpmFexConfigV1();
  virtual const Psana::Lusi::DiodeFexConfigV1& diode(uint32_t i0) const;
  virtual float xscale() const;
  virtual float yscale() const;
  virtual std::vector<int> _diode_shape() const;
  const XtcType& _xtcObj() const { return *m_xtcObj; }
private:
  boost::shared_ptr<const XtcType> m_xtcObj;
  std::vector< Psana::Lusi::DiodeFexConfigV1 > _diode;
};

Psana::Lusi::IpmFexV1 pds_to_psana(PsddlPds::Lusi::IpmFexV1 pds);

Psana::Lusi::PimImageConfigV1 pds_to_psana(PsddlPds::Lusi::PimImageConfigV1 pds);

} // namespace Lusi
} // namespace psddl_pds2psana
#endif // PSDDL_PDS2PSANA_LUSI_DDL_H
