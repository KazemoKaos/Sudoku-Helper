//============================================================================
// Name        : Cluster.hpp
// Author(s)   : Tyler Nguyen & Lucien Zheng
// Version     : 10/2/22
// Description : P11: Sixy
//============================================================================
#pragma once
#include "Square.hpp"
// ---------------------------------------------------------------
enum ClusterT {ROW, COL, BOX, DIAG, VBOX, HBOX};

// ---------------------------------------------------------------
class Cluster
{
  private: // ----------------------------------------------------
    const char* name;
    int clSize = 9; //Default, change accordingly
    Square* arr[9];

  public: // -----------------------------------------------------
    Cluster(ClusterT type, Square* cArr[9], int size); 
    ~Cluster(){ /*cerr << "Cluster deleted!\n";*/ }
    void shoop(char val);
    void print(ostream& os);
};

// ---------------------------------------------------------------
inline ostream& operator<< (ostream& os, Cluster& c){ c.print(os); return os; }