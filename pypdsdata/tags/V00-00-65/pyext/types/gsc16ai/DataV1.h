#ifndef PYPDSDATA_GSC16AI_DataV1_H
#define PYPDSDATA_GSC16AI_DataV1_H

//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class DataV1.
//
//------------------------------------------------------------------------

//-----------------
// C/C++ Headers --
//-----------------

//----------------------
// Base Class Headers --
//----------------------
#include "../PdsDataType.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "pdsdata/gsc16ai/DataV1.hh"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------

//		---------------------
// 		-- Class Interface --
//		---------------------

namespace pypdsdata {
namespace Gsc16ai {

/**
 *  This software was developed for the LCLS project.  If you use all or
 *  part of it, please give an appropriate acknowledgment.
 *
 *  @see AdditionalClass
 *
 *  @version $Id$
 *
 *  @author Andrei Salnikov
 */

class DataV1 : public PdsDataType<DataV1,Pds::Gsc16ai::DataV1> {
public:

  typedef PdsDataType<DataV1,Pds::Gsc16ai::DataV1> BaseType;

  /// Initialize Python type and register it in a module
  static void initType( PyObject* module );

};

} // namespace Gsc16ai
} // namespace pypdsdata

#endif // PYPDSDATA_GSC16AI_DataV1_H
