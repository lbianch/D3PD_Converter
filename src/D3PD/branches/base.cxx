#include <iostream>
#include <exception>
#include "D3PD/branches/base.h"

namespace D3PD {
  namespace Branches {
    
    Tree::Tree(const std::string& fileName) : file(TFile::Open(fileName.c_str())) {
      if(!file || file->IsZombie() || !file->IsOpen()) {
	throw std::runtime_error("Could not use file " + fileName);
      }
      std::unique_ptr<TObject> treeObj(file->Get("physics"));
      if(!treeObj) {
	throw std::runtime_error("Could not find tree 'physics' in " + fileName);
      }
      TTree* physics = dynamic_cast<TTree*>(treeObj.get());
      if(!physics) {
	throw std::runtime_error("Object 'physics' in " + fileName + " is not TTree");
      }
      tree.reset(physics);
      treeObj.release();
      tree->SetBranchStatus("*", 0);
      nEvents = tree->GetEntries();
    }

    TTree* Tree::GetTree() const {
      return tree.get();
    }

    Tree& Tree::SetBranchAddress(const std::string& name, Bool_t* add) {
      return SetBranchViaLeaf(name, reinterpret_cast<void*>(add), "TLeafO");
    }

    Tree& Tree::SetBranchAddress(const std::string& name, Int_t* add) {
      return SetBranchViaLeaf(name, reinterpret_cast<void*>(add), "TLeafI");
    }

    Tree& Tree::SetBranchAddress(const std::string& name, Float_t* add) {
      return SetBranchViaLeaf(name, reinterpret_cast<void*>(add), "TLeafF");
    }

    Tree& Tree::SetBranchAddress(const std::string& name, UInt_t* add) {
      return SetBranchViaLeaf(name, reinterpret_cast<void*>(add), "TLeafI");
    }
      
    Tree& Tree::SetBranchAddress(const std::string& name, std::vector<int>** add) {
      return SetBranch(name, reinterpret_cast<void*>(add), "vector<int>");
    }

    Tree& Tree::SetBranchAddress(const std::string& name, std::vector<float>** add) {
      return SetBranch(name, reinterpret_cast<void*>(add), "vector<float>");
    }

    Tree& Tree::SetBranchAddress(const std::string& name, std::vector<double>** add) {
      return SetBranch(name, reinterpret_cast<void*>(add), "vector<double>");
    }

    Tree& Tree::SetBranchAddress(const std::string& name, std::vector<unsigned short>** add) {
      return SetBranch(name, reinterpret_cast<void*>(add), "vector<unsigned short>");
    }

    Tree& Tree::SetBranchAddress(const std::string& name, std::vector<unsigned int>** add) {
      return SetBranch(name, reinterpret_cast<void*>(add), "vector<unsigned int>");
    }
    
    Tree& Tree::SetBranchAddress(const std::string& name, std::vector<std::vector<int> >** add) {
      return SetBranch(name, reinterpret_cast<void*>(add), "vector<vector<int> >");
    }

    Tree& Tree::SetBranchAddress(const std::string& name, std::vector<std::vector<float> >** add) {
      return SetBranch(name, reinterpret_cast<void*>(add), "vector<vector<float> >");
    }

    Tree& Tree::SetBranchAddress(const std::string& name, std::vector<std::vector<double> >** add) {
      return SetBranch(name, reinterpret_cast<void*>(add), "vector<vector<double> >");
    }

    Tree& Tree::SetBranchAddress(const std::string& name, std::vector<std::vector<std::string> >** add) {
      return SetBranch(name, reinterpret_cast<void*>(add), "vector<vector<string> >");
    }

    Tree& Tree::SetBranchAddress(const std::string& name, std::vector<std::vector<unsigned int> >** add) {
      return SetBranch(name, reinterpret_cast<void*>(add), "vector<vector<unsigned int> >");
    }

    Tree& Tree::SetBranch(const std::string& name, void* add, const std::string& typeName) {
      std::cout << "<D3PD::Branches::Tree::SetBranch>: Setting up " << name << " as " << typeName << std::endl;
      TBranch* b = tree->GetBranch(name.c_str());
      if(!b) {
	throw std::runtime_error("Branch not found: " + name);
      }
      if(b->GetClassName() != typeName) {
	throw std::invalid_argument("Expected " + typeName + " for branch " + name + " but found type " + b->GetClassName());
      }
      tree->SetBranchStatus(name.c_str(), 1);
      tree->SetBranchAddress(name.c_str(), add);
      return *this;
    }

    Tree& Tree::SetBranchViaLeaf(const std::string& name, void* add, const std::string& typeName) {
      std::cout << "<D3PD::Branches::Tree::SetBranchViaLeaf>: Setting up " << name << std::endl;
      TBranch* b = tree->GetBranch(name.c_str());
      if(!b) {
	throw std::runtime_error("Branch not found: " + name);
      }
      TLeaf* l = b->GetLeaf(name.c_str());
      if(!l) {
	throw std::runtime_error("Leaf not found: " + name);
      }
      if(l->ClassName() != typeName) {
	throw std::invalid_argument("Expected " + typeName + " for branch " + name + " but found type " + l->ClassName());
      }
      tree->SetBranchStatus(name.c_str(), 1);
      tree->SetBranchAddress(name.c_str(), add);
      return *this;
    }
    
    Long64_t Tree::GetEntries() const {
      return tree->GetEntries();
    }

    Int_t Tree::GetEntry(const Long64_t iEv) {
      return tree->GetEntry(iEv);
    }

    bool Tree::GetEntry() {
      if(iEvent < nEvents) {
	tree->GetEntry(iEvent++);
	return true;
      }
      return false;
    }

  }
}
