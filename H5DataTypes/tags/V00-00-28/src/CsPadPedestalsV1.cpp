//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class CsPadPedestalsV1...
//
// Author List:
//      Andrei Salnikov
//
//------------------------------------------------------------------------
#include "SITConfig/SITConfig.h"

//-----------------------
// This Class's Header --
//-----------------------
#include "H5DataTypes/CsPadPedestalsV1.h"

//-----------------
// C/C++ Headers --
//-----------------
#include <algorithm>
#include <fstream>

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "hdf5pp/ArrayType.h"
#include "hdf5pp/CompoundType.h"
#include "hdf5pp/TypeTraits.h"
#include "H5DataTypes/H5DataUtils.h"
#include "MsgLogger/MsgLogger.h"

//-----------------------------------------------------------------------
// Local Macros, Typedefs, Structures, Unions and Forward Declarations --
//-----------------------------------------------------------------------

//		----------------------------------------
// 		-- Public Function Member Definitions --
//		----------------------------------------

namespace H5DataTypes {

//----------------
// Constructors --
//----------------
CsPadPedestalsV1::CsPadPedestalsV1 ()
{
  // fill all pedestals with zeros
  std::fill_n(&m_data.pedestals[0][0][0][0], int(CsPadPedestalsV1_Data::Size), 0.0f);
}

CsPadPedestalsV1::CsPadPedestalsV1 (const DataType& data) 
{ 
  const DataType::Pedestals& pdata = data.pedestals();
  const DataType::pedestal_t* src = &pdata[0][0][0][0];
  DataType::pedestal_t* dst = &m_data.pedestals[0][0][0][0];
  std::copy(src, src+int(CsPadPedestalsV1_Data::Size), dst );
}

//--------------
// Destructor --
//--------------
CsPadPedestalsV1::~CsPadPedestalsV1 ()
{
}


hdf5pp::Type
CsPadPedestalsV1::stored_type()
{
  return native_type() ;
}

hdf5pp::Type
CsPadPedestalsV1::native_type()
{
  hsize_t dims[4] = { CsPadPedestalsV1_Data::Quads,
                      CsPadPedestalsV1_Data::Sections,
                      CsPadPedestalsV1_Data::Columns,
                      CsPadPedestalsV1_Data::Rows}; 
  hdf5pp::ArrayType arrType = 
    hdf5pp::ArrayType::arrayType(hdf5pp::TypeTraits<DataType::pedestal_t>::native_type(), 4, dims) ;
  return arrType;
}

void
CsPadPedestalsV1::store( const DataType& data, hdf5pp::Group grp, const std::string& fileName )
{
  CsPadPedestalsV1 obj(data);
  hdf5pp::DataSet<CsPadPedestalsV1> ds = storeDataObject ( obj, "pedestals", grp ) ;

  // add attributes
  ds.createAttr<const char*>("source").store(fileName.c_str());
}

} // namespace H5DataTypes
