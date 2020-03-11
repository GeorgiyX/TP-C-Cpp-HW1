#include <gtest/gtest.h>
#include "utils.hpp"


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    if (argc < 2) {
        std::cout << "Please specify root path in arguments.." << std::endl;
        return -1;
    }
    TestAssist::basePath = argv[1];
    std::cout << "Path to data dir: " << TestAssist::basePath << std::endl;
    return RUN_ALL_TESTS();
}
