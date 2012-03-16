#ifndef IMGALGOS_EVENTSHORTLISTFILTER_H
#define IMGALGOS_EVENTSHORTLISTFILTER_H

//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class EventShortListFilter.
//
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

class EventShortListFilter : public Module {
public:

  // Default constructor
  EventShortListFilter (const std::string& name) ;

  // Destructor
  virtual ~EventShortListFilter () ;

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
  void printInputParameters();
  void parseEvtString();
  void parseOneRecord(char* rec);
  bool eventIsInList();

private:
  bool     m_filter;
  unsigned m_first;
  unsigned m_last;
  std::string m_evtstring;
  unsigned m_count;
  unsigned m_selected;

  std::vector<unsigned> m_events;
  bool m_event_list_is_empty;
};

} // namespace ImgAlgos

#endif // IMGALGOS_EVENTSHORTLISTFILTER_H
