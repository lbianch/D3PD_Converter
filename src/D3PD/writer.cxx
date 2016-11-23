#include "D3PD/writer.h"

namespace D3PD {

  Writer::Writer(const std::string& fName) :
    file(new TFile(fName.c_str(), "recreate")),
    tree(new TTree("physics", "physics"))
  {
    event.Attach(tree.get());
  }

  Writer::~Writer() {
    tree->FlushBaskets();
    file->WriteTObject(tree.get());
    tree.reset(nullptr);
    file.reset(nullptr);
  }

  Writer& Writer::Fill() {
    tree->Fill();
    return *this;
  }

  Writer& Writer::SetEvent(const Event& e) {
    event = e;
    return *this;
  }

  Writer& Writer::SetEvent(Event&& e) {
    event = e;
    return *this;
  }

  Long64_t Writer::GetEntries() const {
    return tree->GetEntries();
  }

}

