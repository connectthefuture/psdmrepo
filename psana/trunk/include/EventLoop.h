#ifndef PSANA_EVENTLOOP_H
#define PSANA_EVENTLOOP_H

//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class EventLoop.
//
//------------------------------------------------------------------------

//-----------------
// C/C++ Headers --
//-----------------
#include <boost/shared_ptr.hpp>
#include <boost/utility.hpp>
#include <stack>
#include <queue>
#include <vector>
#include <utility>

//----------------------
// Base Class Headers --
//----------------------

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "psana/Module.h"
#include "PSEnv/Env.h"
#include "PSEvt/Event.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
namespace psana {
class InputModule;
class Module;
}

//		---------------------
// 		-- Class Interface --
//		---------------------

namespace psana {

/// @addtogroup psana

/**
 *  @ingroup psana
 *
 *  @brief Implementation of the event loop for psana.
 *
 *  The purpose of this class is to provide iteration over "events"
 *  in psana framework with well-defined properties. Event in this
 *  context means not only regular events but also transitions
 *  like BeginRun, EndRun, etc. Instance of this class acts like
 *  iterator which returns two items for each iteration -
 *  event type and event contents (PSEvt::Event object). It guarantees
 *  correct nesting of transitions and events, so that regular events
 *  happen only inside BeginCalibCycle/EndCalibCycle, which in turn
 *  happen only inside BeginRun/EndRun. On every iteration this instance
 *  calls corresponding method of the user modules before returning
 *  event to caller so that user modules can add more data to event.
 *
 *  This software was developed for the LCLS project.  If you use all or 
 *  part of it, please give an appropriate acknowledgment.
 *
 *  @version $Id$
 *
 *  @author Andy Salnikov
 */

class EventLoop : boost::noncopyable {
public:

  /// Enumeration for the event types returned by iterator
  enum EventType {
    None,             ///< Returned if there are no more events
    BeginRun,         ///< Returned at the begin of run
    BeginCalibCycle,  ///< Returned at the begin of calib cycle
    Event,            ///< Returned for regular event
    EndCalibCycle,    ///< Returned at the end of calib cycle
    EndRun,           ///< Returned at the end of run
  };

  typedef boost::shared_ptr<PSEvt::Event> EventPtr;
  typedef std::pair<EventType, EventPtr> value_type;

  /**
   *  @brief Constructor takes instance of input module, and a list of
   *  user modules.
   */
  EventLoop(const boost::shared_ptr<InputModule>& inputModule,
            const std::vector<boost::shared_ptr<Module> >& modules,
            const boost::shared_ptr<PSEnv::Env>& env);

  // Destructor
  ~EventLoop();

  /// Get environment object
  PSEnv::Env& env() const { return *m_env; }

  /**
   *  Method that runs one iteration and returns event type,
   *  and event object.
   */
  value_type next();

protected:

private:

  typedef void (Module::*ModuleMethod)(PSEvt::Event& evt, PSEnv::Env& env);

  /**
   *  Calls a method on all modules and returns summary  status.
   *
   *  @param[in] modules  List of modules
   *  @param[in] method   Pointer to the member function
   *  @param[in] evt      Event object
   *  @param[in] env      Environment object
   *  @param[in] ignoreSkip Should be set to false for event() method, true for all others
   */
  Module::Status callModuleMethod(ModuleMethod method, PSEvt::Event& evt, PSEnv::Env& env, bool ignoreSkip);

  // State order must not change, state machine depends on specific numbers
  enum State {StateNone=0, StateConfigured=1, StateRunning=2, StateScanning=3, NumStates=4};

  Module::Status newState(State state, const EventPtr& evt);
  Module::Status closeState(const EventPtr& evt);
  Module::Status unwind(State newState, const EventPtr& evt, bool ignoreStatus = false);

  boost::shared_ptr<InputModule> m_inputModule;
  std::vector<boost::shared_ptr<Module> > m_modules;
  boost::shared_ptr<PSEnv::Env> m_env;
  bool m_finished;
  State m_state;
  ModuleMethod m_newStateMethods[NumStates];
  EventType m_newStateEventType[NumStates];
  ModuleMethod m_closeStateMethods[NumStates];
  EventType m_closeStateEventType[NumStates];
  std::queue<value_type> m_values;
};

} // namespace psana

#endif // PSANA_EVENTLOOP_H
