//============================================================================
// Name        : Board.hpp
// Author(s)   : Tyler Nguyen & Lucien Zheng
// Version     : 9/22/22
// Description : P12: Documentation
//============================================================================
#pragma once
#include "Square.hpp"
#include "Cluster.hpp"
#include "CanView.hpp"
#include "ExceptStreams.hpp"
#include "ExceptLogic.hpp"
#include "Stack.hpp"
// ---------------------------------------------------------------
class Board : public CanView
{
  protected: // ----------------------------------------------------
    int N; // Game Type Size
    char bSize; //max Char Size
    int boardSize;
    Square* bd;
    ifstream& puzFile;
    short int left;
    vector<Cluster*> clusterV;
    Cluster* clp;
    int nClusters;

    // Private functions -----------------------------------------
    void getPuzzle();
    void makeClusters();
    void clearClusters();
    void createRow(short int j);
    void createColumn(short int k);

  public: // -----------------------------------------------------
    Board(char gameType, ifstream& puzFile, int nClusters);
    ~Board(){ cerr << "Board deleted!\n"; delete[] bd; clearClusters(); }
    Square& sub(int r, int c) const { return bd[(r - 1) * N + (c - 1)]; }
    char getMarkChar(int r, int c) const;
    string getPossibilityString(int r, int c) const;
    Frame* move();
    void restoreState(Frame*);
    void print(ostream& os);

    // Getters ---------------------------------------------------
    int getSize(){ return N; }
};

// ---------------------------------------------------------------
inline ostream& operator<< (ostream& os, Board& b){ b.print(os); return os; }