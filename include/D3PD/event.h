#ifndef D3PD_EVENT_H
#define D3PD_EVENT_H
#include "TTree.h"
#include "D3PD/objects/electron.h"
#include "D3PD/objects/muon.h"
#include "D3PD/objects/emjet.h"
#include "D3PD/objects/lcjet.h"
#include "D3PD/objects/met.h"

namespace D3PD {

  class Event {
  public:
    Event();

    Event& Attach(TTree*);

    const Objects::Electron::Vector& GetElectrons() const;
    Event& SetElectrons(const Objects::Electron::Vector&);
    
    const Objects::Muon::Vector& GetMuons() const;
    Event& SetMuons(const Objects::Muon::Vector&);

    const Objects::EMJet::Vector& GetEMJets() const;
    Event& SetEMJets(const Objects::EMJet::Vector&);

    const Objects::LCJet::Vector& GetLCJets() const;
    Event& SetLCJets(const Objects::LCJet::Vector&);

    const Objects::MET GetMET() const;
    Event& SetMET(const Objects::MET&);
    
  private:
    Objects::Electron::Vector electrons;
    Objects::Muon::Vector muons;
    Objects::EMJet::Vector em_jets;
    Objects::LCJet::Vector lc_jets;
    Objects::MET met;
  };
  
}

#endif
