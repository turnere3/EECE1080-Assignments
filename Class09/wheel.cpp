#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


// Some CONSTANTS you may find useful.
const double PI = atan(1.0)*4;
const double FEET_PER_MILE =  5280;
const double INCHES_PER_FOOT =  12;
const double INCHES_PER_MILE = FEET_PER_MILE*INCHES_PER_FOOT;
const double MINUTES_PER_HOUR = 60;
const double SECONDS_PER_MINUTE = 60;
const double DEFAULT_TIRE_SIZE = 15;

class Wheel {
public:
  // Set the speed and rpms to zero and the radius to DEFAULT_TIRE_SIZE
  Wheel(){
	// FILL IN
  }

  // Set the speed and rpms to zero and the radius to in_radius
  Wheel(double in_radius){
	// FILL IN
  }

  // set the wheel radius and a vehicle speed in MPH.
  // Calculate the RPM based on speed and radius
  Wheel(double in_radius, double in_speed){
	// FILL IN
  }

  // Set the RPM and update the speed 
  // We have count revolution in a certain interval of time 
  // seconds
  void setRPM(double in_revolutions, double in_time){
	// FILL IN
  }

  // Set a new speed and update the RPM
  void setSpeed(double in_speed){
	// FILL IN
  }

  double getRadius(){
	// FILL IN
  }
  double getDiameter(){
	// FILL IN
  }
  double getCircumference(){
	// FILL IN
  }
  double getSurfaceArea(){
	// FILL IN
  }
  double getSpeed(){
	// FILL IN
  }
  double getRPM(){
	// FILL IN
  }

  // Display the Wheel Parameters
  void displayParameters(){
    cout << "Wheel Radius: " << radius << endl;
    cout << "Speed: " << speed << " MPH" << endl;
    cout << "Wheel Circumference: " << getCircumference() << " inches" << endl;
    cout << "Wheel Spin Rate: " << rpm << " RPM" << endl;
  }

private:
  double radius;   // radius inches
  double speed;   // MPH
  double rpm;   // RPM
};

