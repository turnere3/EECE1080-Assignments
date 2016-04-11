/*    @file fractal.cpp    
      @author Eric Turner
      @date 4/6/2016

			@description Creates Fractals
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

myComplex p(myComplex z){
  myComplex z1 = z.multiplication(z).multiplication(z).addition(z).multiplication(z).addition(z);
  return z1;
}

myComplex pp(myComplex z){
  myComplex z2 = myComplex(3,0).multiplication(z).multiplication(z).addition(myComplex(2,0)).multiplication(z).addition(myComplex(1,0));
  return z2;
}

int newton(myComplex z){
  int n = 0;
  myComplex newZ;
  while (abs(newZ.getMagnitude() - z.getMagnitude()) >= 0.0001 && n < 200){
    newZ = z;
    z = z.subtraction((p(z)).division(pp(z)));
    n = n + 1;
  }
  return n;
}

int main(int argc, char* argv[]){
  
  string filename = "image.png";
  if(argc >= 2){
    filename = argv[1];
  }

  int width  = 800;
  int height = 600;

  if(argc >= 3){
    width = atoi(argv[2]);
  }
  
  if(argc >= 4){
    height = atoi(argv[3]);
  }
  
  double urr = 100.0;
  double uri = 100.0;
  double llr = -100.0;
  double lli = -100.0;
 
  double dx = (urr-llr) / (double)width;
  double dy = (uri-lli) / (double)height;

  int brightness = 0;

  cil::CImg<unsigned char> image(width,height,1, 3, 255); 
  for(int x = 0; x < width; x++){
    for(int y = 0; y < height; y++){
   
      double real = (double)x * dx + llr;
      double complex = (double)y * dy * -1 + uri;
      
      brightness = newton(myComplex(real,complex));
      brightness = brightness * 70 % 256;
      
      setRGB(x,y,
             brightness, 
             brightness*23%256,
             brightness*45%256,
             image);    }
  } 
  
  cout << "Saving: " << filename << " Width: " << width;
  cout << " Height: " << height << endl;
  image.save(filename.c_str());
  return 0;
}
