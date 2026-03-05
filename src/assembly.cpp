#include "vex.h"

using namespace vex;
using namespace mik;

// The code in this file is example and can be deleted

// This is example code for a push back robot with two 5.5W motors on the lower intake,
// 11W motor on the top intake, a scraper, and wing

// You want to call this function once in the user control function in main.
void Assembly::init() {
    // Create the task to move the lift arm. We only want one task to be created

    antijamTask = vex::task([](){
        assembly.antijamControl();
        return 0;
    });
    // To stop the task do `assembly.antijamTask.stop();`
} 

// You want to put this function inside the user control loop in main.
void Assembly::control() {
    intakeControl();
    heightControl();
    wingControl();
    tongueControl();
    lockingControl();
}

void Assembly::antijamControl() {
    while (true) {
        if (lowerStage.torque() >= 2 || upperStage.torque() >= 2) { // tune 1.5 value to find something that will work
            lowerStage.spin(fwd, -12, volt);
            upperStage.spin(fwd, -12, volt);
            vex::this_thread::sleep_for(100); // tune this value for something that'll work well to get the object unstuck without losing time
            lowerStage.spin(fwd, 12, volt);
            upperStage.spin(fwd, 12, volt);
        }
        vex::this_thread::sleep_for(20);; // Sleep for 20 milliseconds to prevent wasted resources
     }
}

void Assembly::intakeControl() {
    if(Controller.ButtonR1.pressing()) {
        double speed = (!highGoal.state() && locking.state()) ? 8 : 12; // only reduce speed when high goal is not extended and locking is extended
        lowerStage.spin(fwd, speed, volt);
        upperStage.spin(fwd, speed, volt);
    } else if(Controller.ButtonL1.pressing()) {
        lowerStage.spin(fwd, -8, volt);
        upperStage.spin(fwd, -8, volt);
    } else {
        lowerStage.stop();
        upperStage.stop();
    }
}

// Extends or retracts piston when button A is pressed, can only extend or retract again until button A is released and pressed again
void Assembly::heightControl() {
    if (btnL2_new_press(Controller.ButtonL2.pressing())) {
        highGoal.toggle();
    }
}

void Assembly::tongueControl() {
    if (btnDown_new_press(Controller.ButtonDown.pressing())) {
        tongue.toggle();
    }
}

void Assembly::wingControl() {
    if (btnB_new_press(Controller.ButtonB.pressing())) {
        wing.toggle();
    }
}

void Assembly::lockingControl() {
    if (btnR2_new_press(Controller.ButtonR2.pressing())) {
        locking.toggle();
    }
}