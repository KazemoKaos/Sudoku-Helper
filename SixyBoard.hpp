//============================================================================
// Name        : SixyBoard.hpp
// Author(s)   : Tyler Nguyen & Lucien Zheng
// Version     : 12/17/22
// Description : P12: Documentation
//============================================================================
#pragma once
#include "tools.hpp"
#include "Board.hpp"
// ---------------------------------------------------------------
class SixyBoard : public Board
{
  private:
    // Private functions -----------------------------------------
    void makeClusters();
    void makeVBoxes(short int j, short int k);
    void makeHBoxes(short int j, short int k);

  public: // -----------------------------------------------------
    SixyBoard(char gameType, ifstream& puzFile, int nClusters);
    // ~SixyBoard(){ cerr << "SixyBoard deleted!\n"; } 
};