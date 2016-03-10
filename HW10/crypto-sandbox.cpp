// Author: Fill name in here
// Source File: crypto-sandbox.cpp
// Description: Encrypts or decrypts text files given on the command-line.

// To encrypt ./crypto-sandbox password encrypt c MobyDick.txt
// To decrypt ./crypto-sandbox password decrypt c MobyDick.txt
// Use c for caesar cypter, v for vigenere.

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>

#include "Crypto.h"
using namespace std;

int main(int argc, char* argv[]){
  // Uncomment this code below to play with your Crypto class.
  /*
  Crypto a("password");
  
  string input = "This is a test!";
  cout << input << endl;
  cout << a.caesarEncrypt(input) << endl;
  cout << a.caesarDecrypt(a.caesarEncrypt(input)) << endl;
  
  cout << "input std: " << a.letterFreqStDev(input) << endl;
  cout << "encrypted std: " << a.letterFreqStDev(a.caesarEncrypt(input)) << endl;
  
  cout << a.vigenereEncrypt(input) << endl;
  cout << a.vigenereDecrypt(a.vigenereEncrypt(input)) << endl;
  
  cout << "input std: " << a.letterFreqStDev(input) << endl;
  cout << "encrypted std: " << a.letterFreqStDev(a.vigenereEncrypt(input)) << endl;
  return 0;
  */
  
  if(argc == 5){  // A parameters were given!
  
    string file_string;
    
    // Create a file handle and open it.
    ifstream inFile;
    inFile.open(argv[4]);
    // Make sure it is a valid handle
    if(!inFile){
      cout << argv[4] << " unable to be opened!\n";
      return 0;
    }
    stringstream buffer;
    buffer << inFile.rdbuf();
    file_string = buffer.str();
    
    // Now create a crypto class with the given password
    Crypto crypt(argv[1]); // Use given password
    
    // Encrypt or decrypt
    if( strcmp(argv[2], "encrypt") == 0){ // encrypt
      if( strcmp(argv[3], "c") == 0){ // caesar
        cout << crypt.caesarEncrypt(file_string);
      }else{  // vigenere
        cout << crypt.vigenereEncrypt(file_string);
      }
    }else{  // decrypt
      if( strcmp(argv[3], "c") == 0){ // caesar
        cout << crypt.caesarDecrypt(file_string);
      }else{  // vigenere
        cout << crypt.vigenereDecrypt(file_string);
      }
    }
    
  }else{
    
    cout << "No input parameters given." << endl;
    cout << "./crypto-sandbox password encrypt c MobyDick.txt\n\n";
  }
  return 0;
}
