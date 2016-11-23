#ifndef OBJ_LCJET_H
#define OBJ_LCJET_H
#include <vector>

namespace D3PD {
  namespace Objects {

    class LCJet {
    public:
      typedef std::vector<LCJet> Vector;
      typedef typename std::vector<LCJet>::iterator iterator;
      typedef typename std::vector<LCJet>::const_iterator const_iterator;

      float constscale_E = 0.0F;
      float constscale_eta = 0.0F;
      float constscale_phi = 0.0F;
      float constscale_m = 0.0F;
      float ActiveAreaPx = 0.0F;
      float ActiveAreaPy = 0.0F;
      float ActiveAreaPz = 0.0F;
      float ActiveAreaE = 0.0F;
      float Eventshape = 0.0F;
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
#pragma link C++ class D3PD::Objects::LCJet+;
#pragma link C++ class std::vector<D3PD::Objects::LCJet>+;
#endif

#endif
