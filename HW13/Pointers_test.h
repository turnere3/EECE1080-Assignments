#ifndef POINTERS_TEST_H
#define POINTERS_TEST_H

#include <iostream>
#include <stdlib.h>
#include <cxxtest/TestSuite.h>

#include "Pointers.h"
#include "manip.h"



using namespace std;

class myComplexGetters : public CxxTest::TestSuite {
public:

  void test1(){
    Pointers a;
    manip1(&a);
    TS_ASSERT_EQUALS(*(a.getA()), 10);
  }
  
  void test2(){
    int number = 56;
    Pointers a(number, &number);
    manip2(&a);
    TS_ASSERT_EQUALS(*(a.getB()), 45);
  }
  
  void test3(){
    int number = rand() % 1000;
    int number2 = 4;
    Pointers a(number, &number2);
    manip3(&a);
    TS_ASSERT_EQUALS(*(a.getB()), number);
  }
  
  void test4(){
    int number2 = 4;
    Pointers a;
    manip4(&a, &number2);
    TS_ASSERT_EQUALS(a.getB(), &number2);
  }
  
  void test5(){
    int number2 = 4;
    Pointers a(0, &number2);
    manip5(&a, &number2);
    TS_ASSERT_EQUALS(a.getC(), 45);
  }
  
  void test6(){
    int numbers[] = {5,6,7,8};
    Pointers a(0, numbers);
    manip6(&a);
    TS_ASSERT_EQUALS(numbers[2], 10);
  }
  
  void test7(){
    int* number = new int;
    Pointers a(0, number);
    manip7(&a);
    TS_ASSERT_EQUALS(*number, 15);
    delete number;
  }
  
  void test8(){
    Pointers a;
    manip8(&a);
    TS_ASSERT_EQUALS(a.getC(), 199);
  }
  
  void test9(){
    int* number = new int;
    Pointers* a = new Pointers();
    manip9(a, number);
    TS_ASSERT_EQUALS(a->getB(), number);
    delete number;
    delete a;
  }
  
  void test10(){
    Pointers* a = new Pointers[10];
    manip10(a);
    TS_ASSERT_EQUALS(a[5].getC(), 199);
    delete[] a;
  }
};

#endif
