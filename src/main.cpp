/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Me                                                        */
/*    Created:      Tue Apr 05 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Vision10             vision        10              
// Controller1          controller                    
// Expander9            triport       9               
// RangeFinder9A        sonar         A, B            
// Arm                  motor         4               
// Hand                 motor         5               
// Drivetrain           drivetrain    1, 2, 11        
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

event checkRed = event();
event checkMagenta = event();
event checkGreen = event();
event checkDistance = event();

void visionLocation() {
  printf("CenterX: ");
  printf("%.2f", (double)Vision10.largestObject.centerX); 
  printf("\n");
  printf("CenterY: ");
  printf("%.2f", (double)Vision10.largestObject.centerY);
  printf("\n");
}

void targetObject() {
  //JPearman example
  int TARGET = 150; 
  int error = Vision10.largestObject.centerY - TARGET;  //How far off center is the item.

    // simple P control with a limit of 50
    int drive = error;
    if( drive > 50 ) drive = 50;
    if( drive < -50 ) drive = -50;

    // object is found and centered
    if( Vision10.largestObject.centerY > (TARGET-15) && Vision10.largestObject.centerY < (TARGET+15) ) {
      driveTurn(0);
    }
    else {
      driveTurn( drive ); //What does drive do?
    }
}


void getRange() {
  while (RangeFinder9A.distance(mm) > 50) {
    //Drivetrain.drive(forward);
    // get distance
  }
}

void hasMagentaCallback() { //Add target object somewhere when ready
  Brain.Screen.setFont(mono40);
  Brain.Screen.clearLine(1, black);
  Brain.Screen.setCursor(Brain.Screen.row(), 1);
  Brain.Screen.setCursor(1, 1);
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1,1);
  Vision10.takeSnapshot(Vision10__SIG_1);
  if (Vision10.objectCount > 0) {
    Brain.Screen.print("Magenta Object Found");
    Controller1.Screen.print("Magenta Object Found");
    visionLocation();
  } else {
    Brain.Screen.print("No Magenta Object");
    Controller1.Screen.print("No Magenta Object");
  }
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  checkMagenta(hasMagentaCallback);
  checkDistance(getRange);
  
  while (true) {
    checkMagenta.broadcastAndWait();
    checkDistance.broadcastAndWait();
    wait(1, seconds);
  }
}
