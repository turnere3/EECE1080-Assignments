/*    @file fractal.cpp    
      @author <-- Fill in your name here -->
      @date <-- Fill this in -->

			@description 
*/
#include <iostream>
#include <stdlib.h>
#include <sstream>
// Use your myComplex class!
#include "myComplex.h"

// Import and setup the CImg library
#define cimg_display 0
#include "CImg.h"

using namespace std;


// Convenience function to set the red, green, and blue channels
// at a given pixel location in the image.
void setRGB(int x, int y, unsigned char red, unsigned char green, unsigned char blue, cil::CImg<unsigned char>& image){
  *(image.data(x,y,0,0)) = red;
  *(image.data(x,y,0,1)) = green;
  *(image.data(x,y,0,2)) = blue;
}

// Fill me in!

int main(int argc, char* argv[]){
  // Fill me in!
  return 0;
}
