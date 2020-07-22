#include <stdio.h>
#include <stdlib.h>
#include <gtest/gtest.h>
#include "rvrtest.h"

extern "C" {
    #include "../rover/rvr.h"
}

TEST(RoverTests, TestWrite) {
    int val = 5;
    struct rvrvalue rvrval = {
        .type = INTEGER,
        .num = val
    };

    char* rvr_speed_path = getTestPath(testpath::SPEED);
    rvrWrite(rvr_speed_path, "%d", &rvrval);

    FILE* fptr = fopen(rvr_speed_path, "r");
    int num = -1;
    fscanf(fptr, "%d", &num);
    fclose(fptr);
    EXPECT_EQ(num, val);

    char* cpath = getTestPath(testpath::COMMAND);
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
    char* cpath = getTestPath(testpath::COMMAND);
    rvrWriteStr(cpath, strval);
    FILE* fptr = fopen(cpath, "r");
    char str[64];
    fscanf(fptr, "%63s", str);
    fclose(fptr);
    ASSERT_STREQ(str, strval);
}

TEST(RoverTests, TestWriteInt) {
    int val = -100;
    char* dpath = getTestPath(testpath::DUTY);
    rvrWriteInt(dpath, val);
    FILE* fptr = fopen(dpath, "r");
    int readval;
    fscanf(fptr, "%d", &readval);
    fclose(fptr);
    EXPECT_EQ(readval, val);
}

TEST(RoverTests, TestWriteUInt) {
    size_t val = 1560;
    char* spath = getTestPath(testpath::SPEED);
    rvrWriteUInt(spath, val);
    FILE* fptr = fopen(spath, "r");
    size_t readval;
    fscanf(fptr, "%zu", &readval);
    fclose(fptr);
    EXPECT_EQ(readval, val);
}

