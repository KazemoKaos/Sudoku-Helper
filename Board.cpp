//============================================================================
// Name        : Board.cpp
// Author(s)   : Tyler Nguyen & Lucien Zheng
// Version     : 9/22/22
// Description : P12: Documentation
//============================================================================
#include "Board.hpp"
// ---------------------------------------------------------------
Board::
Board(char type, ifstream& puzFile, int nClusters) : puzFile(puzFile), nClusters(nClusters){
  cerr << "Board created!\n";
  if(type == 't' || type == 'd') N = 9;
  else if(type == 's') N = 6;
  else /*fatal("Error: Input file is invalid.");*/throw BadGame(type);

  boardSize = N*N;
  bSize = '0' + N; //Set max char
  left = boardSize;
  bd = new Square[boardSize]; 
  getPuzzle();
  makeClusters();
  cerr << "bSize: " << bSize << "\n";
  cerr << "Number of Cluster: " << nClusters << "\n";
  cerr << "Construction Done!\n";
}

// ---------------------------------------------------------------
void Board::
getPuzzle(){
  char value;
  puzFile.get(); // Discard the first char (gameType)
  for (int j = 1; j <= N; j++){
    for (int k = 1; k <= N; k++){
      puzFile.get(value);
      while (isspace(value)){
        puzFile.get(value); //If value is space or \n, get next char.
      }
      if(puzFile.eof()) throw IncompleteFile();
      if (value == '-' || ('1' <= value && value <= bSize)){
        sub(j,k) = Square(value,j,k);
        sub(j,k).setbrdSize(N); //Set max char value
      }
      else throw BadFixedValue(value);
    }
  }
}

// ---------------------------------------------------------------
void Board::
makeClusters(){
  for(int var=1;var<N+1;var++){ //Create Row and Column Clusters
    createRow(var);
    clusterV.push_back(clp);
    createColumn(var);
    clusterV.push_back(clp);
  }
}

// ---------------------------------------------------------------
void Board::
createRow(short int j){ //Pass in the Row, iterate through elements in the row
  Square* arr[N];
  int count = 0;
  for(int k=1;k<N+1;k++) { //Column
    arr[count] = &sub(j,k);
    count++;
  }
  clp = new Cluster(ROW, arr, N);
}

// ---------------------------------------------------------------
void Board::
createColumn(short int k){  //Pass in the Column, iterate through elements in the column
  Square* arr[N];
  int count = 0;
  for(int j=1;j<N+1;j++){ //Row
    arr[count] = &sub(j,k);
    count++;
  }
  clp = new Cluster(COL, arr, N);
}

// ---------------------------------------------------------------
void Board::
clearClusters(){
  for(int val=0;val<clusterV.size();val++){ delete clusterV[val]; }
  clusterV.clear();
}
// ---------------------------------------------------------------
char Board::getMarkChar(int r, int c) const{
  return sub(r,c).getValue();
}

// ---------------------------------------------------------------
string Board::getPossibilityString(int r, int c) const{
  return sub(r,c).getPossList();
}

// ---------------------------------------------------------------
Frame* Board::
move(){
  Frame* ss = new Frame; // Dynamic frame
  for (int r = 1; r <= N; r++){
    for (int c = 1; c <= N; c++){
      //Add the state (not fixedValue) of the square into the frame
      ss->addEntireState(sub(r,c).getEntireState()); //Get state of square and adds to snapshot frame
    }
  }
  return ss;
}

// ---------------------------------------------------------------
void Board::
restoreState(Frame* ss){
  int index = 0; //Tracks which square
  for (int r = 1; r <= N; r++){
    for (int c = 1; c <= N; c++){
      sub(r,c).setEntireState(ss->getEntireState(index)); //Sets state of square from snapshot frame
      index++;
    }
  }
}

// ---------------------------------------------------------------
void Board::
print(ostream& os){
  /*
  os << "\n---------------------Clusters----------------------------\n";
  for(int clusters=0;clusters<clusterV.size();clusters++){
    os << " " << *clusterV[clusters];
  }
  */
  os << "\n---------------------Squares----------------------------\n";
  for(int squares=0;squares<=boardSize-1; squares++){
    if(squares % N == 0) os << "\n";
    bd[squares].print(os);
  }
}