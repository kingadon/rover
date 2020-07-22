#ifndef RVRTEST_H
#define RVRTEST_H
#include <stdlib.h>
#include <gtest/gtest.h>

extern "C" {
    #include "../rover/rvr_servo.h"
}

extern char* getTestPath(enum ServoAttr attr); 
extern void readTestStr(char* path, char* str);
extern void readTestNum(char* path, int* num);
#endif