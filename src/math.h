#include <vector>
#include <type_traits>

auto sum(const auto& ... args) {
    using common_type = std::common_type_t<std::remove_cvref_t<decltype(args)>...>;

    std::vector v { static_cast<common_type>(args)...};
    using return_type = typename decltype(v)::value_type;
    return_type sum{};

    for (const auto& e: v) {
        sum += e;
    }

    return sum;
}