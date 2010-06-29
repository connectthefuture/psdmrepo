#ifndef O2OTRANSLATOR_O2OEXCEPTIONS_H
#define O2OTRANSLATOR_O2OEXCEPTIONS_H

//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class O2OExceptions.
//
//------------------------------------------------------------------------

//-----------------
// C/C++ Headers --
//-----------------
#include <string>
#include <cerrno>
#include <boost/lexical_cast.hpp>

//----------------------
// Base Class Headers --
//----------------------
#include <stdexcept>

//-------------------------------
// Collaborating Class Headers --
//-------------------------------

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------

//		---------------------
// 		-- Class Interface --
//		---------------------

/**
 *  Exception classes
 *
 *  This software was developed for the LUSI project.  If you use all or
 *  part of it, please give an appropriate acknowledgement.
 *
 *  @see AdditionalClass
 *
 *  @version $Id$
 *
 *  @author Andrei Salnikov
 */

namespace O2OTranslator {

class O2OException : public std::runtime_error {
public:

  // Constructor
  O2OException ( const std::string& className, const std::string& what ) ;

};

class O2OErrnoException : public O2OException {
public:

    O2OErrnoException(const std::string& className, const std::string& what)
    : O2OException( className, what + ": " + strerror(errno) ) {}

};


// thrown for incorrect arguments provided
class O2OArgumentException : public O2OException {
public:

  O2OArgumentException( const std::string& msg )
    : O2OException( "O2OArgumentException", msg ) {}

};

class O2OFileOpenException : public O2OErrnoException {
public:

  O2OFileOpenException( const std::string& fileName )
    : O2OErrnoException( "O2OFileOpenException", "failed to open file "+fileName ) {}

};

class O2OXTCReadException : public O2OErrnoException {
public:

  O2OXTCReadException(const std::string& fileName)
    : O2OErrnoException( "O2OXTCReadException", "failed to read XTC file "+fileName ) {}

};

class O2OXTCSizeLimitException : public O2OException {
public:

    O2OXTCSizeLimitException(const std::string& fileName, size_t dgSize, size_t maxSize)
    : O2OException( "O2OXTCSizeLimitException", "datagram too large reading XTC file "+fileName+
            ": datagram size="+boost::lexical_cast<std::string>(dgSize) +
            ", max size="+boost::lexical_cast<std::string>(maxSize) ) {}

};

class O2OXTCTransitionException : public O2OException {
public:

  O2OXTCTransitionException( const std::string& type, const std::string& current )
    : O2OException( "O2OXTCTransitionException", "unexpected XTC transition type: "+type+", current state: "+current ) {}

};

class O2OXTCConfigException : public O2OException {
public:

  O2OXTCConfigException( const std::string& type )
    : O2OException( "O2OXTCConfigException", "configuration object missing for type "+type ) {}

};

class O2OXTCLevelException : public O2OException {
public:

  O2OXTCLevelException( const std::string& type, const std::string& level )
    : O2OException( "O2OXTCLevelException", "XTC object of type "+type+" not on Source level: "+level ) {}

};

class O2OXTCSyncException : public O2OException {
public:

  O2OXTCSyncException()
    : O2OException( "O2OXTCSyncException", "XTC streams are desynchronized" ) {}

};

class O2OXTCSizeException : public O2OException {
public:

  O2OXTCSizeException( const std::string& type, size_t expectedSize, size_t xtcSize )
    : O2OException( "O2OXTCSizeException", type + ": XTC size=" +
        boost::lexical_cast<std::string>(xtcSize) +
        ", expected size=" + boost::lexical_cast<std::string>(expectedSize) ) {}

};
/// Generic XTC exception, just give it a message
class O2OXTCGenException : public O2OException {
public:

  O2OXTCGenException( const std::string& msg )
    : O2OException( "O2OXTCGenException", msg ) {}

};

class O2OHdf5Exception : public O2OException {
public:

  O2OHdf5Exception( const std::string& function )
    : O2OException( "O2OHdf5Exception", "HDF5 error in call to function "+function ) {}

};


} // namespace O2OTranslator

#endif // O2OTRANSLATOR_O2OEXCEPTIONS_H
