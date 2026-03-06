#include <iostream>

int main()
{
	float min_f = -3.4e38f; // flaot by default is 32 bits (4byte) value! min is 3.4 * 10 ^ 38
	float max_f = +3.4e38f; 

	double min_d = -1.79e308; // (8byte) 
	double max_d = +1.79e308;

	long double min_ld = -1.79e308; // on windows is the same  
	long double max_ld = +1.79e308;


	std::cout << sizeof(min_f);

	return 0;
}