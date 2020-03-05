cmake_minimum_required(VERSION 3.15)
project(TP_C_Cpp_HW1 C)

set(CMAKE_C_STANDARD 11)

include_directories(project/include)

add_executable(TP_C_Cpp_HW1
        project/include/utils.h
        project/src/main.c
        project/src/utils.c)
