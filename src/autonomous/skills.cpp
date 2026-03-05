#include "vex.h"
#include "autonomous/autons.h"

using namespace vex;
using namespace mik;

double mlToGoal = 1500;
double centerToGoal = 750;
double scoringOnGoal = 1000;
double timeAtML = 3000;


std::string skills(bool calibrate, mik::auto_variation var, bool get_name) {
    if (get_name) { return "skills"; }
    if (calibrate) {
        chassis.set_coordinates(-47.5, -17, 90);

        return "";
    }
    chassis.drive_max_voltage = 8;
    // assembly.highGoal.open();
    assembly.locking.close(); 
    intake();

    // Drive to set of two blocks and intake them
    chassis.drive_to_point(-22.82, -24.43, {.wait = false});
    wait(700, msec); // tune time to grab set of 4 blocks
    assembly.tongue.open();
    wait(300, msec);
    assembly.tongue.close();
    chassis.wait();

    // turn to low goal
    chassis.turn_to_angle(45 , {.turn_direction = mik::ccw });

    // drive to low goal and score
    chassis.drive_to_point(-6.5, 12.3, {.wait = false, .max_voltage = 8});
    wait(300, msec);
    extake(8, 8);
    wait(300, msec); // time to score blocks
    chassis.wait();

    // drive away from low goal
    chassis.drive_to_point(-46, -47.5);

    // turn to matchloader
    chassis.turn_to_angle(270);

    // intake blocks from matchloader
    chassis.drive_to_point(-61.53, -48, {.max_voltage = 5, .timeout = 3000});
    assembly.tongue.open();
    wait(300, msec); // time to intake blocks
    chassis.wait();

    // drive past the long goal to go to the other side
    chassis.drive_to_point(-26, -60);
    assembly.tongue.close();
    
    // turn to drive to other side
    chassis.turn_to_angle(270, { .turn_direction = mik::ccw });

    // reset distance with the wall to reduce odometry error, tune distance if needed
    chassis.reset_axis(left_sensor, mik::bottom_wall, 8);

    // drive to otherside of the field
    chassis.drive_to_point(30, -60);

    // drive infront of the long goal
    chassis.drive_to_point(36.27, -47.44);

    // turn to long goal
    chassis.turn_to_angle(90, { .turn_direction = mik::ccw });

    // score on long goal
    chassis.drive_to_point(28, -47.5, {.wait = false, .max_voltage = 8});
    wait(centerToGoal, msec);
    assembly.locking.open();
    wait (scoringOnGoal, msec);
    chassis.wait();

    // drive into matchloader and intake blocks
    chassis.drive_to_point(63.76, -47.62, {.wait = false, .max_voltage = 5, .timeout = 3000});
    assembly.locking.close();
    wait(300, msec);
    assembly.tongue.open();
    chassis.wait();

    // drive back to the goal and score
    chassis.drive_to_point(28.98, -47.62, {.wait = false});
    wait(mlToGoal, msec); // time to get to goal
    assembly.locking.open();
    wait (scoringOnGoal, msec);
    chassis.wait();
    chassis.wait();

    chassis.drive_to_point(60.4, -25.18, { .max_voltage = 8.1 });
    chassis.drive_to_point(61.89, 34.66);
    chassis.turn_to_point(30.66, 26.43);
    chassis.drive_to_point(30.66, 26.43);
    chassis.drive_to_point(24.12, -23.31);
    chassis.turn_to_angle(135);
    chassis.drive_to_point(12.52, -12.65);
    chassis.drive_to_point(27.86, -26.86);
    chassis.drive_to_point(46.93, 46.82);
    chassis.turn_to_angle(90);
    chassis.drive_to_point(65.63, 46.63);
    chassis.drive_to_point(26, 60);
    chassis.turn_to_angle(90);
    chassis.drive_to_point(-29.44, 59.72);
    chassis.drive_to_point(-34.41, 46.26);
    chassis.turn_to_angle(270);
    chassis.drive_to_point(-26.19, 46.44);
    chassis.drive_to_point(-62.28, 45.69);
    chassis.drive_to_point(-26.19, 46.26);
    chassis.drive_to_point(-61.34, 22.69);
    chassis.turn_to_angle(180);
    chassis.drive_to_point(-62.28, -1.43);
    return "";
}