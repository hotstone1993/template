#ifndef TEST_UTILS
#define TEST_UTILS

#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>

std::string toUpper(std::string_view sv) {
    std::string target(sv.begin(), sv.end());
    std::transform(target.begin(), target.end(), target.begin(), 
                   [](unsigned char c) { return std::toupper(c); });
    return target;
}


void startTest() {
    std::string_view fileName{__FILE__};
    int startIndex = fileName.find_last_of("/");
    int endIndex = fileName.find_last_of(".");
    std::string_view testName = fileName.substr(startIndex + 1, endIndex - startIndex - 1);

    std::cout << "====================================" << std::endl;
    std::cout << "NAME: "<< toUpper(testName) << std::endl;
}


void endTest() {
    std::cout << "\n====================================" << std::endl;
}

#endif // TEST_UTILS