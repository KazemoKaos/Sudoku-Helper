//============================================================================
// Name        : TradBoard.hpp
// Author(s)   : Tyler Nguyen & Lucien Zheng
// Version     : 12/17/22
// Description : P11: Sixy
//============================================================================
#pragma once
#include "Board.hpp"
// ---------------------------------------------------------------
class TradBoard : public Board
{
  private:
    // Private functions -----------------------------------------
    void makeClusters();
    void createBox(short int j, short int k);

  public: // -----------------------------------------------------
    TradBoard(char gameType, ifstream& puzFile, int nClusters);
    // ~TradBoard(){ cerr << "TradBoard deleted!\n"; } 
};