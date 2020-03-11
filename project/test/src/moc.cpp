#include <moc.hpp>
#include <cstdarg>
#include <iostream>
#include "utils.hpp"

int moc_printf(const char *format, ...) {
    FILE *out_file = fopen((TestAssist::basePath + std::string(TEST_DATA_PATH) + TestAssist::currentTestDir +
                            std::string(OUTPUT_FILE)).c_str(), "a+");
    if (out_file == nullptr) {
        return -1;
    }

    va_list args;
    va_start(args, format);
    int ret_val = vfprintf(out_file, format, args);
    va_end(args);
    fclose(out_file);
    return ret_val;
}

int moc_scanf(const char *format, ...) {
    FILE *in_file = fopen((TestAssist::basePath + std::string(TEST_DATA_PATH) + TestAssist::currentTestDir +
                           std::string(INPUT_FILE)).c_str(), "r");
    if (in_file == nullptr) {
        return -1;
    }

    if (fseek(in_file, TestAssist::positionInInputFile, SEEK_SET) != 0) {
        fclose(in_file);
        return -1;
    }


    va_list args;
    va_start(args, format);
    int ret_val = vfscanf(in_file, format, args);
    va_end(args);

    if ((TestAssist::positionInInputFile = ftell(in_file)) == -1L) {
        fclose(in_file);
        return -1;
    }
    fclose(in_file);
    return ret_val;
}
