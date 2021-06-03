// 
//   Analysis.hh
// 

#ifndef Analysis_h
#define Analysis_h 1
#include <string>
#include "TTree.h"
#include "NKS2SimEvent.h"
#include "NKS2SimTrack.h"
using namespace std;


//class TTree;
class NKS2SimEvent;
class NKS2SimTrack;

class Analysis 
{
  public:
             Analysis( string fileName = "root/jogamuito.root" );
    virtual ~Analysis();
  
    void DefineNKS2SimTree();
    void FillNKS2SimTree( int evID );
    void EndOfRun();
  
 
  private:

    TTree        *pTTreeForNKS2SimEvent;
    NKS2SimEvent *pNKS2SimEvent;
};

#endif
