#ifndef D3PD_WRITER_H
#define D3PD_WRITER_H
#include <string>
#include <memory>
#include "TFile.h"
#include "TTree.h"
#include "D3PD/event.h"

namespace D3PD {

  class Writer {
  public:
    Writer(const std::string& fileName);
    ~Writer();

    Writer& Fill();
    Writer& SetEvent(const Event& event);
    Writer& SetEvent(Event&& event);
    Long64_t GetEntries() const;
    
  private:
    std::unique_ptr<TFile> file;
    std::unique_ptr<TTree> tree;
    Event event;
  };

}

#endif
