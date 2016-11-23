#ifndef READER_H
#define READER_H
#include <string>
#include "D3PD/branches/base.h"
#include "D3PD/branches/electron.h"
#include "D3PD/branches/muon.h"
#include "D3PD/branches/emjet.h"
#include "D3PD/branches/lcjet.h"
#include "D3PD/branches/met.h"
#include "D3PD/event.h"

namespace D3PD {
  
  class Reader : public D3PD::Branches::Electron,
		 public D3PD::Branches::Muon,
		 public D3PD::Branches::EMJet,
		 public D3PD::Branches::LCJet,
		 public D3PD::Branches::MET {
  public:
    Reader(const std::string& fileName);

    Event GetEvent(const Long64_t iEvent);
    Event GetEvent();
  }; 

}

#endif
