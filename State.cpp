//============================================================================
// Name        : State.cpp
// Author(s)   : Tyler Nguyen & Lucien Zheng
// Version     : 9/3/22
// Description : P12: Documentation
//============================================================================
#include "State.hpp"
// ---------------------------------------------------------------
State::
State(char ch) : value(ch){
  if('1' <= value && value <= '9'){ poss = 0; fixedValue = true; } //should be dynamic (6/9)
  else{ poss = 0x3fe; fixedValue = false; }
}

// ---------------------------------------------------------------
void State::
mark(char ch){
  if(fixedValue){
    cout << "\nError: State is fixed!\n";
    cout << "\nThe state of this square is: "<< getState() << "\n";
  } 
  else{
    value = ch; poss = 0;
    cout << "\nThe state of this square is: "<< getState() << "\n";
  } //value = ch; poss = 0; cout << "I am in the state mark! "<< endl;
}

// ---------------------------------------------------------------
void State::
turnOff(int n){ 
  // poss = 1 1 1 1 1 1 1 1 1 0
  //sposs = 0 0 0 1 0 0 0 0 0 0
  int mask = 1;
  int shftdPoss = (poss >> n);
  //Check to see if the bit is already off.
  if ((mask & shftdPoss) != 0){ 
    int sPoss = pow(2,n);
    poss = poss - sPoss;
  }
}

// ---------------------------------------------------------------
void State::
print(ostream& os){
  short int mask = 1;
  os << " | Poss: ";
  
  for(int digit=1;digit<=boardSize;digit++){
    short int shftdPoss = (poss >> digit);   
    if ((mask & shftdPoss) != 0) os << digit; 
    else os << "-"; 
  }
  
  os << "  |  Value: " << value;
  if (fixedValue) os << "  |  Fixed: T\n";
  else os << "  |  Fixed: F\n";
}