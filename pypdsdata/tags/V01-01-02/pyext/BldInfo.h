#ifndef PYPDSDATA_BLDINFO_H
#define PYPDSDATA_BLDINFO_H

//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class BldInfo.
//
//------------------------------------------------------------------------

//-----------------
// C/C++ Headers --
//-----------------

//----------------------
// Base Class Headers --
//----------------------
#include "types/PdsDataTypeEmbedded.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
#include "pdsdata/xtc/BldInfo.hh"

//    ---------------------
//    -- Class Interface --
//    ---------------------

namespace pypdsdata {

/// @addtogroup pypdsdata

/**
 *  @ingroup pypdsdata
 *
 *  This software was developed for the LUSI project.  If you use all or
 *  part of it, please give an appropriate acknowledgment.
 *
 *  @version $Id$
 *
 *  @author Andrei Salnikov
 */

class BldInfo : public PdsDataTypeEmbedded<BldInfo,Pds::BldInfo> {
public:

  typedef PdsDataTypeEmbedded<BldInfo,Pds::BldInfo> BaseType;

  /// Initialize Python type and register it in a module
  static void initType( PyObject* module );

  // Dump object info to a stream
  void print(std::ostream& out) const;
};

} // namespace pypdsdata

namespace Pds {
inline PyObject* toPython(const Pds::BldInfo& v) { return pypdsdata::BldInfo::PyObject_FromPds(v); }
}

#endif // PYPDSDATA_BLDINFO_H
