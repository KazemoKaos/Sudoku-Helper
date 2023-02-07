//============================================================================
// Name        : DiagBoard.hpp
// Author(s)   : Tyler Nguyen & Lucien Zheng
// Version     : 11/8/22
// Description : P12: Documentation
//============================================================================
#pragma once
#include "TradBoard.hpp"
// ---------------------------------------------------------------
class DiagBoard : public TradBoard
{
  private:
    // Private functions -----------------------------------------
    void makeDiagClusters();
    void createDiagL();
    void createDiagR();

  public: // -----------------------------------------------------
    DiagBoard(char gameType, ifstream& puzFile, int nClusters);
    // ~DiagBoard(){ cerr << "DiagBoard deleted!\n"; } 
};