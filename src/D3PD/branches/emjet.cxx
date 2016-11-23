#include <iostream>
#include <exception>
#include <cmath>
#include "utils/range.h"
#include "D3PD/branches/emjet.h"

namespace D3PD {
    
  Branches::EMJet::EMJet() {
    if(!Tree::GetTree()) {
      std::cout << "EMJet being constructed on an empty Tree" << std::endl;
      return;
    }
    SetBranchAddress("jet_AntiKt4TopoEM_n", &jet_AntiKt4TopoEM_n);
    SetBranchAddress("jet_AntiKt4TopoEM_E", &jet_AntiKt4TopoEM_E);
    SetBranchAddress("jet_AntiKt4TopoEM_pt", &jet_AntiKt4TopoEM_pt);
    SetBranchAddress("jet_AntiKt4TopoEM_eta", &jet_AntiKt4TopoEM_eta);
    SetBranchAddress("jet_AntiKt4TopoEM_phi", &jet_AntiKt4TopoEM_phi);
    SetBranchAddress("jet_AntiKt4TopoEM_m", &jet_AntiKt4TopoEM_m);
    SetBranchAddress("jet_AntiKt4TopoEM_emscale_E", &jet_AntiKt4TopoEM_emscale_E);
    SetBranchAddress("jet_AntiKt4TopoEM_emscale_pt", &jet_AntiKt4TopoEM_emscale_pt);
    SetBranchAddress("jet_AntiKt4TopoEM_emscale_eta", &jet_AntiKt4TopoEM_emscale_eta);
    SetBranchAddress("jet_AntiKt4TopoEM_emscale_phi", &jet_AntiKt4TopoEM_emscale_phi);
    SetBranchAddress("jet_AntiKt4TopoEM_emscale_m", &jet_AntiKt4TopoEM_emscale_m);
    SetBranchAddress("jet_AntiKt4TopoEM_EtaOrigin", &jet_AntiKt4TopoEM_EtaOrigin);
    SetBranchAddress("jet_AntiKt4TopoEM_PhiOrigin", &jet_AntiKt4TopoEM_PhiOrigin);
    SetBranchAddress("jet_AntiKt4TopoEM_MOrigin", &jet_AntiKt4TopoEM_MOrigin);
    SetBranchAddress("jet_AntiKt4TopoEM_NegativeE", &jet_AntiKt4TopoEM_NegativeE);
    SetBranchAddress("jet_AntiKt4TopoEM_jvtxf", &jet_AntiKt4TopoEM_jvtxf);
    SetBranchAddress("jet_AntiKt4TopoEM_BCH_CORR_JET", &jet_AntiKt4TopoEM_BCH_CORR_JET);
    SetBranchAddress("jet_AntiKt4TopoEM_BCH_CORR_CELL", &jet_AntiKt4TopoEM_BCH_CORR_CELL);
    SetBranchAddress("jet_AntiKt4TopoEM_flavor_weight_IP3D", &jet_AntiKt4TopoEM_flavor_weight_IP3D);
    SetBranchAddress("jet_AntiKt4TopoEM_flavor_weight_SV0", &jet_AntiKt4TopoEM_flavor_weight_SV0);
    SetBranchAddress("jet_AntiKt4TopoEM_flavor_weight_SV1", &jet_AntiKt4TopoEM_flavor_weight_SV1);
    SetBranchAddress("jet_AntiKt4TopoEM_flavor_weight_JetFitterCOMBNN", &jet_AntiKt4TopoEM_flavor_weight_JetFitterCOMBNN);
    SetBranchAddress("jet_AntiKt4TopoEM_isBadLoose", &jet_AntiKt4TopoEM_isBadLoose);
    SetBranchAddress("jet_AntiKt4TopoEM_ActiveAreaPx", &jet_AntiKt4TopoEM_ActiveAreaPx);
    SetBranchAddress("jet_AntiKt4TopoEM_ActiveAreaPy", &jet_AntiKt4TopoEM_ActiveAreaPy);
    SetBranchAddress("jet_AntiKt4TopoEM_ActiveAreaPz", &jet_AntiKt4TopoEM_ActiveAreaPz);
    SetBranchAddress("jet_AntiKt4TopoEM_ActiveAreaE", &jet_AntiKt4TopoEM_ActiveAreaE);
    SetBranchAddress("jet_AntiKt4TopoEM_hecf", &jet_AntiKt4TopoEM_hecf);
    SetBranchAddress("jet_AntiKt4TopoEM_HECQuality", &jet_AntiKt4TopoEM_HECQuality);
    SetBranchAddress("jet_AntiKt4TopoEM_AverageLArQF", &jet_AntiKt4TopoEM_AverageLArQF);
    SetBranchAddress("jet_AntiKt4TopoEM_emfrac", &jet_AntiKt4TopoEM_emfrac);
    SetBranchAddress("jet_AntiKt4TopoEM_LArQuality", &jet_AntiKt4TopoEM_LArQuality);
    SetBranchAddress("jet_AntiKt4TopoEM_sumPtTrk", &jet_AntiKt4TopoEM_sumPtTrk);
    SetBranchAddress("jet_AntiKt4TopoEM_fracSamplingMax", &jet_AntiKt4TopoEM_fracSamplingMax);
    SetBranchAddress("jet_AntiKt4TopoEM_SamplingMax", &jet_AntiKt4TopoEM_SamplingMax);
    SetBranchAddress("Eventshape_rhoKt4EM", &Eventshape_rhoKt4EM);
  }

  Objects::EMJet Branches::EMJet::GetJet(const int iJet) const {
    if(iJet < 0 || iJet > jet_AntiKt4TopoEM_n) {
      throw std::out_of_range("Invalid jet number");
    }
    Objects::EMJet jet;
    jet.E = jet_AntiKt4TopoEM_E->at(iJet);
    jet.pt = jet_AntiKt4TopoEM_pt->at(iJet);
    jet.eta = jet_AntiKt4TopoEM_eta->at(iJet);
    jet.phi = jet_AntiKt4TopoEM_phi->at(iJet);
    jet.m = jet_AntiKt4TopoEM_m->at(iJet);
    jet.emscale_E = jet_AntiKt4TopoEM_emscale_E->at(iJet);
    jet.emscale_pt = jet_AntiKt4TopoEM_emscale_pt->at(iJet);
    jet.emscale_eta = jet_AntiKt4TopoEM_emscale_eta->at(iJet);
    jet.emscale_phi = jet_AntiKt4TopoEM_emscale_phi->at(iJet);
    jet.emscale_m = jet_AntiKt4TopoEM_emscale_m->at(iJet);
    jet.EtaOrigin = jet_AntiKt4TopoEM_EtaOrigin->at(iJet);
    jet.PhiOrigin = jet_AntiKt4TopoEM_PhiOrigin->at(iJet);
    jet.MOrigin = jet_AntiKt4TopoEM_MOrigin->at(iJet);
    jet.NegativeE = jet_AntiKt4TopoEM_NegativeE->at(iJet);
    jet.jvtxf = jet_AntiKt4TopoEM_jvtxf->at(iJet);
    jet.BCH_CORR_JET = jet_AntiKt4TopoEM_BCH_CORR_JET->at(iJet);
    jet.BCH_CORR_CELL = jet_AntiKt4TopoEM_BCH_CORR_CELL->at(iJet);
    jet.flavor_weight_IP3D = jet_AntiKt4TopoEM_flavor_weight_IP3D->at(iJet);
    jet.flavor_weight_SV0 = jet_AntiKt4TopoEM_flavor_weight_SV0->at(iJet);
    jet.flavor_weight_SV1 = jet_AntiKt4TopoEM_flavor_weight_SV1->at(iJet);
    jet.flavor_weight_JetFitterCOMBNN = jet_AntiKt4TopoEM_flavor_weight_JetFitterCOMBNN->at(iJet);
    jet.isBadLoose = jet_AntiKt4TopoEM_isBadLoose->at(iJet);
    jet.ActiveAreaPx = jet_AntiKt4TopoEM_ActiveAreaPx->at(iJet);
    jet.ActiveAreaPy = jet_AntiKt4TopoEM_ActiveAreaPy->at(iJet);
    jet.ActiveAreaPz = jet_AntiKt4TopoEM_ActiveAreaPz->at(iJet);
    jet.ActiveAreaE = jet_AntiKt4TopoEM_ActiveAreaE->at(iJet);
    jet.hecf = jet_AntiKt4TopoEM_hecf->at(iJet);
    jet.HECQuality = jet_AntiKt4TopoEM_HECQuality->at(iJet);
    jet.AverageLArQF = jet_AntiKt4TopoEM_AverageLArQF->at(iJet);
    jet.emfrac = jet_AntiKt4TopoEM_emfrac->at(iJet);
    jet.LArQuality = jet_AntiKt4TopoEM_LArQuality->at(iJet);
    jet.sumPtTrk = jet_AntiKt4TopoEM_sumPtTrk->at(iJet);
    jet.fracSamplingMax = jet_AntiKt4TopoEM_fracSamplingMax->at(iJet);
    jet.SamplingMax = jet_AntiKt4TopoEM_SamplingMax->at(iJet);
    return jet;
  }

  Objects::EMJet::Vector Branches::EMJet::GetJets() const {
    Objects::EMJet::Vector jets;
    jets.reserve(jet_AntiKt4TopoEM_n);
    for(Utilities::Range i(jet_AntiKt4TopoEM_n); i; ++i) {
      jets.push_back(GetJet(*i));
    }
    return jets;
  }
    
}

