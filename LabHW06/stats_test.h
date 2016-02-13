#ifndef STATS_TEST_H
#define STATS_TEST_H

#include <iostream>
#include <cxxtest/TestSuite.h>

#include "stats.cpp"

using namespace std;

// This requires CxxTest to be installed!
// For this CPPVideos example, navigate your terminal to CPPVideos and type:
// git submodule add https://github.com/CxxTest/cxxtest.git
// This will add the public CxxTest repository INSIDE the current repo.
// The current Makefile in this directory assumes cxxtest is a folder one
// level down.


class MyTests : public CxxTest::TestSuite {
public:
  void testSum1() {
    int a[] = {1,2,3};
    TS_ASSERT_EQUALS(arrSum(a, 3), 6);
  }
  
  void testSum2() {
    int a[] = {};
    TS_ASSERT_EQUALS(arrSum(a, 0), 0);
  }
  
  // TODO: Fill in more tests!
};

#endif
