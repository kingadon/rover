#include <stdio.h>
#include <stdlib.h>
#include <gtest/gtest.h>

extern "C" {
    #include "../rover/rvr.h"
}

class RoverTests : public ::testing::Test {
public:
    static void SetUpTestSuite() {
        rvr_speed_path = (char*)"tests/sys/class/tacho-motor/motor0/speed_sp";
        rvr_command_path = (char*)"tests/sys/class/tacho-motor/motor0/command";
        rvr_duty_path = (char*)"tests/sys/class/tacho-motor/motor0/duty_cycle_sp";
    }

    static void TearDownTestSuite() {
    }

    static char* rvr_speed_path;
    static char* rvr_command_path;
    static char* rvr_duty_path;
};

char* RoverTests::rvr_speed_path;
char* RoverTests::rvr_command_path;
char* RoverTests::rvr_duty_path;

TEST_F(RoverTests, TestWrite) {
    int val = 5;
    struct rvrvalue rvrval = {
        .type = INTEGER,
        .num = val
    };
    rvrWrite(RoverTests::rvr_speed_path, "%d", &rvrval);

    FILE* fptr = fopen(RoverTests::rvr_speed_path, "r");
    int num = -1;
    fscanf(fptr, "%d", &num);
    fclose(fptr);
    EXPECT_EQ(num, val);

    
    struct rvrvalue rvrstr = {
        .type = STRING,
        .str = "run-forever" 
    };
    rvrWrite(RoverTests::rvr_command_path, "%s", &rvrstr);

    FILE* fptr_com = fopen(RoverTests::rvr_command_path, "r");
    char str[64];
    fscanf(fptr_com, "%63s", str);
    fclose(fptr_com);
    ASSERT_STREQ(str, rvrstr.str);
}

TEST_F(RoverTests, TestWriteStr) {
    char strval[] = "run-timed";
    rvrWriteStr(RoverTests::rvr_command_path, strval);
    FILE* fptr = fopen(RoverTests::rvr_command_path, "r");
    char str[64];
    fscanf(fptr, "%63s", str);
    fclose(fptr);
    ASSERT_STREQ(str, strval);
}

TEST_F(RoverTests, TestWriteInt) {
    int val = -100;
    rvrWriteInt(RoverTests::rvr_duty_path, val);
    FILE* fptr = fopen(RoverTests::rvr_duty_path, "r");
    int readval;
    fscanf(fptr, "%d", &readval);
    fclose(fptr);
    EXPECT_EQ(readval, val);
}

TEST_F(RoverTests, TestWriteUInt) {
    size_t val = 1560;
    rvrWriteUInt(RoverTests::rvr_speed_path, val);
    FILE* fptr = fopen(RoverTests::rvr_speed_path, "r");
    size_t readval;
    fscanf(fptr, "%zu", &readval);
    fclose(fptr);
    EXPECT_EQ(readval, val);
}

