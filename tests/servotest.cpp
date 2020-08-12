#include <stdio.h>
#include <stdlib.h>
#include <gtest/gtest.h>
#include "rvrtest.h"

extern "C" {
    #include "../rover/rvr.h"
    #include "../rover/rvr_servo.h"
}

TEST(RoverTests, TestSetStrAttr) {
    char val[] = "run-direct";
    int len = strlen(val) + 1;
    int numChars = servoSetStrAttr(ServoComponent::MOTOR0, ServoAttr::COMMAND, val);
    EXPECT_EQ(numChars, len);

    char readstr[MAX_PATH_BYTES];
    char* path = getTestPath(ServoAttr::COMMAND);
    readTestStr(path, readstr);
    EXPECT_STREQ(readstr, val);
}

TEST(RoverTests, TestSetUIntAttr) {
    size_t val = 888;
    int len = 4;
    int numChars = servoSetUIntAttr(ServoComponent::MOTOR0, ServoAttr::SPEED_SP, val);
    EXPECT_EQ(numChars, len);

    int readUInt;
    char* path = getTestPath(ServoAttr::SPEED_SP);
    readTestNum(path, &readUInt);
    EXPECT_EQ((size_t)readUInt, val);
}

TEST(RoverTests, TestSetIntAtrr) {
    int val = -88;
    int len = 4;
    int numChars = servoSetIntAttr(ServoComponent::MOTOR0, ServoAttr::DUTY_CYCLE_SP, val);
    EXPECT_EQ(numChars, len);

    int readInt;
    char* path = getTestPath(ServoAttr::DUTY_CYCLE_SP);
    readTestNum(path, &readInt);
    EXPECT_EQ(readInt, val);
}

TEST(RoverTests, TestSetCommand) {
    char command[] = "run-to-abs-pos";
    int len = strlen(command) + 1;
    int numChars = servoSetCommand(ServoComponent::MOTOR0, ServoCommand::RUN_TO_ABS_POS);
    EXPECT_EQ(numChars, len);
}

TEST(RoverTests, TestSetSpeed) {
    size_t val = 100;
    int len = 4;
    int numChars = servoSetSpeed(ServoComponent::MOTOR0, val);
    EXPECT_EQ(numChars, len);

    int readInt;
    char* path = getTestPath(ServoAttr::SPEED_SP);
    readTestNum(path, &readInt);
    EXPECT_EQ((size_t)readInt, val);

    val = 2000;
    numChars = servoSetSpeed(ServoComponent::MOTOR0, val);
    EXPECT_EQ(numChars, ERROR_VAL);
}

TEST(RoverTests, TestSetDutyCycle) {
    int val = -100;
    int len = 5;
    int numChars = servoSetDutyCycle(ServoComponent::MOTOR0, val);
    EXPECT_EQ(numChars, len);

    int readInt;
    char* path = getTestPath(ServoAttr::DUTY_CYCLE_SP);
    readTestNum(path, &readInt);
    EXPECT_EQ(readInt, val);

    val = -101;
    numChars = servoSetDutyCycle(ServoComponent::MOTOR0, val);
    EXPECT_EQ(numChars, ERROR_VAL);

    val = 101;
    numChars = servoSetDutyCycle(ServoComponent::MOTOR0, val);
    EXPECT_EQ(numChars, ERROR_VAL);
}

TEST(RoverTests, TestSetPolarity) {
    char val[] = "normal";
    int len = strlen(val) + 1;
    int numChars = servoSetPolarity(ServoComponent::MOTOR0, ServoPolarity::NORMAL);
    EXPECT_EQ(numChars, len);

    char readstr[MAX_PATH_BYTES];
    char* path = getTestPath(ServoAttr::POLARITY);
    readTestStr(path, readstr);
    EXPECT_STREQ(readstr, val);
}

TEST(RoverTests, TestSetPosition) {
    int val = -121;
    int len = 5;
    int numChars = servoSetPosition(ServoComponent::MOTOR0, val);
    EXPECT_EQ(numChars, len);

    int readInt;
    char* path = getTestPath(ServoAttr::POSITION_SP);
    readTestNum(path, &readInt);
    EXPECT_EQ(readInt, val);
}

TEST(RoverTests, TestSetRampDown) {
    size_t val = 100;
    int len = 4;
    int numChars = servoSetRampDown(ServoComponent::MOTOR0, val);
    EXPECT_EQ(numChars, len);

    int readInt;
    char* path = getTestPath(ServoAttr::RAMP_DOWN_SP);
    readTestNum(path, &readInt);
    EXPECT_EQ((size_t)readInt, val);
}

TEST(RoverTests, TestSetRampUp) {
    size_t val = 100;
    int len = 4;
    int numChars = servoSetRampUp(ServoComponent::MOTOR0, val);
    EXPECT_EQ(numChars, len);

    int readInt;
    char* path = getTestPath(ServoAttr::RAMP_UP_SP);
    readTestNum(path, &readInt);
    EXPECT_EQ((size_t)readInt, val);
}

TEST(RoverTests, TestSetStopAction) {
    char val[] = "coast";
    int len = strlen(val) + 1;
    int numChars = servoSetStopAction(ServoComponent::MOTOR0, ServoStopAction::COAST);
    EXPECT_EQ(numChars, len);

    char readstr[MAX_PATH_BYTES];
    char* path = getTestPath(ServoAttr::STOP_ACTION);
    readTestStr(path, readstr);
    EXPECT_STREQ(readstr, val);
}

TEST(RoverTests, TestSetTime) {
    size_t val = 100;
    int len = 4;
    int numChars = servoSetTime(ServoComponent::MOTOR0, val);
    EXPECT_EQ(numChars, len);

    int readInt;
    char* path = getTestPath(ServoAttr::TIME_SP);
    readTestNum(path, &readInt);
    EXPECT_EQ((size_t)readInt, val);
}

TEST(RoverTests, TestRunToPosition) {
    size_t position = 888;
    servoRunTo(position, ServoComponent::MOTOR0);

    int readInt;
    char* path = getTestPath(ServoAttr::POSITION_SP);
    readTestNum(path, &readInt);
    EXPECT_EQ((size_t)readInt, position);

    char command[] = "run-to-abs-pos";
    path = getTestPath(ServoAttr::COMMAND);
    char readstr[MAX_PATH_BYTES];
    readTestStr(path, readstr);
    EXPECT_STREQ(readstr, command);
}

TEST(RoverTests, TestRunToRelativePosition) {
    size_t position = 999;
    servoRunToRelative(position, ServoComponent::MOTOR0);

    int readInt;
    char* path = getTestPath(ServoAttr::POSITION_SP);
    readTestNum(path, &readInt);
    EXPECT_EQ((size_t)readInt, position);

    char command[] = "run-to-rel-pos";
    path = getTestPath(ServoAttr::COMMAND);
    char readstr[MAX_PATH_BYTES];
    readTestStr(path, readstr);
    EXPECT_STREQ(readstr, command);
}

TEST(RoverTests, TestRunForSeconds) {
    size_t val = 111;
    servoRunFor(val, ServoComponent::MOTOR0);
    int readInt;
    char* path = getTestPath(ServoAttr::TIME_SP);
    readTestNum(path, &readInt);
    EXPECT_EQ((size_t)readInt, val);

    char command[] = "run-timed";
    path = getTestPath(ServoAttr::COMMAND);
    char readstr[MAX_PATH_BYTES];
    readTestStr(path, readstr);
    EXPECT_STREQ(readstr, command);

}

TEST(RoverTests, TestRunReverse) {
    char val[] = "inversed";
    servoRunReverse(ServoComponent::MOTOR0);

    char readstr[MAX_PATH_BYTES];
    char* path = getTestPath(ServoAttr::POLARITY);
    readTestStr(path, readstr);
    EXPECT_STREQ(readstr, val);
}

TEST(RoverTests, TestRunNormal) {
    char val[] = "normal";
    servoRunNormal(ServoComponent::MOTOR0);

    char readstr[MAX_PATH_BYTES];
    char* path = getTestPath(ServoAttr::POLARITY);
    readTestStr(path, readstr);
    EXPECT_STREQ(readstr, val);
}

TEST(RoverTests, TestRunAt) {
    size_t val = 555;
    int readInt;
    servoRunAt(val, ServoComponent::MOTOR0);
    char* path = getTestPath(ServoAttr::SPEED_SP);
    readTestNum(path, &readInt);
    EXPECT_EQ((size_t)readInt, val);
}

TEST(RoverTests, TestRunCycle) {
    int val = 191;
    servoRunCycle(ServoComponent::MOTOR0, val, ServoCommand::RUN_TO_ABS_POS);

    int readInt;
    char* path = getTestPath(ServoAttr::POSITION_SP);
    readTestNum(path, &readInt);
    EXPECT_EQ(readInt, -val);

    char command[] = "run-to-abs-pos";
    path = getTestPath(ServoAttr::COMMAND);
    char readstr[MAX_PATH_BYTES];
    readTestStr(path, readstr);
    EXPECT_STREQ(readstr, command);

}

