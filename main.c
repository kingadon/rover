#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rvr.h"
#include "rvr_servo.h"


int main(int argc, char* argv[]) {
    if (argc == 1) return 0;

    enum ServoCommand command = (enum ServoCommand) atoi(argv[1]);
    size_t speed = (size_t) atoi(argv[2]);
    size_t position;
    size_t time;
    size_t cycle;
    enum ServoStopAction action;

    switch (command) {
        case RUN_FOREVER:
            break;
        case RUN_TO_ABS_POS:
        case RUN_TO_REL_POS:
            position = (size_t) atoi(argv[3]);
            servoSetPosition(MOTOR0, position);
            break;
        case RUN_TIMED:
            time = (size_t) atoi(argv[3]);
            servoSetTime(MOTOR0, time);
            break;
        case RUN_DIRECT:
            cycle = (size_t) atoi(argv[3]);
            servoSetDutyCycle(MOTOR0, cycle);
            break;
        case STOP:
            action = (enum ServoStopAction) atoi(argv[3]);
            servoSetStopAction(MOTOR0, action);
            break;
        default:
            printf("thank you for using rover. have a nice day. give us ur money\n");
    }

    servoSetSpeed(MOTOR0, speed);
    servoSetCommand(MOTOR0, command);

    /**
    servoSetDutyCycle(MOTOR0, cycles);
    servoSetSpeed(MOTOR0, speed);
    servoSetPolarity(MOTOR0, polarity);
    servoSetPosition(MOTOR0, position);
    servoSetRampDown(MOTOR0, rDown);
    servoSetRampUp(MOTOR0, rUp);
    servoSetStopAction(MOTOR0, action);
    servoSetTime(MOTOR0, time);
    servoSetCommand(MOTOR0, command);
    */
    return 0;
}
