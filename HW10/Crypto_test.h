#ifndef CRYPTO_TEST_H
#define CRYPTO_TEST_H

#include <iostream>
#include <cxxtest/TestSuite.h>

#include "Crypto.h"

using namespace std;

// This requires CxxTest to be installed!
// For this CPPVideos example, navigate your terminal to CPPVideos and type:
// git submodule add https://github.com/CxxTest/cxxtest.git
// This will add the public CxxTest repository INSIDE the current repo.
// The current Makefile in this directory assumes cxxtest is a folder one
// level down.


class CryptoFreq : public CxxTest::TestSuite {
public:

  string alphabet;
  
  void setUp(){
    for(int i = 0; i < 26; i++){
      alphabet += i + 'a';
    }
  }
  
  void test0(){
    Crypto a("dummy");
    TS_ASSERT_DELTA(a.letterFreqStDev(alphabet), 0.0, 0.0001);
  }
  
  void test1(){
    Crypto a("dummy");
    TS_ASSERT_DELTA(a.letterFreqStDev(""), 0.0, 0.0001);
  }
  
  void test2(){
    Crypto a("dummy");
    TS_ASSERT_DELTA(a.letterFreqStDev(alphabet + alphabet), 0.0, 0.0001);
  }
  
  void test3(){
    Crypto a("dummy");
    TS_ASSERT_DELTA(a.letterFreqStDev("abcdefghijklm"), 0.5, 0.0001);
  }
  
  void test4(){
    Crypto a("dummy");
    TS_ASSERT_DELTA(a.letterFreqStDev("aaaaaaaaaa"), 1.923, 0.0001);
  }
  
  void test5(){
    Crypto a("dummy");
    TS_ASSERT_DELTA(a.letterFreqStDev("abababababababababab"), 2.6646, 0.0001);
  }
};

class CryptoCaesar : public CxxTest::TestSuite {
public:
  void test0(){
    Crypto a("a");
    TS_ASSERT_DIFFERS(a.caesarEncrypt("ab"), "ab");
  }
  
  void test1(){
    Crypto a("a");
    Crypto b("b");
    TS_ASSERT_DIFFERS(a.caesarEncrypt("ab"), b.caesarEncrypt("ab"));
  }
  
  void test2(){
    Crypto a("a");
    TS_ASSERT_EQUALS(a.caesarDecrypt(a.caesarEncrypt("ab")), "ab");
  }
  
  void test3(){
    Crypto a("z");
    TS_ASSERT_EQUALS(a.caesarDecrypt(a.caesarEncrypt("ab")), "ab");
  }
  
  void test4(){
    Crypto a("g");
    TS_ASSERT_EQUALS(a.caesarDecrypt(a.caesarEncrypt("abz")), "abz");
  }
  
  void test5(){
    Crypto a("g");
    TS_ASSERT_EQUALS(a.caesarDecrypt(a.caesarEncrypt("abz U")), "abz U");
  }
  
  void test6(){
    Crypto a("g");
    TS_ASSERT_DELTA(a.letterFreqStDev(a.caesarEncrypt("abz U")), 
      a.letterFreqStDev("abz U"),0.0001);
  }
  
  void test7(){
    Crypto a("zz");
    TS_ASSERT_DELTA(a.letterFreqStDev(a.caesarEncrypt("abz U?")), 
      a.letterFreqStDev("abz U?"),0.0001);
  }
  
  
};

class CryptoVig : public CxxTest::TestSuite {
public:
  void test0(){
    Crypto a("a");
    TS_ASSERT_DIFFERS(a.vigenereEncrypt("ab"), "ab");
  }
  
  void test1(){
    Crypto a("a");
    Crypto b("b");
    TS_ASSERT_DIFFERS(a.vigenereEncrypt("ab"), b.vigenereEncrypt("ab"));
  }
  
  void test2(){
    Crypto a("a");
    TS_ASSERT_EQUALS(a.vigenereDecrypt(a.vigenereEncrypt("ab")), "ab");
  }
  
  void test3(){
    Crypto a("z");
    TS_ASSERT_EQUALS(a.vigenereDecrypt(a.vigenereEncrypt("ab")), "ab");
  }
  
  void test4(){
    Crypto a("secret");
    TS_ASSERT_EQUALS(a.vigenereDecrypt(a.vigenereEncrypt("abz")), "abz");
  }
  
  void test5(){
    Crypto a("secret");
    TS_ASSERT_EQUALS(a.vigenereDecrypt(a.vigenereEncrypt("abz U")), "abz U");
  }
  
  void test6(){
    Crypto a("secret");
    string input = "aaabbbccc";
    TS_ASSERT_LESS_THAN(a.letterFreqStDev(a.vigenereEncrypt(input)), 
      a.letterFreqStDev(input));
    TS_ASSERT_EQUALS(a.vigenereDecrypt(a.vigenereEncrypt(input)), input);
  }
  
  void test7(){
    Crypto a("secret");
    string input = "This is a longer sentence. The quick brown fox jumps over the lazy dog";
    //TS_ASSERT_LESS_THAN(a.letterFreqStDev(a.vigenereEncrypt(input)), 
    //  a.letterFreqStDev(input));
    TS_ASSERT_EQUALS(a.vigenereDecrypt(a.vigenereEncrypt(input)), input);
  }
  
  void test8(){
    // Make sure longer inputs get at least a 2/3 reduction in
    // StDev.
    Crypto a("SecretKey");
    string input = "Oak is strong and also gives shade.\n";
    input += "Cats and dogs each hate the other.\n";
    input += "The pipe began to rust while new.\n";
    input += "Open the crate but don't break the glass.\n";
    input += "Add the sum to the product of these three.\n";
    input += "Thieves who rob friends deserve jail.\n";
    input += "The ripe taste of cheese improves with age.\n";
    input += "Act on these orders with great speed.\n";
    input += "The hog crawled under the high fence.\n";
    input += "Move the vat over the hot fire.";
    TS_ASSERT_LESS_THAN(a.letterFreqStDev(a.vigenereEncrypt(input)), 
      a.letterFreqStDev(input) * 2.0 / 3.0);
    TS_ASSERT_EQUALS(a.vigenereDecrypt(a.vigenereEncrypt(input)), input);
  }
  
  void test9(){
    // Verify the key rotates.
    Crypto a("ab");
    string encrypted = a.vigenereEncrypt("aa");
    TS_ASSERT_DIFFERS(encrypted[0],encrypted[1]);
  }
  
  void test10(){
    // Verify the key rotates properly.
    Crypto a("ab");
    string encrypted = a.vigenereEncrypt("aaaa");
    TS_ASSERT_DIFFERS(encrypted[0],encrypted[1]);
    TS_ASSERT_EQUALS(encrypted[0],encrypted[2]);
    TS_ASSERT_EQUALS(encrypted[1],encrypted[3]);
  }
};
#endif
