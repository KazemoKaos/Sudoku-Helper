//============================================================================
// Name        : Frame.hpp
// Author(s)   : Tyler Nguyen & Lucien Zheng
// Version     : 12/9/22
// Description : P12: Documentation
//============================================================================
#include "Frame.hpp"
// ---------------------------------------------------------------
void Frame::
serialize(ofstream& gameOut){
  gameOut << snapShot.vector::size() << "\n";  //print total squares
  for (State i: snapShot){
    gameOut << i.getPoss() << "\n";   //Prints poss
    gameOut << i.getValue() << "\n";  //Prints Value
    gameOut << i.getState() << "\n";  //Prints the bool of fixed state
  }
}

void Frame::
realize(ifstream& gameIn){
  cout << "Restoring Game" << "\n";
  cout << "=====================================================\n";
  // Data
  int maxSquares;
  short int poss;
  char val;
  bool fixed;
  //=====================================================================
  gameIn >> maxSquares;
  cout << "This game has " << maxSquares << " sqaures to load" << "\n";
  for (int i = 1; i <= maxSquares; i++){
    gameIn >> poss;
    gameIn >> val;
    gameIn >> fixed;
    State st = State(poss, val, fixed);
    addEntireState(st);
  }
  cout << "Snapshot loaded!\n";
}