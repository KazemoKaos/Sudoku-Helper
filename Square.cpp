//============================================================================
// Name        : Square.cpp
// Author(s)   : Tyler Nguyen & Lucien Zheng
// Version     : 9/6/22
// Description : P12: Documentation
//============================================================================
#include "Square.hpp"
#include "Cluster.hpp"
// ---------------------------------------------------------------
Square::
Square(char d, short int row, short int col) : state(d), row(row), col(col){
  //cerr << "Created Square [" << row << ", " << column << "] Value: " << d << '\n';
}

// ---------------------------------------------------------------
void Square::
shoop(char val){ for(Cluster* cl : clusterV){ cl->shoop(val); }}

// ---------------------------------------------------------------
void Square::
print(ostream& os){ os << "R: " << row << " | C: " << col; state.print(os); }