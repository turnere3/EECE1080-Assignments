// Author: Eric Turner
// Source File: myComplex.cpp
// Description: Implements complex number class, capable of doing typical
// operations using overloaded operators.

#include <iostream>
#include <cmath>
#include <sstream>

#include "myComplex.h"

using namespace std;

myComplex::myComplex(){
  setComplex(0,0);
}

myComplex::myComplex(double in_real){
  setComplex(in_real,0);
}

myComplex::myComplex(double in_real, double in_imaginary){
  setComplex(in_real,in_imaginary);
}

void myComplex::setReal(const double in_real){
  real = in_real;
}

void myComplex::setImaginary(const double in_imaginary){
  imaginary = in_imaginary;
}

void myComplex::setComplex(const double in_real, const double in_imaginary){
  setReal(in_real);
  setImaginary(in_imaginary);
}

double myComplex::getReal() const{
  return real;
}

double myComplex::getImaginary() const{
  return imaginary;
}

double myComplex::getMagnitude() const{
  double magnitude = hypot(real,imaginary);
  return magnitude;
}

double myComplex::getAngle() const{
  double angleRad = atan2(imaginary,real);
  double angleDeg = angleRad*(180/3.1415926);
  return angleDeg;
}
  
myComplex myComplex::conjugate(){
  myComplex retval;
  retval.real = real;
  retval.imaginary = -1*imaginary;
  return retval;
}

myComplex myComplex::addition(const myComplex right){
  myComplex retval;
  retval.real = (real+right.real);
  retval.imaginary = (imaginary+right.imaginary);
  return retval;
}

myComplex myComplex::subtraction(const myComplex right){
  myComplex retval;
  retval.real = (real-right.real);
  retval.imaginary = (imaginary-right.imaginary);
  return retval;
}

myComplex myComplex::operator- (const myComplex& right){
  return(subtraction(right));
}

myComplex myComplex::operator* (const myComplex& right){
  return(multiplication(right));
}

myComplex myComplex::operator/ (const myComplex& right){
  return(division(right));
}

static const double eq_delta = 0.0001;

bool myComplex::operator!= (const myComplex& right){
  double diff_real = abs(real - right.real);
  double diff_im = abs(imaginary - right.imaginary);

  return !(diff_real < eq_delta && diff_im < eq_delta);
}

// TODO: Fill in the rest of the class methods!
 
void myComplex::displayPolar() const {
  cout << getMagnitude();
  cout << "@ "  << getAngle() << endl;
}

myComplex myComplex::division(const myComplex right){
  myComplex retval;
  double denom = right.real*right.real + right.imaginary*right.imaginary;
  retval.real = (real*right.real + imaginary*right.imaginary)/denom;
  retval.imaginary = (imaginary*right.real - real*right.imaginary)/denom;
  return retval;
}

myComplex myComplex::multiplication(const myComplex right){
  myComplex retval;
  retval.real = (real*right.real) - (imaginary*right.imaginary);
  retval.imaginary = (imaginary*right.real) + (real*right.imaginary);
  return retval;
}

string myComplex::display() const{
  stringstream retval;
  retval << "(" << real << " + " << imaginary << "i)";
  return retval.str();
}

myComplex myComplex::operator+ (const myComplex& right){
  return(addition(right));
}

bool myComplex::operator== (const myComplex& right){
  double diff_real = abs(real - right.real);
  double diff_im = abs(imaginary - right.imaginary);

  return diff_real < eq_delta && diff_im < eq_delta;
}

ostream& operator<<( ostream& output, const myComplex &thing ){
  output << thing.display();
  return output;
}
  
istream& operator>>( istream &input, myComplex &thing ){
  cout << "Enter Real Part: ";
  input >> thing.real;
  cout << "Enter Imaginary Part: ";
  input >> thing.imaginary;
  return input;
}
