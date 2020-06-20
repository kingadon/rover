#include <stdio.h>
#include <string.h>
#include "rvr.h"
#include "rvr_led.h"

const size_t NUM_LEDS = 4;

const char* const led_component_path[] = {
    "leds/led0:green:brick-status",
    "leds/led0:red:brick-status",
    "leds/led1:green:brick-status",
    "leds/led1:red:brick-status"
};

const char* const led_attr_path[] = {
    "brightness",
    "delay_off",
    "delay_on",
    "max_brightness",
    "trigger"
};

int ledSetStrAttr(enum LedComponent led, enum LedAttr attr, char* val) {
    char path[MAX_PATH_BYTES];
    snprintf(path, MAX_PATH_BYTES, "/%s/%s/%s", 
             ROOT_COMPONENT_DIR, 
             led_component_path[led], 
             led_attr_path[attr]);
    rvr_write(path, val);
    return 0;
}

int ledSetIntAttr(enum LedComponent led, enum LedAttr attr, size_t val) {
    char path[MAX_PATH_BYTES];
    snprintf(path, MAX_PATH_BYTES, "/%s/%s/%s", 
             ROOT_COMPONENT_DIR, 
             led_component_path[led], 
             led_attr_path[attr]);
    rvr_write_uint(path, val);
    return 0;
}

int rvrLedOn(enum LedComponent led) {
    ledSetStrAttr(led, TRIGGER, "default-on");
    return 0;
}

int rvrLedOff(enum LedComponent led) {
    ledSetStrAttr(led, TRIGGER, "none");
    return 0;
}

int rvrLedBlink(enum LedComponent led) {
    ledSetStrAttr(led, TRIGGER, "timer");
    return 0;
}

int rvrSetLedBrightness(enum LedComponent led, size_t val) {
    ledSetIntAttr(led, BRIGHTNESS, val);
    return 0;
}