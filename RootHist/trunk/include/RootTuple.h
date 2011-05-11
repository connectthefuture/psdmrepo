#ifndef ROOTHIST_ROOTTUPLE_H
#define ROOTHIST_ROOTTUPLE_H

//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class RootTuple.
//
//------------------------------------------------------------------------

//-----------------
// C/C++ Headers --
//-----------------

#include <iostream>
#include <string>

//----------------------
// Base Class Headers --
//----------------------

#include "PSHist/Tuple.h"
#include "PSHist/Column.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------

#include "root/TTree.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------

class TTree;

//		---------------------
// 		-- Class Interface --
//		---------------------

namespace RootHist {

/**
 *  This class implements Tuple which is defined in ROOT as TTree.
 *  
 *  Essentially, constructor of this class creates the type-independent pointer TTree *m_tuple.
 *  
 *  This software was developed for the LCLS project.  If you use all or 
 *  part of it, please give an appropriate acknowledgment.
 *
 *  @see AdditionalClass
 *
 *  @version $Id$
 *
 *  @author Mikhail S. Dubrovin
 */

class RootTuple : public PSHist::Tuple {
public:

  // Constructors
  RootTuple () {}
  RootTuple ( const std::string &name="Tuple_N01", const std::string &title="This is a default comment to Tuple" );

  // Destructor
  virtual ~RootTuple(){}

  // Methods

  virtual PSHist::Column* column( const std::string &name, void* address, const std::string &columnlist );

  virtual void fill();
  virtual void reset();
  virtual void print(std::ostream &o) const;

  TTree *getTuplePointer(){ return m_tuple; }

private:

  // Data members
  TTree *m_tuple;

  // Static members

  // Copy constructor and assignment are disabled by default
  RootTuple              ( const RootTuple& );
  RootTuple & operator = ( const RootTuple& );

};

} // namespace RootHist

#endif // ROOTHIST_ROOTTUPLE_H
