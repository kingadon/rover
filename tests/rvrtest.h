#ifndef RVRTEST_H
#define RVRTEST_H
#include <stdlib.h>
#include <gtest/gtest.h>

extern "C" {
    #include "../rover/rvr.h"
    #include "../rover/rvr_servo.h"
}

char* rvr_speed_path = (char*) "tests/sys/class/tacho-motor/motor0/speed_sp";
char* rvr_command_path = (char*) "tests/sys/class/tacho-motor/motor0/command";
char* rvr_duty_path = (char*) "tests/sys/class/tacho-motor/motor0/duty_cycle_sp";

#endif