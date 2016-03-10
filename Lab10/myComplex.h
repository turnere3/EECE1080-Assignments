#ifndef COMPLEX_H
#define COMPLEX_H

// Author: Fill name in here
// Source File: myComplex.h
// Description: Implements complex number class, capable of doing typical
// operations using overloaded operators.

#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

class myComplex {
public:
  myComplex(){};
  myComplex(double in_real){};
  myComplex(double in_real, double in_imaginary){};

  void setReal(const double in_real){};
  void setImaginary(const double in_imaginary){};
  void setComplex(const double in_real, const double in_imaginary){};
  
  double getReal() const{return 0.0;};
  double getImaginary() const{return 0.0;};
  double getMagnitude() const{return 0.0;};
  double getAngle() const{return 0.0;};
  
  void displayPolar() const;
  string display() const;

  myComplex conjugate(){return myComplex();};
  myComplex addition(const myComplex right){return myComplex();};
  myComplex subtraction(const myComplex right){return myComplex();};
  myComplex multiplication(const myComplex right){return myComplex();};
  myComplex division(const myComplex right);
  
  myComplex operator+ (const myComplex& right);
  myComplex operator- (const myComplex& right){return myComplex();};
  myComplex operator* (const myComplex& right){return myComplex();};
  myComplex operator/ (const myComplex& right){return myComplex();};

  bool operator== (const myComplex& right);
  bool operator!= (const myComplex& right){return true;};

 
  friend ostream & operator<<( ostream& output,const myComplex &thing );
  friend istream & operator>>( istream &input, myComplex &thing );

private:
  double real;
  double imaginary;
};
#endif
