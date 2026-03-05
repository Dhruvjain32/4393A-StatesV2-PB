#pragma once

#include "vex.h"

using namespace vex;

// The internals of this class is example code and can be deleted

// This is example code for a push back robot with two 5.5W motors on the lower intake,
// 11W motor on the top intake, a scraper, and wing

class Assembly {
public:
/* Create your devices here */
    static mik::motor lowerStage;
    static mik::motor upperStage;
    static mik::piston wing;
    static mik::piston locking;
    static mik::piston highGoal;
    static mik::piston tongue;

/* Examples of other vex devices you may need */
    static vex::rotation rotation_sensor;
    static vex::optical optical_sensor;
    static vex::limit limit_switch;

    void init();
    void control();

    vex::task antijamTask;

    void antijamControl();

    void intakeControl();
    void heightControl();
    void tongueControl();
    void wingControl();
    void lockingControl();
    
};