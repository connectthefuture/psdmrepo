//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class DumpLusi...
//
// Author List:
//      Andrei Salnikov
//
//------------------------------------------------------------------------

//-----------------------
// This Class's Header --
//-----------------------
#include "psana_examples/DumpLusi.h"

//-----------------
// C/C++ Headers --
//-----------------

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "MsgLogger/MsgLogger.h"
#include "psddl_psana/lusi.ddl.h"

//-----------------------------------------------------------------------
// Local Macros, Typedefs, Structures, Unions and Forward Declarations --
//-----------------------------------------------------------------------

using namespace psana_examples;
PSANA_MODULE_FACTORY(DumpLusi)

//		----------------------------------------
// 		-- Public Function Member Definitions --
//		----------------------------------------

namespace psana_examples {

//----------------
// Constructors --
//----------------
DumpLusi::DumpLusi (const std::string& name)
  : Module(name)
{
  m_ipimbSrc = configStr("ipimbSource", "DetInfo(:Ipimb)");
  m_tmSrc = configStr("tmSource", "DetInfo(:Tm6740)");
}

//--------------
// Destructor --
//--------------
DumpLusi::~DumpLusi ()
{
}

// Method which is called at the beginning of the calibration cycle
void 
DumpLusi::beginCalibCycle(Event& evt, Env& env)
{
  MsgLog(name(), info, "in beginCalibCycle()");

  shared_ptr<Psana::Lusi::DiodeFexConfigV1> dconfig1 = env.configStore().get(m_ipimbSrc);
  if (dconfig1.get()) {
    
    WithMsgLog(name(), info, str) {
      str << "Lusi::DiodeFexConfigV1:";
      const float* base = dconfig1->base();
      const float* scale = dconfig1->scale();
      str << "\n  base =";
      for (int i = 0; i < Psana::Lusi::DiodeFexConfigV1::NRANGES; ++ i) {
        str << " " << base[i];
      }
      str << "\n  scale =";
      for (int i = 0; i < Psana::Lusi::DiodeFexConfigV1::NRANGES; ++ i) {
        str << " " << scale[i];
      }
    }
    
  }

  shared_ptr<Psana::Lusi::DiodeFexConfigV2> dconfig2 = env.configStore().get(m_ipimbSrc);
  if (dconfig2.get()) {
    
    WithMsgLog(name(), info, str) {
      str << "Lusi::DiodeFexConfigV2:";
      const float* base = dconfig2->base();
      const float* scale = dconfig2->scale();
      str << "\n  base =";
      for (int i = 0; i < Psana::Lusi::DiodeFexConfigV2::NRANGES; ++ i) {
        str << " " << base[i];
      }
      str << "\n  scale =";
      for (int i = 0; i < Psana::Lusi::DiodeFexConfigV2::NRANGES; ++ i) {
        str << " " << scale[i];
      }
    }
    
  }

  shared_ptr<Psana::Lusi::IpmFexConfigV1> iconfig1 = env.configStore().get(m_ipimbSrc);
  if (iconfig1.get()) {
    
    WithMsgLog(name(), info, str) {
      str << "Psana::Lusi::IpmFexConfigV1:";
      str << "\n  xscale = " << iconfig1->xscale();
      str << "\n  yscale = " << iconfig1->yscale();
      for (int ch = 0; ch < Psana::Lusi::IpmFexConfigV1::NCHANNELS; ++ ch) {
        str << "\n  channel #" << ch << ":";
        
        const Psana::Lusi::DiodeFexConfigV1& dconfig = iconfig1->diode(ch);
        const float* base = dconfig.base();
        const float* scale = dconfig.scale();
        str << "\n    base =";
        for (int i = 0; i < Psana::Lusi::DiodeFexConfigV1::NRANGES; ++ i) {
          str << " " << base[i];
        }
        str << "\n    scale =";
        for (int i = 0; i < Psana::Lusi::DiodeFexConfigV1::NRANGES; ++ i) {
          str << " " << scale[i];
        }
      }
    }
    
  }

  shared_ptr<Psana::Lusi::IpmFexConfigV2> iconfig2 = env.configStore().get(m_ipimbSrc);
  if (iconfig2.get()) {
    
    WithMsgLog(name(), info, str) {
      str << "Psana::Lusi::IpmFexConfigV2:";
      str << "\n  xscale = " << iconfig2->xscale();
      str << "\n  yscale = " << iconfig2->yscale();
      for (int ch = 0; ch < Psana::Lusi::IpmFexConfigV2::NCHANNELS; ++ ch) {
        str << "\n  channel #" << ch << ":";
        
        const Psana::Lusi::DiodeFexConfigV2& dconfig = iconfig2->diode(ch);
        const float* base = dconfig.base();
        const float* scale = dconfig.scale();
        str << "\n    base =";
        for (int i = 0; i < Psana::Lusi::DiodeFexConfigV2::NRANGES; ++ i) {
          str << " " << base[i];
        }
        str << "\n    scale =";
        for (int i = 0; i < Psana::Lusi::DiodeFexConfigV2::NRANGES; ++ i) {
          str << " " << scale[i];
        }
      }
    }
    
  }

  shared_ptr<Psana::Lusi::PimImageConfigV1> pconfig = env.configStore().get(m_tmSrc);
  if (pconfig.get()) {
    
    WithMsgLog(name(), info, str) {
      str << "Psana::Lusi::PimImageConfigV1:";
      str << "\n  xscale = " << pconfig->xscale();
      str << "\n  yscale = " << pconfig->yscale();
    }
    
  }

}

// Method which is called with event data
void 
DumpLusi::event(Event& evt, Env& env)
{
  shared_ptr<Psana::Lusi::DiodeFexV1> diode = evt.get(m_ipimbSrc);
  if (diode.get()) {
    WithMsgLog(name(), info, str) {
      str << "Lusi::DiodeFexV1: value = " << diode->value();
    }
  }

  shared_ptr<Psana::Lusi::IpmFexV1> fex = evt.get(m_ipimbSrc);
  if (fex.get()) {
    WithMsgLog(name(), info, str) {
      str << "Psana::Lusi::IpmFexV1:";
      str << "\n  sum = " << fex->sum();
      str << "\n  xpos = " << fex->xpos();
      str << "\n  ypos = " << fex->ypos();

      const float* channel = fex->channel();
      str << "\n  channel =";
      for (int i = 0; i < Psana::Lusi::IpmFexV1::NCHANNELS; ++ i) {
        str << " " << channel[i];
      }
    }
  }

}

} // namespace psana_examples
