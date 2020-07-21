cmake_minimum_required(VERSION 3.16)

project(RoverTests VERSION 1.0
              DESCRIPTION "Lego Mindstorm EV3 library written in C and for the ev3_dev os."
              LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(SOURCES
    testrvr.cpp
)

add_executable(RoverTests ${SOURCES})

link_directories(${EV3}/Rover)
target_link_libraries(RoverTests PUBLIC
                      gtest_main
                      Rover)