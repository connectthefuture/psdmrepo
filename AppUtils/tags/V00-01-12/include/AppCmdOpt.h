//--------------------------------------------------------------------------
//
// Environment:
//      This software was developed for the BaBar collaboration.  If you
//      use all or part of it, please give an appropriate acknowledgement.
//
// Copyright Information:
//	Copyright (C) 2003	SLAC
//
//------------------------------------------------------------------------

#ifndef APPUTILS_APPCMDOPT_HH
#define APPUTILS_APPCMDOPT_HH

//-------------
// C Headers --
//-------------
extern "C" {
}

//---------------
// C++ Headers --
//---------------

//----------------------
// Base Class Headers --
//----------------------
#include "AppUtils/AppCmdOptBase.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------

//		---------------------
// 		-- Class Interface --
//		---------------------

namespace AppUtils {

/// @addtogroup AppUtils

/**
 *  @ingroup AppUtils
 *
 *  This class defines a command line option with argument. This is a templated
 *  class parameterized by the type of the argument. Any type supported by the
 *  AppCmdTypeTraits can be used as a template parameter.
 *
 *  This software was developed for the BaBar collaboration.  If you
 *  use all or part of it, please give an appropriate acknowledgement.
 *
 *  Copyright (C) 2003		SLAC
 *
 *  @see AppCmdOptBase
 *
 *  @version $Id$
 *
 *  @author Andy Salnikov	(originator)
 */


template<class Type>
class AppCmdOpt : public AppCmdOptBase {

public:

  /**
   *  Make an option with an argument
   */
  AppCmdOpt ( char shortOpt,
              const std::string& longOpt,
              const std::string& name,
              const std::string& descr,
              const Type& defValue ) ;

  // option with the long name only
  AppCmdOpt ( const std::string& longOpt,
              const std::string& name,
              const std::string& descr,
              const Type& defValue ) ;

  // option with the short name only
  AppCmdOpt ( char shortOpt,
              const std::string& name,
              const std::string& descr,
              const Type& defValue ) ;

  /// Destructor
  virtual ~AppCmdOpt( ) throw() ;

  /**
   *  Returns true if option requires argument. Does not make sense for
   *  positional arguments.
   */
  virtual bool hasArgument() const throw() ;

  /**
   *  Get the name of the argument, only used if hasArgument() returns true
   */
  virtual const std::string& name() const throw() ;

  /**
   *  Get one-line description
   */
  virtual const std::string& description() const throw() ;

  /**
   *  Return short option symbol for -x option, or @c NULL if no short option
   */
  virtual char shortOption() const throw() ;

  /**
   *  Return long option symbol for --xxxxx option, or empty string
   */
  virtual const std::string& longOption() const throw() ;

  /**
   *  Set option's argument. The value string will be empty if hasArgument() is false
   */
  virtual void setValue( const std::string& value ) throw(AppCmdException) ;

  /**
   *  True if the value of the option was changed from command line.
   */
  virtual bool valueChanged() const throw() ;

  /**
   *  Return current value of the argument
   */
  virtual const Type& value() const throw() ;

  /**
   *  Return default value of the argument
   */
  const Type& defValue() const throw() { return _defValue ; }

  /**
   *  Reset option to its default value
   */
  virtual void reset() throw() ;

protected:

  // Helper functions

private:

  // Friends

  // Data members
  const char _shortOpt ;
  const std::string _longOpt ;
  const std::string _name ;
  const std::string _descr ;
  Type _value ;
  const Type _defValue ;
  bool _changed ;

  // Note: if your class needs a copy constructor or an assignment operator,
  //  make one of the following public and implement it.
  AppCmdOpt( const AppCmdOpt<Type>& );  // Copy Constructor
  AppCmdOpt<Type>& operator= ( const AppCmdOpt<Type>& );

};

} // namespace AppUtils

#include  "AppUtils/AppCmdOpt.icc"

#endif  // APPUTILS_APPCMDOPT_HH