#include <iostream>
#include <exception>
#include <cmath>
#include "utils/range.h"
#include "D3PD/branches/electron.h"

namespace D3PD {
  
  Branches::Electron::Electron() {
    if(!Tree::GetTree()) {
      std::cout << "Electron being constructed on an empty Tree" << std::endl;
      return;
    }
    SetBranchAddress("el_n", &el_n);
    SetBranchAddress("el_charge", &el_charge);
    SetBranchAddress("el_author", &el_author);
    SetBranchAddress("el_OQ", &el_OQ);
    SetBranchAddress("el_convFlag", &el_convFlag);
    SetBranchAddress("el_isConv", &el_isConv);
    SetBranchAddress("el_loosePP", &el_loosePP);
    SetBranchAddress("el_mediumPP", &el_mediumPP);
    SetBranchAddress("el_tightPP", &el_tightPP);
    SetBranchAddress("el_Etcone20", &el_Etcone20);
    SetBranchAddress("el_Etcone20_pt_corrected", &el_Etcone20_pt_corrected);
    SetBranchAddress("el_Etcone30", &el_Etcone30);
    SetBranchAddress("el_Etcone30_pt_corrected", &el_Etcone30_pt_corrected);
    SetBranchAddress("el_Etcone40", &el_Etcone40);
    SetBranchAddress("el_Etcone40_pt_corrected", &el_Etcone40_pt_corrected);
    SetBranchAddress("el_ptcone40", &el_ptcone40);      
    SetBranchAddress("el_ptcone20", &el_ptcone20);
    SetBranchAddress("el_ptcone30", &el_ptcone30);
    SetBranchAddress("el_cl_E", &el_cl_E);
    SetBranchAddress("el_cl_eta", &el_cl_eta);
    SetBranchAddress("el_cl_phi", &el_cl_phi);
    SetBranchAddress("el_trackphi", &el_trackphi);
    SetBranchAddress("el_tracketa", &el_tracketa);
    SetBranchAddress("el_etas2", &el_etas2);
    SetBranchAddress("el_etap", &el_etap);
    SetBranchAddress("el_trackd0pvunbiased", &el_trackd0pvunbiased);
    SetBranchAddress("el_trackz0pvunbiased", &el_trackz0pvunbiased);    
    SetBranchAddress("el_tracksigd0pvunbiased", &el_tracksigd0pvunbiased);
    SetBranchAddress("el_Ethad", &el_Ethad);
    SetBranchAddress("el_Ethad1", &el_Ethad1);
    SetBranchAddress("el_reta", &el_reta);
    SetBranchAddress("el_weta2", &el_weta2);
    SetBranchAddress("el_f1", &el_f1);
    SetBranchAddress("el_Es0", &el_Es0);
    SetBranchAddress("el_Es1", &el_Es1);
    SetBranchAddress("el_Es2", &el_Es2);
    SetBranchAddress("el_Es3", &el_Es3);
    SetBranchAddress("el_wstot", &el_wstot);
    SetBranchAddress("el_emaxs1", &el_emaxs1);
    SetBranchAddress("el_Emax2", &el_Emax2);
    SetBranchAddress("el_deltaeta1", &el_deltaeta1);
    SetBranchAddress("el_deltaphi2", &el_deltaphi2);
    SetBranchAddress("el_trackqoverp", &el_trackqoverp);
    SetBranchAddress("el_trackd0_physics", &el_trackd0_physics);
    SetBranchAddress("el_Unrefittedtrack_theta", &el_Unrefittedtrack_theta);
    SetBranchAddress("el_Unrefittedtrack_phi", &el_Unrefittedtrack_phi);
    SetBranchAddress("el_TRTHighTOutliersRatio", &el_TRTHighTOutliersRatio);
    SetBranchAddress("el_nTRTHits", &el_nTRTHits);
    SetBranchAddress("el_nTRTOutliers", &el_nTRTOutliers);
    SetBranchAddress("el_nSiHits", &el_nSiHits);
    SetBranchAddress("el_nSCTOutliers", &el_nSCTOutliers);
    SetBranchAddress("el_nPixelOutliers", &el_nPixelOutliers);
    SetBranchAddress("el_nPixHits", &el_nPixHits);
    SetBranchAddress("el_nBLHits", &el_nBLHits);
    SetBranchAddress("el_nBLayerOutliers", &el_nBLayerOutliers);
    SetBranchAddress("el_expectHitInBLayer", &el_expectHitInBLayer);
    SetBranchAddress("el_isEM", &el_isEM);
    SetBranchAddress("el_MET_wet", &el_MET_wet);
    SetBranchAddress("el_MET_wpx", &el_MET_wpx);
    SetBranchAddress("el_MET_wpy", &el_MET_wpy);
    SetBranchAddress("el_MET_statusWord", &el_MET_statusWord);
  }

  Objects::Electron Branches::Electron::GetElectron(const int iEl) const {
    if(iEl < 0 || iEl > el_n) {
      throw std::out_of_range("Invalid electron number");
    }
    Objects::Electron electron;
    electron.charge = el_charge->at(iEl);
    electron.author = el_author->at(iEl);
    electron.OQ = el_OQ->at(iEl);
    electron.convFlag = el_convFlag->at(iEl);
    electron.isConv = el_isConv->at(iEl);
    electron.loosePP = el_loosePP->at(iEl);
    electron.mediumPP = el_mediumPP->at(iEl);
    electron.tightPP = el_tightPP->at(iEl);
    electron.Etcone20 = el_Etcone20->at(iEl);
    electron.Etcone20_pt_corrected = el_Etcone20_pt_corrected->at(iEl);
    electron.Etcone30 = el_Etcone30->at(iEl);
    electron.Etcone30_pt_corrected = el_Etcone30_pt_corrected->at(iEl);
    electron.Etcone40 = el_Etcone40->at(iEl);
    electron.Etcone40_pt_corrected = el_Etcone40_pt_corrected->at(iEl);
    electron.ptcone20 = el_ptcone20->at(iEl);
    electron.ptcone30 = el_ptcone30->at(iEl);
    electron.ptcone40 = el_ptcone40->at(iEl);
    electron.cl_E = el_cl_E->at(iEl);
    electron.cl_eta = el_cl_eta->at(iEl);
    electron.cl_phi = el_cl_phi->at(iEl);
    electron.trackphi = el_trackphi->at(iEl);
    electron.tracketa = el_tracketa->at(iEl);
    electron.etas2 = el_etas2->at(iEl);
    electron.etap = el_etap->at(iEl);
    electron.trackd0pvunbiased = el_trackd0pvunbiased->at(iEl);
    electron.trackz0pvunbiased = el_trackz0pvunbiased->at(iEl);
    electron.tracksigd0pvunbiased = el_tracksigd0pvunbiased->at(iEl);
    electron.Ethad = el_Ethad->at(iEl);
    electron.Ethad1 = el_Ethad1->at(iEl);
    electron.reta = el_reta->at(iEl);
    electron.weta2 = el_weta2->at(iEl);
    electron.f1 = el_f1->at(iEl);
    electron.Es0 = el_Es0->at(iEl);
    electron.Es1 = el_Es1->at(iEl);
    electron.Es2 = el_Es2->at(iEl);
    electron.Es3 = el_Es3->at(iEl);
    electron.wstot = el_wstot->at(iEl);
    electron.emaxs1 = el_emaxs1->at(iEl);
    electron.Emax2 = el_Emax2->at(iEl);
    electron.deltaeta1 = el_deltaeta1->at(iEl);
    electron.deltaphi2 = el_deltaphi2->at(iEl);
    electron.trackqoverp = el_trackqoverp->at(iEl);
    electron.trackd0_physics = el_trackd0_physics->at(iEl);
    electron.Unrefittedtrack_theta = el_Unrefittedtrack_theta->at(iEl);
    electron.Unrefittedtrack_phi = el_Unrefittedtrack_phi->at(iEl);
    electron.TRTHighTOutliersRatio = el_TRTHighTOutliersRatio->at(iEl);
    electron.nTRTHits = el_nTRTHits->at(iEl);
    electron.nTRTOutliers = el_nTRTOutliers->at(iEl);
    electron.nSiHits = el_nSiHits->at(iEl);
    electron.nSCTOutliers = el_nSCTOutliers->at(iEl);
    electron.nPixelOutliers = el_nPixelOutliers->at(iEl);
    electron.nPixHits = el_nPixHits->at(iEl);
    electron.nBLHits = el_nBLHits->at(iEl);
    electron.nBLayerOutliers = el_nBLayerOutliers->at(iEl);
    electron.expectHitInBLayer = el_expectHitInBLayer->at(iEl);
    electron.isEM = el_isEM->at(iEl);
    electron.MET_wet = el_MET_wet->at(iEl);
    electron.MET_wpx = el_MET_wpx->at(iEl);
    electron.MET_wpy = el_MET_wpy->at(iEl);
    electron.MET_statusWord = el_MET_statusWord->at(iEl);
    return electron;
  }

  Objects::Electron::Vector Branches::Electron::GetElectrons() const {
    Objects::Electron::Vector electrons;
    for(Utilities::Range i(el_n); i; ++i) {
      Objects::Electron e = GetElectron(*i);
      if(e.author != 1 && e.author != 3) {
	continue;
      }
      if(e.cl_E/std::cosh(e.tracketa) < 8000.) {
	continue;
      }
      if(e.cl_E/std::cosh(e.cl_eta) < 8000.) {
	continue;
      }
      const double eta = std::fabs(e.cl_eta);
      if(eta > 2.47) {
	continue;
      }
      if(1.37 < eta && eta < 1.52) {
	continue;
      }
      electrons.push_back(e);
    }
    return electrons;
  }
    
}
