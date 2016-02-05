#ifndef MYLIB_TEST_H
#define MYLIB_TEST_H

#include <mylib.cpp>

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

// This requires CxxTest to be installed!
// The current Makefile in this directory assumes cxxtest is a folder one
// level down.


class MyTests : public CxxTest::TestSuite {
public:
  void testFact1() {
    TS_ASSERT_DELTA(factorial(1), 1.0, 0.01);
  }
  
  void testFact2() {
    TS_ASSERT_DELTA(factorial(5), 120, 0.01);
  }
  
  // TODO: Fill in more tests!

  
};


#endif
