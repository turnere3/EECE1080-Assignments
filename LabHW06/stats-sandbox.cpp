// Author: Eric Turner
// Source File: stats-sandbox.cpp
// Description: Analyzes the provided file for statistics.

// Execute as: ./stats-sandbox small.txt

#include <iostream>
#include <fstream>
#include <cmath>
#include "stats.cpp"

using namespace std;

int main(int argc, char* argv[]){
  if(argc == 2){  // A parameter was given!
  
    int numbers[100000];
    int number = 0; 
    unsigned int count = 0;
    
    // Create a file handle and open it.
    ifstream inFile;
    inFile.open(argv[1]);
    // Make sure it is a valid handle
    if(!inFile){
      cout << argv[1] << " unable to be opened!\n";
      return 0;
    }
    // Pull off numbers while we can.  This will stop at the end of the file.
    while(inFile >> number){
      numbers[count] = number;
      count++;
    }  
    
    cout << "Count: " << count << endl;
    cout << "Sum: " << arrSum(numbers, count) << endl;
    cout << "Mean: " << arrMean(numbers, count) << endl;
    cout << "Min: " << arrMin(numbers, count) << endl;
    cout << "Max: " << arrMax(numbers, count) << endl;
    // cout << "StdDev: " << arrStdDev(numbers, count) << endl;
    cout << "Primes: " << arrNumPrimes(numbers, count) << endl;
    cout << "Set Size: " << arrSetSize(numbers, count) << endl;
    
  }else{
    cout << "No parameters, or more than one parameter given.\n";
  }
  

  return 0;
}
