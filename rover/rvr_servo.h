/**
 * @file rvr_servo.h
 * @author Kingston A Huynh
 * @date June 29 2020
 * @brief File contains functions and values related to servo components.
 */

/** Put global constants here. */
/** @brief Servo components. Use these to access paths. */
enum ServoComponent {
    MOTOR0,
    MOTOR1,
    MOTOR2,
    MOTOR3
};

enum ServoAttr {
    ADDRESS,
    COMMAND,
    COUNT_PER_ROT,
    DUTY_CYCLE_SP,
    MAX_SPEED,
    POLARITY,
    POSITION_SP,
    RAMP_DOWN_SP,
    RAMP_UP_SP,
    SPEED_SP,
    STATE,
    STOP_ACTION,
    TIME_SP,
    UEVENT
};

enum ServoCommand {
    RUN_FOREVER,
    RUN_TO_ABS_POS,
    RUN_TO_REL_POS,
    RUN_TIMED,
    RUN_DIRECT,
    STOP,
    RESET
};

enum ServoPolarity {
    INVERSED,
    NORMAL
};

enum ServoStopAction {
    COAST,
    BRAKE,
    HOLD
};
/** End global constants. */

/**
 * @brief Builds path to specified servo component using root dir and servo dir paths.
 * @param path Pointer to string variable to hold built path.
 * @param servo The subject servo component.
 * @return Return the number of characters written to string param, -1 if error.
 */
int servoPath(char* path, enum ServoComponent servo);

/**
 * @brief Builds path to specified servo component attr.
 * @param path Pointer to string variable to hold built path.
 * @param servo The subject servo component.
 * @param attr The subject attribute.
 * @return Return the number of characters written to string param, -1 if error.
 */
int servoAttrPath(char* path, enum ServoComponent servo, enum ServoAttr attr);

/**
 * @brief Sets string type attribute on the servo component.
 * @param servo The subject servo component.
 * @param attr The subject attribute.
 * @param val String value to set attribute with.
 * @return Return the number of characters written to string param, -1 if error.
 */
int servoSetStrAttr(enum ServoComponent servo, enum ServoAttr attr, const char* val);

/**
 * @brief Sets positive integer type attribute on the servo component.
 * @param servo The subject servo component.
 * @param attr The subject attribute.
 * @param val Unsigned integer value to set attribute with.
 * @return Return the number of characters written to string param, -1 if error.
 */
int servoSetUIntAttr(enum ServoComponent servo, enum ServoAttr attr, size_t val);

/**
 * @brief Sets integer type attribute on the servo component.
 * @param servo The subject servo component.
 * @param attr The subject attribute.
 * @param val Int value to set attribute with.
 * @return Return the number of characters written to string param, -1 if error.
 */
int servoSetIntAttr(enum ServoComponent servo, enum ServoAttr attr, int val);

/**
 * @brief Sets command attribute for the servo component.
 * @param servo The subject servo component.
 * @param command String value to set attribute with.
 * @return Return the number of characters written to string param, -1 if error.
 */
int servoSetCommand(enum ServoComponent servo, enum ServoCommand command);

/**
 * @brief Sets speed attribute (tacho counts per second) for the servo component.
 * @param servo The subject servo component.
 * @param val Positive integer between 0 and 1560 value to set attribute with.
 * @return Return the number of characters written to string param, -1 if error.
 */
int servoSetSpeed(enum ServoComponent servo, size_t val);

/**
 * @brief Sets duty cycle (speed for run direct command) attribute for the servo component. 
 * @param servo The subject servo component.
 * @param val Positive integer value between -100 and 100 to set attribute with.
 * @return Return the number of characters written to string param, -1 if error.
 */
int servoSetDutyCycle(enum ServoComponent servo, int val);

/**
 * @brief Sets polarity (direction that motor turns) attribute for the servo component. 
 * @param servo The subject servo component.
 * @param val String value either inversed or normal.
 * @return Return the number of characters written to string param, -1 if error.
 */
int servoSetPolarity(enum ServoComponent servo, enum ServoPolarity polarity);

/**
 * @brief Sets position (target for run-to-abs-pos and run-to-rel-pos) attribute for the servo component. 
 * @param servo The subject servo component.
 * @param val Positive integer to set attribute with.
 * @return Return the number of characters written to string param, -1 if error.
 */
int servoSetPosition(enum ServoComponent servo, size_t val);

/**
 * @brief Sets ramp down (the time in milliseconds motor from 100% to 0%) attribute for the servo component. 
 * @param servo The subject servo component.
 * @param val Positive integer to set attribute with.
 * @return Return the number of characters written to string param, -1 if error.
 */
int servoSetRampDown(enum ServoComponent servo, size_t val);

/**
 * @brief Sets ramp up (the time in milliseconds motor from 0% to 100%) attribute for the servo component. 
 * @param servo The subject servo component.
 * @param val Positive integer to set attribute with.
 * @return Return the number of characters written to string param, -1 if error.
 */
int servoSetRampUp(enum ServoComponent servo, size_t val);

/**
 * @brief Sets braking behavior attribute for the servo component. 
 * @param servo The subject servo component.
 * @param action String value (either coast, brake, or hold) to set attribute with.
 * @return Return the number of characters written to string param, -1 if error.
 */
int servoSetStopAction(enum ServoComponent servo, enum ServoStopAction action);

/**
 * @brief Sets time motor will run in milliseconds for the servo component. 
 * @param servo The subject servo component.
 * @param val Positive integer value to set attribute with.
 * @return Return the number of characters written to string param, -1 if error.
 */
int servoSetTime(enum ServoComponent servo, size_t val);