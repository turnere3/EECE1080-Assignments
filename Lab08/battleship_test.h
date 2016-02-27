#ifndef BATTLESHIP_TEST_H
#define BATTLESHIP_TEST_H

#include <iostream>
#include <cxxtest/TestSuite.h>

#include "battleship.cpp"

using namespace std;

// This requires CxxTest to be installed!
// For this CPPVideos example, navigate your terminal to CPPVideos and type:
// git submodule add https://github.com/CxxTest/cxxtest.git
// This will add the public CxxTest repository INSIDE the current repo.
// The current Makefile in this directory assumes cxxtest is a folder one
// level down.

int numBs(char board[][BOARD_SIZE]){
  unsigned count = 0;
  for(int i=0; i < BOARD_SIZE; i++){
    for(int j=0; j < BOARD_SIZE; j++){
      if(board[i][j] == BOAT) count++;
    }
  }
  return count;      
}

class CreateBoat : public CxxTest::TestSuite {
public:
  // board and setUp gets run before each test so we don't have to duplicte code.
  char board[BOARD_SIZE][BOARD_SIZE];
  void setUp(){
    for(int i=0; i < BOARD_SIZE; i++){
      for(int j=0; j < BOARD_SIZE; j++){
        board[i][j]=EMPTY;
      }
    }
  }
  
  // Create some horizontal boats that should work
  void testCreateBoat1() {
    for(int len = 2; len <=5; len++){
      TS_ASSERT(createBoat(board, 0,0,0,len));
      TS_ASSERT_EQUALS(numBs(board),len); 
      setUp();
    }
  }
  
  void testCreateBoat2() {
    for(int len = 2; len <=5; len++){
      TS_ASSERT(createBoat(board, 0,BOARD_SIZE-1,0,len));
      TS_ASSERT_EQUALS(numBs(board),len);
      setUp();
    }
  }
  
  // Create some vertical boats that should work
  void testCreateBoat3() {
    for(int len = 2; len <=5; len++){
      TS_ASSERT(createBoat(board, 0,0,1,len));
      TS_ASSERT_EQUALS(numBs(board),len);
      setUp();
    }
  }
  
  void testCreateBoat4() {
    for(int len = 2; len <=5; len++){
      TS_ASSERT(createBoat(board, BOARD_SIZE-1,0,1,len));
      TS_ASSERT_EQUALS(numBs(board),len);
      setUp();
    }
  }
  
  // Verify we can't put boats off the edge
  // And boards are empty after a false
  void testBadBoat1() {
    TS_ASSERT( !createBoat(board, -1,0,0,5));
    TS_ASSERT_EQUALS(numBs(board),0);
    TS_ASSERT( !createBoat(board, -1,BOARD_SIZE-1,0,5));
    TS_ASSERT_EQUALS(numBs(board),0);
    TS_ASSERT( !createBoat(board, BOARD_SIZE-1, BOARD_SIZE-4,0,5));
    TS_ASSERT_EQUALS(numBs(board),0);
    TS_ASSERT( !createBoat(board, -1,0,1,5));
    TS_ASSERT_EQUALS(numBs(board),0);
    TS_ASSERT( !createBoat(board, -1,BOARD_SIZE-1,1,5));
    TS_ASSERT_EQUALS(numBs(board),0);
    TS_ASSERT( !createBoat(board, 0,BOARD_SIZE-4,1,5));
    TS_ASSERT_EQUALS(numBs(board),0);
    TS_ASSERT( !createBoat(board, BOARD_SIZE-1, BOARD_SIZE-4,1,5));
    TS_ASSERT_EQUALS(numBs(board),0);
  }
  
  // Verify we can't give bad rotations
  void testBadBoat2() {
    TS_ASSERT( !createBoat(board, 0,0,-1,5));
    TS_ASSERT_EQUALS(numBs(board),0);
    TS_ASSERT( !createBoat(board, 0,0,2,5));
    TS_ASSERT_EQUALS(numBs(board),0);
  }
  
  // Verify we can't put a boat on another
  void testBadBoat3(){
    TS_ASSERT(createBoat(board, 0,0,0,5));
    TS_ASSERT_EQUALS(numBs(board),5);
    TS_ASSERT( !createBoat(board, 3,0,1,5));
    TS_ASSERT_EQUALS(numBs(board),5);
  }
  
};

class PlaceAIBoats : public CxxTest::TestSuite {
public:
  // board and setUp gets run before each test so we don't have to duplicte code.
  char board[BOARD_SIZE][BOARD_SIZE];
  void setUp(){
    for(int i=0; i < BOARD_SIZE; i++){
      for(int j=0; j < BOARD_SIZE; j++){
        board[i][j]= EMPTY;
      }
    }
  }
  
  // Note srand has not been called, so this is deterministic.
  // Add some boats and verify the correct number of spots change
  void testBoats1() {
    placeAIBoats(board);
    unsigned count = 0;
    for(int i=0; i < BOARD_SIZE; i++){
      for(int j=0; j < BOARD_SIZE; j++){
        if(board[i][j] == BOAT) count++;
      }
    }
    TS_ASSERT_EQUALS(count, 14);
  }
  
  // Try adding more boats and verify they go on.
  // This should stop when it is 2/3 full.
  void testBoats2() {
    for(int run = 1; run <= BOARD_SIZE * BOARD_SIZE * 2 / 3 / 14; run++){
      placeAIBoats(board);
      
      // Each application of placeAIBoats should turn on 14 spaces.
      TS_ASSERT_EQUALS(numBs(board), 14 * run);
      
    }
  }
  
  // Fill up the board and verify it eventually can't add boats.
  // Note placeAIBoats likely will start to fail earlier due to boat shape.
  void testBoats3() {
    for(int run = 1; run <= BOARD_SIZE * BOARD_SIZE / 14; run++){
      placeAIBoats(board);
    }
    TS_ASSERT( !placeAIBoats(board) );
  }
  
  
  
};

class HasLost : public CxxTest::TestSuite {
public:
  // board and setUp gets run before each test so we don't have to duplicte code.
  char board[BOARD_SIZE][BOARD_SIZE];
  void setUp(){
    for(int i=0; i < BOARD_SIZE; i++){
      for(int j=0; j < BOARD_SIZE; j++){
        board[i][j]= EMPTY;
      }
    }
  }
  
  // Verify hit or not within the board
  void testLost1() {
    // No boats, so they must have lost
    TS_ASSERT(hasLost(board));
  }
  
  void testLost2() {
    board[0][0] = MISS;
    // No boats, so they must have lost
    TS_ASSERT(hasLost(board));
  }
  
  void testLost3() {
    board[0][0] = HIT;
    // No boats, so they must have lost
    TS_ASSERT(hasLost(board));
  }
  
  void testLost4() {
    board[0][0] = BOAT;
    // BOAT!  
    TS_ASSERT( !hasLost(board));
  }

};

class IsHit : public CxxTest::TestSuite {
public:
  // board and setUp gets run before each test so we don't have to duplicte code.
  char board[BOARD_SIZE][BOARD_SIZE];
  void setUp(){
    for(int i=0; i < BOARD_SIZE; i++){
      for(int j=0; j < BOARD_SIZE; j++){
        board[i][j]= EMPTY;
      }
    }
  }
  
  // Verify hit or not within the board
  void testHit1() {
    board[0][0] = BOAT;
    TS_ASSERT(isHit(board,0,0));
  }
  
  void testHit2() {
    board[5][5] = BOAT;
    TS_ASSERT(isHit(board,5,5));
  }
  
  void testHit3() {
    board[0][0] = BOAT;
    TS_ASSERT( !isHit(board,1,0));
  }
  
  void testHit4() {
    board[0][0] = BOAT;
    TS_ASSERT( !isHit(board,0,1));
  }
  
  // Verify false is thrown if outside bounds
  void testOuside1() {
    TS_ASSERT( !isHit(board,-1,1));
  }
  
  void testOuside2() {
    TS_ASSERT( !isHit(board,1,-1));
  }
  
  void testOuside3() {
    TS_ASSERT( !isHit(board,-1,-1));
  }
  
  void testOuside4() {
    TS_ASSERT( !isHit(board,BOARD_SIZE,0));
  }
  
  void testOuside5() {
    TS_ASSERT( !isHit(board,0,BOARD_SIZE));
  }
  
  void testOuside6() {
    TS_ASSERT( !isHit(board,BOARD_SIZE,0));
  }
  
  void testOuside7() {
    TS_ASSERT( !isHit(board,BOARD_SIZE,BOARD_SIZE));
  }
  
  // Verify false if already hit or a miss
  void testDup1() {
    board[0][1] = HIT;
    TS_ASSERT( !isHit(board,0,1));
  }
  
  void testDup2() {
    board[0][1] = MISS;
    TS_ASSERT( !isHit(board,0,1));
  }
  
};


#endif
