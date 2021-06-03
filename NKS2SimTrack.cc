//-------------------------------------------------------------
//
//  data class for Track
//
//                                               Masashi Kaneta
//-------------------------------------------------------------

#include "NKS2SimTrack.h"

ClassImp(NKS2SimTrack)

//____________________________________________________________

NKS2SimTrack::NKS2SimTrack() : TObject() {

  Init();

}

//____________________________________________________________

NKS2SimTrack::NKS2SimTrack(NKS2SimTrack* pNKS2SimTrack) : TObject() {

   mTrackID        = pNKS2SimTrack -> GetTrackID       ();
   mParentID       = pNKS2SimTrack -> GetParentID      ();
   mPx             = pNKS2SimTrack -> GetPx            ();
   mPy             = pNKS2SimTrack -> GetPy            ();
   mPz             = pNKS2SimTrack -> GetPz            ();
   mX              = pNKS2SimTrack -> GetX             ();
   mY              = pNKS2SimTrack -> GetY             ();
   mZ              = pNKS2SimTrack -> GetZ             ();
   mDecayX         = pNKS2SimTrack -> GetDecayX        ();
   mDecayY         = pNKS2SimTrack -> GetDecayY        ();
   mDecayZ         = pNKS2SimTrack -> GetDecayZ        ();
   mChargeSign     = pNKS2SimTrack -> GetChargeSign    ();
   mMass           = pNKS2SimTrack -> GetMass          ();
   mPDGEncoding    = pNKS2SimTrack -> GetPDGEncoding   ();
   mStep		   = pNKS2SimTrack -> GetStepFirst	   ();

//   mPathLength	   = pNKS2SimTrack -> GetPathLength	   (); // by takeuchi
   mTPosX		   = pNKS2SimTrack -> GetTrackPointX   ();
   mTPosY		   = pNKS2SimTrack -> GetTrackPointY   ();
   mTPosZ		   = pNKS2SimTrack -> GetTrackPointZ   ();

   mNumberOfDCHits = pNKS2SimTrack -> GetNumberOfDCHits();
   mNumberOfIHHits = pNKS2SimTrack -> GetNumberOfIHHits();
   mNumberOfOHHits = pNKS2SimTrack -> GetNumberOfOHHits();
   mNumberOfEVHits = pNKS2SimTrack -> GetNumberOfEVHits();
   mNumberOfEVLGHits = pNKS2SimTrack -> GetNumberOfEVLGHits();
#ifdef MRPCSIM
   mNumberOfMRPCHits = pNKS2SimTrack -> GetNumberOfMRPCHits();
#endif
}

//____________________________________________________________

void NKS2SimTrack::Init() {

   mTrackID                     = -99;
   mParentID                    = -99;
   mPx     = mPy     = mPz      = -99.;
   mX      = mY      = mZ       = -99.;
   mDecayX = mDecayY = mDecayZ  = -99.;
   mChargeSign                  = -99.;
   mMass                        = -99.;
   mPDGEncoding                 = -99;
   mStep						= -99.;

//   mPathLength					= -99.; // by takeuchi

   mTPosX = mTPosY = mTPosZ		= -99.;

   mNumberOfDCHits = 0;
   mNumberOfIHHits = 0;
   mNumberOfOHHits = 0;
   mNumberOfEVHits = 0;
   mNumberOfEVLGHits = 0;
#ifdef MRPCSIM
   mNumberOfMRPCHits = 0;
#endif

}

//____________________________________________________________

void NKS2SimTrack::Clear() {

   mTrackID                     = 0;
   mParentID                    = 0;
   mPx     = mPy     = mPz      = 0.;
   mX      = mY      = mZ       = 0.;
   mDecayX = mDecayY = mDecayZ  = 0.;
   mChargeSign                  = 0.;
   mMass                        = 0.;
   mPDGEncoding                 = 0;
   mStep						= 0.;

//   mPathLength					= 0.; // by takeuchi

   mTPosX = mTPosY = mTPosZ		= 0.;

   mNumberOfDCHits = 0;
   mNumberOfIHHits = 0;
   mNumberOfOHHits = 0;
   mNumberOfEVHits = 0;
   mNumberOfEVLGHits = 0;
#ifdef MRPCSIM
   mNumberOfMRPCHits = 0;
#endif
}


//____________________________________________________________
