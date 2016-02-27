// Author: Seth Waldstein, Rob Montjoy, Paul Talaga
// Source File: battleship-sandbox.cpp
// Description: An interactive Battleship Game!
// Date: Feb 2016
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <iomanip>

#include "simpio.h"

#include <battleship.cpp>

using namespace std;

//functions implemented in battleship.cpp
//  createBoat
//  placeAIBoats
//  hasLost
//  isHit

//function prototypes implemented in this file
void printFullBoard(char boatArray[][BOARD_SIZE]);
void printHitMissBoard(char boatArray[][BOARD_SIZE]);
void printBoard(char boatArray[][BOARD_SIZE], bool all);
bool placeUserBoats(char boatArray[][BOARD_SIZE]);
void clearArray(char boatArray[][BOARD_SIZE]);
void getAIXandY(int& x,int& y);
void getXandY(int& x,int& y);
void pauseGame();



int main(){
  int x,y;
  //bool you_win=false, ai_win = false;
  char myArray[BOARD_SIZE][BOARD_SIZE]={{}};
  char AIArray[BOARD_SIZE][BOARD_SIZE]={{}};

  srand(time(0));
  clearArray(AIArray);
  clearArray(myArray);

  cout<< "Welcome to Battleship!"<<endl;
  pauseGame();
  printFullBoard(myArray);   //prints my game board
  
  placeUserBoats(myArray);  

  
  cout << "Initializing AI Board: .\b...\b.\b\b...\b" << endl;
  pauseGame();
  
  cout<<"Ok your boats are all placed.  Lets start the game!"<<endl;
  placeAIBoats(AIArray);   //creates computers board

  while(true){  //game play loop while no one has won
    printFullBoard(myArray);   // Print your board
    printHitMissBoard(AIArray);  //Prints hit/miss board for you
    
    cout<<"It is your turn, choose where to attack"<<endl;
    getXandY(x,y);
    isHit(AIArray,x,y);  // Register attack on AI
    //printHitMissBoard(AIArray);
    
    if(hasLost(AIArray))break;  //checks if you have won, will skip to end
      
    cout<<"The computer will now attack"<<endl;
    pauseGame();
    
    getAIXandY(x,y);
    isHit(myArray,x,y); // Register attack on my ships
    cout<<"The computer attacked at " << (char)(y+'A') << x+1<< "..." <<endl;
    if(hasLost(myArray)) break;  //checks if you have one, will skip to end
  };   

  if(hasLost(AIArray)){
    printHitMissBoard(AIArray);
    cout<<"YOU WON!\n"<<endl;
  }else{
    printFullBoard(myArray);
    cout<<"Sorry, you lost\n"<<endl;
  }

  return 0;
}

void pauseGame(){
  //Pause for 500ms
  usleep(500000);
}

void getXandY(int& x,int& y){
  // Subtract 1 as the visual board goes from 1-10 and array indexes
  // go from 0-9
  x = -1;
  y = -1;
  do{
    string input = getLine("Location: ");
    if( input.size() != 2 && input.size() != 3){
      cout << "Invalid Entry, try again.\n";
      continue;
    }
    y = tolower(input[0]) - 'a';
    x = atoi(input.substr(1).c_str()) - 1; // -1 for 0 based
  }while(x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE);
  // This passes 2 parameters back via reference
}


void getAIXandY(int& x,int& y){
  x = rand()%BOARD_SIZE;
  y = rand()%BOARD_SIZE;
}

bool placeUserBoats(char boatArray[][BOARD_SIZE]){ //gets users boat inputs
  int x,y,orientation;
  for(int i=5; i >= 2; i--){ //loops for inputs of boat size 5 to 2
    bool boat_created;
    do {
      cout << "\nInput starting point of boat size "<<i<<", using ";
      cout << " LetterColumn ex: B5 or g3"<<endl;
      getXandY(x, y);
      cout<<"Enter the orientation(0=right,1=down)"<<endl;
      orientation = getInteger("Orientation: " );
      boat_created = createBoat(boatArray,x,y,orientation,i);
      if(!boat_created){
        cout<<"\nYour boat placement is invalid, Please try again!\n" <<endl;
      }
      printFullBoard(boatArray);      // if successfull print out updated array
    } while(!boat_created);    //checks if inputs create valid boat
  }
  return true;   //if all boats placed move on
}


void printFullBoard(char boatArray[][BOARD_SIZE]){
  cout<<"Here is your board:"<<endl;
  printBoard(boatArray, true);
}

void printHitMissBoard(char boatArray[][BOARD_SIZE]){
  cout<<"Your Hit/Miss Board:"<<endl;
  printBoard(boatArray, false);
}

void printBoard(char boatArray[][BOARD_SIZE], bool all){
  cout << "   ";
  for(int k = 1; k <= BOARD_SIZE; k++){
    if( k/10 == 0)cout << "  ";
    else cout << k/10 << " ";

  }
  cout << endl << "  ";
  for(int k = 1; k <= BOARD_SIZE; k++){
    cout << fixed << setw(2) << k%10;
  }
  cout << endl;
  for(int i=0; i < BOARD_SIZE; i++){
    cout <<  (char)('A' + i) << "  " ;
    for(int j=0; j < BOARD_SIZE; j++){
      if( !all && boatArray[i][j] == BOAT){
        cout << EMPTY << " ";
      }else{
        cout << boatArray[i][j] << " ";
      }
    }
    cout << endl;
  }
  cout << endl;
}

void clearArray(char boatArray[][BOARD_SIZE]){ //clears array to all EMPTY
  for(int i=0; i < BOARD_SIZE; i++){
    for(int j=0; j < BOARD_SIZE; j++){
      boatArray[i][j]= EMPTY;
    }
  }
}

