#ifndef O2OTRANSLATOR_CSPADMINIELEMENTV1CVT_H
#define O2OTRANSLATOR_CSPADMINIELEMENTV1CVT_H

//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class CsPadMiniElementV1Cvt.
//
//------------------------------------------------------------------------

//-----------------
// C/C++ Headers --
//-----------------

//----------------------
// Base Class Headers --
//----------------------
#include "O2OTranslator/EvtDataTypeCvt.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "H5DataTypes/CsPadMiniElementV1.h"
#include "O2OTranslator/CalibObjectStore.h"
#include "O2OTranslator/ConfigObjectStore.h"
#include "O2OTranslator/CvtDataContainer.h"
#include "O2OTranslator/CvtDataContFactoryDef.h"
#include "O2OTranslator/CvtDataContFactoryTyped.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------

//		---------------------
// 		-- Class Interface --
//		---------------------

namespace O2OTranslator {

/**
 *  Special converter class for Pds::CsPad::ElementV1 XTC class
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

class CsPadMiniElementV1Cvt : public EvtDataTypeCvt<Pds::CsPad::MiniElementV1> {
public:

  typedef Pds::CsPad::MiniElementV1 XtcType ;

  // constructor
  CsPadMiniElementV1Cvt ( const std::string& typeGroupName,
                      const CalibObjectStore& calibStore,
                      hsize_t chunk_size,
                      int deflate ) ;

  // Destructor
  virtual ~CsPadMiniElementV1Cvt () ;

protected:

  // typed conversion method
  virtual void typedConvertSubgroup ( hdf5pp::Group group,
                                      const XtcType& data,
                                      size_t size,
                                      const Pds::TypeId& typeId,
                                      const O2OXtcSrc& src,
                                      const H5DataTypes::XtcClockTime& time ) ;

  /// method called when the driver closes a group in the file
  virtual void closeSubgroup( hdf5pp::Group group ) ;

private:

  typedef CvtDataContainer<CvtDataContFactoryTyped<H5DataTypes::CsPadMiniElementV1> > ElementCont ;
  typedef CvtDataContainer<CvtDataContFactoryTyped<int16_t> > PixelDataCont ;
  typedef CvtDataContainer<CvtDataContFactoryTyped<float> > CommonModeDataCont ;
  typedef CvtDataContainer<CvtDataContFactoryDef<H5DataTypes::XtcClockTime> > XtcClockTimeCont ;

  // Data members
  const CalibObjectStore& m_calibStore;
  hsize_t m_chunk_size ;
  int m_deflate ;
  ElementCont* m_elementCont ;
  PixelDataCont* m_pixelDataCont ;
  CommonModeDataCont* m_cmodeDataCont ;
  XtcClockTimeCont* m_timeCont ;

  // Copy constructor and assignment are disabled by default
  CsPadMiniElementV1Cvt ( const CsPadMiniElementV1Cvt& ) ;
  CsPadMiniElementV1Cvt& operator = ( const CsPadMiniElementV1Cvt& ) ;
};

} // namespace O2OTranslator

#endif // O2OTRANSLATOR_CSPADMINIELEMENTV1CVT_H
