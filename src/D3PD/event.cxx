#include "D3PD/event.h"

namespace D3PD {

  Event::Event() {
  }

  Event& Event::Attach(TTree* tree) {
    tree->Branch("electrons", &electrons);
    tree->Branch("muons", &muons);
    tree->Branch("em_jets", &em_jets);
    tree->Branch("lc_jets", &lc_jets);
    tree->Branch("met", &met);
    return *this;
  }

  const Objects::Electron::Vector& Event::GetElectrons() const {
    return electrons;
  }
  
  Event& Event::SetElectrons(const Objects::Electron::Vector& el) {
    electrons = el;
    return *this;
  }

  const Objects::Muon::Vector& Event::GetMuons() const {
    return muons;
  }

  Event& Event::SetMuons(const Objects::Muon::Vector& mu) {
    muons = mu;
    return *this;
  }

  const Objects::EMJet::Vector& Event::GetEMJets() const {
    return em_jets;
  }

  Event& Event::SetEMJets(const Objects::EMJet::Vector& j) {
    em_jets = j;
    return *this;
  }

  const Objects::LCJet::Vector& Event::GetLCJets() const {
    return lc_jets;
  }

  Event& Event::SetLCJets(const Objects::LCJet::Vector& j) {
    lc_jets = j;
    return *this;
  }

  const Objects::MET Event::GetMET() const {
    return met;
  }
  
  Event& Event::SetMET(const Objects::MET& m) {
    met = m;
    return *this;
  }
  
}

