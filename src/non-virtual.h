#ifndef NON_VIRTUAL
#define NON_VIRTUAL

#include <iostream>
#include <ranges>
#include <execution>
#include <vector>
#include <type_traits>
#include <algorithm>
#include <variant>

////////////////////////////////////////////////////////////////////////////////////////////////
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

    [[nodiscard]] auto func() const -> int {
		return std::visit([](auto& obj) -> auto { return obj.func(); }, foo);
    }
private:
	std::variant<TFoos...> foo{};
};
//////////////////////////////////////////////////////////////////////////////////////////////////

// Overload pattern
template<typename... Ls>
struct Overload : Ls... {
	using Ls::operator()...;
};

// Class Template Argument Deduction (CTAD)
template<typename... Ls> Overload(Ls...) -> Overload<Ls...>;

auto ol = Overload{
	[](int x) { return x * x; },
	[](double x) { return x + 0.5; },
	[](const std::string& s) { return s.size(); }
};

//////////////////////////////////////////////////////////////////////////////////////////////////


void nonVirtualTest() {
    startTest();

    Foo f0;
    Foo1 f1;
    Foo2 f2;

    Bar<Foo, Foo1, Foo2> b{f0};
	std::cout << b.func() << std::endl;
    b.set_foo(f1);
	std::cout << b.func() << std::endl;
    b.set_foo(f2);
	std::cout << b.func() << std::endl;
	
	int x1 = 2;
	double x2 = 2.0;
	std::string s{"Hello"};

	std::cout << ol(x1) << std::endl;
	std::cout << ol(x2) << std::endl;
	std::cout << ol(s) << std::endl;

    endTest();
}



#endif