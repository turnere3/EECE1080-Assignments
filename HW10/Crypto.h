#ifndef CRYPTO_H
#define CRYPTO_H

// Author: Fill name in here
// Source File: Crypto.h
// Description: Implements text encryption and decryption using different
// methods

#include <iostream>
#include <string>
using namespace std;


class Crypto{
  public:
  
  // Define a crypto instance with a given key.
  Crypto(const string &key);

  // https://en.wikipedia.org/wiki/Caesar_cipher
  // Use the sum of the passcode's ascii as the offset (or any other method)
  string caesarEncrypt(const string& input);
  string caesarDecrypt(const string& input);
  
  // Vigenere
  // https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher 
  string vigenereEncrypt(const string& input);
  string vigenereDecrypt(const string& input);
  
  double letterFreqStDev(const string& intput);

  private:
  Crypto(); // By placing the default constructor in private, we REQUIRE
  // users to use the other constructor.
  
  // TODO: Fill me in.  
  // Hint: you'll need one private variable and possibly a few private functions.
  // Remember, don't copy code in different functions: write a common function
  // and call it with different parameters.  Hint: what is the difference between
  // encrypt and decrypt above?  Not much!

};

#endif
