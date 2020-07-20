cmake_minimum_required(VERSION 3.16)

project(EV3 VERSION 1.0
              DESCRIPTION "Lego Mindstorm EV3 library written in C and for the ev3_dev os."
              LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()
add_subdirectory(lib/googletest)
add_subdirectory(tests)
add_subdirectory(rover)

add_executable(main main.c rover/rvr_led.c rover/rvr_servo.c rover/rvr.c)