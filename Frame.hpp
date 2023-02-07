//============================================================================
// Name        : Frame.hpp
// Author(s)   : Tyler Nguyen & Lucien Zheng
// Version     : 12/9/22
// Description : P12: Documentation
//============================================================================
#pragma once
#include "tools.hpp"
#include "Square.hpp"
// ---------------------------------------------------------------
class Frame
{
  private: // ----------------------------------------------------
    vector<State> snapShot; //A snapshot of all sqaure states
  public: // -----------------------------------------------------
    Frame(){}
    ~Frame(){ /*cerr << "Deleting Frame\n";*/ }
    void addEntireState(State et) {snapShot.push_back(et);}
    State getEntireState(int index) {return snapShot.at(index);}
    void serialize(ofstream& gameOut);
    void realize(ifstream& gameIn);
};