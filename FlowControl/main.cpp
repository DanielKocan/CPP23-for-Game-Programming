#include <iostream>

int main()
{
	if (true)
	{
		std::cout << "this is true." << std::endl;
	}

	std::cout << "The code will continue here..." << std::endl;

	if (false)
	{
		std::cout << " The condition is true" << std::endl;
	}
	else
	{
		std::cout << " The condition is false " << std::endl;
	}

	int i = 10;

	// nest conditions
	if (i < 5)
	{
		std::cout << "The number is less than 5." << std::endl;
	}
	else if (i < 8)
	{
		std::cout << " The number is less than 8" << std::endl;
	}
	else if (i >= 10)
	{
		std::cout << " The number is greater than or equal to 10." << std::endl;
	}
	else
	{
		std::cout << "The number is between 5 and 7" << std::endl;
	}

	switch (i)
	{
	case 0 :
		std::cout << "you fail!" << std::endl;
		break;
	case 1:
		std::cout << "you almost failed!" << std::endl;
		break;
	case 10:
		std::cout << "Excellent!" << std::endl;
		break;
	default:
		std::cout << "your grade was: " << i << std::endl;
		break;//dont need it if its last but alwasys nice to ahve it
	}

	// while loops
	i = 0;
	while (i < 10)
	{
		std::cout << "i: " << i << std::endl;
		++i;
	}

	// do while loops
	i = 0;
	do
	{
		std::cout << "i: " << i << std::endl;
		++i;
	} while (i < 10);

	// For loops
	for (int j = 0; j < 10; j++)
	{
		std::cout << "j: " << j << std::endl;
		//break // breaks any loop above it (if you have two loops it will break the only one loop) works in do while and while also
	}

	// j = 0; //j is out of scope (so dosent exist outside of loop

	int arr[] = { 1,2,3,4,5 };
	// Range-based For Loops
	// c++20 adds initialize (int i = 0;)
	for (int i = 0; int v : arr)
	{
		std::cout << "v[" << i << "]: "<< v << std::endl;
		++i;
	}

	return 0;
}