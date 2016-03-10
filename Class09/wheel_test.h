
#ifndef COMPLEX_TEST_H
#define COMPLEX_TEST_H

#include <wheel.cpp>

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <cxxtest/TestSuite.h>

using namespace std;

const double delta = 0.0001;
// Multiple test classes are used so groups of functions can be tested
// independently.
class WheelGetRadius : public CxxTest::TestSuite {
public:
  void testGetRadius1(){
    TS_ASSERT_DELTA(Wheel().getRadius(), 15/2., delta);
  }

  void testGetRadius2(){
    TS_ASSERT_DELTA(Wheel(-1).getRadius(), 0, delta);
  }

  void testGetRadius3(){
    TS_ASSERT_DELTA(Wheel(6).getRadius(), 6, delta);
  }
};

class WheelGetSpeed : public CxxTest::TestSuite {
public:
  void testGetSpeed0(){
    TS_ASSERT_DELTA(Wheel().getSpeed(), 0.0, delta);
  }
  
  void testGetSpeed01(){
    TS_ASSERT_DELTA(Wheel(5).getSpeed(), 0.0, delta);
  }

  void testGetSpeed1(){
    TS_ASSERT_DELTA(Wheel(15,100).getSpeed(), 100, delta);
  }

  void testGetSpeed2(){
    TS_ASSERT_DELTA(Wheel(15/2.,70.).getSpeed(), 70., delta);
  }

  void testGetSpeed3(){
    TS_ASSERT_DELTA(Wheel(-15/2.,1600.0/60.0).getSpeed(), 0, delta);
  }
  
  /*void notestGetSpeed4(){
    Wheel unit(10.0, 60.0);
    unit.setRadius(15.0);
    TS_ASSERT_DELTA(unit.getSpeed(), 90.00, delta);
  }*/
  
  void testGetSpeed5(){
    Wheel unit(15/2.0, 30);
    unit.setSpeed(70.0);
    TS_ASSERT_DELTA(unit.getSpeed(), 70.0, delta);
  }
};

class WheelSetRPM : public CxxTest::TestSuite {
public:
  void testSetRPM0(){
    Wheel unit(15/2.0);
    unit.setRPM(9000.0, 90.);
    TS_ASSERT_DELTA(unit.getRPM(), 6000.0, delta);
    TS_ASSERT_DELTA(unit.getSpeed(), 267.7493, delta);
  }
  void testSetRPM1(){
    Wheel unit(15/2.0);
    unit.setRPM(0.0, 90.);
    TS_ASSERT_DELTA(unit.getRPM(), 0.0, delta);
    TS_ASSERT_DELTA(unit.getSpeed(), 0.0, delta);
  }
  void testSetRPM2(){
    Wheel unit(15/2.0);
    unit.setRPM(9000.0, -90.);
    TS_ASSERT_DELTA(unit.getRPM(), 0.0, delta);
    TS_ASSERT_DELTA(unit.getSpeed(), 0.0, delta);
  }
  void testSetRPM3(){
    Wheel unit(0.0);
    unit.setRPM(9000.0, -90.);
    TS_ASSERT_DELTA(unit.getRPM(), 0.0, delta);
    TS_ASSERT_DELTA(unit.getSpeed(), 0.0, delta);
  }
};

class WheelGetRPM : public CxxTest::TestSuite {
public:
  void testGetRPM0(){
    TS_ASSERT_DELTA(Wheel().getRPM(), 0.0, delta);
  }
  
  void testGetRPM01(){
    TS_ASSERT_DELTA(Wheel(5).getRPM(), 0.0, delta);
  }
  
  void testGetRPM1(){
    TS_ASSERT_DELTA(Wheel(24, 70).getRPM(), 490.1972, delta);
  }

  void testGetRPM2(){
    TS_ASSERT_DELTA(Wheel(45, 10).getRPM(), 37.3483, delta);
  }

  void testGetRPM3(){
    TS_ASSERT_DELTA(Wheel(0,-100.0/6.0).getRPM(), 0, delta);
  }

  void testGetRPM4(){
    TS_ASSERT_DELTA(Wheel(45, 0).getRPM(), 0, delta);
  }

  void testGetRPM5(){

    TS_ASSERT_DELTA(Wheel(15/2.,70.).getRPM(), 1568.6311, delta);
  }

  void testGetRPM6(){
    TS_ASSERT_DELTA(Wheel(600,-100.0/6.0).getRPM(), -4.6685, delta);
  }

};

class WheelGetDiameter : public CxxTest::TestSuite {
public:
  void testGetDiameter1(){
    TS_ASSERT_DELTA(Wheel().getDiameter(), 15, delta);
  }

  void testGetDiameter2(){
    TS_ASSERT_DELTA(Wheel(-1).getDiameter(), 0, delta);
  }

  void testGetDiameter3(){
    TS_ASSERT_DELTA(Wheel(6).getDiameter(), 12, delta);
  }
};

class WheelGetCirc : public CxxTest::TestSuite {
public:
  void testGetCircumference1(){
    TS_ASSERT_DELTA(Wheel().getCircumference(), 47.1238, delta);
  }

  void testGetCircumference2(){
    TS_ASSERT_DELTA(Wheel(-1).getCircumference(), 0, delta);
  }

  void testGetCircumference3(){
    TS_ASSERT_DELTA(Wheel(6).getCircumference(), 37.6991, delta);
  }
};

class WheelGetSA : public CxxTest::TestSuite {
public:
  void testGetSA1(){
    TS_ASSERT_DELTA(Wheel().getSurfaceArea(), 176.7145, delta);
  }

  void testGetSA2(){
    TS_ASSERT_DELTA(Wheel(-1).getSurfaceArea(), 0, delta);
  }

  void testGetSA3(){
    TS_ASSERT_DELTA(Wheel(6).getSurfaceArea(), 113.0973, delta);
  }

};


#endif

