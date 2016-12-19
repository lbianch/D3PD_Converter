# D3PD Converter
Convert D3PDs to object oriented files for skimming, thinning, and slimming and for more object-oriented analysis.

The typical D3PD is a flat tree structure, consisting of blocks of objects by related variable names.  For example, electrons may have branches `"electron_cl_eta"` and `"el_cl_phi"` which are both `std::vector<float>` containers.  This code instead chooses to turn these related containers into a single container of objects.  Instead of `electron_cl_eta->at(0)`, one would be able to use `electrons.at(0).cl_eta` or, better, to iterate through the container and use `my_electron->cl_eta`.  

# Requirements
This project uses [ROOT6](http://root.cern.ch), which also requires c++1y support.  The Makefile contained in this project uses `-std=c++14`, however.  Compilation has only been tested on Scientific Linux 6, though any Unix-like system which can build ROOT6 should work.

# Type Safety
One potential issue with ROOT files in this format is that pointers to `std::vector` objects containing one type may be confused with a different type if the two types happen to have the same size.  For example, a `std::vector<int>*` and a `std::vector<float>*` often have this confusion.  By default, ROOT doesn't do any checking because the branch location one typically passes into `TTree::SetBranchAddress` is taken via `void*`.  In this project, `D3PD::Branches::Tree` is careful to distinguish between different kinds of pointers and will throw a `std::invalid_argument` if the type being used to hold the branch data is different from what the branch truly contains.

# Using
Once checked out, one only needs to run `make` to build the project and produce the provided executable.  To add the library to the `LD_LIBRARY_PATH` environmental variable one can also use `source add_library.sh` prior to trying to invoke the executable.  The expected input is `./convert input_filename output_filename` where `output_filename` defaults to `"out.root"` if not provided.

# Selection criteria
Event selection criteria could be added into `converter.cxx` and selection criteria for each object in a module can be modified.  Using the electrons example, this would be in `D3PD::Branches::Electron::GetElectrons()`.

# Extending
The general structure of the project is that the `D3PD::Reader` object inherits from numerous submodules (eg, one for electrons, one for muons, one for EM jets, etc.) which in turn inhert from `D3PD::Branches::Tree` virtually.  This parent type is responsible for owning and managing the `TFile` and `TTree`.  Using a `TChain` would also be possible.  In order to add or remove branches to an existing module (example below using electrons), one needs to modify four things:

1. The branch in the `D3PD::Branches::Electron` class (`include/D3PD/branches/electron.h`), with a default member initializer if adding.
2. The field in the `D3PD::Objects::Electron` class (`include/D3PD/objects/electron.h`), also with a default member initalizer
3. Attach/remove the branch in the constructor `D3PD::Branches::Electron::Electron()` (in `src/D3PD/branches/electron.cxx`) using the `SetBranchAddress` method provided by `D3PD::Branches::Tree`
4. Modify the conversion from the branch data to the object in `D3PD::Branches::Electron::GetElectron(int)`

In order to add a new module entirely, similar classes (with an example of photons, `D3PD::Branches::Photon` and `D3PD::Objects::Photon`) would be required and in addition three modifications need to be made to `D3PD::Reader`, and `D3PD::Event`:

1. To `D3PD::Reader`, one must also include the header for the new module and inherit from the new module
2. To `D3PD::Event`, one needs to
   1. Add in the correct object type as a new `private` data member (eg, `D3PD::Objects::Photon::Vector photons;`)
   2. Modify `D3PD::Event::Attach(TTree*)` to add a new branch for that data member (eg, `tree->Branch("photons", &photons);`)
   3. Add new `Get` and `Set` methods
3. Add the new class to the ROOT dictionary. To `dict/headers.h` one would need to include the new object's header (eg, `#include "D3PD/objects/photon.h"`)

One last note about the header files in `D3PD/objects` is that there are no corresponding files in `src/` since no methods are defined on those classes.
