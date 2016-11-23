#ifndef D3PD_OBJECTS_MUON_H
#define D3PD_OBJECTS_MUON_H
#include <vector>

namespace D3PD {
  namespace Objects {
    
    class Muon {
    public:
      typedef std::vector<Muon> Vector;
      typedef typename std::vector<Muon>::iterator it;
      typedef typename std::vector<Muon>::const_iterator const_iterator;

      float E = 0.0F;
      float pt = 0.0F;
      float eta = 0.0F;
      float phi = 0.0F;
      float m = 0.0F;
      float charge = 0.0F;
      bool isCombinedMuon = false;
      bool loose = false;
      float ptcone20 = 0.0F;
      float ptcone30 = 0.0F;
      float ptcone40 = 0.0F;
      float etcone20 = 0.0F;
      float etcone30 = 0.0F;
      float etcone40 = 0.0F;    
      float id_qoverp = 0.0F;
      float me_qoverp = 0.0F;
      float me_theta_exPV = 0.0F;
      float id_theta_exPV = 0.0F;
      float me_qoverp_exPV = 0.0F;
      float id_qoverp_exPV = 0.0F;
      float id_phi = 0.0F;
      float id_theta = 0.0F;
      bool expectBLayerHit;
      int nBLHits = 0.0F;
      int nPixHits = 0.0F;
      int nPixelDeadSensors = 0.0F;
      int nSCTHits = 0.0F;
      int nSCTDeadSensors = 0;
      int nPixHoles = 0;
      int nSCTHoles = 0;
      int nTRTHits = 0;
      int nTRTOutliers = 0;
      float id_d0_exPV = 0.0F;
      float id_z0_exPV = 0.0F;
      float id_cov_d0_exPV = 0.0F;
      float trackd0pvunbiased = 0.0F;
      float trackz0pvunbiased = 0.0F;
      float tracksigd0pvunbiased = 0.0F;
      int L1_index = 0;
      float ms_qoverp = 0.0F;
      float ms_theta = 0.0F;
      float ms_phi = 0.0F;
      std::vector<float> MET_wet;
      std::vector<float> MET_wpx;
      std::vector<float> MET_wpy;
      std::vector<unsigned> MET_statusWord;
    };

  }
} 

#ifdef __CINT__
#pragma link C++ namespace D3PD;
#pragma link C++ namespace D3PD::Objects;
#pragma link C++ class D3PD::Objects::Muon+;
#pragma link C++ class std::vector<D3PD::Objects::Muon>+;
#endif

#endif
