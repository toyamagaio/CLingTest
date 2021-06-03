//----------------------------------------------------------------
//
// Simulation Event class for NKS2 TTree
//                                                  Masashi Kaneta
//----------------------------------------------------------------

#include "NKS2SimEvent.h"
#include "NKS2SimTrack.h"
#include "TClonesArray.h"

ClassImp(NKS2SimEvent)

TClonesArray* NKS2SimEvent::fgNKS2SimTrack    = NULL;

//________________________________________________________________

NKS2SimEvent::NKS2SimEvent() {

  Initialization();

  // When the constructor is invoked for the first time, the class static
  // variable fgXXXXX is 0 and the TClonesArray fgXXXXX is created.

  if ( fgNKS2SimTrack   == NULL ){ fgNKS2SimTrack   = new TClonesArray( "NKS2SimTrack"  , 1000 ); }
  
  fNKS2SimTrack   = fgNKS2SimTrack;

}

//________________________________________________________________

NKS2SimEvent::~NKS2SimEvent() {}


//________________________________________________________________

void NKS2SimEvent::Initialization() {

  mEventNumber     = -99;
  mTriggerNumber   = -99;

  mBeamEnergy      = -99.;

  mTargetMomentumX = -99.;
  mTargetMomentumY = -99.;
  mTargetMomentumZ = -99.;
  mTargetMass      = -99.;

  mW               = -99.;

  mVertexX         = -99.;
  mVertexY         = -99.;
  mVertexZ         = -99.;


  mNumberOfTracks   = 0;
}

//________________________________________________________________

void NKS2SimEvent::Clear() {

  fNKS2SimTrack    -> Clear();

  Initialization();

}

//________________________________________________________________

void NKS2SimEvent::AddTrack(NKS2SimTrack* pNKS2SimTrack) {

  TClonesArray &sim_track = *fNKS2SimTrack;                          // Get a pointer of TClones Array of NKS2SimTrack for Track
  new(sim_track[mNumberOfTracks++]) NKS2SimTrack(pNKS2SimTrack);     // Increase the array size and then store a pointer at the end of the array

}

//________________________________________________________________

