//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class Group...
//
// Author List:
//      Andrei Salnikov
//
//------------------------------------------------------------------------
#include "Lusi/Lusi.h"

//-----------------------
// This Class's Header --
//-----------------------
#include "hdf5pp/Group.h"

//-----------------
// C/C++ Headers --
//-----------------

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "hdf5pp/Exceptions.h"

//-----------------------------------------------------------------------
// Local Macros, Typedefs, Structures, Unions and Forward Declarations --
//-----------------------------------------------------------------------

//		----------------------------------------
// 		-- Public Function Member Definitions --
//		----------------------------------------

namespace hdf5pp {

//----------------
// Constructors --
//----------------
Group::Group ( hid_t grp )
  : m_id( new hid_t(grp), GroupPtrDeleter() )
{
}

//--------------
// Destructor --
//--------------
Group::~Group ()
{
}

// factory methods
Group
Group::createGroup ( hid_t parent, const std::string& name )
{
  // allow creatyion of intermediate directories
  hid_t lcpl_id = H5Pcreate( H5P_LINK_CREATE ) ;
  H5Pset_create_intermediate_group( lcpl_id, 1 ) ;
  hid_t f_id = H5Gcreate2 ( parent, name.c_str(), lcpl_id, H5P_DEFAULT, H5P_DEFAULT ) ;
  H5Pclose( lcpl_id ) ;
  if ( f_id < 0 ) {
    throw Hdf5CallException( "File::create", "H5Gcreate2") ;
  }
  return Group(f_id) ;
}

Group
Group::openGroup ( hid_t parent, const std::string& name )
{
  hid_t f_id = H5Gopen2 ( parent, name.c_str(), H5P_DEFAULT ) ;
  if ( f_id < 0 ) {
    throw Hdf5CallException( "File::create", "H5Gopen2") ;
  }
  return Group(f_id) ;
}

// close the group
void
Group::close()
{
  m_id.reset();
}


} // namespace hdf5pp
