#ifndef IMGALGOS_PRINCETONIMAGEPRODUCER_H
#define IMGALGOS_PRINCETONIMAGEPRODUCER_H

//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class PrincetonImageProducer.
// 1. Get Camera data as uint16_t
// 2. Do nothing for now...
// 3. Save image in the event as ndarray<uint16_t,2>
//------------------------------------------------------------------------

//-----------------
// C/C++ Headers --
//-----------------

//----------------------
// Base Class Headers --
//----------------------
#include "psana/Module.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------

//		---------------------
// 		-- Class Interface --
//		---------------------

namespace ImgAlgos {

/// @addtogroup ImgAlgos

/**
 *  @ingroup ImgAlgos
 *
 *  @brief Example module class for psana
 *
 *  This software was developed for the LCLS project.  If you use all or 
 *  part of it, please give an appropriate acknowledgment.
 *
 *  @version \$Id$
 *
 *  @author Mikhail S. Dubrovin
 */

class PrincetonImageProducer : public Module {
public:

  // Default constructor
  PrincetonImageProducer (const std::string& name) ;

  // Destructor
  virtual ~PrincetonImageProducer () ;

  /// Method which is called once at the beginning of the job
  virtual void beginJob(Event& evt, Env& env);
  
  /// Method which is called at the beginning of the run
  virtual void beginRun(Event& evt, Env& env);
  
  /// Method which is called at the beginning of the calibration cycle
  virtual void beginCalibCycle(Event& evt, Env& env);
  
  /// Method which is called with event data, this is the only required 
  /// method, all other methods are optional
  virtual void event(Event& evt, Env& env);
  
  /// Method which is called at the end of the calibration cycle
  virtual void endCalibCycle(Event& evt, Env& env);

  /// Method which is called at the end of the run
  virtual void endRun(Event& evt, Env& env);

  /// Method which is called once at the end of the job
  virtual void endJob(Event& evt, Env& env);

protected:
  void procEvent(Event& evt, Env& env);
  void saveImageInEvent(Event& evt, double *p_data, const unsigned *shape);
  void printInputParameters();
  void printEventRecord(Event& evt, std::string comment="");
  void printSummary(Event& evt, std::string comment="");

private:

  Pds::Src       m_src;              // source address of the data object
  Source         m_str_src;          // string with source name
  std::string    m_key_in;           // string with key for input data
  std::string    m_key_out;          // string with key for output image
  unsigned       m_print_bits;       // control print bits
  long           m_count;            // local event counter

  double*        m_data;             // pointer to output image data
  //ndarray<double,2>* m_ndarr; 
};

} // namespace ImgAlgos

#endif // IMGALGOS_PRINCETONIMAGEPRODUCER_H