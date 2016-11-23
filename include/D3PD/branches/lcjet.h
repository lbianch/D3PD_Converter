#ifndef D3PD_BRANCHES_LCJET_H
#define D3PD_BRANCHES_LCJET_H
#include <vector>
#include "D3PD/branches/base.h"
#include "D3PD/objects/lcjet.h"

namespace D3PD {
  namespace Branches {
    
    class LCJet : public virtual Tree {
    public:
      LCJet();

      D3PD::Objects::LCJet GetJet(const int) const;
      D3PD::Objects::LCJet::Vector GetJets() const;

      Int_t jet_AntiKt4LCTopo_n = 0;
      std::vector<float>* jet_AntiKt4LCTopo_constscale_E = nullptr;
      std::vector<float>* jet_AntiKt4LCTopo_constscale_eta = nullptr;
      std::vector<float>* jet_AntiKt4LCTopo_constscale_phi = nullptr;
      std::vector<float>* jet_AntiKt4LCTopo_constscale_m = nullptr;
      std::vector<float>* jet_AntiKt4LCTopo_ActiveAreaPx = nullptr;
      std::vector<float>* jet_AntiKt4LCTopo_ActiveAreaPy = nullptr;
      std::vector<float>* jet_AntiKt4LCTopo_ActiveAreaPz = nullptr;
      std::vector<float>* jet_AntiKt4LCTopo_ActiveAreaE = nullptr;
      std::vector<std::vector<float> >* jet_AntiKt4LCTopo_MET_wet = nullptr;
      std::vector<std::vector<float> >* jet_AntiKt4LCTopo_MET_wpx = nullptr;
      std::vector<std::vector<float> >* jet_AntiKt4LCTopo_MET_wpy = nullptr;
      std::vector<std::vector<unsigned> >* jet_AntiKt4LCTopo_MET_statusWord = nullptr;
      Float_t Eventshape_rhoKt4LC = 0.0F;
    };
    
  }
}

#endif
