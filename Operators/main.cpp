#include <iostream>
#include <compare>

int main()
{
	{
		int a = 4;
		int b = 5;

		// basic arithmetic operators

		int c = a + b;
		c = a - b;
		c = a * b;
		c = a / b;
	}

	{
		// unary operator
		int a = 5;
		int b = -a;
		b = +a;

		uint8_t c = 5;
		auto d = +c; // integral promotion to integer!

		auto e = c + 1; // will be the wider type!
	}

	{
		for (int i = 0; i < 20; ++i)
		{
			std::cout << i << " % 10: " << (i % 10) << std::endl;
			// std::cout << i << " % 10: " << fmodf(i, 10.0) << std::endl; // does the same but with floats
		}
	}

	{
		int a = 5;
		int b = ++a; // b will be 6 (same with --) pre decriment, first give resuklt and then increment
		int c = a++; // c will be 5 (same with --) pos decrimnent, first give result then increment
	}

	{
		bool a = true;
		bool b = false;

		bool c = a || b;
		bool d = b && a; // short  circuiting rule c++ -> means b is false so a will not be evalueted
		bool e = !a;
	}

	{
		int a = 5;
		int b = 4;

		if (a < b)
		{
			std::cout << "a is less than b " << std::endl;
		}
		if (a > b)
		{
			std::cout << "a is greater than b " << std::endl;
		}
		if (a == b)
		{
			std::cout << "a is equal than b " << std::endl;
		}
	}

	// C++20 three-wat comparision operator (spaceship operator)
	{
		int a = 5;
		int b = 4;

		auto c = a <=> b;

		if (c < 0)
		{
			std::cout << "a is less than b" << std::endl;
		}
		if (c > 0)
		{
			std::cout << "a is greater than b" << std::endl;
		}
		if (c == 0)
		{
			std::cout << "a is equall to b" << std::endl;
		}
	}

	return 0;
}