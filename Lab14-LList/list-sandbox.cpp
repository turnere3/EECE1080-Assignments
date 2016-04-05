/*
	Fill me in
*/

#include <iostream>
#include <vector>

#include "LList.h"
#include "LListR.h"

using namespace std;

int main(){
  LList a;
  a.push_back(55);
  a.push_back(56);
  cout << a[0] + 0 << endl;
  a[0] = 7;
  cout << a[0] << endl; 
  
  LListR b;
  b.push_back(55);
  b.push_back(56);
  cout << b[0] + 0 << endl;
  b[0] = 7;
  cout << b[0] << endl;
 
}
