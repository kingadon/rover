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

int buildServoPath(char* path, enum ServoComponent servo, enum ServoAttr attr) { 
    int numChars = snprintf(path, MAX_PATH_BYTES, PATH_FMT,
                            ROOT_COMPONENT_DIR, 
                            servo_component_path[servo],
                            servo_attr_path[attr]);
    if (numChars < 0) { 
        perror("buildServoPath:snprintf"); 
        printf("error building path\n");
        path = "";
    } 

    return -1;
}

int servoSetStrAttr(enum ServoComponent servo, enum ServoAttr attr, const char* const val) {
    char path[MAX_PATH_BYTES]; 
    buildServoPath(path, servo, attr);

    int numChars = 0;
    if (path) {
        numChars = rvrWriteStr(path, val);
    }
    return numChars;
}

int servoSetUIntAttr(enum ServoComponent servo, enum ServoAttr attr, size_t val) {
    char path[MAX_PATH_BYTES];
    buildServoPath(path, servo, attr);

    int numChars = 0;
    if (path) {
        numChars = rvrWriteUInt(path, val);
    }
    return numChars;
}

int servoSetIntAttr(enum ServoComponent servo, enum ServoAttr attr, int val) {
    char path[MAX_PATH_BYTES];
    buildServoPath(path, servo, attr);

    int numChars = 0;
    if (path) {
        numChars = rvrWriteInt(path, val);
    }
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
        return ERROR_VAL;
    }
}

int servoSetDutyCycle(enum ServoComponent servo, int val) {
    if ((val >= -100) & (val <= 100)) {
        return servoSetIntAttr(servo, DUTY_CYCLE_SP, val);
    } else {
        perror("servoSetDutyCycle: cycle must be between -100 and 100\n");
        return ERROR_VAL;
    }
}

int servoSetPolarity(enum ServoComponent servo, enum ServoPolarity polarity) {
    return servoSetStrAttr(servo, POLARITY, servo_polarities[polarity]);
}

int servoSetPosition(enum ServoComponent servo, int pos) {
    return servoSetUIntAttr(servo, POSITION_SP, pos);
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

int servoRunTo(int position, enum ServoComponent servo) {
    int code = servoSetPosition(servo, position);
    if (code == -1) {
        return code;
    }
    return servoSetCommand(servo, RUN_TO_ABS_POS);
}

int servoRunToRelative(int position, enum ServoComponent servo) {
    int code = servoSetPosition(servo, position);
    if (code == -1) {
        return code;
    }
    return servoSetCommand(servo, RUN_TO_REL_POS);
}

int servoRunFor(size_t seconds, enum ServoComponent servo) {
    int code = servoSetTime(servo, seconds);
    if (code == -1) {
        return code;
    }
    return servoSetCommand(servo, RUN_TIMED);
}

int servoRunReverse(enum ServoComponent servo) {
    int code = servoSetCommand(servo, RUN_DIRECT);
    if (code == -1) {
        return code;
    }
    return servoSetPolarity(servo, INVERSED);
}

int servoRunNormal(enum ServoComponent servo) {
    int code = servoSetCommand(servo, RUN_DIRECT);
    if (code == -1) {
        return code;
    }
    return servoSetPolarity(servo, NORMAL);
}

int servoRunAt(size_t speed, enum ServoComponent servo) {
    int code = servoSetCommand(servo, RUN_DIRECT);
    if (code == -1) {
        return code;
    }
    return servoSetSpeed(servo, speed);
}

int servoRunCycle(enum ServoComponent servo, int pos, enum ServoCommand com) {
    int code = servoSetPosition(servo, pos);
    if (code = -1) {
        return code;
    }
    servoSetCommand(servo, com);
    servoSetPosition(servo, -pos);
    return servoSetCommand(servo, com);
}