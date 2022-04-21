using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern signature Vision10__SIG_1;
extern signature Vision10__SIG_2;
extern signature Vision10__SIG_3;
extern signature Vision10__SIG_4;
extern signature Vision10__SIG_5;
extern signature Vision10__SIG_6;
extern signature Vision10__SIG_7;
extern vision Vision10;
extern controller Controller1;
extern triport Expander9;
extern sonar RangeFinder9A;
extern motor Arm;
extern motor Hand;
extern smartdrive Drivetrain;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
