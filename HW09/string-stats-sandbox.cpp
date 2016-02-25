// Author: <Your Name Here>
// Source File: string-stats-sandbox.cpp
// Description: Analyzes the provided file for statistics.

// Execute as: ./string-stats-sandbox MobyDick.txt

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "string-stats.cpp"

using namespace std;

int main(int argc, char* argv[]){
  if(argc == 2){  // A parameter was given!
  
    string file_string;
    
    // Create a file handle and open it.
    ifstream inFile;
    inFile.open(argv[1]);
    // Make sure it is a valid handle
    if(!inFile){
      cout << argv[1] << " unable to be opened!\n";
      return 0;
    }
    stringstream buffer;
    buffer << inFile.rdbuf();
    file_string = buffer.str();
    
    // TODO: Fill me in. file_string contains the file.
    
  }else{
    cout << "No input file given." << endl << endl;
  }
  

  return 0;
}
