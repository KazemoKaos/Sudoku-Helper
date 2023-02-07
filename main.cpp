//============================================================================
// Name        : main.cpp
// Author(s)   : Tyler Nguyen & Lucien Zheng
// Version     : 9/3/22
// Description : P12: Documentation (Sudoku Helper)
//============================================================================
#include "Game.hpp"
// ---------------------------------------------------------------
int main(int argc, char* argv[]){
  banner();
  say("Welcome to P12: Sudoku Helper!");
  try{
    if(argc!=2) throw CLError();
    cout << ("Checking file: " + string(argv[1]) + "\n");
    ifstream in(argv[1]);
    if(!in.is_open()) /*fatal("Can't open file " + string(argv[1]) + " for reading\n")*/throw StreamError(string(argv[1]));
    Game gm(in);
    gm.run();
    in.close();
  }
  catch (StreamError& se) {se.print(); return 1;}
  //catch (LogicError& le) {le.print();}
  catch (bad_alloc ba){
    cerr << "Allocation error happened. Review the lines you just typed.\n";
    return 1;
  }
  catch (...){
    cerr << " This is the catch everything block. Seems like we ran out of time to imeplement an exception. Sorry for the inconvenience!\n";
    return 1;
  }  
  bye();
}