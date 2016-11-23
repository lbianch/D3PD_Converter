#ifndef D3PD_OBJECTS_MET_H
#define D3PD_OBJECTS_MET_H

namespace D3PD {
  namespace Objects {

    class MET {
    public:
      float RefGamma_et = 0.0F;
      float RefGamma_phi = 0.0F; 
      float RefTau_et = 0.0F;
      float RefTau_phi = 0.0F; 
      float CellOut_Eflow_et = 0.0F; 
      float CellOut_Eflow_phi = 0.0F;
    };

  }
}

#ifdef __CINT__
#pragma link C++ namespace D3PD;
#pragma link C++ namespace D3PD::Objects;
#pragma link C++ class D3PD::Objects::MET+;
#endif

#endif
