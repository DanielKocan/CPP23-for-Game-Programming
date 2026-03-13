#include <iostream>
#include <vector>

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
	/*std::cout << "Write number (to finish write 'd')" << std::endl;
	double result = 0, input;
	char op;
	std::cin >> result;

	while (std::cin.fail())
	{
		std::cout << "Write operator (to finish write 'd')" << std::endl;
		std::cin >> op;

		switch (op) {

		case '+':
			std::cin >> input;
			result = result + input;
			break;

		case '-':
			std::cin >> input;
			result = result - input;
			break;

		case '*':

			result = number * number2;
			break;

		case '/':
			result = number / number2;
			break;
		}
	}
	*/
}


int main()
{
	void SimpleCalculator();
	//void AdvancedCalculator();
}