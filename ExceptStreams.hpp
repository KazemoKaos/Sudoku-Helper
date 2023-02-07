//============================================================================
// Name        : ExceptStreams.hpp
// Author(s)   : Tyler Nguyen & Lucien Zheng
// Version     : 11/15/22
// Description : P12: Documentation
//============================================================================
#pragma once
#include "tools.hpp"

// Base StreamError Class
class StreamError
{
  public:
    string stringError;
    char charError;
    //Constructors for different errors
    StreamError() {}
    StreamError(string x) : stringError(x) {}
    StreamError(char x) : charError(x) {}
    // Invalid file
    virtual ~StreamError()=default;
    virtual void print(){
      cerr << "You have entered an invalid file name!\n";
      prs();
    }
    //Prints for different errors
    void pr(){
      cerr << "Please reenter.\n";
    }
    void prs(){
      cerr << "You entered " << stringError
      << ".\nPlease reenter.\n";
    }
    void prc(){
      cerr << "You entered " << charError
      << ".\nPlease reenter.\n";
    }
};

// Bad Game Type
class BadGame : public StreamError
{
  public:
    BadGame(char x) : StreamError(x) {}
    virtual ~BadGame(){}
    virtual void print(){
      cerr << "Legal game types are: T, S, D\n";
      prc();
    }
};

// Bad Value in File
class BadFixedValue : public StreamError
{
  public:
    BadFixedValue(char x) : StreamError(x) {}
    virtual ~BadFixedValue(){}
    virtual void print(){
      cerr << "Legal values are: 1..N, -\n";
      prc();
    }
};

// Incomplete File
class IncompleteFile : public StreamError
{
  public:
    IncompleteFile(){};
    virtual ~IncompleteFile(){};
    virtual void print(){
      cerr << "Your file is incomplete!\n";
      pr();
    }
};

class CLError : public StreamError
{
  public:
    CLError(){};
    virtual ~CLError(){};
    virtual void print(){
      cerr << "Usage: game filename\n";
      pr();
    }
};


/* 
Exceptions for streams
- Input file cannot be read (Done)
- Invalid game type (Done)
- Puzzle file is incomplete (Done)
- Wrong value in the file (Done)
*/