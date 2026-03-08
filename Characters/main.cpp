#include <iostream>

int main()
{
	char c = 'A';
	char name[] = "Jeremiah";

	signed char sc = 'A'; // (from -127 to 127 )
	unsigned char uc = 'A'; // from 0 to 255

	wchar_t wc = L'A'; // (2 bytes, might be 4 on other platforms) 

	std::cout << "Size of wchar_t: "<< sizeof(wchar_t) << std::endl;

	char16_t c16 = u'A'; // UTF-16
	char32_t c32 = U'A'; // UTF-32

	char8_t c8 = u8'A'; 

	return 0;
}