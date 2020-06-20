/**
 * @file rvr_led.h
 * @author Kingston A Huynh
 * @date June 17 2020
 * @brief File contains functions and values related to LED components.
 */

/** Put global constants here. */
/** @brief Number of led components. */
extern const size_t NUM_LEDS;

/** @brief LED components. Use these to access paths. */
enum LedComponent {
    LED0_GREEN,
    LED0_RED,
    LED1_GREEN,
    LED1_RED
};

/** @brief LED attributes in alpha order. Use these to access attributes. */
enum LedAttr {
    BRIGHTNESS,
    DELAY_OFF,
    DELAY_ON,
    MAX_BRIGHTNESS,
    TRIGGER
};
/** End global constants. */

/**
 * @brief Builds path to specified led component using root dir and led dir paths.
 * @param path Pointer to string variable to hold built path.
 * @param led The subject led component.
 * @return Return the number of characters written to string param, -1 if error.
 */
int ledPath(char* path, enum LedComponent led);

/**
 * @brief Builds path to specified led component attr.
 * @param path Pointer to string variable to hold built path.
 * @param led The subject led component.
 * @param attr The subject attribute.
 * @return Return the number of characters written to string param, -1 if error.
 */
int ledAttrPath(char* path, enum LedComponent led, enum LedAttr attr);

/**
 * @brief Sets string type attribute on the led component.
 * @param led The subject led component.
 * @param attr The subject attribute.
 * @param val String value to set attribute with.
 * @return Return the number of characters written to string param, -1 if error.
 */
int ledSetStrAttr(enum LedComponent led, enum LedAttr attr, char* val);

/**
 * @brief Sets int type attribute on the led component.
 * @param led The subject led component.
 * @param attr The subject attribute.
 * @param val Int value to set attribute with.
 * @return Return the number of characters written to string param, -1 if error.
 */
int ledSetIntAttr(enum LedComponent led, enum LedAttr attr, size_t val);

/**
 * @brief Turns specified led component on solid
 * @param led The subject led component.
 * @return Return the number of characters written to string param, -1 if error.
 */
extern int rvrLedOn(enum LedComponent led);

/**
 * @brief Turns specified led component off
 * @param led The subject led component.
 * @return Return the number of characters written to string param, -1 if error.
 */
extern int rvrLedOff(enum LedComponent led);

/**
 * @brief Turns the led off and on with default delay times.
 * @param led The subject led component.
 * @return Return the number of characters written to string param, -1 if error.
 */
extern int rvrLedBlink(enum LedComponent led);

/**
 * @brief Sets brightness attribute of led component.
 * @param led The subject led component.
 * @param val Value to set brightness from 0 to 255; 
 * @return Return the number of characters written to string param, -1 if error.
 */
extern int rvrSetLedBrightness(enum LedComponent led, size_t val);

