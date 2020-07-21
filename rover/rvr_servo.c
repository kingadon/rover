#include <stdio.h>
#include <string.h>
#include "rvr.h"
#include "rvr_servo.h"


const char* const servo_component_path[] = {
    "tacho-motor/motor0",
    "tacho-motor/motor1",
    "tacho-motor/motor2",
    "tacho-motor/motor3"
};

const char* const servo_attr_path[] = {
    "address",
    "command",
    "count_per_rot",
    "duty_cycle_sp",
    "max_speed",
    "polarity",
    "position_sp",
    "ramp_down_sp",
    "ramp_up_sp",
    "speed_sp",
    "state",
    "stop_action",
    "time_sp",
    "uevent"
};

const char* const servo_commands[] = {
    "run-forever",
    "run-to-abs-pos",
    "run-to-rel-pos",
    "run-timed",
    "run-direct",
    "stop",
    "reset"
};

const char* const servo_polarities[] = {
    "inversed",
    "normal"
};

const char* const servo_stop_actions[] = {
    "coast",
    "brake",
    "hold"
};

const char* const ROOT_COMPONENT_DIR1 = "sys/class";

int servoSetStrAttr(enum ServoComponent servo, enum ServoAttr attr, const char* const val) {
    char path[MAX_PATH_BYTES];
    int numChars = snprintf(path, MAX_PATH_BYTES, PATH_FMT,
                            ROOT_COMPONENT_DIR1, 
                            servo_component_path[servo],
                            servo_attr_path[attr]);
    if (numChars < 0) { perror("servoSetStrAttr:snprintf"); return -1; }

    numChars = rvrWriteStr(path, val);
    return numChars;
}

int servoSetUIntAttr(enum ServoComponent servo, enum ServoAttr attr, size_t val) {
    char path[MAX_PATH_BYTES];
    int numChars = snprintf(path, MAX_PATH_BYTES, PATH_FMT,
                            ROOT_COMPONENT_DIR1,
                            servo_component_path[servo],
                            servo_attr_path[attr]);
    if (numChars < 0) {
        perror("servoSetStrAttr:snprintf");
        return -1;
    }

    numChars = rvrWriteUInt(path, val);
    return numChars;
}

int servoSetIntAttr(enum ServoComponent servo, enum ServoAttr attr, int val) {
    char path[MAX_PATH_BYTES];
    int numChars = snprintf(path, MAX_PATH_BYTES, PATH_FMT,
                            ROOT_COMPONENT_DIR1,
                            servo_component_path[servo],
                            servo_attr_path[attr]);
    if (numChars < 0) {
        perror("servoSetStrAttr:snprintf");
        return -1;
    }

    numChars = rvrWriteInt(path, val);
    return numChars;
}

int servoSetCommand(enum ServoComponent servo, enum ServoCommand command) {
    return servoSetStrAttr(servo, COMMAND, servo_commands[command]);
}

int servoSetSpeed(enum ServoComponent servo, size_t val) {
    if ((val >= 0) & (val <= 1560)) {
        return servoSetUIntAttr(servo, SPEED_SP, val);
    } else {
        perror("servoSetSpeed: speed must be between 0 and 1560\n");
        return -1;
    }
}

int servoSetDutyCycle(enum ServoComponent servo, int val) {
    if ((val >= -100) & (val <= 100)) {
        return servoSetIntAttr(servo, DUTY_CYCLE_SP, val);
    } else {
        perror("servoSetDutyCycle: cycle must be between -100 and 100\n");
        return -1;
    }
}

int servoSetPolarity(enum ServoComponent servo, enum ServoPolarity polarity) {
    return servoSetStrAttr(servo, POLARITY, servo_polarities[polarity]);
}

int servoSetPosition(enum ServoComponent servo, size_t val) {
    return servoSetUIntAttr(servo, POSITION_SP, val);
}

int servoSetRampDown(enum ServoComponent servo, size_t val) {
    return servoSetUIntAttr(servo, RAMP_DOWN_SP, val);
}

int servoSetRampUp(enum ServoComponent servo, size_t val) {
    return servoSetUIntAttr(servo, RAMP_UP_SP, val);
}

int servoSetStopAction(enum ServoComponent servo, enum ServoStopAction action) {
    return servoSetStrAttr(servo, STOP_ACTION, servo_stop_actions[action]);
}

int servoSetTime(enum ServoComponent servo, size_t val) {
    return servoSetUIntAttr(servo, TIME_SP, val);
}
