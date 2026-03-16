#include <iostream>

int main()
{
	int i = 3;
	const char* name = "Jeremiah"; // the first letter of the name, THAT WHY IT HAS TO BE CONST

	int* pi = nullptr; //&i
	pi = &i;
	if (pi != nullptr)
	{
		*pi = 3;
	}

	std::cout << "Address of i: " << pi << std::endl;
	std::cout << "Number of i: " << *pi << std::endl;

	*pi = 4;

	std::cout << "Number of i: " << *pi << std::endl;

	if (*pi == i)
	{
		std::cout << "The values are both " << i << std::endl;
	}

	std::cout << "The first letter is: " << *name << std::endl;
	std::cout << "The first letter is: " << name[0] << std::endl;

	// -------

	const char* const lastName = "van Oosten";
	//lastName = name; // cant do it!

	// -------

	const int values[] = { 1,2,3,4 };
	std::cout << *(values + 1) << std::endl; // increaments by bytes (by type)

	// -------

	int* arr = new int[100]; // allocate memory 4 bytes * 100;

	*(arr + 0) = 0; //same
	arr[0] = 0; // same

	arr[99] = 99;

	delete[] arr;

	// -------

	int& ri = i; // must be initialized when created!  Refernce its like another name for the variable
	ri = i; // This will only set the value of i.
	ri = 5;
	std::cout << "Value of i: " << i << std::endl;

	return 0;
}