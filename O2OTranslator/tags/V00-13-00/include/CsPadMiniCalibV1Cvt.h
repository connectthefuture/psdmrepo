#ifndef O2OTRANSLATOR_CSPADMINICALIBV1CVT_H
#define O2OTRANSLATOR_CSPADMINICALIBV1CVT_H

//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class CsPadMiniCalibV1Cvt.
//
//------------------------------------------------------------------------

//-----------------
// C/C++ Headers --
//-----------------
#include <string>
#include <stack>

//----------------------
// Base Class Headers --
//----------------------
#include "O2OTranslator/DataTypeCvtI.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
namespace O2OTranslator {
  class O2OMetaData;
  class CalibObjectStore;
}

//		---------------------
// 		-- Class Interface --
//		---------------------

namespace O2OTranslator {

/**
 *  Special converter class which reads cspad calibration data from 
 *  external source and prodices HDF5 object from it and also stores 
 *  calibration objects in calibration store.
 *
 *  This software was developed for the LCLS project.  If you use all or 
 *  part of it, please give an appropriate acknowledgment.
 *
 *  @see AdditionalClass
 *
 *  @version $Id$
 *
 *  @author Andrei Salnikov
 */

class CsPadMiniCalibV1Cvt : public DataTypeCvtI {
public:

  // Default constructor
  CsPadMiniCalibV1Cvt ( const std::string& typeGroupName,
          const O2OMetaData& metadata,
          CalibObjectStore& calibStore);

  // Destructor
  virtual ~CsPadMiniCalibV1Cvt () ;

  /// main method of this class
  virtual void convert ( const void* data, 
                         size_t size,
                         const Pds::TypeId& typeId,
                         const O2OXtcSrc& src,
                         const H5DataTypes::XtcClockTime& time ) ;

  /// method called when the driver makes a new group in the file
  virtual void openGroup( hdf5pp::Group group ) ;

  /// method called when the driver closes a group in the file
  virtual void closeGroup( hdf5pp::Group group ) ;

protected:
  
private:

  // Data members
  std::string m_typeGroupName ;
  const O2OMetaData& m_metadata;
  CalibObjectStore& m_calibStore;
  std::stack<hdf5pp::Group> m_groups ;

};

} // namespace O2OTranslator

#endif // O2OTRANSLATOR_CSPADMINICALIBV1CVT_H
