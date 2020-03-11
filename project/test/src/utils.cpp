#include <fstream>
#include <sstream>
#include <cstdarg>
#include "utils.hpp"


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

void TestAssist::initTestCase(const std::string& testDir) {
    TestAssist::currentTestDir = testDir;
    TestAssist::positionInInputFile = 0;
    remove((TestAssist::basePath + std::string(TEST_DATA_PATH) + TestAssist::currentTestDir + std::string(OUTPUT_FILE)).c_str());
}

