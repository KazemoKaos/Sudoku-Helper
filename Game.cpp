//============================================================================
// Name        : Game.cpp
// Author(s)   : Tyler Nguyen & Lucien Zheng
// Version     : 9/13/22
// Description : P12: Documentation
//============================================================================
#include "Game.hpp"
// ---------------------------------------------------------------
Game::
Game(ifstream& inputFile) : inputFile(inputFile){
  inputFile.get(gameType);
  cout << "\nGame Type: " << gameType << "\n";
  
  string validType = "TtDdSs"; //Traditional, Diagonal, Sixy
  size_t found = validType.find(gameType);
  if (found!=string::npos) cout << "Game Type is valid!\n";
  else /*fatal("Error: Game Type is invalid!\n");*/throw BadGame(gameType);

  gameTypeV = tolower(gameType);
  if(gameTypeV == 't'){ 
    brd = new TradBoard(gameTypeV, inputFile, 27); 
    gameSize = 9;
  } else if(gameTypeV == 'd'){ 
    brd = new DiagBoard(gameTypeV, inputFile, 29);
    gameSize = 9;
  } else{
    brd = new SixyBoard(gameTypeV, inputFile, 24);
    gameSize = 6;
  }

  if(gameTypeV == 't' || gameTypeV == 'd'){
    fancyView = new Viewer(9, 9, *brd);
    fancyView->show(cout);
    //brd->print(cout); // For Debugging
  }else{ brd->print(cout); }
}

// ---------------------------------------------------------------
void Game::
run(){
  const char* title = "Game Menu";
  const char* validOptions = "MmUuDdSsRrQq";
  char ch = ' ', value;
  short int r, c;
  

  while(ch != 'Q'){
    char menuInput = menu_c(title, 6, gameMenu, validOptions);
    int size = brd->getSize(); //Cannot mark row and columns that does not exist
    char bSize = '0' + size;
    ch = toupper(menuInput);
    
    switch(ch){
      case 'M': 
        cout << "\nEnter Value, Row, and Column (Ex. 3 1 5): ";
        try {
          cin >> value; 
          if(value == '-' || ('1' <= value && value <= bSize)){
            cin >> r; //If value is correct, continue
            if (!cin.fail() && r > 0 && r <= size){
              cin >> c; //If row exists, continue
              if (!cin.fail() && c > 0 && c <= size){
                brd->sub(r, c).mark(value); //If column exists, mark.
                if (!brd->sub(r,c).getState()){
                  if(gameTypeV == 't' || gameTypeV == 'd'){
                    fancyView->show(cout);
                  }else{ brd->print(cout); }
                  cout << "\nSquare [" << r << ", " << c << "] was marked: " << value << "\n";
                  cout << "=====================================================\n";
                  //Handle after every move
                  Frame* ss = brd->move(); //Push Board* brd onto Frame
                  cout << "Board ptr pushed onto Frame\n";
                  undo.push(ss);
                  cout << "Frame pushed onto the Undo Stack\n"; //Push Frame onto Undo Stack
                  redo.zap();
                  cout << "Redo Stack was Zapped (Cleared)\n"; 
                  cout << "=====================================================\n";
                }
                break;
              } 
            }
          }
          throw LogicError(value);
        }
        catch (LogicError& le) {le.print();}
        break;
      case 'U': 
        //Push brd pointer onto Frame, THEN push Frame onto Stack
        cout << "Undo.\n";
        cout << "=====================================================\n";
        if(undo.size() >= 2){
          Frame* uSS = undo.top();
          cout << "Top of Undo Stack is Saved\n";
          undo.pop();
          cout << "Frame was popped from Undo Stack\n";
          redo.push(uSS);
          cout << "Frame was pushed onto Redo Stack\n";
          brd->restoreState(undo.top()); //restore state
          cout << "=====================================================\n";
          if(gameTypeV == 't' || gameTypeV == 'd'){
            fancyView->show(cout);
          }else{ brd->print(cout); }
          break;
          } else cout << "Not enough Frames on the Undo Stack, please try again.\n"; 
        break; 
      case 'D': 
        cout << "Redo.\n";
        // Case Scenario: Must Undo before Redo-ing
        cout << "=====================================================\n";
        if(redo.size() == 0){ 
        cout << "Not enough Frames on the Redo Stack, please try again. \n";
        cout << "=====================================================\n"; break; }
        else{
          Frame* rSS = redo.top();
          cout << "Top of Redo Stack is Saved\n";
          redo.pop();
          cout << "Frame was popped from Redo Stack\n";
          undo.push(rSS);
          cout << "Frame was pushed onto Undo Stack\n";
          brd->restoreState(undo.top()); //restore state
          cout << "=====================================================\n";
          if(gameTypeV == 't' || gameTypeV == 'd'){
            fancyView->show(cout);
          }else{ brd->print(cout); }
          break;
        }
      case 'S': 
      {
        //Saving the game to a file.
        cout << "Save.\n";
        cout << "=====================================================\n";
        if (undo.size() >=1){
          string name;
          cout << "Type in the name of your save file: ";
          cin >> name;
          ofstream oFile(name);
          //oFile.open(name);
          undo.top()->serialize(oFile);
          oFile.close();
          cout << "Screenshot of current board state has been saved\n";
          cout << "=====================================================\n";
          if(gameTypeV == 't' || gameTypeV == 'd'){
            fancyView->show(cout);
          }else{ brd->print(cout); }
        } else cout << "Not enough Frames on the Undo Stack, please try again.\n"; 
        break; 
      }
      case 'R': 
      {
        cout << "Restore.\n"; 
        cout << "=====================================================\n";
        string name;
        cout << "Type in the name of your save file: ";
        cin >> name;
        ifstream iFile(name);
        cout << ("Checking file: " + name + "\n");
        if (!iFile.is_open()) throw StreamError(name);
        undo.zap();
        cout << "Undo Stack was Zapped (Cleared)\n"; 
        redo.zap();
        cout << "Redo Stack was Zapped (Cleared)\n";
        cout << "Starting Restore Process\n";
        Frame* rSS = new Frame;
        rSS->realize(iFile);
        iFile.close();
        brd->restoreState(rSS); //Restore state of previous save
        for (int j = 1; j <= gameSize; j++){ //Sets max char 
          for (int k = 1; k <= gameSize; k++){
            brd->sub(j,k).setbrdSize(gameSize);
          }
        }
        cout << "=====================================================\n";
          if(gameTypeV == 't' || gameTypeV == 'd'){
            fancyView->show(cout);
          }else{ brd->print(cout); }
        break;
      }
      case 'Q': 
        cout << "Quitting ... \nExit Complete.";
        cout << "\n--------------------------------------------------------\n"; break;
    }
  }
}