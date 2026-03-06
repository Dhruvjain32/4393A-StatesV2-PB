#include "vex.h"

using namespace vex;
using namespace mik;

std::string blue_left_elim(bool calibrate, mik::auto_variation var, bool get_name) {   
    if (get_name) { return "blue left elim (8)"; }


    if (calibrate) {
        chassis.set_coordinates(49, -17.5, 270);        

      	return "";
    }

odom_constants();


    assembly.highGoal.open();
    assembly.locking.close();
    intake();

    chassis.drive_to_point(15, -27, {.wait = false});
    wait(700, msec);
    assembly.tongue.open();
    wait(300, msec);
    assembly.tongue.close();
    chassis.wait();

    chassis.drive_to_point(6.5, -45, {.max_voltage = 5});

    chassis.drive_to_point(24, -24, { .max_voltage = 10 });
    chassis.turn_to_angle(135, {.turn_direction = ccw});
    chassis.drive_to_point(45, -47.5, { .max_voltage = 10 });
    chassis.turn_to_angle(90, {.turn_direction = ccw});

    
    assembly.tongue.open();
    chassis.drive_to_point(64.52, -47.5, { .max_voltage = 10, .timeout = 1000});
    chassis.drive_distance(-46, { .wait = false, .max_voltage = 10, .timeout = 2500 });
    wait(400, msec);
    assembly.tongue.close();
    wait(350, msec);
    assembly.locking.open();
    wait(2000, msec);
    chassis.wait();
    chassis.drive_distance(4);
    assembly.locking.close();
    chassis.drive_distance(-8);


    return "";
}