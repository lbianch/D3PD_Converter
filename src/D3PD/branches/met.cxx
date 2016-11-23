#include <iostream>
#include "D3PD/branches/met.h"

namespace D3PD {

  Branches::MET::MET() {
    if(!Tree::GetTree()) {
      std::cout << "MET being constructed on an empty Tree" << std::endl;
      return;
    }
    SetBranchAddress("MET_RefGamma_et", &MET_RefGamma_et);
    SetBranchAddress("MET_RefGamma_phi", &MET_RefGamma_phi); 
    SetBranchAddress("MET_RefTau_et", &MET_RefTau_et);
    SetBranchAddress("MET_RefTau_phi", &MET_RefTau_phi); 
    SetBranchAddress("MET_CellOut_Eflow_et", &MET_CellOut_Eflow_et); 
    SetBranchAddress("MET_CellOut_Eflow_phi", &MET_CellOut_Eflow_phi);
  }

  Objects::MET Branches::MET::GetMET() const {
    Objects::MET met;
    met.RefGamma_et = MET_RefGamma_et;
    met.RefGamma_phi = MET_RefGamma_phi; 
    met.RefTau_et = MET_RefTau_et;
    met.RefTau_phi = MET_RefTau_phi; 
    met.CellOut_Eflow_et = MET_CellOut_Eflow_et; 
    met.CellOut_Eflow_phi = MET_CellOut_Eflow_phi;
    return met;
  }

}
