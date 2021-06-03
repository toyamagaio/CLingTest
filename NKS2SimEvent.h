//----------------------------------------------------------------
//  
// Simulation Event class for NKS2 TTree
//                                                  Masashi Kaneta
//----------------------------------------------------------------

#ifndef NKS2SimEvent__h
#define NKS2SimEvent__h

#include "TObject.h"
#include "TClonesArray.h"

class NKS2SimTrack;

class NKS2SimEvent : public TObject {

  public:
                           NKS2SimEvent();
    virtual               ~NKS2SimEvent();

           void            Initialization();
           void            Clear();

    // Get method

           Int_t           GetEventNumber    ()       { return mEventNumber;     }
           Int_t           GetTriggerNumber  ()       { return mTriggerNumber;   }

           Double_t        GetBeamEnergy     ()       { return mBeamEnergy;      }

           Double_t        GetTargetMomentumX()       { return mTargetMomentumX; }
           Double_t        GetTargetMomentumY()       { return mTargetMomentumY; }
           Double_t        GetTargetMomentumZ()       { return mTargetMomentumZ; }
           Double_t        GetTargetMass()            { return mTargetMass;      }

           Double_t        GetW              ()       { return mW;               }

           Double_t        GetVertexX        ()       { return mVertexX;         }
           Double_t        GetVertexY        ()       { return mVertexY;         }
           Double_t        GetVertexZ        ()       { return mVertexZ;         }

           Int_t           GetNumberOfTracks ()       { return mNumberOfTracks;  }


           TClonesArray*   GetNKS2SimTrack   () const { return fNKS2SimTrack;    }

    // Set method

           void            SetEventNumber    ( const Int_t    eventnumber     ) { mEventNumber     = eventnumber;     }
           void            SetTriggerNumber  ( const Int_t    triggernumber   ) { mTriggerNumber   = triggernumber;   }

           void            SetBeamEnergy     ( const Double_t beamenergy      ) { mBeamEnergy      = beamenergy;      }
                         
           void            SetTargetMomentumX( const Double_t targetmomentumx ) { mTargetMomentumX = targetmomentumx; }
           void            SetTargetMomentumY( const Double_t targetmomentumy ) { mTargetMomentumY = targetmomentumy; }
           void            SetTargetMomentumZ( const Double_t targetmomentumz ) { mTargetMomentumZ = targetmomentumz; }
           void            SetTargetMass     ( const Double_t targetmass      ) { mTargetMass      = targetmass;      }

           void            SetW              ( const Double_t w               ) { mW               = w;               }

           void            SetVertexX        ( const Double_t vertexx         ) { mVertexX         = vertexx;         }
           void            SetVertexY        ( const Double_t vertexy         ) { mVertexY         = vertexy;         }
           void            SetVertexZ        ( const Double_t vertexz         ) { mVertexZ         = vertexz;         }

           void            AddTrack   ( NKS2SimTrack*    pNKS2SimTrack    );

  private:

           Int_t           mEventNumber;             //  Event number
           Int_t           mTriggerNumber;           //  Trigger number

           Double_t        mBeamEnergy;              //  Beam Energy [GeV]

           Double_t        mTargetMomentumX;         //  Target momentum x [GeV/c]
           Double_t        mTargetMomentumY;         //  Target momentum y [GeV/c]
           Double_t        mTargetMomentumZ;         //  Target momentum z [GeV/c]
           Double_t        mTargetMass;              //  Target mass       [GeV/c^2]

           Double_t        mW;                       //  Total energy of the system ( root(s) ) [GeV]

           Double_t        mVertexX;                 // collision vertex x [cm]
           Double_t        mVertexY;                 // collision vertex y [cm]
           Double_t        mVertexZ;                 // collision vertex z [cm]


           Int_t           mNumberOfTracks;          //  Number of Tracks
           TClonesArray*    fNKS2SimTrack;
    static TClonesArray*   fgNKS2SimTrack;

  ClassDef(NKS2SimEvent,1)

};

#endif
