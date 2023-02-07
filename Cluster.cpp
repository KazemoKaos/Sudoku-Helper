//============================================================================
// Name        : Cluster.cpp
// Author(s)   : Tyler Nguyen & Lucien Zheng
// Version     : 10/2/22
// Description : P11: Sixy
//============================================================================
#include "Cluster.hpp"
// ---------------------------------------------------------------
static const char* clusterTString[6] = {"ROW", "COL", "BOX", "DIAG", "VBOX", "HBOX"};

// ---------------------------------------------------------------
Cluster::
Cluster(ClusterT type, Square* cArr[9], int size) : name(clusterTString[type]), clSize(size){ 
  for(int val=0;val<clSize;val++){
    arr[val] = cArr[val];
    arr[val]->addCluster(this);
  }
}

// ---------------------------------------------------------------
void Cluster::
shoop(char val){
  int intVal = val - '0';
  for(int squareP=0;squareP<clSize;squareP++){
    arr[squareP]->turnOff(intVal);
  }
}

// ---------------------------------------------------------------
void Cluster::
print(ostream& os){
  os << "Type: " << name << "\n";
  for(int val=0;val<clSize;val++){
    os << *arr[val];
  }
}