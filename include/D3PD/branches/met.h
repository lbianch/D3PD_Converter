#ifndef D3PD_BRANCHES_MET_H
#define D3PD_BRANCHES_MET_H
#include "D3PD/branches/base.h"
#include "D3PD/objects/met.h"

namespace D3PD {
  namespace Branches {

    class MET : public virtual Tree {
    public:
      MET();

      D3PD::Objects::MET GetMET() const;
      
      Float_t MET_RefGamma_et = 0.0F;
      Float_t MET_RefGamma_phi = 0.0F; 
      Float_t MET_RefTau_et = 0.0F;
      Float_t MET_RefTau_phi = 0.0F; 
      Float_t MET_CellOut_Eflow_et = 0.0F; 
      Float_t MET_CellOut_Eflow_phi = 0.0F;
    };

  }
}

#endif
