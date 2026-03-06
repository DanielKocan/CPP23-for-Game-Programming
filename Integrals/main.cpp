#include <iostream>

int main()
{
	int min_int = -2147483647;
	int max_int = 2147483647;

	// unsigned int max_uint = 4'294'967'295;
	unsigned int min_uint = 0u;
	//unsigned int max_uint = -1;
	unsigned int max_uint = 0xFFFFFFFF;

	std::cout << "Sizeof int: " << sizeof(int) << std::endl;
	std::cout << "Min uint (-1): " << max_uint <<  std::endl;;

	short max_short = 32767;
	short min_short = -32768;

	short max_ushort = 0xFFFF; // All bits on;

	std::cout << "sizeof short: " << sizeof(max_ushort) << std::endl;

	long max_long = 2147483647l; //certain platfomr have 64 bits
	long min_long = -2147483647;

	long long max_ll = 9223372036854775807ll;
	long long min_ll = -9223372036854775807;

	unsigned long long max_ull = 18'446'744'073'709'551'615ull;

	// --- standart interger types to be guarantee taht all size are correct

	std::int32_t i = 0; //always 32-bits
	std::uint32_t ui = 0; //always 32-bits
	std::int16_t i16 = 0; //always 16-bits
	std::int64_t i64 = 0; //always 64-bits

	std::size_t sz = 0; // 64-bites on 64bit builds, 32-bits (8byte) on 32-bit platforms

	std::cout << "sizeof size_t: " << sizeof(sz) << std::endl;

	return 0;
}