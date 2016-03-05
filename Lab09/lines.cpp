// Author: Fill name in here
// Source File: lines.cpp
// Description: Implements a line class.  Provide two points on the 
// line and this class can tell you the slope, intercept, and if two
// lines are paralell, perpendicular, and their intersection point.

#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
using namespace std;

const double DDIFF = 0.0001;
const double inf = std::numeric_limits<double>::infinity();

struct point_t{
  double x_coord, y_coord;
};

class Line{
  private:
    point_t a, b;
    
  public:
  
  // Default constructor makes 2 points at 0,0
  Line(){
    point_t zero;
    zero.x_coord = 0.0;
    zero.y_coord = 0.0;
    setPoints(zero, zero);
  }
  
  // Take two points to define a line.
  Line(point_t a_temp, point_t b_temp){
    // TODO: Fill me in
  }

  // Assign the given points to this line
  void setPoints(point_t a_temp, point_t b_temp){
    a = a_temp;
    b = b_temp;  
  }
  
  // Return the first point of the line
  point_t getFirstPoint(){
    // TODO: Fill me in
    point_t ret;
    ret.x_coord = 0.0;
    ret.y_coord = 0.0;
    return ret;
  }
  
  // Return the second point of the line
  point_t getSecondPoint(){
    // TODO: Fill me in
    point_t ret;
    ret.x_coord = 0.0;
    ret.y_coord = 0.0;
    return ret;
  }
  
  // Given the line, what is the slope?  Return inf (constant above) if
  // the the line is vertical (no x difference).
  double getSlope(){
    // TODO: Fill me in
    return 0.0;
  }
  
  // Returns the intercept (the y location where the line intercepts the y axis).
  // If the line is vertical, return 0;
  double getIntercept(){
    // TODO: Fill me in
    return 0.0;
  }
  
  // Returns a string containing point1 point2
  string getLineInfo(){
    stringstream temp;
    temp << a.x_coord << "," << a.y_coord << " " << b.x_coord << "," << b.y_coord;
    return temp.str();
  }

  // Returns the length of the line between the two points
  double getLength(){
    // TODO: Fill me in
    return 0.0;
  }
  
  // Returns true if the line is horizontal  
  bool isHorizontal(){
    // TODO: Fill me in
    return true;
  }
  
  // Returns true if the line is vertical  
  bool isVertical(){
    // TODO: Fill me in
    return true;
  }

  // Return the distance between two lines.  If they intersect, return 0.0.
  // Return value should always be positive.
  double getDistance(Line line2){
    // TODO: Fill me in
    return 0.0;
  }

  // Return true if the two lines are parallel.  Be sure to return the 
  // correct result if they are both vertical!
  bool isParallel(Line line2){
    // TODO: Fill me in
    return true;
      
  }
  
  // Return true if the two lines are perpendicular.  Be sure to return the
  // correct result if they one is vertical.
  bool isPerpendicular(Line line2){
    // TODO: Fill me in
    return true;
  }



};
