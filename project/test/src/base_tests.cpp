#include <gtest/gtest.h>
extern "C" {
#include "utils.h"
}
#include "utils.hpp"

#define MAIN_LOGIC_DIR "test1/"


TEST(BASE_TESTS, main_logic) {
    TestAssist::initTestCase(MAIN_LOGIC_DIR);

    resource_node ***const resource_store = collect_resources_data();

    if (!resource_store) {
        return;
    }

    size_t **const resource_information = get_resources_information_from_resource_store(
            (const resource_node ***) resource_store);
    if (!resource_information) {
        free_resource_store(resource_store);
        return;
    }

    print_resource_information((const size_t **) resource_information);
    free_resource_store(resource_store);
    free_resource_information(resource_information);

    ASSERT_EQ(TestAssist::compareCurrentFiles(), true);
}

TEST(BASE_TESTS, get_resources_information_from_resource_store) {
    ASSERT_EQ(get_resources_information_from_resource_store(nullptr), nullptr);
}
