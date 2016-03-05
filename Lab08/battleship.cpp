// Author: <fill in your name>
// Source File: battleship.cpp
// Description: Helper functions for the battleship game.
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <iomanip>
#include <time.h>

using namespace std;

// Constants representing characters in the arrays
const int BOARD_SIZE = 10;
const char HIT = 'X';
const char MISS = 'o';
const char BOAT = 'B';
const char EMPTY = ' ';


// Creates the boat at position x,y, (0 based) with orientation, and length.  This should
// return true if the boat could be placed (and change the array), but if the
// boat could not be placed, either because a boat is in its path or the boat goes
// outside the bounds, then return false and be sure NOT to change the array.
// Orientation 0 is horizontal (right), and 1 is vertical (down)
bool createBoat(char boatArray[][BOARD_SIZE],int x, int y, int orientation, int boat_length){
//return 0;
  if (x >= BOARD_SIZE || y >= BOARD_SIZE || x < 0 || y < 0 || orientation < 0 || orientation > 1){
    return false;
  }
  if (orientation == 1){
    if ((x + boat_length - 1) > BOARD_SIZE - 1){
      return false;
    }  
    for (int j = 0; j < 2; j++){
      for (int k = 0; k < boat_length; k++){
        if(boatArray[x+k][y] == BOAT){
          return false;
        }else{
          if (j == 1){
            boatArray[x+k][y] = BOAT;
          }
        }
      }
    }  
  }
  if (orientation == 0){
    if ((y + boat_length - 1) > BOARD_SIZE - 1){
      return false;
    }
    for (int j = 0; j < 2; j++){
      for (int k = 0; k < boat_length; k++){
        if(boatArray[x][y+k] == BOAT){
          return false;
        }else{
          if (j == 1){
            boatArray[x][y+k] = BOAT;
          }
        }
      }
    }
  } 
  return true;   // if boat is successfull
}


// Places 4 boats on the board randomly.  One of size 5,4,3,2, in any orientation.
// Return true if successful, and false ONLY if there is no way to place boats.
// It is OK to try to place boats for a limited (large) amount of tries and then
// give up.
bool placeAIBoats(char boatArray[][BOARD_SIZE]){
  int count = 0;
  bool t = false;
  for (int l = 2; l < 6; l++){
    do {
      int x = rand()%10;
      int y = rand()%10;
      int boat_length = l;
      int orientation = rand()%2;
      t = createBoat(boatArray,x,y,orientation,boat_length);
      count++;
      if (count > 100){
        return false;
      }
    }while(t == false);
  }
  return true;
}

// Returns true if no more boats (BOAT characters) exist on the board.
bool hasLost(char boatArray[][BOARD_SIZE]){
  for (int j = 0; j < BOARD_SIZE; j++){
    for (int k = 0; k < BOARD_SIZE; k++){
      if (boatArray[j][k] == BOAT){
        return false;   
    }
  }
 
}
 return true; // if no boat is found, someone has lost
}

// Returns true if a boat was hit in that spot for the first time.  If x or y
// are outside the bounds of the board, return false.  If that x,y was previously
// chosen (either a hit or a miss) or no boat is there, return false.  
// This should change the array if a hit was done, or a miss on a un-missed spot.
// Note to use HIT, MISS, and BOAT char constants in the array.
// It is OK to cout a message to the user, but not required.
bool isHit(char boatArray[][BOARD_SIZE],int x, int y){
  if (x >= BOARD_SIZE || y >= BOARD_SIZE){
    return false;
  }else{
    if (boatArray[x][y] == BOAT){
      boatArray[x][y] = HIT;
      return true;
    }else if (boatArray[x][y] != BOAT || boatArray[x][y] != HIT){
      boatArray[x][y] = MISS;
      return false;
    }
  }
  
  return false;
}
