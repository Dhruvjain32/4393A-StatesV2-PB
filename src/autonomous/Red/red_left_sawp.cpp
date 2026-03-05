#include "vex.h"

using namespace vex;
using namespace mik;

std::string red_left_sawp(bool calibrate, mik::auto_variation var, bool get_name) { 
    
    if (get_name) { return "red left sawp"; }
    if (calibrate) {
        chassis.set_coordinates(-46, -15.5, 180);
        return "";
    }
    odom_constants();

    intake();
    assembly.highGoal.open();
    assembly.locking.close();

    chassis.drive_to_point(-46.13, -47.5, {.max_voltage = 12});
    chassis.turn_to_angle(270, {.timeout = 700});
    
    assembly.tongue.open();
    chassis.drive_to_point(-61.5, -48, {.timeout = 1000, .max_voltage = 7 }); // timeout is time to get both matchloader and blocks
    chassis.drive_to_point(-26, -48, {.wait = false, .max_voltage = 12, .timeout = 1400 });
    wait(400, msec);
    assembly.tongue.close();
    wait(150, msec);
    assembly.locking.open();
    wait(700, msec);
    chassis.wait();

    // drive out of goal
    chassis.drive_distance(10, {.max_voltage = 12, .timeout = 600});
    assembly.locking.close();
    chassis.turn_to_angle(45, {.timeout = 700});

    // drive to set of three blocks and intake them
    chassis.drive_to_point(-19, -21, {.max_voltage = 12, .wait = false});
    wait(500, msec);
    assembly.tongue.open();
    wait(250, msec);
    assembly.tongue.close();
    chassis.wait();

    // Turn to the other set of 3 blocks while intaking
    chassis.turn_to_point(-21, 21, {.timeout = 600});
    
    // drive to other set of 3 blocks and intake them
    chassis.drive_to_point(-19, 25, { .max_voltage = 12, .wait = false });

    wait(900, msec);
    assembly.tongue.open();
    wait(250, msec); // time for tongue to intake blocks
    assembly.tongue.close();
    chassis.wait();

    // drive to point between matchloader and goal
    chassis.drive_to_point(-45.5, 47.5, {.max_voltage = 12});

    // turn to face matchloader
    chassis.turn_to_angle(270, {.timeout = 600});

    // drive to goal and extake blocks into goal  
    chassis.drive_distance(-30, {.max_voltage = 12, .timeout = 1500, .wait = false});
    wait(450, msec);
    assembly.locking.open();
    wait(550, msec);
    chassis.wait();
    assembly.highGoal.open();

    // drive into matchloader
    chassis.drive_to_point(-63.5, 47.5, {.wait = false, .max_voltage = 7, .timeout = 1500});

    assembly.locking.close();
    assembly.tongue.open();
    wait(1000, msec); // time for tongue to intake blocks
    chassis.wait();

    // drive to middle goal and score
    chassis.drive_to_point(-6.5, 12.3, {.wait = false, .max_voltage = 12});
    
    
    assembly.highGoal.close();
    wait(650, msec);
    extake();
    wait(50, msec);
    stopIntake();
    assembly.tongue.close();
    chassis.wait();

    assembly.locking.open();
    intake();
    wait(1500, msec);

    return "";
}