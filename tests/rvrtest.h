#ifndef RVRTEST_H
#define RVRTEST_H
#include <stdlib.h>
#include <gtest/gtest.h>

enum testpath {
    SPEED,
    COMMAND,
    DUTY
};

char* getTestPath(enum testpath t) {
    switch (t) {
        case testpath::SPEED:
            return (char*) "tests/sys/class/tacho-motor/motor0/duty_cycle_sp"; 
            break;
        case testpath::COMMAND:
            return (char*) "tests/sys/class/tacho-motor/motor0/speed_sp"; 
            break;
        default:
            return (char*) "tests/sys/class/tacho-motor/motor0/command"; 
    }
}

#endif