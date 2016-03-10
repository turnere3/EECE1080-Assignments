#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#include <wheel.cpp>

int main(){
  Wheel Yugo;

  Yugo.displayParameters();
  Wheel Porsche(15/2., 70.0);

  Porsche.displayParameters();

  Wheel Mustang(15/2.,0);
  Mustang.displayParameters();

  Mustang.setSpeed(70);
  Mustang.displayParameters();

  Mustang.setSpeed(90);
  Mustang.displayParameters();

  Mustang.setRPM(9000.0, 90);
  Mustang.displayParameters();

  return 0;
}

