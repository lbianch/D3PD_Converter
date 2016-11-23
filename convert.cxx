#include <iostream>
#include "D3PD/reader.h"
#include "D3PD/writer.h"

void convert(const std::string& fName, const std::string& outName) {
  D3PD::Reader reader(fName);
  D3PD::Writer writer(outName);
  std::cout << "Found " << reader.GetEntries() << " events" << std::endl;
  while(reader.GetEntry()) {
    writer.SetEvent(reader.GetEvent());
    writer.Fill();
  }
  std::cout << "Wrote " << writer.GetEntries() << " events" << std::endl;
}

int main(int argc, char** argv) {
  if(argc < 2) {
    return 1;
  }
  convert(argv[1], argc == 2 ? "out.root" : argv[2]);
  return 0;
}
