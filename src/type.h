#ifndef INCLUDE_GUARD_HEADER_TYPE
#define INCLUDE_GUARD_HEADER_TYPE

#include <cstring>
#include <string_view>
#include <utility>

template <typename T>
std::string_view getType() {
#ifdef __FUNCSIG__ // msvc
    std::string name{__FUNCSIG__};
    return __FUNCSIG__;
#elif defined(__GNUC__)
    std::string_view funcSignature {__PRETTY_FUNCTION__};
    const char* start  = "[T = ";
    auto tpyeStringPos = funcSignature.find(start) + strlen(start);
    auto posEnd = funcSignature.find_last_of("]");
    auto tpyeStringSize = posEnd - tpyeStringPos;

    return funcSignature.substr(tpyeStringPos, tpyeStringSize);
#else
    return __PRETTY_FUNCTION__;
#endif
}

#define getTypeString(type) getType<decltype(type)>()



void typeTest() {
    startTest(__FILE__);

    int a = 1;
    const int& c = 1;
    std::cout << getTypeString(c) << std::endl;
    
    endTest();
}


    // std::cout << "sum - " << sum_left_fold(1, -2, 3, -4, 5) << std::endl;


#endif // INCLUDE_GUARD_HEADER_TYPE
