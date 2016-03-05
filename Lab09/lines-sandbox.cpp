#include <iostream>

#include "lines.cpp"
using namespace std;

int main(){
  // Sandbox to play with your Line class
  
  // Some examples...
  
  // Create a line on the x axis
  point_t x1;
  x1.x_coord = 0.0;
  x1.y_coord = 0.0;
  
  point_t x2;
  x2.x_coord = 10.0;
  x2.y_coord = 0.0;
  
  Line xaxis(x1, x2);
  
  // Print some stats
  cout << "Info: " << xaxis.getLineInfo() << endl;
  cout << "Slope: " << xaxis.getSlope() << endl;
  cout << "Length: " << xaxis.getLength() << endl;
  cout << "Horizontal?: " << xaxis.isHorizontal() << endl;
  cout << "Vertical?: " << xaxis.isVertical() << endl;
  
  // Create a second line
  point_t x12;
  x12.x_coord = 0.0;
  x12.y_coord = 1.0;
  
  point_t x22;
  x22.x_coord = 10.0;
  x22.y_coord = 1.0;
  
  Line xaxis2(x12, x22);
  
  // Print some stats.
  cout << "Parallel?: " << xaxis.isParallel(xaxis2) << endl;
  return 0;
}
