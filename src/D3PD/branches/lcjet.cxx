#include <iostream>
#include <exception>
#include <cmath>
#include "utils/range.h"
#include "D3PD/branches/lcjet.h"

namespace D3PD {
    
  Branches::LCJet::LCJet() {
    if(!Tree::GetTree()) {
      std::cout << "LCJet being constructed on an empty Tree" << std::endl;
      return;
    }
    SetBranchAddress("jet_AntiKt4LCTopo_n", &jet_AntiKt4LCTopo_n);
    SetBranchAddress("jet_AntiKt4LCTopo_constscale_E", &jet_AntiKt4LCTopo_constscale_E);
    SetBranchAddress("jet_AntiKt4LCTopo_constscale_eta", &jet_AntiKt4LCTopo_constscale_eta);
    SetBranchAddress("jet_AntiKt4LCTopo_constscale_phi", &jet_AntiKt4LCTopo_constscale_phi);
    SetBranchAddress("jet_AntiKt4LCTopo_constscale_m", &jet_AntiKt4LCTopo_constscale_m);
    SetBranchAddress("jet_AntiKt4LCTopo_ActiveAreaPx", &jet_AntiKt4LCTopo_ActiveAreaPx);
    SetBranchAddress("jet_AntiKt4LCTopo_ActiveAreaPy", &jet_AntiKt4LCTopo_ActiveAreaPy);
    SetBranchAddress("jet_AntiKt4LCTopo_ActiveAreaPz", &jet_AntiKt4LCTopo_ActiveAreaPz);
    SetBranchAddress("jet_AntiKt4LCTopo_ActiveAreaE", &jet_AntiKt4LCTopo_ActiveAreaE);
    SetBranchAddress("jet_AntiKt4LCTopo_MET_wet", &jet_AntiKt4LCTopo_MET_wet);
    SetBranchAddress("jet_AntiKt4LCTopo_MET_wpx", &jet_AntiKt4LCTopo_MET_wpx);
    SetBranchAddress("jet_AntiKt4LCTopo_MET_wpy", &jet_AntiKt4LCTopo_MET_wpy);
    SetBranchAddress("jet_AntiKt4LCTopo_MET_statusWord", &jet_AntiKt4LCTopo_MET_statusWord);
    SetBranchAddress("Eventshape_rhoKt4LC", &Eventshape_rhoKt4LC);

  }

  Objects::LCJet Branches::LCJet::GetJet(const int iJet) const {
    if(iJet < 0 || iJet > jet_AntiKt4LCTopo_n) {
      throw std::out_of_range("Invalid jet number");
    }
    Objects::LCJet jet;
    jet.constscale_E = jet_AntiKt4LCTopo_constscale_E->at(iJet);
    jet.constscale_eta = jet_AntiKt4LCTopo_constscale_eta->at(iJet);
    jet.constscale_phi = jet_AntiKt4LCTopo_constscale_phi->at(iJet);
    jet.constscale_m = jet_AntiKt4LCTopo_constscale_m->at(iJet);
    jet.ActiveAreaPx = jet_AntiKt4LCTopo_ActiveAreaPx->at(iJet);
    jet.ActiveAreaPy = jet_AntiKt4LCTopo_ActiveAreaPy->at(iJet);
    jet.ActiveAreaPz = jet_AntiKt4LCTopo_ActiveAreaPz->at(iJet);
    jet.ActiveAreaE = jet_AntiKt4LCTopo_ActiveAreaE->at(iJet);
    jet.MET_wet = jet_AntiKt4LCTopo_MET_wet->at(iJet);
    jet.MET_wpx = jet_AntiKt4LCTopo_MET_wpx->at(iJet);
    jet.MET_wpy = jet_AntiKt4LCTopo_MET_wpy->at(iJet);
    jet.MET_statusWord = jet_AntiKt4LCTopo_MET_statusWord->at(iJet);
    jet.Eventshape = Eventshape_rhoKt4LC;
    return jet;
  }

  Objects::LCJet::Vector Branches::LCJet::GetJets() const {
    Objects::LCJet::Vector jets;
    jets.reserve(jet_AntiKt4LCTopo_n);
    for(Utilities::Range i(jet_AntiKt4LCTopo_n); i; ++i) {
      jets.push_back(GetJet(*i));
    }
    return jets;
  }
    
}

