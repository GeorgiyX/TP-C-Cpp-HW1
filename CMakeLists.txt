cmake_minimum_required(VERSION 3.15)
#project(TP_C_Cpp_HW1 C)
project(TP_C_Cpp_HW1)

#set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage -fPIC -O0")
#TODO(G): IF DEF TEST...
ENABLE_TESTING()
ADD_SUBDIRECTORY(project)

include_directories(project/include)

add_executable(TP_C_Cpp_HW1
        project/include/utils.h
        project/src/main.c
        project/src/utils.c)
#target_compile_options(TP_C_Cpp_HW1 PRIVATE -fprofile-arcs -ftest-coverage -fPIC -O0)
#target_link_libraries(TP_C_Cpp_HW1 gcov --coverage)