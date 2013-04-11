#ifndef ODBCPP_ODBCRESULT_H
#define ODBCPP_ODBCRESULT_H

//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class OdbcResult.
//
//------------------------------------------------------------------------

//-----------------
// C/C++ Headers --
//-----------------
#include <string>
#include <boost/shared_ptr.hpp>

//----------------------
// Base Class Headers --
//----------------------

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "odbcpp/OdbcColumnVar.h"
#include "odbcpp/OdbcException.h"
#include "odbcpp/OdbcResultHeader.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------

//		---------------------
// 		-- Class Interface --
//		---------------------

/**
 *  C++ interface for QDBS result set
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

namespace odbcpp {

class OdbcResult  {
public:

  // Default constructor
  OdbcResult ( OdbcHandle<OdbcStmt> stmtH ) ;

  // Destructor
  ~OdbcResult () ;

  // check if the result set is empty
  bool empty() const { return m_header.empty()  ; }

  // get access to header
  const OdbcResultHeader& header() const { return m_header ; }

  // Set the number of rows returned in a single fetch operation
  // All OdbcColumnVar should use the same size then. Note that
  // this sets statement attribute, be careful because the same
  // statement can be used by different results. Destructor resets
  // this value back to 1.
  void setRowArraySize( unsigned int rowArraySize = 1 ) ;

  // bind the column with a given name
  template <typename VarType>
  void bindColumn ( const std::string& name, OdbcColumnVar<VarType>& var ) {
    const OdbcColumnDescr* col = m_header.findColumn(name) ;
    if ( not col ) OdbcExceptionThrow ( "OdbcResult::bind - unknown column name "+name ) ;
    bindColumn ( col->columnNumber(), var ) ;
  }

  // bind the column with a given column number
  template <typename VarType>
  void bindColumn ( unsigned int columnNumber, OdbcColumnVar<VarType>& var ) ;

  // unbind all bound columns
  void unbindColumns() ;

  // fetch the next set of rows, return number of rows fetched
  unsigned int fetch() ;

  // fetch the row at offset, return number of rows fetched.
  // Parameters are the same as for SQLFetchScroll
  unsigned int fetchScroll( int orientation, int offset ) ;

  // close the cursor and discard all pending data
  void closeCursor() ;

protected:

  void updateRowArraySize( unsigned int nRow ) ;

private:

  // Data members
  OdbcHandle<OdbcStmt> m_stmtH ;
  OdbcResultHeader m_header ;
  SQLUINTEGER m_fetched ;
  SQLUINTEGER m_rowArraySize ;

  // Copy constructor and assignment are disabled by default
  OdbcResult ( const OdbcResult& ) ;
  OdbcResult operator = ( const OdbcResult& ) ;

};

typedef boost::shared_ptr<OdbcResult> OdbcResultPtr ;

// bind the column with a given column number
template <typename VarType>
inline
void
OdbcResult::bindColumn ( unsigned int columnNumber, OdbcColumnVar<VarType>& var )
{
  SQLRETURN r = SQLBindCol ( *m_stmtH,
                             columnNumber,
                             var.targetType(),
                             var.targetValuePtr(),
                             var.bufferLength(),
                             var.strLenOrIndPtr() );
  OdbcStatusCheck ( r, m_stmtH ) ;

  updateRowArraySize( var.nRows() ) ;
}

} // namespace odbcpp

#endif // ODBCPP_ODBCRESULT_H