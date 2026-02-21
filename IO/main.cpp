#include <iostream>
#include <string>
#include <limits>

#include "Advanced.h"

int main()
{
	PrintAdvancedTask6();

	int age;
	std::string name;

	std::cout << "What is your name?" << std::endl;
	std::cin >> name;

	std::cout << "What is your age?" << std::endl;
	std::cin >> age;

	if (age < 0)
	{
		
		std::cout << "ERROR: Age must be positive!" << std::endl;
		std::cin.setstate(std::ios::failbit); // forces cin to fail (Manually forces cin to fail - thanks chatgpt for showing this function!)
	}

	while (std::cin.fail()) // is a way to check if the previous input operation failed
	{
		std::cout << "ERROR: Expected a proper age number" << std::endl;
		std::cin.clear(); // Resets the fail state of the stream so that `std::cin` can work again. Does not remove the invalid input from the buffer. !!
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> age;

		if (age < 0) // check again
		{
			std::cout << "ERROR: Age must be positive!" << std::endl;
			std::cin.setstate(std::ios::failbit);
		}
	}

	std::cout << "Hello, " << name;
	std::cout << ". You are " << age << " years old. " << std::endl;

	// Code to not close the window
	std::cout << "Press any key to continue" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();

	return 0;
}