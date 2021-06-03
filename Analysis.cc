//
// Analysis.cc
//

#include "Analysis.hh"

#include "NKS2SimEvent.h"
#include "NKS2SimTrack.h"

#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TRandom.h" // takeuchi

#include <cmath>
#include <fstream>
#include <iomanip>
#include <signal.h>
#include <sstream>
#include <vector>
//================================================================================================================

void closeFile( int sid )
{ 
  gFile -> Write();
  gFile -> Close();
}

//================================================================================================================

//______________________________________________________________________________________________________________

Analysis::Analysis( string fileName )
{
  // TFile *fp = new TFile(fileName.c_str(),"RECREATE","NKS2 ROOT FILE");
  new TFile(fileName.c_str(),"RECREATE","NKS2 ROOT FILE");

  DefineNKS2SimTree();
}

//______________________________________________________________________________________________________________

Analysis::~Analysis()
{
}

//______________________________________________________________________________________________________________



void Analysis::DefineNKS2SimTree()
{

  pTTreeForNKS2SimEvent = new TTree("TTreeForNKS2SimEvent","NKS2 Simulation TTree");
  pNKS2SimEvent         = new NKS2SimEvent();

  Int_t split   = 99;                                  // by default split Event into sub branches
  Int_t bufsize = 256000;

  if ( split !=0 ) { bufsize /= 16; }

  pTTreeForNKS2SimEvent -> SetAutoSave(1000000);      // autosave when 1 Mbyte data is written in the memory
  pTTreeForNKS2SimEvent -> Bronch( "pNKS2SimEvent",   // Branch name
                                    "NKS2SimEvent",   // Class name of the pointer of data container class
                                   &pNKS2SimEvent ,   // Reference of the pointer
                                          bufsize ,
                                            split  );

}

//______________________________________________________________________________________________________________

void Analysis::FillNKS2SimTree( int evID )
{

  // get pointers for hit 
  //  Fill TTree
  //G4cout<<"Filling Tree..."<<G4endl;
  pNKS2SimEvent -> SetEventNumber    ( evID );

  int trigger_number = -99;
  pNKS2SimEvent -> SetTriggerNumber  ( trigger_number );

  pNKS2SimEvent -> SetBeamEnergy     ( 0.1 );

  pNKS2SimEvent -> SetTargetMomentumX( 0.3 );
  pNKS2SimEvent -> SetTargetMomentumY( 0.3 );
  pNKS2SimEvent -> SetTargetMomentumZ( 0.3 );
  pNKS2SimEvent -> SetTargetMass     ( 0.3 );

  pNKS2SimEvent -> SetW              ( 1. );

  pNKS2SimEvent -> SetVertexX        ( 1. );
  pNKS2SimEvent -> SetVertexY        ( 1. );
  pNKS2SimEvent -> SetVertexZ        ( 1. );

  // Set pointers of data container class
  NKS2SimTrack *pNKS2SimTrack = new NKS2SimTrack();
  pNKS2SimTrack->SetTrackPointX(0.5);	   
  pNKS2SimTrack->SetTrackPointY(0.5);	   
  pNKS2SimTrack->SetTrackPointZ(0.5);	   

  pNKS2SimTrack -> SetTrackID       ( 1  );
  pNKS2SimTrack -> SetParentID      ( 1  );
  pNKS2SimTrack -> SetPx            ( 1. );
  pNKS2SimTrack -> SetPy            ( 1. );
  pNKS2SimTrack -> SetPz            ( 1. );
  pNKS2SimTrack -> SetX             ( 1. );
  pNKS2SimTrack -> SetY             ( 1. );
  pNKS2SimTrack -> SetZ             ( 1. );
  pNKS2SimTrack -> SetDecayX        ( 1. );
  pNKS2SimTrack -> SetDecayY        ( 1. );
  pNKS2SimTrack -> SetDecayZ        ( 1. );
  pNKS2SimTrack -> SetChargeSign    ( 1. );
  pNKS2SimTrack -> SetMass          ( 1. );
  pNKS2SimTrack -> SetPDGEncoding   ( 1. );

  
  delete pNKS2SimTrack;
  pTTreeForNKS2SimEvent -> Fill();
  pNKS2SimEvent -> Clear();      //  Clear TCronesArray of this event and counter
}

//______________________________________________________________________________________________________________
void Analysis::EndOfRun(){

  closeFile( 1 );
}
