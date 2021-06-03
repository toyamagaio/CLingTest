#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
using namespace std;

#include "TApplication.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TF1.h"
#include "TFile.h"
#include "TLeaf.h"
#include "TTree.h"
#include "TCut.h"
#include "TChain.h"
#include "TCanvas.h"
#include "TVector3.h"
#include "TGraph.h"
#include "TLine.h"
#include "TLatex.h"
#include "TText.h"
#include "TStyle.h"
#include "TROOT.h"
#include "TGraphErrors.h"
#include "TProfile.h"
#include "TSystem.h"
#include "TColor.h"
#include "TPaveText.h"
#include "TMath.h"
#include "TGaxis.h"

#include "TLorentzVector.h"
#include "TVector3.h"
#include "TRandom.h"


#include "Analysis.hh"
int main( int argc, char **argv )
{
  //TApplication *theApp = new TApplication("App", &argc, argv);
  Analysis *ana = new Analysis();
  ana->DefineNKS2SimTree();
  for(int i=0;i<10;i++){
    cout<<i<<endl;
    ana->FillNKS2SimTree(i);
  }
  ana->EndOfRun();

  return 0;
}
