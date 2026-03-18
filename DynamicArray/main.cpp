#include <iostream>
#include <limits>

int main()
{
	int arraySize;
	double average = 0;
	int maxValue = std::numeric_limits<int>::min();
	int minValue = std::numeric_limits<int>::max();

	std::cout << "Enter the size of the dynamic array (less or equal than 10 and not 0): " << std::endl;
	std::cin >> arraySize;

	if (std::cin.fail() || arraySize <= 0 || arraySize > 10)
	{
		std::cout << "ERROR, WRONG INPUT! ";
		return 0;
	}

	int* array = new int[arraySize];
	// new int[10]{}			  // Array of 10 ints (zero-initialized)
	// new int(10) or new int{10} // Single int with value 10

	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Enter value in [" << i << "] array: " << std::endl;
		std::cin >> array[i];

		if (array[i] < minValue) minValue = array[i];
		if (array[i] > maxValue) maxValue = array[i];

		average += array[i];
	}

	std::cout << "Average: " << average / static_cast<double>(arraySize) << std::endl;
	std::cout << "Highest: " << maxValue << std::endl;
	std::cout << "Lowest: " << minValue << std::endl;

	delete[] array;

	return 0;
}