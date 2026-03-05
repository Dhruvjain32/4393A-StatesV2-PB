#include "vex.h"

using namespace vex;
using namespace mik;

void intake(double lowerStageSpeed, double upperStageSpeed ) {
    assembly.lowerStage.spin(fwd, lowerStageSpeed, volt);
    assembly.upperStage.spin(fwd, upperStageSpeed, volt);
}


void extake(double lowerStageSpeed, double upperStageSpeed ) {
    assembly.lowerStage.spin(reverse, lowerStageSpeed, volt);
    assembly.upperStage.spin(reverse, upperStageSpeed, volt);
}

void stopIntake() {
    assembly.lowerStage.stop(coast);
    assembly.upperStage.stop(coast);
}