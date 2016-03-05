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

// arrSum

  void testSum1() {
    int a[] = {1,2,3};
    TS_ASSERT_EQUALS(arrSum(a, 3), 6);
  }
  
  void testSum2() {
    int a[] = {};
    TS_ASSERT_EQUALS(arrSum(a, 0), 0);
  }
  
  void testSum3() {
    int a[] = {5,2,9,30,7};
    TS_ASSERT_EQUALS(arrSum(a, 5), 53);
  }
    
  void testSum4() {
    int a[] = {10,-20,3};
    TS_ASSERT_EQUALS(arrSum(a, 3), -7);
  }
  
// arrMean

  void testMean1() {
    int a[] = {1,5,7};
    TS_ASSERT_EQUALS(arrMean(a, 3), 4.333333333333333);
  } 
    
  void testMean2() {  
    int a[] = {4,4};
    TS_ASSERT_EQUALS(arrMean(a, 2), 4);
  }
    
  void testMean3() {
    int a[] = {-3,-11,-5,-2,-4,-10,-14};
    TS_ASSERT_EQUALS(arrMean(a, 7), -7);
  }
  
  void testMean4() {
    int a[] = {0,0,0};
    TS_ASSERT_EQUALS(arrMean(a, 3), 0);
  }  
    
// arrMin

  void testMin1() {
    int a[] = {3,2,1};
    TS_ASSERT_EQUALS(arrMin(a, 3), 1);
  }
  
  void testMin2() {
    int a[] = {11, 42, 3, 64, 56, 8, -1, 4};
    TS_ASSERT_EQUALS(arrMin(a, 8), -1);
  }
  
  void testMin3() {
    int a[] = {-9,-10};
    TS_ASSERT_EQUALS(arrMin(a, 2), -10);
  }
  
  void testMin4() {
    int a[] = {0,1,2,3,4};
    TS_ASSERT_EQUALS(arrMin(a, 5), 0);
  }
    
// arrMax

  void testMax1() {
    int a[] = {3,2,1};
    TS_ASSERT_EQUALS(arrMax(a, 3), 3);
  }
  
  void testMax2() {
    int a[] = {11, 42, 3, 64, 56, 8, -1, 4};
    TS_ASSERT_EQUALS(arrMax(a, 8), 64);
  }
  
  void testMax3() {
    int a[] = {-9,-10};
    TS_ASSERT_EQUALS(arrMax(a, 2), -9);
  }
  
  void testMax4() {
    int a[] = {0,-1,-2,-3,-4};
    TS_ASSERT_EQUALS(arrMax(a, 5), 0);
  }
    
// arrStdDev



// isPrime

 void testPrime1() {
    TS_ASSERT_EQUALS(isPrime(0), false);
  }
  
  void testPrime2() {
    TS_ASSERT_EQUALS(isPrime(1), false);
  }
  
  void testPrime3() {
    TS_ASSERT_EQUALS(isPrime(-5), false);
  }
  
  void testPrime4() {
    TS_ASSERT_EQUALS(isPrime(59), true);
  }
  
  void testPrime5() {
    TS_ASSERT_EQUALS(isPrime(4), false);
  }
  
// arrNumPrimes

  void testNumPrimes1() {
    int a[] = {4,3,2};
    TS_ASSERT_EQUALS(arrNumPrimes(a, 3), 1);
  }
  
  void testNumPrimes2() {
    int a[] = {0,0,1,0,-7};
    TS_ASSERT_EQUALS(arrNumPrimes(a, 5), 0);
  }
  
  void testNumPrimes3() {
    int a[] = {};
    TS_ASSERT_EQUALS(arrNumPrimes(a, 0), 0);
  }
  
  void testNumPrimes4() {
    int a[] = {3,9,37,5,4,9,10};
    TS_ASSERT_EQUALS(arrNumPrimes(a, 8), 3);
  }
    
// arrSetSize

  void testSetSize1() {
    int a[] = {3,5,6,2,3};
    TS_ASSERT_EQUALS(arrSetSize(a, 5), 4);
  }
  
  void testSetSize2() {
    int a[] = {11,7,1,3,5};
    TS_ASSERT_EQUALS(arrSetSize(a, 5), 5);
  }
  
  void testSetSize3() {
    int a[] = {0,0,1};
    TS_ASSERT_EQUALS(arrSetSize(a, 3), 2);
  }
  
  void testSetSize4() {
    int a[] = {};
    TS_ASSERT_EQUALS(arrSetSize(a, 0), 0);
  }

// arrNumCount

  void testNumCount1() {
    int a[] = {0,0,1};
    int num = 0;
    TS_ASSERT_EQUALS(arrNumCount(a, 3, num), 2);
  }
  
  void testNumCount2() {
    int a[] = {5,8,3,3,2};
    int num = 3;
    TS_ASSERT_EQUALS(arrNumCount(a, 5, num), 2);
  }
  
  void testNumCount3() {
    int a[] = {9,6,9,45,32,77,3,0};
    int num = 9;
    TS_ASSERT_EQUALS(arrNumCount(a, 8, num), 2);
  }
  
  void testNumCount4() {
    int a[] = {-5,-6,-23,11,-5};
    int num = -5;
    TS_ASSERT_EQUALS(arrNumCount(a, 5, num), 2);
  }
  
// arrNumBetween
  
  void testNumBetween1() {
    int a[] = {3,8,10};
    int low = 1;
    int high = 9;
    TS_ASSERT_EQUALS(arrNumBetween(a, 3, low, high),2);
  }

  void testNumBetween2() {
    int a[] = {32,97,110,30,58};
    int low = 31;
    int high = 100;
    TS_ASSERT_EQUALS(arrNumBetween(a, 5, low, high),3);
  }

  void testNumBetween3() {
    int a[] = {-5,-4,-3,-2,-1};
    int low = -5;
    int high = -1;
    TS_ASSERT_EQUALS(arrNumBetween(a, 5, low, high),4);
  }
  
  void testNumBetween4() {
    int a[] = {-29,-10,-5,-1,0,82,38,57,11,12,23};
    int low = -3;
    int high = 57;
    TS_ASSERT_EQUALS(arrNumBetween(a, 11, low, high),6);
  }

//arrReverse

void testRev1() {
    int a[] = {1,2,3};
    arrReverse(a,3);
    TS_ASSERT_EQUALS(a[0], 3);
    TS_ASSERT_EQUALS(a[1], 2);
    TS_ASSERT_EQUALS(a[2], 1);
  }

  void testRev2() {
    int a[] = {-5,-8,3,7,20};
    arrReverse(a,5);
    TS_ASSERT_EQUALS(a[0], 20);
    TS_ASSERT_EQUALS(a[1], 7);
    TS_ASSERT_EQUALS(a[2], 3);
    TS_ASSERT_EQUALS(a[3], -8);
    TS_ASSERT_EQUALS(a[4], -5);
  }
  
  void testRev3() {
    int a[] = {-1,0,1};
    arrReverse(a,3);
    TS_ASSERT_EQUALS(a[0], 1);
    TS_ASSERT_EQUALS(a[1], 0);
    TS_ASSERT_EQUALS(a[2], -1);
  }
  
  void testRev4() {
    int a[] = {10};
    arrReverse(a,1);
    TS_ASSERT_EQUALS(a[0], 10);
  }



};

#endif
