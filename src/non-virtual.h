#ifndef NON_VIRTUAL
#define NON_VIRTUAL

#include <iostream>
#include <ranges>
#include <execution>
#include <vector>
#include <type_traits>
#include <algorithm>
#include <variant>

template<typename T, typename... Ts>
concept same_as_any = (... or std::same_as<T, Ts>);

template <typename T>
concept CFoo = requires(T foo) {
	{ foo.func() } -> std::same_as<int>;
};

struct Foo {
	[[nodiscard]] auto func() const -> int {
		return 42;
	}
};
struct Foo1 {
	[[nodiscard]] auto func() const -> int {
		return 43;
	}
};
struct Foo2 {
	[[nodiscard]] auto func() const -> int {
		return 44;
	}
};

static_assert(CFoo<Foo>);

template <CFoo... TFoos>
class Bar {
public:
	constexpr Bar(same_as_any<TFoos...> auto input_foo) : foo{ input_foo } {
	}

	constexpr auto set_foo(same_as_any<TFoos...> auto input_foo) -> void {
		foo = input_foo;
	}
private:
	std::variant<TFoos...> foo{};
};


void nonVirtualTest() {
    startTest();

    endTest();
}


#endif