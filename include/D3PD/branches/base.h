#ifndef D3PD_BRANCHES_TREE_H
#define D3PD_BRANCHES_TREE_H
#include <string>
#include <memory>
#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"
#include "TLeaf.h"

namespace D3PD {
  namespace Branches {

    class Tree {
    public:
      Tree() = default;
      Tree(const std::string&);

      Tree(const Tree&) = delete;
      Tree& operator=(const Tree&) = delete;

      Tree(Tree&&) = default;
      Tree& operator=(Tree&&) = default;
      
      TTree* GetTree() const;
      Long64_t GetEntries() const;
      Int_t GetEntry(const Long64_t);
      bool  GetEntry();

      Tree& SetBranchAddress(const std::string&, Bool_t*);
      Tree& SetBranchAddress(const std::string&, Int_t*);
      Tree& SetBranchAddress(const std::string&, Float_t*);
      Tree& SetBranchAddress(const std::string&, UInt_t*);
      
      Tree& SetBranchAddress(const std::string&, std::vector<int>**);
      Tree& SetBranchAddress(const std::string&, std::vector<float>**);
      Tree& SetBranchAddress(const std::string&, std::vector<double>**);
      Tree& SetBranchAddress(const std::string&, std::vector<unsigned short>**);
      Tree& SetBranchAddress(const std::string&, std::vector<unsigned int>**);
      
      Tree& SetBranchAddress(const std::string&, std::vector<std::vector<int> >**);
      Tree& SetBranchAddress(const std::string&, std::vector<std::vector<float> >**);
      Tree& SetBranchAddress(const std::string&, std::vector<std::vector<double> >**);
      Tree& SetBranchAddress(const std::string&, std::vector<std::vector<std::string> >**);
      Tree& SetBranchAddress(const std::string&, std::vector<std::vector<unsigned int> >**);

    private:
      Tree& SetBranch(const std::string&, void*, const std::string&);
      Tree& SetBranchViaLeaf(const std::string&, void*, const std::string&);

      std::unique_ptr<TFile> file;
      std::unique_ptr<TTree> tree;

      Long64_t iEvent = 0;
      Long64_t nEvents = 0;
    };

  }
}

#endif     

