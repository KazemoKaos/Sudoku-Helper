//============================================================================
// Name        : ExceptLogic.hpp
// Author(s)   : Tyler Nguyen & Lucien Zheng
// Version     : 11/15/22
// Description : P12: Documentation
//============================================================================
#pragma once
#include "tools.hpp"

// Base LogicError Class
class LogicError
{
  public:
    char charError;
    //Constructors for different errors
    LogicError() {}
    LogicError(char x) : charError(x) {}
    // Invalid Mark Value
    virtual ~LogicError()=default;
    virtual void print(){
      cerr << "The input value is invalid!\n";
      pr();
    }
    //Prints for different errors
    void pr(){
      cerr << "Please reenter.\n";
    }
    void prc(){
      cerr << "You entered " << charError
      << ".\nPlease reenter.\n";
    }
};

// Marking a fixed value
class BadMark : public LogicError
{
  public:
    BadMark() {}
    virtual ~BadMark(){};
    virtual void print(){
      cerr << "This is a fixed value!";
      pr();
    }
};
/* 
Exceptions for game logic. (Should rename this file to ExceptLogic or something so it will be together on the file list with ExceptStream)
- Invalid Row (Done)
- Invalid Column (Done)
- Invalid value to mark (Done) Combined the three
- Trying to mark a square that is fixed. (Done)
*/