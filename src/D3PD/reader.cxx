#include "D3PD/reader.h"

namespace D3PD {
  
  Reader::Reader(const std::string& fileName) : Tree(fileName) {
  }
  
  Event Reader::GetEvent(const Long64_t iEvent) {
    Tree::GetEntry(iEvent);
    return GetEvent();
  }
  
  Event Reader::GetEvent() {
    Event event;
    event.SetElectrons(Branches::Electron::GetElectrons());
    event.SetMuons(Branches::Muon::GetMuons());
    event.SetEMJets(Branches::EMJet::GetJets());
    event.SetLCJets(Branches::LCJet::GetJets());
    event.SetMET(Branches::MET::GetMET());
    return event;
  }

}

