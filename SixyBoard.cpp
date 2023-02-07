//============================================================================
// Name        : SixyBoard.cpp
// Author(s)   : Tyler Nguyen & Lucien Zheng
// Version     : 12/17/22
// Description : P12: Documentation
//============================================================================
#include "SixyBoard.hpp"
// ---------------------------------------------------------------
SixyBoard::
SixyBoard(char gameType, ifstream& puzFile, int nClusters) : Board(gameType, puzFile, nClusters){
  makeClusters();
  cerr << "SixyBoard Created!\n";
}

// ---------------------------------------------------------------
void SixyBoard::
makeClusters(){
  for(int j=1;j<N+1;j+=3){ //Pass in Top Left Square as Parameter(s) to Create Boxes
    for(int k=1;k<N+1;k+=2){
      makeVBoxes(j,k);
      clusterV.push_back(clp);
    }
  }
  
  for(int j=1;j<N+1;j+=2){ //Pass in Top Left Square as Parameter(s) to Create Boxes
    for(int k=1;k<N+1;k+=3){
      makeHBoxes(j,k);
      clusterV.push_back(clp);
      }
    }
}

// ---------------------------------------------------------------
void SixyBoard::
makeVBoxes(short int j, short int k){ //Pass in the Top Left Square(s)
  int jMax = j + 3;
  int kMax = k + 2;
  Square* arr[N];
  int count = 0;
    for(j;j<jMax;j++){ //Row
      for(int kMin=k;kMin<kMax;kMin++){ //Column
        arr[count] = &sub(j,kMin);
        count++;
      }
    }
  clp = new Cluster(VBOX, arr, N);
}

// ---------------------------------------------------------------
void SixyBoard::
makeHBoxes(short int j, short int k){ //Pass in the Top Left Square(s)
  int jMax = j + 2;
  int kMax = k + 3;
  Square* arr[N];
  int count = 0;
    for(j;j<jMax;j++){ //Row
      for(int kMin=k;kMin<kMax;kMin++){ //Column
        arr[count] = &sub(j,kMin);
        count++;
      }
    }
  clp = new Cluster(HBOX, arr, N);
}