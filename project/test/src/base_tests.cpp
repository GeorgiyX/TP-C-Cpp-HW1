#include <gtest/gtest.h>
#include "utils.hpp"
extern "C" {
#include "module.h"
}

#define MAIN_LOGIC_DIR "test1/"
#define ERROR_DATA_DIR "test2/"
#define BAD_DATA_DIR "test3/"

TEST(BASE_TESTS, MAIN_LOGIC) {
    TestAssist::initTestCase(MAIN_LOGIC_DIR);
    testCase();
    ASSERT_EQ(TestAssist::compareCurrentFiles(), true);
}

TEST(BASE_TESTS, MAIN_LOGIC_ERROR_INPUT_TYPE) {
    TestAssist::initTestCase(ERROR_DATA_DIR);
    testCase();
    ASSERT_EQ(TestAssist::compareCurrentFiles(), true);
}

TEST(BASE_TESTS, MAIN_LOGIC_ERROR_INPUT_BAD_DATA) {
    TestAssist::initTestCase(BAD_DATA_DIR);
    testCase();
    ASSERT_EQ(TestAssist::compareCurrentFiles(), true);
}

TEST(BASE_TESTS, GET_RESOURCES_INFORMATION_FROM_RESOURCE_STORE) {
    ASSERT_EQ(get_resources_information_from_resource_store(nullptr), nullptr);
}
