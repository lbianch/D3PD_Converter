#ifndef D3PD_BRANCHES_MUON_H
#define D3PD_BRANCHES_MUON_H
#include <vector>
#include "D3PD/branches/base.h"
#include "D3PD/objects/muon.h"

namespace D3PD {
  namespace Branches {

    class Muon : public virtual Tree {
    public:
      Muon();

      D3PD::Objects::Muon GetMuon(const int) const;
      D3PD::Objects::Muon::Vector GetMuons() const;
      
      Int_t mu_staco_n = 0;
      std::vector<float>* mu_staco_E = nullptr;
      std::vector<float>* mu_staco_pt = nullptr;
      std::vector<float>* mu_staco_eta = nullptr;
      std::vector<float>* mu_staco_phi = nullptr;
      std::vector<float>* mu_staco_m = nullptr;
      std::vector<float>* mu_staco_charge = nullptr;
      std::vector<int>* mu_staco_isCombinedMuon = nullptr;
      std::vector<int>* mu_staco_loose = nullptr;
      std::vector<float>* mu_staco_ptcone20 = nullptr;
      std::vector<float>* mu_staco_ptcone30 = nullptr;
      std::vector<float>* mu_staco_ptcone40 = nullptr;
      std::vector<float>* mu_staco_etcone20 = nullptr;
      std::vector<float>* mu_staco_etcone30 = nullptr;
      std::vector<float>* mu_staco_etcone40 = nullptr;    
      std::vector<float>* mu_staco_id_qoverp = nullptr;
      std::vector<float>* mu_staco_me_qoverp = nullptr;
      std::vector<float>* mu_staco_me_theta_exPV = nullptr;
      std::vector<float>* mu_staco_id_theta_exPV = nullptr;
      std::vector<float>* mu_staco_me_qoverp_exPV = nullptr;
      std::vector<float>* mu_staco_id_qoverp_exPV = nullptr;
      std::vector<float>* mu_staco_id_phi = nullptr;
      std::vector<float>* mu_staco_id_theta = nullptr;
      std::vector<int>* mu_staco_expectBLayerHit = nullptr;
      std::vector<int>* mu_staco_nBLHits = nullptr;
      std::vector<int>* mu_staco_nPixHits = nullptr;
      std::vector<int>* mu_staco_nPixelDeadSensors = nullptr;
      std::vector<int>* mu_staco_nSCTHits = nullptr;
      std::vector<int>* mu_staco_nSCTDeadSensors = nullptr;
      std::vector<int>* mu_staco_nPixHoles = nullptr;
      std::vector<int>* mu_staco_nSCTHoles = nullptr;
      std::vector<int>* mu_staco_nTRTHits = nullptr;
      std::vector<int>* mu_staco_nTRTOutliers = nullptr;
      std::vector<float>* mu_staco_id_d0_exPV = nullptr;
      std::vector<float>* mu_staco_id_z0_exPV = nullptr;
      std::vector<float>* mu_staco_id_cov_d0_exPV = nullptr;
      std::vector<float>* mu_staco_trackd0pvunbiased = nullptr;
      std::vector<float>* mu_staco_trackz0pvunbiased = nullptr;
      std::vector<float>* mu_staco_tracksigd0pvunbiased = nullptr;
      std::vector<int>* mu_staco_L1_index = nullptr;
      std::vector<float>* mu_staco_ms_qoverp = nullptr;
      std::vector<float>* mu_staco_ms_theta = nullptr;
      std::vector<float>* mu_staco_ms_phi = nullptr;
      std::vector<std::vector<float> >* mu_staco_MET_wet = nullptr;
      std::vector<std::vector<float> >* mu_staco_MET_wpx = nullptr;
      std::vector<std::vector<float> >* mu_staco_MET_wpy = nullptr;
      std::vector<std::vector<unsigned> >* mu_staco_MET_statusWord = nullptr;
    };
    
  }
}

#endif
