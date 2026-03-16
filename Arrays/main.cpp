#include <iostream>

int main()
{
	int values[5]{}; //initialized all values by zero

	for (int i = 0; i < std::size(values); ++i)
	{
		std::cout << "values [" << i << "]: " << values[i] << std::endl;
	}

	int* pvalues = new int[10];
	memset(pvalues, 0, sizeof(int) * 10); //  "starting at pvalues, write the byte 0x00 into every byte, for the next 40 bytes" (assuming int is 4 bytes -> 4 * 10 = 40).

	// for (int i = 0; i < std::size(pvalues); ++i) // dosent work because we have now dynamic array and it basically means that compiler cant detect at run time the size of the array
	for (int i = 0; i < 10; ++i)
	{
		pvalues[i] = i;
		std::cout << "values [" << i << "]: " << pvalues[i] << std::endl;
	}

	int values2d[][3]
	{
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8},
		{9, 10, 11}
	};

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; ++j)
		{
			int idx = i * 3 + j;
			std::cout << "Value2d[" << i << "][" << j << "]: " << values2d[i][j] << " idx: "<< idx << std::endl;
		}
	}

	int* pvalues2d = &values2d[0][0]; //acesing the firs elemnt

	for (int i = 0; i < 12; i++)
	{
		std::cout << "Values: " << *pvalues << "at index " << i;
		pvalues++;
	}

	return 0;
}