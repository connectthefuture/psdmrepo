//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class BldDataEBeamV1...
//
// Author List:
//      Andrei Salnikov
//
//------------------------------------------------------------------------

//-----------------------
// This Class's Header --
//-----------------------
#include "BldDataEBeamV1.h"

//-----------------
// C/C++ Headers --
//-----------------

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "../../Exception.h"
#include "../TypeLib.h"

//-----------------------------------------------------------------------
// Local Macros, Typedefs, Structures, Unions and Forward Declarations --
//-----------------------------------------------------------------------

namespace {

  // methods
  MEMBER_WRAPPER(pypdsdata::BldDataEBeamV1, uDamageMask)
  MEMBER_WRAPPER(pypdsdata::BldDataEBeamV1, fEbeamCharge)
  MEMBER_WRAPPER(pypdsdata::BldDataEBeamV1, fEbeamL3Energy)
  MEMBER_WRAPPER(pypdsdata::BldDataEBeamV1, fEbeamLTUPosX)
  MEMBER_WRAPPER(pypdsdata::BldDataEBeamV1, fEbeamLTUPosY)
  MEMBER_WRAPPER(pypdsdata::BldDataEBeamV1, fEbeamLTUAngX)
  MEMBER_WRAPPER(pypdsdata::BldDataEBeamV1, fEbeamLTUAngY)
  MEMBER_WRAPPER(pypdsdata::BldDataEBeamV1, fEbeamPkCurrBC2)
  PyObject* _repr( PyObject *self );

  PyGetSetDef getset[] = {
    {"uDamageMask",    uDamageMask,    0, "integer number", 0},
    {"fEbeamCharge",   fEbeamCharge,   0, "floating number, in nC", 0},
    {"fEbeamL3Energy", fEbeamL3Energy, 0, "floating number, in MeV", 0},
    {"fEbeamLTUPosX",  fEbeamLTUPosX,  0, "floating number, in mm", 0},
    {"fEbeamLTUPosY",  fEbeamLTUPosY,  0, "floating number, in mm", 0},
    {"fEbeamLTUAngX",  fEbeamLTUAngX,  0, "floating number, in mrad", 0},
    {"fEbeamLTUAngY",  fEbeamLTUAngY,  0, "floating number, in mrad", 0},
    {"fEbeamPkCurrBC2", fEbeamPkCurrBC2, 0, "floating number, in Amps", 0},
    {0, 0, 0, 0, 0}
  };

  char typedoc[] = "Python class wrapping C++ Pds::BldDataEBeamV1 class.";
}

//              ----------------------------------------
//              -- Public Function Member Definitions --
//              ----------------------------------------

void
pypdsdata::BldDataEBeamV1::initType( PyObject* module )
{
  PyTypeObject* type = BaseType::typeObject() ;
  type->tp_doc = ::typedoc;
  type->tp_getset = ::getset;
  type->tp_str = _repr;
  type->tp_repr = _repr;

  BaseType::initType( "BldDataEBeamV1", module );
}

namespace {

PyObject*
_repr( PyObject *self )
{
  Pds::BldDataEBeamV1* pdsObj = pypdsdata::BldDataEBeamV1::pdsObject(self);
  if(not pdsObj) return 0;

  char buf[64];
  snprintf( buf, sizeof buf, "BldDataEBeamV1(Charge=%g, L3Energy=%g, ...)",
            pdsObj->fEbeamCharge, pdsObj->fEbeamL3Energy );
  return PyString_FromString( buf );
}

}
