cmake_minimum_required(VERSION 4.1)
project(lab10 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab10
        src/MAIN.c
        headers/common.h
        headers/scturturs.h
        headers/shift.h)
