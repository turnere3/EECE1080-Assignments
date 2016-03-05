// Author: Eric Turner
// Source File: mylib.cpp
// Description: Library of Mathematical FUNCTIONS

#include <cmath>

using namespace std;

// You may implement any helper functions you like, or define
// or change any constant you like.

double factorial(double);
double degreesToRadians(double);
bool isPrime(int);
double mySine(double);
double myCosine(double);
double myTangent(double,double);
const double PI = atan(1.0)*4.0;
const double PRECISION = 0.00001;

// For lab....
double factorial(double n){
	double product = 1;
  if (n == 0){
    product = 1;
  }else if (n < 0){
    product = -1;
  }else{
    for (int i = n; i > 0; i--){
      product = product * i;
    }
  }
	return product;
}

double degreesToRadians(double degrees){
double radians;
  if (degrees >= 0){
    radians = degrees * PI/180.0;
    while(radians >= 2*PI){
      radians -= 2*PI;
    }
  }else{
    radians = degrees * PI/180.0;
    while (radians <= -2*PI){
    radians += 2*PI;
    }
  }
  return radians;
}

bool isPrime(int number){
  int count = 0;
  if (number == 0 || number == 1 || number < 0){
    return false;
  }else{
    for (int i = 2; i < sqrt(number) + 1; i++){
      if (number % i == 0){
        count++;
      }
    }
    if (count > 0){
      return false;
    }else{
	    return true;
	  }
  }
}

// For HW.....
double mySine(double n){
	double p = 1; // p = 0 in cosine
  double v = 0;
  double sum = 0;
  double current = 0;
  do{ 
    current = sum;
    sum = sum + (pow(-1,v)*pow(n,p)/factorial(p));
    p = p + 2;
    v = v + 1;
  }while (abs(sum-current) > 0.00001);
	return sum;
}

double myCosine(double n){
	double p = 0; // p = 0 in cosine
  double v = 0;
  double sum = 0;
  double current = 0;
  do{ 
    current = sum;
    sum = sum + (pow(-1,v)*pow(n,p)/factorial(p));
    p = p + 2;
    v = v + 1;
  }while (abs(sum-current) > 0.00001);
  return sum;
}

/*double myTangent(double myCosine, double mySine){
  double tangent = mySine/myCosine;
	return tangent;
}*/
