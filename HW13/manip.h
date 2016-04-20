#ifndef MANIP_H
#define MANIP_H

// Author: Fill in your name
// Source File: manip.h
// Description: A set of functions where you should manipulate
// the passed parameters to change the object in a specific way, 
// so that Pointers_test.h passes all tests.

#include "Pointers.h"

void manip1(Pointers* p){
  *p->getA() = 10;
}

void manip2(Pointers* p){
  int *number = new int;
  *number = 45;
  p->setB(number);
}
  
void manip3(Pointers* p){  
  p->setB(p->getA());
}

void manip4(Pointers* p, int* other){
  p->setB(other);
}

void manip5(Pointers* p, int* other){
  *other = 45;
  p->setB(other);
  p->setC();
}

void manip6(Pointers* p){
  
}

void manip7(Pointers* p){
  // TODO: Fill me in
}

void manip8(Pointers* p){
  p->getC(*a) = 199;
}

void manip9(Pointers* p, int* other){
  // TODO: Fill me in
}

void manip10(Pointers* p){
  // TODO: Fill me in
}

#endif
