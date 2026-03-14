#include <iostream>
#include <sstream>
#include <vector>

#define skip continue

void SimpleCalculator()
{
	double number, number2;
	double result = 0;
	char op;

	std::cout << "Write a number: ";
	std::cin >> number;
	if (std::cin.fail())
	{
		std::cout << "Not a number, please write a proper number" << std::endl;
		std::cin >> number;
	}

	std::cout << "Enter operator: ";
	std::cin >> op;
	if (op != '+' && op != '-' && op != '*' && op != '/')
	{
		std::cout << "Please enter a proper operator +, -, * or /" << std::endl;
		std::cin >> op;
	}

	std::cout << "Write a second number: ";
	std::cin >> number2;
	if (std::cin.fail())
	{
		std::cout << "Not a number, please write a proper number" << std::endl;
		std::cin >> number2;
	}

	if (op == '/' && number2 == 0)
	{
		std::cout << "ERROR: WE CANT DIVIDE BY 0";
		return;
	}

	switch (op) {
	case '+':
		result = number + number2;
		break;
	case '-':
		result = number - number2;
		break;
	case '*':
		result = number * number2;
		break;
	case '/':
		result = number / number2;
		break;
	}

	std::cout << "Result: " << result;

	return;
}

void AdvancedCalculator()
{
	std::vector<double> numbers;
	std::vector<char> symbols;

	std::string input;
	std::cout << "Write number expresion (0/9 digit) and (+,-,/,*)" << std::endl;

	std::getline(std::cin, input);

	for (size_t i = 0; i < input.length(); i++) // Get all numbers and symbols
	{
		if (input[i] == ' ') skip;

		if (input[i] >= '0' && input[i] <= '9') // add number
		{
			numbers.push_back(input[i] - '0');
		}
		else if (input[i] == '/' || input[i] == '*' || input[i] == '+' || input[i] == '-')
		{
			symbols.push_back(input[i]);
		}
	}

	for (size_t i = 0; i < symbols.size(); i++)
	{
		if (symbols[i] == '/' || symbols[i] == '*')
		{
			if (symbols[i] == '/')
			{
				numbers[i] = numbers[i] / numbers[i + 1];
				numbers.erase(numbers.begin() + i + 1); // For deleting an element at index i and shifting everything left
				symbols.erase(symbols.begin() + i);
				i--;
			}
			else
			{
				numbers[i] = numbers[i] * numbers[i + 1];
				numbers.erase(numbers.begin() + i + 1); // For deleting an element at index i and shifting everything left
				symbols.erase(symbols.begin() + i);
				i--;
			}
		}
	}

	for (size_t i = 0; i < symbols.size(); i++)
	{
		if (symbols[i] == '-')
		{
			numbers[i] = numbers[i] - numbers[i + 1];
			numbers.erase(numbers.begin() + i + 1); // For deleting an element at index i and shifting everything left
			symbols.erase(symbols.begin() + i);
			i--;
		}
		else
		{
			numbers[i] = numbers[i] + numbers[i + 1];
			numbers.erase(numbers.begin() + i + 1); // For deleting an element at index i and shifting everything left
			symbols.erase(symbols.begin() + i);
			i--;
		}
	}

	double result = numbers[0];

	std::cout << "Result : " << result << std::endl;

	return;
}


int main()
{
	//SimpleCalculator();
    AdvancedCalculator();

	return 0;
}