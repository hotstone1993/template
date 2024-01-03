module;

#include <cstring>
#include <string_view>
#include <utility>

export module Type;

export template <typename T>
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

export template <typename T>
constexpr std::string_view getOriginalTypeString(T&& type) {
    return getType<std::remove_cvref_t<T>>();
}