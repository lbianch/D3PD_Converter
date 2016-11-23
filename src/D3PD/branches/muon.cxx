#include <iostream>
#include <exception>
#include <cmath>
#include "utils/range.h"
#include "D3PD/branches/muon.h"

namespace D3PD {
  
  Branches::Muon::Muon() {
    if(!Tree::GetTree()) {
      std::cout << "Muon being constructed on empty Tree" << std::endl;
      return;
    }
    SetBranchAddress("mu_staco_n", &mu_staco_n);
    SetBranchAddress("mu_staco_E", &mu_staco_E);
    SetBranchAddress("mu_staco_pt", &mu_staco_pt);
    SetBranchAddress("mu_staco_eta", &mu_staco_eta);
    SetBranchAddress("mu_staco_phi", &mu_staco_phi);
    SetBranchAddress("mu_staco_m", &mu_staco_m);
    SetBranchAddress("mu_staco_charge", &mu_staco_charge);
    SetBranchAddress("mu_staco_isCombinedMuon", &mu_staco_isCombinedMuon);
    SetBranchAddress("mu_staco_loose", &mu_staco_loose);
    SetBranchAddress("mu_staco_ptcone20", &mu_staco_ptcone20);
    SetBranchAddress("mu_staco_ptcone30", &mu_staco_ptcone30);
    SetBranchAddress("mu_staco_ptcone40", &mu_staco_ptcone40);
    SetBranchAddress("mu_staco_etcone20", &mu_staco_etcone20);
    SetBranchAddress("mu_staco_etcone30", &mu_staco_etcone30);
    SetBranchAddress("mu_staco_etcone40", &mu_staco_etcone40);    
    SetBranchAddress("mu_staco_id_qoverp", &mu_staco_id_qoverp);
    SetBranchAddress("mu_staco_me_qoverp", &mu_staco_me_qoverp);
    SetBranchAddress("mu_staco_me_theta_exPV", &mu_staco_me_theta_exPV);
    SetBranchAddress("mu_staco_id_theta_exPV", &mu_staco_id_theta_exPV);
    SetBranchAddress("mu_staco_me_qoverp_exPV", &mu_staco_me_qoverp_exPV);
    SetBranchAddress("mu_staco_id_qoverp_exPV", &mu_staco_id_qoverp_exPV);
    SetBranchAddress("mu_staco_id_phi", &mu_staco_id_phi);
    SetBranchAddress("mu_staco_id_theta", &mu_staco_id_theta);
    SetBranchAddress("mu_staco_expectBLayerHit", &mu_staco_expectBLayerHit);
    SetBranchAddress("mu_staco_nBLHits", &mu_staco_nBLHits);
    SetBranchAddress("mu_staco_nPixHits", &mu_staco_nPixHits);
    SetBranchAddress("mu_staco_nPixelDeadSensors", &mu_staco_nPixelDeadSensors);
    SetBranchAddress("mu_staco_nSCTHits", &mu_staco_nSCTHits);
    SetBranchAddress("mu_staco_nSCTDeadSensors", &mu_staco_nSCTDeadSensors);
    SetBranchAddress("mu_staco_nPixHoles", &mu_staco_nPixHoles);
    SetBranchAddress("mu_staco_nSCTHoles", &mu_staco_nSCTHoles);
    SetBranchAddress("mu_staco_nTRTHits", &mu_staco_nTRTHits);
    SetBranchAddress("mu_staco_nTRTOutliers", &mu_staco_nTRTOutliers);
    SetBranchAddress("mu_staco_id_d0_exPV", &mu_staco_id_d0_exPV);
    SetBranchAddress("mu_staco_id_z0_exPV", &mu_staco_id_z0_exPV);
    SetBranchAddress("mu_staco_id_cov_d0_exPV", &mu_staco_id_cov_d0_exPV);
    SetBranchAddress("mu_staco_trackd0pvunbiased", &mu_staco_trackd0pvunbiased);
    SetBranchAddress("mu_staco_trackz0pvunbiased", &mu_staco_trackz0pvunbiased);
    SetBranchAddress("mu_staco_tracksigd0pvunbiased", &mu_staco_tracksigd0pvunbiased);
    SetBranchAddress("mu_staco_L1_index", &mu_staco_L1_index);
    SetBranchAddress("mu_staco_ms_qoverp", &mu_staco_ms_qoverp);
    SetBranchAddress("mu_staco_ms_theta", &mu_staco_ms_theta);
    SetBranchAddress("mu_staco_ms_phi", &mu_staco_ms_phi);
    SetBranchAddress("mu_staco_MET_wet", &mu_staco_MET_wet);
    SetBranchAddress("mu_staco_MET_wpx", &mu_staco_MET_wpx);
    SetBranchAddress("mu_staco_MET_wpy", &mu_staco_MET_wpy);
    SetBranchAddress("mu_staco_MET_statusWord", &mu_staco_MET_statusWord);
  }

  Objects::Muon Branches::Muon::GetMuon(const int iMu) const {
    if(iMu < 0 || iMu > mu_staco_n) {
      throw std::out_of_range("Invalid muon number");
    }
    Objects::Muon m;
    m.E = mu_staco_E->at(iMu);
    m.pt = mu_staco_pt->at(iMu);
    m.eta = mu_staco_eta->at(iMu);
    m.phi = mu_staco_phi->at(iMu);
    m.m = mu_staco_m->at(iMu);
    m.charge = mu_staco_charge->at(iMu);
    m.isCombinedMuon = mu_staco_isCombinedMuon->at(iMu);
    m.loose = mu_staco_loose->at(iMu);
    m.ptcone20 = mu_staco_ptcone20->at(iMu);
    m.ptcone30 = mu_staco_ptcone30->at(iMu);
    m.ptcone40 = mu_staco_ptcone40->at(iMu);
    m.etcone20 = mu_staco_etcone20->at(iMu);
    m.etcone30 = mu_staco_etcone30->at(iMu);
    m.etcone40 = mu_staco_etcone40->at(iMu);    
    m.id_qoverp = mu_staco_id_qoverp->at(iMu);
    m.me_qoverp = mu_staco_me_qoverp->at(iMu);
    m.me_theta_exPV = mu_staco_me_theta_exPV->at(iMu);
    m.id_theta_exPV = mu_staco_id_theta_exPV->at(iMu);
    m.me_qoverp_exPV = mu_staco_me_qoverp_exPV->at(iMu);
    m.id_qoverp_exPV = mu_staco_id_qoverp_exPV->at(iMu);
    m.id_phi = mu_staco_id_phi->at(iMu);
    m.id_theta = mu_staco_id_theta->at(iMu);
    m.expectBLayerHit = mu_staco_expectBLayerHit->at(iMu);
    m.nBLHits = mu_staco_nBLHits->at(iMu);
    m.nPixHits = mu_staco_nPixHits->at(iMu);
    m.nPixelDeadSensors = mu_staco_nPixelDeadSensors->at(iMu);
    m.nSCTHits = mu_staco_nSCTHits->at(iMu);
    m.nSCTDeadSensors = mu_staco_nSCTDeadSensors->at(iMu);
    m.nPixHoles = mu_staco_nPixHoles->at(iMu);
    m.nSCTHoles = mu_staco_nSCTHoles->at(iMu);
    m.nTRTHits = mu_staco_nTRTHits->at(iMu);
    m.nTRTOutliers = mu_staco_nTRTOutliers->at(iMu);
    m.id_d0_exPV = mu_staco_id_d0_exPV->at(iMu);
    m.id_z0_exPV = mu_staco_id_z0_exPV->at(iMu);
    m.id_cov_d0_exPV = mu_staco_id_cov_d0_exPV->at(iMu);
    m.trackd0pvunbiased = mu_staco_trackd0pvunbiased->at(iMu);
    m.trackz0pvunbiased = mu_staco_trackz0pvunbiased->at(iMu);
    m.tracksigd0pvunbiased = mu_staco_tracksigd0pvunbiased->at(iMu);
    m.L1_index = mu_staco_L1_index->at(iMu);
    m.ms_qoverp = mu_staco_ms_qoverp->at(iMu);
    m.ms_theta = mu_staco_ms_theta->at(iMu);
    m.ms_phi = mu_staco_ms_phi->at(iMu);
    m.MET_wet = mu_staco_MET_wet->at(iMu);
    m.MET_wpx = mu_staco_MET_wpx->at(iMu);
    m.MET_wpy = mu_staco_MET_wpy->at(iMu);
    m.MET_statusWord = mu_staco_MET_statusWord->at(iMu);
    return m;
  }

  Objects::Muon::Vector Branches::Muon::GetMuons() const {
    Objects::Muon::Vector muons;
    for(Utilities::Range i(mu_staco_n); i; ++i) {
      Objects::Muon m = GetMuon(*i);
      if(!m.loose) {
	continue;
      }
      if(m.pt < 8000.) {
	continue;
      }
      if(std::fabs(m.eta) > 2.5) {
	continue;
      }
      muons.push_back(m);
    }
    return muons;
  }

}


