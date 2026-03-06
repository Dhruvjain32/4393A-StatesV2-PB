#include "vex.h"

using namespace vex;
using namespace mik;

std::string blue_right_elim(bool calibrate, mik::auto_variation var, bool get_name) {

    if(var == one) { }
    if (var == true) { return blue_right_midgoal(calibrate, var, get_name);}
    if (get_name) { return "blue right elim (8)"; }
    if (calibrate) {
        chassis.set_coordinates(49, 17.5, 270);        

        return "";
    }

     odom_constants();


    assembly.highGoal.open();
    assembly.locking.close();
    intake();

    chassis.drive_to_point(12, 27, {.wait = false});
    wait(700, msec);
    assembly.tongue.open();
    wait(300, msec);
    assembly.tongue.close();
    chassis.wait();

    chassis.drive_to_point(7.5, 43, {.max_voltage = 5});

    chassis.drive_to_point(24, 24, { .max_voltage = 10 });
    chassis.turn_to_angle(45);
    chassis.drive_to_point(45, 47.5, { .max_voltage = 10 });
    chassis.turn_to_angle(90);
    assembly.tongue.open();
    
    
    chassis.drive_to_point(63, 47.5, { .max_voltage = 10, .timeout = 1300}); // timeout is time to get both matchloader and blocks
    chassis.drive_to_point(27, 47.5, { .wait = false, .max_voltage = 10, .timeout = 2500 });
    wait(400, msec);
    assembly.tongue.close();
    wait(150, msec);
    assembly.locking.open();
    wait(1000, msec);
    chassis.wait();
    chassis.drive_distance(-5);

    return "";
}

// THIS IS ACTUALLY BLUE LEFT MIDGOAL (5+3)
std::string blue_right_midgoal(bool calibrate, mik::auto_variation var, bool get_name) {
 if (get_name) { return "blue right elim (5 + 3)"; }
    if (calibrate) {
        chassis.set_coordinates(49, 17.5, 270);        

        return "";
    }

     odom_constants();


    assembly.highGoal.open();
    assembly.locking.close();
    intake();

    chassis.drive_to_point(12, 27, {.wait = false});
    wait(700, msec);
    assembly.tongue.open();
    wait(300, msec);
    assembly.tongue.close();
    chassis.wait();

    chassis.drive_to_point(7.5, 43, {.max_voltage = 5});

    chassis.drive_to_point(24, 24, { .max_voltage = 10 });
    chassis.turn_to_angle(135);
    chassis.drive_to_point(45, 47.5, { .max_voltage = 10 });
    chassis.turn_to_angle(90);
    
    
    chassis.drive_distance(-43, { .wait = false, .max_voltage = 10, .timeout = 2500 });
    wait(400, msec);
    assembly.tongue.close();
    wait(150, msec);
    assembly.locking.open();
    wait(1000, msec);
    chassis.wait();

    // go to matchloader and collect blocks
    assembly.tongue.open();
    chassis.drive_to_point(63, 47.5, { .max_voltage = 10, .timeout = 1300}); // timeout is time to get both matchloader and blocks

    chassis.drive_to_point(13.5, 9.5, {.wait = false});
    assembly.highGoal.close();
    chassis.wait();
    intake(12, 9.5);
    assembly.locking.open();



    return "";
}