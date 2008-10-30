//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class AppBase...
//
// Author List:
//      Andrei Salnikov
//
//------------------------------------------------------------------------
#include "Lusi/Lusi.h"

//-----------------------
// This Class's Header --
//-----------------------
#include "AppUtils/AppBase.h"

//-----------------
// C/C++ Headers --
//-----------------
#include <iostream>

//-------------------------------
// Collaborating Class Headers --
//-------------------------------

//-----------------------------------------------------------------------
// Local Macros, Typedefs, Structures, Unions and Forward Declarations --
//-----------------------------------------------------------------------

namespace {

  /**
   *  removes dirname from the path name
   */
  std::string fixAppName ( const std::string& appName )
  {
    std::string::size_type idx = appName.rfind('/') ;
    if ( idx != std::string::npos ) {
      return std::string ( appName, idx+1 ) ;
    } else {
      return appName ;
    }
  }

}

//		----------------------------------------
// 		-- Public Function Member Definitions --
//		----------------------------------------

namespace AppUtils {

//----------------
// Constructors --
//----------------
AppBase::AppBase ( const std::string& appName )
  : _cmdline( ::fixAppName(appName) )
  , _optVerbose( 'v', "verbose", "verbose output, multiple allowed", 1 )
  , _optQuiet( 'q', "quiet", "quieter output, multiple allowed", 0 )
{
}

//--------------
// Destructor --
//--------------
AppBase::~AppBase ()
{
}

/**
 *  Run the application
 */
int
AppBase::run ( int argc, char** argv )
{
  // parse command line, set all options and arguments
  bool ok = _cmdline.parse ( argc, argv ) ;
  if ( ! ok ) {
    std::cerr << "Error parsing command line: " << _cmdline.getErrorString() << "\n" ;
    _cmdline.usage( std::cerr ) ;
    this->moreUsage ( std::cerr ) ;
    return 2 ;
  } else if ( _cmdline.helpWanted() ) {
    _cmdline.usage( std::cout ) ;
    this->moreUsage ( std::cout ) ;
    return 0 ;
  }

  int stat = preRunApp() ;
  if ( stat != 0 ) return stat ;

  // call subclass for some real stuff
  stat = this->runApp() ;
  if ( stat != 0 ) return stat ;

  stat = postRunApp() ;
  if ( stat != 0 ) return stat ;

  return 0 ;
}

/**
 *  add command line option or argument, typically called from subclass constructor
 */
bool
AppBase::addOption ( AppCmdOptBase& option )
{
  return _cmdline.addOption ( option ) ;
}

bool
AppBase::addArgument ( AppCmdArgBase& arg )
{
  return _cmdline.addArgument ( arg ) ;
}

/**
 *  print some additional info after the usage information is printed.
 */
void
AppBase::moreUsage ( std::ostream& out ) const
{
}

/**
 *  Method called before runApp, can be overriden in subclasses.
 *  Usually if you override it, call base class method too.
 */
int
AppBase::preRunApp ()
{
  return 0 ;
}

/**
 *  Method called after runApp, can be overriden in subclasses.
 *  Usually if you override it, call base class method too.
 */
int
AppBase::postRunApp ()
{
  return 0 ;
}

} // namespace AppUtils
