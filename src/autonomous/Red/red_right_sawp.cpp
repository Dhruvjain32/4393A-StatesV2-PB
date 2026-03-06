#include "vex.h"

using namespace vex;
using namespace mik;

std::string red_right_sawp(bool calibrate, mik::auto_variation var, bool get_name) {
    if (get_name) { return "red right sawp"; }
    if (calibrate) {
        chassis.set_coordinates(-46, -0.5, 0);
        
        return "";
    }
    odom_constants();
    intake();
    assembly.highGoal.open();
    assembly.locking.close();

    // drive into teammate and grab the pre-load
    chassis.drive_to_point(-46, 5, {.max_voltage = 12});

    // drive to point inbween the long goal and matchloader
    chassis.drive_to_point(-47.5, -47.5, {.max_voltage = 12});

    // turn to face matchlaoder
    chassis.turn_to_angle(270, {.timeout = 600});

    // drive to matchloader and intake the blocks
    chassis.drive_to_point(-61.5, -47.5, {.max_voltage = 8, .wait = false});
    assembly.tongue.open();
    wait(700, msec);
    chassis.wait();

    // drive to long goal and outtake the blocks
    chassis.drive_to_point(-27, -48.22, {.max_voltage = 12, .wait = false, .timeout = 1200});
    wait(350, msec);
    assembly.tongue.close();
    assembly.locking.open();
    wait(750, msec);
    chassis.wait();

    // drive to set of 3 blocks and intake them
    chassis.drive_to_point(-20.42, -23.15, { .drive_direction = mik::drive_direction::FWD, .wait = false, .max_voltage = 12 });
    wait(500, msec);
    assembly.tongue.open();
    wait(250, msec);
    assembly.tongue.close();
    chassis.wait();

    // drive to other set of 3 blocks and intake them
    chassis.drive_to_point(-22.19, 22.83, {.max_voltage = 12, .wait = false});
    wait(900, msec);
    assembly.tongue.open();
    wait(250, msec); // time for tongue to intake blocks
    assembly.tongue.close();
    chassis.wait();

    // drive to point between matchloader and goal
    chassis.drive_to_point(-46, 47.5, {.max_voltage = 10});

    // turn to face matchloader
    chassis.turn_to_angle(270);

    // outtake blocks into long goal
    chassis.drive_to_point(-27, 47.5, {.max_voltage = 12, .wait = false, .timeout = 1200});
    wait(350, msec);
    assembly.locking.open();
    wait(750, msec);
    chassis.wait();

    // intake blocks from matchloader
    chassis.drive_to_point(-61.5, 47.5, {.max_voltage = 8, .wait = false, .timeout = 1500});
    assembly.tongue.open();
    wait(700, msec);
    chassis.wait();
    
    // drive to middle goal and extake the blocks
    chassis.drive_to_point(-11.34, 10.79, {.max_voltage = 12, .wait = false});
    assembly.highGoal.close(); 
    intake(12, 9);   
    chassis.wait();
    assembly.locking.open();
    wait(650, msec);

    return "";
}