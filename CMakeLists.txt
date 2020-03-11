CMAKE_MINIMUM_REQUIRED(VERSION 3.10.2)
PROJECT(TP_C_Cpp_HW1 C)
SET(CMAKE_C_STANDARD 11)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

INCLUDE_DIRECTORIES(project/include)

ADD_EXECUTABLE(TP_C_Cpp_HW1
        project/include/module.h
        project/src/main.c
        project/src/module.c)
