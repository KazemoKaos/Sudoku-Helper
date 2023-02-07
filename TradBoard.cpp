//============================================================================
// Name        : DiagBoard.cpp
// Author(s)   : Tyler Nguyen & Lucien Zheng
// Version     : 11/8/22
// Description : P11: Sixy
//============================================================================
#include "TradBoard.hpp"
// ---------------------------------------------------------------
TradBoard::
TradBoard(char gameType, ifstream& puzFile, int nClusters) : Board(gameType, puzFile, nClusters){
  makeClusters();
  cerr << "TradBoard created!\n";
}

// ---------------------------------------------------------------
void TradBoard::
makeClusters(){
  for(int j=1;j<N+1;j+=3){ //Pass in Top Left Square as Parameter(s) to Create Boxes
    for(int k=1;k<N+1;k+=3){
      createBox(j,k);
      clusterV.push_back(clp);
    }
  }
}

// ---------------------------------------------------------------
void TradBoard::
createBox(short int j, short int k){ //Pass in the Top Left Square(s)
  int jMax = j + 3;
  int kMax = k + 3;
  Square* arr[N];
  int count = 0;
    for(j;j<jMax;j++){ //Row
      for(int kMin=k;kMin<kMax;kMin++){ //Column
        arr[count] = &sub(j,kMin);
        count++;
      }
    }
  clp = new Cluster(BOX, arr, N);
}