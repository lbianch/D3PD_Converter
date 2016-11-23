#ifndef D3PD_BRANCHES_EMJET_H
#define D3PD_BRANCHES_EMJET_H
#include <vector>
#include "D3PD/branches/base.h"
#include "D3PD/objects/emjet.h"

namespace D3PD {
  namespace Branches {
    
    class EMJet : public virtual Tree {
    public:
      EMJet();

      D3PD::Objects::EMJet GetJet(const int) const;
      D3PD::Objects::EMJet::Vector GetJets() const;
      
      Int_t jet_AntiKt4TopoEM_n = 0;
      std::vector<float>* jet_AntiKt4TopoEM_E = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_pt = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_eta = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_phi = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_m = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_emscale_E = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_emscale_pt = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_emscale_eta = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_emscale_phi = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_emscale_m = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_EtaOrigin = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_PhiOrigin = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_MOrigin = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_NegativeE = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_jvtxf = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_BCH_CORR_JET = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_BCH_CORR_CELL = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_flavor_weight_IP3D = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_flavor_weight_SV0 = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_flavor_weight_SV1 = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_flavor_weight_JetFitterCOMBNN = nullptr;
      std::vector<int>* jet_AntiKt4TopoEM_isBadLoose = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_ActiveAreaPx = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_ActiveAreaPy = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_ActiveAreaPz = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_ActiveAreaE = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_hecf = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_HECQuality = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_AverageLArQF = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_emfrac = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_LArQuality = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_sumPtTrk = nullptr;
      std::vector<float>* jet_AntiKt4TopoEM_fracSamplingMax = nullptr;
      std::vector<int>* jet_AntiKt4TopoEM_SamplingMax = nullptr;
      Float_t Eventshape_rhoKt4EM = 0.0F;
    };
    
  }
}

#endif
