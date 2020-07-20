cmake_minimum_required(VERSION 3.16)

project(Rover VERSION 1.0
              DESCRIPTION "Lego Mindstorm EV3 library written in C and for the ev3_dev os."
              LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(HEADERS
    rvr.h
    rvr_led
    rvr_servo)

set(SOURCES
    rvr.c
    rvr_led.c
    rvr_servo.c)

add_library(Rover STATIC ${HEADERS} ${SOURCES})