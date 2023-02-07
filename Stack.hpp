//============================================================================
// Name        : Stack.hpp
// Author(s)   : Tyler Nguyen & Lucien Zheng
// Version     : 12/9/22
// Description : P12: Documentation
//============================================================================
#pragma once
#include "tools.hpp"
#include "Frame.hpp"

class Stack : private vector<Frame> //template
{
  private:
    vector<Frame*> snapShots; //Collection of snapshots of frames

  public:
    Stack(){}
    ~Stack(){ /*cerr << "Deleting Stack\n";*/ }
    void pop() {snapShots.pop_back();}               //Remove last element
    Frame* top() {return snapShots.back();}          //returns last element
    void push(Frame* ss) {snapShots.push_back(ss);}  //add to end of vector
    int size() {return snapShots.vector::size();}    //returns size of vector
    void zap() {snapShots.clear();}                  //remove all elements in vector
};
