cmake_minimum_required(VERSION 4.1)
project(lab10 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab10
        src/MAIN.c
        include/structure.h
        include/shift.h
        src/shift.c
        src/caesar.c)
