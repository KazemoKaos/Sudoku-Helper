//============================================================================
// Name        : Game.hpp
// Author(s)   : Tyler Nguyen & Lucien Zheng
// Version     : 9/13/22
// Description : P12: Documentation
//============================================================================
#pragma once
#include "Board.hpp"
#include "DiagBoard.hpp"
#include "TradBoard.hpp"
#include "SixyBoard.hpp"
#include "Viewer.hpp"
#include "Stack.hpp"
// ---------------------------------------------------------------
class Game
{
  private: // ----------------------------------------------------
    const string gameMenu[6] = {"Mark    (M)", "Undo    (U)",
    "Redo    (D)", "Save    (S)", "Restore (R)", "Quit    (Q)"};
    Board* brd;
    Viewer* fancyView;
    char gameType = 't';
    char gameTypeV;
    int gameSize = 9;
    ifstream& inputFile;
    Stack undo;
    Stack redo;

  public: // -----------------------------------------------------
    Game(ifstream& inputFile);
    ~Game(){ cerr << "Game deleted!\n"; delete brd; }
    void run();
};