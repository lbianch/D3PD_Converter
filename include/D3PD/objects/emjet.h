#ifndef D3PD_OBJECTS_EMJET_H
#define D3PD_OBJECTS_EMJET_H
#include <vector>

namespace D3PD {
  namespace Objects {
    
    class EMJet {
    public:
      typedef std::vector<EMJet> Vector;
      typedef typename std::vector<EMJet>::iterator iterator;
      typedef typename std::vector<EMJet>::const_iterator const_iterator;
      
      float E = 0.0F;
      float pt = 0.0F;
      float eta = 0.0F;
      float phi = 0.0F;
      float m = 0.0F;
      float emscale_E = 0.0F;
      float emscale_pt = 0.0F;
      float emscale_eta = 0.0F;
      float emscale_phi = 0.0F;
      float emscale_m = 0.0F;
      float EtaOrigin = 0.0F;
      float PhiOrigin = 0.0F;
      float MOrigin = 0.0F;
      float NegativeE = 0.0F;
      float jvtxf = 0.0F;
      float BCH_CORR_JET = 0.0F;
      float BCH_CORR_CELL = 0.0F;
      float flavor_weight_IP3D = 0.0F;
      float flavor_weight_SV0 = 0.0F;
      float flavor_weight_SV1 = 0.0F;
      float flavor_weight_JetFitterCOMBNN = 0.0F;
      bool isBadLoose = false;
      float ActiveAreaPx = 0.0F;
      float ActiveAreaPy = 0.0F;
      float ActiveAreaPz = 0.0F;
      float ActiveAreaE = 0.0F;
      float hecf = 0.0F;
      float HECQuality = 0.0F;
      float AverageLArQF = 0.0F;
      float emfrac = 0.0F;
      float LArQuality = 0.0F;
      float sumPtTrk = 0.0F;
      float fracSamplingMax = 0.0F;
      int SamplingMax = 0;
    };
    
  } 
} 

#ifdef __CINT__
#pragma link C++ namespace D3PD;
#pragma link C++ namespace D3PD::Objects;
#pragma link C++ class D3PD::Objects::EMJet+;
#pragma link C++ class std::vector<D3PD::Objects::EMJet>+;
#endif

#endif
