#include "vex.h"

using namespace vex;
using namespace mik;

std::string red_left_elim(bool calibrate, mik::auto_variation var, bool get_name) { 

    if (get_name) { return "red left elim"; }
    if (calibrate) {
        chassis.set_coordinates(-49, 17.5, 90);        
        return "";
    }
    odom_constants();


    assembly.highGoal.open();
    assembly.locking.close();
    intake();

    chassis.drive_to_point(-15, 27, {.wait = false});
    wait(700, msec);
    assembly.tongue.open();
    wait(300, msec);
    assembly.tongue.close();
    chassis.wait();

    chassis.drive_to_point(-6, 45, {.max_voltage = 5});

    chassis.drive_to_point(-24.88, 24.11, { .max_voltage = 10 });
    chassis.turn_to_angle(315);
    chassis.drive_to_point(-48, 49, { .max_voltage = 10 });
    chassis.turn_to_angle(270);
    assembly.tongue.open();
    
    
    chassis.drive_to_point(-64.52, 49, { .max_voltage = 10, .timeout = 1300}); // timeout is time to get both matchloader and blocks
    chassis.drive_to_point(-28, chassis.get_Y_position(), { .wait = false, .max_voltage = 10, .timeout = 2500 });
    wait(400, msec);
    assembly.tongue.close();
    wait(150, msec);
    assembly.locking.open();
    wait(1000, msec);
    chassis.wait();
    chassis.drive_distance(-5);

    
    return "";
}