#include <fstream>
#include <sstream>
#include <cstdarg>
#include "utils.hpp"

extern "C" {
#include "module.h"
}


std::string TestAssist::basePath;
std::string TestAssist::currentTestDir;
long TestAssist::positionInInputFile;


std::string TestAssist::getStringFromFile(const std::string &path) {
    if (!path.length()) {
        throw "Null path";
    }
    std::ifstream file(path);
    if (!file.is_open()) {
        throw "File not exists";
    }
    std::stringstream stringStream;
    stringStream << file.rdbuf();
    return stringStream.str();
}

bool TestAssist::compareCurrentFiles() {
    return getStringFromFile(TestAssist::basePath + std::string(TEST_DATA_PATH) + TestAssist::currentTestDir +
                             std::string(TRUE_OUTPUT_FILE)) == getStringFromFile(
            TestAssist::basePath + std::string(TEST_DATA_PATH) + TestAssist::currentTestDir + std::string(OUTPUT_FILE));
}

void TestAssist::initTestCase(const std::string &testDir) {
    TestAssist::currentTestDir = testDir;
    TestAssist::positionInInputFile = 0;
    remove((TestAssist::basePath + std::string(TEST_DATA_PATH) + TestAssist::currentTestDir +
            std::string(OUTPUT_FILE)).c_str());
}

void testCase() {
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

}
