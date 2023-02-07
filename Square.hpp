//============================================================================
// Name        : Square.hpp
// Author(s)   : Tyler Nguyen & Lucien Zheng
// Version     : 9/6/22
// Description : P12: Documentation
//============================================================================
#pragma once
#include "State.hpp"
// ---------------------------------------------------------------
class Cluster;

// ---------------------------------------------------------------
class Square : public State
{
  private: // ----------------------------------------------------
    State state;
    short int row;
    short int col;
    vector<Cluster*> clusterV;
    
  public: // -----------------------------------------------------
    Square() = default;
    Square(char d, short int row, short int col);
    ~Square(){ /*cerr << "Square Deleted!\n";*/ }
    void mark(char ch){ state.mark(ch); shoop(ch); }
    void addCluster(Cluster* clstr){ clusterV.push_back(clstr); }
    void shoop(char val);
    void turnOff(int n){ state.turnOff(n); }
    void print(ostream& os);

    // Setters ---------------------------------------------------
    void setbrdSize(int size){ state.setbSize(size); } //Sets max char
    void setEntireState(State et){ state = et; }       //Sets the state of square

    // Getters ---------------------------------------------------
    char getValue(){ return state.getValue(); }
    bool getState(){ return state.getState(); }        //Get fixedValue Bool
    State getEntireState(){ return state;}             //Get state of square
    string getPossList(){ return state.getPossList(); }
};

// ---------------------------------------------------------------
inline ostream& operator << (ostream& os, Square& s){ s.print(os); return os; }