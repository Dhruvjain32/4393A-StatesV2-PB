#include "vex.h"

using namespace vex;
using namespace mik;

std::string red_left_sawp(bool calibrate, mik::auto_variation var, bool get_name) { 
        if (var == one) {}

    if (var == two) {return red_left_sawp_No_XY(calibrate,var, get_name);}

    
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
    wait(150, msec);
    assembly.tongue.open();
    wait(850, msec); // time for tongue to intake blocks
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

std::string red_left_sawp_No_XY(bool calibrate, mik::auto_variation var, bool get_name) { 
    if (get_name) { return "moveDist"; }
    
    // Mirror template_auto() from the x-axis
    
    if (calibrate) {
        chassis.set_coordinates(-46, -15.5, 180);
        return "";
    }

    odom_constants();

    intake();
    assembly.highGoal.open();
    assembly.locking.close();

    chassis.drive_distance(32, {.max_voltage = 12});
    chassis.turn_to_angle(270, {.timeout = 700});
    
    assembly.tongue.open();

    // drive to matchloader and intake blocks
    chassis.drive_distance(18, {.timeout = 1000, .max_voltage = 7 }); // timeout is time to get both matchloader and blocks
    
    // drive to goal and score
    chassis.drive_distance(-40, {.wait = false, .max_voltage = 12, .timeout = 1300 });
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
    chassis.drive_distance(26, {.max_voltage = 12, .wait = false});
    wait(500, msec);
    assembly.tongue.open();
    wait(250, msec);
    assembly.tongue.close();
    chassis.wait();

    // Turn to the other set of 3 blocks while intaking
    chassis.turn_to_angle(0, {.timeout = 600});
    
    // drive to other set of 3 blocks and intake them
    chassis.drive_distance(52, { .max_voltage = 12, .wait = false });
    wait(900, msec);
    assembly.tongue.open();
    wait(250, msec); // time for tongue to intake blocks
    assembly.tongue.close();
    chassis.wait();

    // drive to point between matchloader and goal
    chassis.turn_to_angle(315, {.timeout = 700});
    chassis.drive_distance(34.5, {.max_voltage = 12});
    // chassis.drive_to_point(-45, 47.5, {.max_voltage = 12}); // keeping this movement because it allows for a solid basepoint

    // turn to face matchloader
    chassis.turn_to_angle(270, {.timeout = 800});

    // drive to goal and extake blocks into goal  
    chassis.drive_distance(-30, {.max_voltage = 12, .timeout = 1300, .wait = false});
    wait(450, msec);
    assembly.locking.open();
    wait(450, msec);
    chassis.wait();
    assembly.highGoal.open();

    // drive into matchloader
    chassis.drive_distance(48, {.wait = false, .max_voltage = 7, .timeout = 1500});

    assembly.locking.close();
    wait(300, msec);
    assembly.tongue.open();
    wait(700, msec); // time for tongue to intake blocks
    chassis.wait();

    // drive to middle goal and score
    chassis.drive_to_point(-7, 11.75, {.wait = false, .max_voltage = 12});
    
    
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
    
    // Run auto, make sure to pass in one as var.

    return "";
}

