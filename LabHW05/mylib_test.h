#ifndef MYLIB_TEST_H
#define MYLIB_TEST_H

#include <mylib.cpp>

#include <iostream>
#include <cxxtest/TestSuite.h>
#include <cmath>

using namespace std;

// This requires CxxTest to be installed!
// The current Makefile in this directory assumes cxxtest is a folder one
// level down.


class MyTests : public CxxTest::TestSuite {
public:
  
  // factorial
  
  void testFact1() {
    TS_ASSERT_DELTA(factorial(1), 1.0, 0.01);
  }
  
  void testFact2() {
    TS_ASSERT_DELTA(factorial(5), 120, 0.01);
  }
  
  void testFact3() {
    TS_ASSERT_DELTA(factorial(3), 6, 0.01);
  }
    
  void testFact5() {
    TS_ASSERT_DELTA(factorial(7), 5040, 0.01);
  }
  
    void testFact4() {
    TS_ASSERT_EQUALS(factorial(0), 1);
  }
  
  void testFact6() {
    TS_ASSERT_EQUALS(factorial(-11), -1);
  }
  
  // degreesToRadians
  
  void testFact7() {
    TS_ASSERT_DELTA(degreesToRadians(45), 0.7853, 0.01);
  }
  
  void testFact8() {
    TS_ASSERT_DELTA(degreesToRadians(30), 0.5235, 0.01);
  }
  
  void testFact9() {
    TS_ASSERT_DELTA(degreesToRadians(480), 2.0943, 0.01);
  }
  
  void testFact10() {
    TS_ASSERT_DELTA(degreesToRadians(-420), -1.0471, 0.01);
  }
  
  void testFact11() {
    TS_ASSERT_DELTA(degreesToRadians(240), 4.1887, 0.01);
  }
  
  void testFact12() {
    TS_ASSERT_EQUALS(degreesToRadians(0), 0);
  }
  
  // isPrime
  
  void testFact13() {
    TS_ASSERT_EQUALS(isPrime(5), true);
  }
  
  void testFact14() {
    TS_ASSERT_EQUALS(isPrime(59), true);
  }
  
  void testFact15() {
    TS_ASSERT_EQUALS(isPrime(4), false);
  }
  
  void testFact16() {
    TS_ASSERT_EQUALS(isPrime(0), false);
  }
  
  void testFact17() {
    TS_ASSERT_EQUALS(isPrime(1), false);
  }
  
  void testFact18() {
    TS_ASSERT_EQUALS(isPrime(-5), false);
  }
  
  // mySine
  
  void testFact19() {
    TS_ASSERT_DELTA(mySine(1), sin(1), 0.0001);
  }
  
  void testFact20() {
    TS_ASSERT_DELTA(mySine(0.5), sin(0.5), 0.0001);
  }
  
  void testFact21() {
    TS_ASSERT_DELTA(mySine(0), sin(0), 0.0001);
  }
  
  void testFact22() {
    TS_ASSERT_DELTA(mySine(-1), sin(-1), 0.0001);
  }
    
  void testFact23() {
    TS_ASSERT_DELTA(mySine(-2.3), sin(-2.3), 0.0001);
  }
  
  void testFact24() {
    TS_ASSERT_DELTA(mySine(10), sin(10), 0.0001);
  }
  
  // myCosine
  
  void testFact25() {
    TS_ASSERT_DELTA(myCosine(1), cos(1), 0.0001);
  }
  
  void testFact26() {
    TS_ASSERT_DELTA(myCosine(0.5), cos(0.5), 0.0001);
  }
  
  void testFact27() {
    TS_ASSERT_DELTA(myCosine(0), cos(0), 0.0001);
  }
  
  void testFact28() {
    TS_ASSERT_DELTA(myCosine(-1), cos(-1), 0.0001);
  }
    
  void testFact29() {
    TS_ASSERT_DELTA(myCosine(-2.3), cos(-2.3), 0.0001);
  }
  
  void testFact30() {
    TS_ASSERT_DELTA(myCosine(10), cos(10), 0.0001);
  }
  
};

#endif
