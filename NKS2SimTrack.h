//-------------------------------------------------------------
//
//  data class for Track
//
//                                               Masashi Kaneta
//-------------------------------------------------------------

#ifndef NKS2SimTrack__h
#define NKS2SimTrack__h

#include "TObject.h"
#include "TMath.h"

class NKS2SimTrack : public TObject {

  public:

             NKS2SimTrack();
             NKS2SimTrack(NKS2SimTrack* pNKS2SimTrack);
    virtual ~NKS2SimTrack() {}


    // Get method
           Int_t    GetTrackID       () { return mTrackID;        }
           Int_t    GetParentID      () { return mParentID;       }
           Double_t GetPx            () { return mPx;             }
           Double_t GetPy            () { return mPy;             }
           Double_t GetPz            () { return mPz;             }
           Double_t GetX             () { return mX;              }
           Double_t GetY             () { return mY;              }
           Double_t GetZ             () { return mZ;              }
           Double_t GetDecayX        () { return mDecayX;         }
           Double_t GetDecayY        () { return mDecayY;         }
           Double_t GetDecayZ        () { return mDecayZ;         }
           Double_t GetChargeSign    () { return mChargeSign;     }
           Double_t GetMass          () { return mMass;           }
           Int_t    GetPDGEncoding   () { return mPDGEncoding;    }
		   Double_t GetStepFirst	 () { return mStep;			  }

//		   Double_t GetPathLength	 () { return mPathLength;	  } // by takeuchi

		   Double_t GetTrackPointX	 () { return mTPosX;		  }
		   Double_t GetTrackPointY	 () { return mTPosY;		  }
		   Double_t GetTrackPointZ	 () { return mTPosZ;		  }

           Int_t    GetNumberOfDCHits() { return mNumberOfDCHits; }
           Int_t    GetNumberOfIHHits() { return mNumberOfIHHits; }
           Int_t    GetNumberOfOHHits() { return mNumberOfOHHits; }
           Int_t    GetNumberOfEVHits() { return mNumberOfEVHits; }
           Int_t    GetNumberOfEVLGHits() { return mNumberOfEVLGHits; }
           Int_t    GetNumberOfMRPCHits() { return mNumberOfMRPCHits; }

           Double_t GetMomentum      () { return TMath::Sqrt( mPx * mPx + mPy * mPy + mPz * mPz ); }

    // Set method
           void     SetTrackID       ( const Int_t    trackid        ) { mTrackID        = trackid;        }
           void     SetParentID      ( const Int_t    parentid       ) { mParentID       = parentid;       }
           void     SetPx            ( const Double_t px             ) { mPx             = px;             }
           void     SetPy            ( const Double_t py             ) { mPy             = py;             }
           void     SetPz            ( const Double_t pz             ) { mPz             = pz;             }
           void     SetX             ( const Double_t x              ) { mX              = x;              }
           void     SetY             ( const Double_t y              ) { mY              = y;              }
           void     SetZ             ( const Double_t z              ) { mZ              = z;              }
           void     SetDecayX        ( const Double_t decayx         ) { mDecayX         = decayx;         }
           void     SetDecayY        ( const Double_t decayy         ) { mDecayY         = decayy;         }
           void     SetDecayZ        ( const Double_t decayz         ) { mDecayZ         = decayz;         }
           void     SetChargeSign    ( const Double_t chargesign     ) { mChargeSign     = chargesign;     }
           void     SetMass          ( const Double_t mass           ) { mMass           = mass;           }
           void     SetPDGEncoding   ( const Int_t    pdgencoding    ) { mPDGEncoding    = pdgencoding;    }
		   void		SetStepFirst	 ( const Double_t step			 ) { mStep			 = step;		   }

//		   void		SetPathLength	 ( const Double_t pathlength	 ) { mPathLength	 = pathlength;	   } // by takeuchi

		   void		SetTrackPointX	 ( const Double_t TPosX			 ) { mTPosX			 = TPosX;		   }
		   void		SetTrackPointY	 ( const Double_t TPosY			 ) { mTPosY			 = TPosY;		   }
		   void		SetTrackPointZ	 ( const Double_t TPosZ			 ) { mTPosZ			 = TPosZ;		   }

           void     SetNumberOfDCHits( const Int_t    numberofdchits ) { mNumberOfDCHits = numberofdchits; }
           void     SetNumberOfIHHits( const Int_t    numberofihhits ) { mNumberOfIHHits = numberofihhits; }
           void     SetNumberOfOHHits( const Int_t    numberofohhits ) { mNumberOfOHHits = numberofohhits; }
           void     SetNumberOfEVHits( const Int_t    numberofevhits ) { mNumberOfEVHits = numberofevhits; }
           void     SetNumberOfEVLGHits( const Int_t    numberofevlghits ) { mNumberOfEVLGHits = numberofevlghits; }
           void     SetNumberOfMRPCHits( const Int_t    numberofmrpchits ) { mNumberOfMRPCHits = numberofmrpchits; }

  private:

    void     Init();
    void     Clear();

    Int_t    mTrackID;                     // ID (serial) number
    Int_t    mParentID;                    // ID (serial) number of Parent Track in Geant4
    Double_t mPx, mPy, mPz;                // [GeV/c]
    Double_t mX , mY , mZ;                 // generted position [cm]
    Double_t mDecayX , mDecayY , mDecayZ;  // decay position [cm]
    Double_t mChargeSign;                  // elementary charge with sign
    Double_t mMass;                        // [GeV/c^2]
    Int_t    mPDGEncoding;                 //  particle encoding number by PDG
	Double_t mStep;
//	Double_t mPathLength;				   // path length from center(target position) to detector by takeuchi [cm]
	Double_t mTPosX,mTPosY,mTPosZ;

    Int_t    mNumberOfDCHits;
    Int_t    mNumberOfIHHits;
    Int_t    mNumberOfOHHits;
    Int_t    mNumberOfEVHits;
    Int_t    mNumberOfEVLGHits;
    Int_t    mNumberOfMRPCHits;


  ClassDef(NKS2SimTrack,1)
};

//_________________________________________________________________________________________________________________________

#endif


