cmake_minimum_required(VERSION 3.26)
project(zad1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(zad1
        decimal_fsm.h
        float_fsm.h
        FSM.c)
