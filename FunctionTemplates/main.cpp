#include <iostream>

template<typename T, typename U>
decltype(auto) max(const T& a, const U& b) //if someting is not correct the decltype will return by value
{
	return a > b ? a : b;
}

// abbreviated function templates fucntoin c++ 20, same as above
decltype(auto) max2(const auto& a, const auto& b) 
{
	return a > b ? a : b;
}

template<typename T>
void swap(T& a, T& b) 
{
	auto tmp = std::move(a); // tmp steals a's pointer (After `std::move(a)`, the pointer inside `a` is set to `nullptr` (or something equivalent).)
	// Dereferencing a `nullptr` causes a crash — a segmentation fault.
	// So this is why the rule exists — after `std::move(a)`, don't read from `a` until you assign

	a = std::move(b); // a steals b's pointer
	b = std::move(tmp); // b steals tmp's pointer
}


void swap2(auto& a, auto& b)
{
	// auto ignores references and const. it just gives variable thats why we are using move to avoid coppies
	auto tmp = std::move(a); // tmp steals a's pointer (After `std::move(a)`, the pointer inside `a` is set to `nullptr` (or something equivalent).)
	// Dereferencing a `nullptr` causes a crash — a segmentation fault.
	// So this is why the rule exists — after `std::move(a)`, don't read from `a` until you assign

	a = std::move(b); // a steals b's pointer
	b = std::move(tmp); // b steals tmp's pointer
}


int main()
{
	{
		int a = 5;
		int b = 10;

		int c = max(a, b);
		std::cout << "c: " << c << std::endl;
	}

	{
		int a = 5;
		double b = 10.0;

		auto c = max2(a, b);
		std::cout << "c: " << c << std::endl;
	}

	{
		int a = 5;
		int b = 10;
		swap(a, b);
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
	}

	return 0;
}