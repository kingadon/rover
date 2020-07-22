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
    rvrWrite(rvr_speed_path, "%d", &rvrval);

    FILE* fptr = fopen(rvr_speed_path, "r");
    int num = -1;
    fscanf(fptr, "%d", &num);
    fclose(fptr);
    EXPECT_EQ(num, val);

    
    struct rvrvalue rvrstr = {
        .type = STRING,
        .str = "run-forever" 
    };
    rvrWrite(rvr_command_path, "%s", &rvrstr);

    FILE* fptr_com = fopen(rvr_command_path, "r");
    char str[64];
    fscanf(fptr_com, "%63s", str);
    fclose(fptr_com);
    ASSERT_STREQ(str, rvrstr.str);
}

TEST(RoverTests, TestWriteStr) {
    char strval[] = "run-timed";
    rvrWriteStr(rvr_command_path, strval);
    FILE* fptr = fopen(rvr_command_path, "r");
    char str[64];
    fscanf(fptr, "%63s", str);
    fclose(fptr);
    ASSERT_STREQ(str, strval);
}

TEST(RoverTests, TestWriteInt) {
    int val = -100;
    rvrWriteInt(rvr_duty_path, val);
    FILE* fptr = fopen(rvr_duty_path, "r");
    int readval;
    fscanf(fptr, "%d", &readval);
    fclose(fptr);
    EXPECT_EQ(readval, val);
}

TEST(RoverTests, TestWriteUInt) {
    size_t val = 1560;
    rvrWriteUInt(rvr_speed_path, val);
    FILE* fptr = fopen(rvr_speed_path, "r");
    size_t readval;
    fscanf(fptr, "%zu", &readval);
    fclose(fptr);
    EXPECT_EQ(readval, val);
}

