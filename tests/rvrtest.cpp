#include <stdio.h>
#include <stdlib.h>
#include <gtest/gtest.h>
#include "rvrtest.h"

extern "C" {
    #include "../rover/rvr.h"
}

char* getTestPath(enum ServoAttr attr) {
    switch (attr) {
        case ServoAttr::SPEED_SP:
            return (char*) "tests/sys/class/tacho-motor/motor0/speed_sp"; 
            break;
        case ServoAttr::DUTY_CYCLE_SP:
            return (char*) "tests/sys/class/tacho-motor/motor0/duty_cycle_sp"; 
            break;
        default:
            return (char*) "tests/sys/class/tacho-motor/motor0/command"; 
    }
}

void readTestStr(char* path, char* str) {
    FILE* fptr = fopen(path, "r");
    if (!fptr) {
        perror("readTestStr:fopen:");
        printf("error for path: %s\n", path);
    } else {
        fscanf(fptr, " %[^\n]\n", str);
    }
    fclose(fptr);
}

void readTestNum(char* path, int* num) {
    FILE* fptr = fopen(path, "r");
    if (!fptr) {
        perror("readTestStr:fopen:");
        printf("path: %s\n", path);
    } else {
        fscanf(fptr, "%d", num);
    }
    fclose(fptr);
}

TEST(RoverTests, TestWrite) {
    int val = 5;
    struct rvrvalue rvrval = {
        .type = INTEGER,
        .num = val
    };

    char* spath = getTestPath(ServoAttr::SPEED_SP);
    rvrWrite(spath, "%d", &rvrval);
    int num = -1;
    readTestNum(spath, &num);
    EXPECT_EQ(num, val);

    char* cpath = getTestPath(ServoAttr::COMMAND);
    struct rvrvalue rvrstr = {
        .type = STRING,
        .str = "run-forever" 
    };
    rvrWrite(cpath, "%s", &rvrstr);

    FILE* fptr_com = fopen(cpath, "r");
    char str[64];
    fscanf(fptr_com, "%63s", str);
    fclose(fptr_com);
    ASSERT_STREQ(str, rvrstr.str);
}

TEST(RoverTests, TestWriteStr) {
    char strval[] = "run-timed";
    char* cpath = getTestPath(ServoAttr::COMMAND);
    rvrWriteStr(cpath, strval);
    FILE* fptr = fopen(cpath, "r");
    char str[64];
    fscanf(fptr, "%63s", str);
    fclose(fptr);
    ASSERT_STREQ(str, strval);
}

TEST(RoverTests, TestWriteInt) {
    int val = -100;
    char* dpath = getTestPath(ServoAttr::DUTY_CYCLE_SP);
    rvrWriteInt(dpath, val);
    FILE* fptr = fopen(dpath, "r");
    int readval;
    fscanf(fptr, "%d", &readval);
    fclose(fptr);
    EXPECT_EQ(readval, val);
}

TEST(RoverTests, TestWriteUInt) {
    size_t val = 1560;
    char* spath = getTestPath(ServoAttr::SPEED_SP);
    rvrWriteUInt(spath, val);
    FILE* fptr = fopen(spath, "r");
    size_t readval;
    fscanf(fptr, "%zu", &readval);
    fclose(fptr);
    EXPECT_EQ(readval, val);
}

