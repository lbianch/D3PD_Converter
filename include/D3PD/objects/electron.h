#ifndef D3PD_OBJECTS_ELECTRON_H
#define D3PD_OBJECTS_ELECTRON_H
#include <vector>

namespace D3PD {
  namespace Objects {
    
    class Electron {
    public:
      typedef std::vector<Electron> Vector;
      typedef typename std::vector<Electron>::iterator iterator;
      typedef typename std::vector<Electron>::const_iterator const_iterator;
      
      float charge = 0.0F;
      int author = 0;
      unsigned int OQ = 0U;
      int convFlag = 0;
      int isConv = 0;
      bool loosePP = false;
      bool mediumPP = false;
      bool tightPP = false;
      float Etcone20 = 0.0F;
      float Etcone20_pt_corrected = 0.0F;
      float Etcone30 = 0.0F;
      float Etcone30_pt_corrected = 0.0F;
      float Etcone40 = 0.0F;
      float Etcone40_pt_corrected = 0.0F;    
      float ptcone20 = 0.0F;
      float ptcone30 = 0.0F;
      float ptcone40 = 0.0F;    
      float cl_E = 0.0F;
      float cl_eta = 0.0F;
      float cl_phi = 0.0F;
      float trackphi = 0.0F;
      float tracketa = 0.0F;
      float etas2 = 0.0F;
      float etap = 0.0F;
      float trackd0pvunbiased = 0.0F;
      float trackz0pvunbiased = 0.0F;
      float tracksigd0pvunbiased = 0.0F;
      float Ethad = 0.0F;
      float Ethad1 = 0.0F;
      float reta = 0.0F;
      float weta2 = 0.0F;
      float f1 = 0.0F;
      float Es0 = 0.0F;
      float Es1 = 0.0F;
      float Es2 = 0.0F;
      float Es3 = 0.0F;
      float wstot = 0.0F;
      float emaxs1 = 0.0F;
      float Emax2 = 0.0F;
      float deltaeta1 = 0.0F;
      float deltaphi2 = 0.0F;
      float trackqoverp = 0.0F;
      float trackd0_physics = 0.0F;
      float Unrefittedtrack_theta = 0.0F;
      float Unrefittedtrack_phi = 0.0F;
      float TRTHighTOutliersRatio = 0.0F;
      int nTRTHits = 0;
      int nTRTOutliers = 0;
      int nSiHits = 0;
      int nSCTOutliers = 0;
      int nPixelOutliers = 0;
      int nPixHits = 0;
      int nBLHits = 0;
      int nBLayerOutliers = 0;
      int expectHitInBLayer = 0;
      unsigned int isEM = 0U;
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
#pragma link C++ class D3PD::Objects::Electron+;
#pragma link C++ class std::vector<D3PD::Objects::Electron>+;
#endif

#endif
