SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -fprofile-arcs -ftest-coverage -fPIC -O0")
FIND_PACKAGE(GTest REQUIRED)
INCLUDE_DIRECTORIES("${GTEST_INCLUDE_DIRS}")

FIND_PACKAGE(Threads REQUIRED)

ADD_DEFINITIONS(-D_TESTING)

INCLUDE_DIRECTORIES(test/include include)

ADD_EXECUTABLE(tests test/src/main.cpp test/src/utils.cpp test/src/base_tests.cpp test/src/moc.cpp src/utils.c)

TARGET_LINK_LIBRARIES(tests ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

ADD_TEST(
        NAME BASE_TESTS
        COMMAND tests ${CMAKE_SOURCE_DIR}
)
