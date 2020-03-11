CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
PROJECT(TP_C_Cpp_HW1 C)
SET(CMAKE_C_STANDARD 11)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
#SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage -fPIC -O0")
#ADD_SUBDIRECTORY(project)

INCLUDE_DIRECTORIES(project/include)

ADD_EXECUTABLE(TP_C_Cpp_HW1
        project/include/module.h
        project/src/main.c
        project/src/module.c)
#target_compile_options(TP_C_Cpp_HW1 PRIVATE -fprofile-arcs -ftest-coverage -fPIC -O0)
#target_link_libraries(TP_C_Cpp_HW1 gcov --coverage)