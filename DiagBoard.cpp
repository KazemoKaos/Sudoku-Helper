//============================================================================
// Name        : DiagBoard.cpp
// Author(s)   : Tyler Nguyen & Lucien Zheng
// Version     : 11/8/22
// Description : P12: Documentation
//============================================================================
#include "DiagBoard.hpp"
// ---------------------------------------------------------------
DiagBoard::
DiagBoard(char gameType, ifstream& puzFile, int nClusters) : TradBoard(gameType, puzFile, nClusters){
  makeDiagClusters();
  cerr << "DiagBoard created!\n";
}

// ---------------------------------------------------------------
void DiagBoard::
makeDiagClusters(){
  createDiagL();
  clusterV.push_back(clp);
  createDiagR();
  clusterV.push_back(clp);
}

// ---------------------------------------------------------------
void DiagBoard::
createDiagL(){
  Square* arr[N];
  int count = 0;
  int j=1;
  for(int k=1;k<=N;k++){
    arr[count] = &sub(j,k);
    j++;
    count++;
  }
  clp = new Cluster(DIAG, arr, N);
}

// ---------------------------------------------------------------
void DiagBoard::
createDiagR(){
  Square* arr[N];
  int count = 0;
  int j=1;
  for(int k=N;k>=1;k--){
    arr[count] = &sub(j,k);
    j++;
    count++;
  }
  clp = new Cluster(DIAG, arr, N);
} 