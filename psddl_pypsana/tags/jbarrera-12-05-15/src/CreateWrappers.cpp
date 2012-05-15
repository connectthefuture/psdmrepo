#define DECL(ns) namespace ns { extern void createWrappers(); }

namespace Psana {
#include "psddl_pypsana/CreateWrappers.h"
}

#undef DECL
#define DECL(ns) ns::createWrappers();

namespace Psana {
  namespace CreateWrappers {
    void createWrappers() {
#include "psddl_pypsana/CreateWrappers.h"
    }
  }
}
