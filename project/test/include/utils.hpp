#ifndef TP_C_CPP_HW1_UTILS_HPP
#define TP_C_CPP_HW1_UTILS_HPP

#include <string>
#define TEST_DATA_PATH "/project/test/test_data/"
#define INPUT_FILE "INPUT.txt"
#define OUTPUT_FILE "OUTPUT.txt"
#define TRUE_OUTPUT_FILE "TRUE_OUTPUT.txt"

struct TestAssist {
    TestAssist() = delete;
    static std::string basePath;
    static std::string currentTestDir;
    static long positionInInputFile;
    static void initTestCase(const std::string& testDir);
    static bool compareCurrentFiles();
private:
    static std::string getStringFromFile(const std::string& path);
};

#endif //TP_C_CPP_HW1_UTILS_HPP
