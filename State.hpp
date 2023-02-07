//============================================================================
// Name        : State.hpp
// Author(s)   : Tyler Nguyen & Lucien Zheng
// Version     : 9/3/22
// Description : P12: Documentation
//============================================================================
#pragma once
#include "tools.hpp"
// ---------------------------------------------------------------
class State
{
  protected: // --------------------------------------------------
    short int poss = 0;
    char value = '-';
    bool fixedValue = false;
    int boardSize = 9; //Max char Value

  public: // -----------------------------------------------------
    State() = default;
    State(char ch);
    State(short int p, char ch, bool fv):poss(p), value(ch), fixedValue(fv){}
    ~State() = default;
    void mark(char ch);
    void turnOff(int n);
    void print(ostream& os);
    
    // Getters ---------------------------------------------------
    short int getPoss() {return poss; }         //Get numberic poss
    char getValue() const { return value; }      
    bool getState(){ return fixedValue; }       //Get fixedValue Bool
    string getPossList() const{                 //Get readable possibilty list
      ostringstream oss;
      short int mask = 1;
      for(int digit=1;digit<=boardSize;digit++){
        short int shftdPoss = (poss >> digit);   
        if ((mask & shftdPoss) != 0) oss << digit; 
        else oss << "-"; 
      }
      return oss.str();
    }

    // Setters ---------------------------------------------------
    void setbSize(int size){ boardSize = size; } //Setting max char
};

// ---------------------------------------------------------------
inline ostream& operator << (ostream& os, State& s){ s.print(os); return os; }