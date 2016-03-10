// Author: Fill name in here
// Source File: myComplex.cpp
// Description: Implements complex number class, capable of doing typical
// operations using overloaded operators.

#include <iostream>
#include <cmath>
#include <sstream>

#include "myComplex.h"

using namespace std;

static const double eq_delta = 0.0001;

// TODO: Fill in the rest of the class methods!
 
  void myComplex::displayPolar() const {
    cout << getMagnitude();
    cout << "@ "  << getAngle() << endl;
  }

myComplex myComplex::division(const myComplex right){
    myComplex retval;
    double denom = right.real*right.real + right.imaginary*right.imaginary;

    retval.real    = (real*right.real + imaginary*right.imaginary)/denom;
    retval.imaginary = (imaginary*right.real - real*right.imaginary)/denom;

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


