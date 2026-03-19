#include <iostream>
#include <bitset>

int main()
{
	int8_t a = 0b01010101;
	int8_t b = 0b11111111;
	uint8_t mask = 0b111; // means the last 3 bits is set, everything else is 0, so b00000111

	std::cout << "a: " << std::bitset<8>(a) << std::endl;
	std::cout << "b: " << std::bitset<8>(b) << std::endl;

	std::cout << "a & b: " << std::bitset<8>(a & b) << std::endl;
	std::cout << "~a: " << std::bitset<8>(~a) << std::endl; // flip the bits!
	std::cout << "a & ~a: " << std::bitset<8>(a & ~a) << std::endl; //inverse itself and all bits will be 0
	std::cout << "a | ~a: " << std::bitset<8>(a | ~a) << std::endl; 

	std::cout << "a: " << std::bitset<8>(a) << std::endl;
	std::cout << "b: " << std::bitset<8>(b) << std::endl;
	std::cout << "a ^ b: " << std::bitset<8>(a ^ b) << std::endl;

	std::cout << "a<<1: " << std::bitset<8>(a << 1) << std::endl; // shift all bits by 1 into left
	std::cout << "a<<8: " << std::bitset<8>(a << 8) << std::endl; // shift all bits by 8 into left
	std::cout << "a>>6: " << std::bitset<8>(a >> 6) << std::endl; // shift all bits by 6 into right

	int8_t c = 0b10000000;
	std::cout << "c: " << std::bitset<8>(c) << std::endl;
	std::cout << "c>>6: " << std::bitset<8>(c >> 6) << std::endl; // shift all bits by 6 into right but because it start with 1 it will use 0 not 1

	// common way is to mask bits to get bits u want
	std::cout << "mask (0b111) a: " << std::bitset<8>(a & mask) << std::endl;

	return 0;
}