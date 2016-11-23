#ifndef D3PD_BRANCHES_ELECTRON_H
#define D3PD_BRANCHES_ELECTRON_H
#include <vector>
#include "D3PD/branches/base.h"
#include "D3PD/objects/electron.h"

namespace D3PD {
  namespace Branches {

    class Electron : public virtual Tree {
    public:
      Electron();
      
      D3PD::Objects::Electron GetElectron(const int) const;
      D3PD::Objects::Electron::Vector GetElectrons() const;
      
      Int_t el_n = 0;
      std::vector<float>* el_charge = nullptr;
      std::vector<int>* el_author = nullptr;
      std::vector<unsigned int>* el_OQ = nullptr;
      std::vector<int>* el_convFlag = nullptr;
      std::vector<int>* el_isConv = nullptr;
      std::vector<int>* el_loosePP = nullptr;
      std::vector<int>* el_mediumPP = nullptr;
      std::vector<int>* el_tightPP = nullptr;
      std::vector<float>* el_Etcone20 = nullptr;
      std::vector<float>* el_Etcone20_pt_corrected = nullptr;
      std::vector<float>* el_Etcone30 = nullptr;
      std::vector<float>* el_Etcone30_pt_corrected = nullptr;
      std::vector<float>* el_Etcone40 = nullptr;
      std::vector<float>* el_Etcone40_pt_corrected = nullptr;    
      std::vector<float>* el_ptcone20 = nullptr;
      std::vector<float>* el_ptcone30 = nullptr;
      std::vector<float>* el_ptcone40 = nullptr;    
      std::vector<float>* el_cl_E = nullptr;
      std::vector<float>* el_cl_eta = nullptr;
      std::vector<float>* el_cl_phi = nullptr;
      std::vector<float>* el_trackphi = nullptr;
      std::vector<float>* el_tracketa = nullptr;
      std::vector<float>* el_etas2 = nullptr;
      std::vector<float>* el_etap = nullptr;
      std::vector<float>* el_trackd0pvunbiased = nullptr;
      std::vector<float>* el_trackz0pvunbiased = nullptr;
      std::vector<float>* el_tracksigd0pvunbiased = nullptr;
      std::vector<float>* el_Ethad = nullptr;
      std::vector<float>* el_Ethad1 = nullptr;
      std::vector<float>* el_reta = nullptr;
      std::vector<float>* el_weta2 = nullptr;
      std::vector<float>* el_f1 = nullptr;
      std::vector<float>* el_Es0 = nullptr;
      std::vector<float>* el_Es1 = nullptr;
      std::vector<float>* el_Es2 = nullptr;
      std::vector<float>* el_Es3 = nullptr;
      std::vector<float>* el_wstot = nullptr;
      std::vector<float>* el_emaxs1 = nullptr;
      std::vector<float>* el_Emax2 = nullptr;
      std::vector<float>* el_deltaeta1 = nullptr;
      std::vector<float>* el_deltaphi2 = nullptr;
      std::vector<float>* el_trackqoverp = nullptr;
      std::vector<float>* el_trackd0_physics = nullptr;
      std::vector<float>* el_Unrefittedtrack_theta = nullptr;
      std::vector<float>* el_Unrefittedtrack_phi = nullptr;
      std::vector<float>* el_TRTHighTOutliersRatio = nullptr;
      std::vector<int>* el_nTRTHits = nullptr;
      std::vector<int>* el_nTRTOutliers = nullptr;
      std::vector<int>* el_nSiHits = nullptr;
      std::vector<int>* el_nSCTOutliers = nullptr;
      std::vector<int>* el_nPixelOutliers = nullptr;
      std::vector<int>* el_nPixHits = nullptr;
      std::vector<int>* el_nBLHits = nullptr;
      std::vector<int>* el_nBLayerOutliers = nullptr;
      std::vector<float>* el_expectHitInBLayer = nullptr;
      std::vector<unsigned int>* el_isEM = nullptr;
      std::vector<std::vector<float> >* el_MET_wet = nullptr;
      std::vector<std::vector<float> >* el_MET_wpx = nullptr;
      std::vector<std::vector<float> >* el_MET_wpy = nullptr;
      std::vector<std::vector<unsigned> >* el_MET_statusWord = nullptr;
    };
    
  }
}

#endif
