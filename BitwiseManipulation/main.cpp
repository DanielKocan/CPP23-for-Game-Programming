#include <iostream>
#include <bitset>   // for printing binary
#include <cstdint>  // for uint8_t

int main()
{
    // uint8_t is just a number that can only go from 0 to 255 (8 bits)
    uint8_t number;
    int input; // using int first so we can check if its out of range

    std::cout << "Enter a number (0 - 255): ";
    std::cin >> input;

    while (input < 0 || input > 255)
    {
        std::cout << "Error: number must be between 0 and 255, try again: ";
        std::cin >> input;
    }

    number = input;

    int bitPos;
    std::cout << "Enter a bit position (0 - 7): ";
    std::cin >> bitPos;

    while (bitPos < 0 || bitPos > 7)
    {
        std::cout << "Error: bit position must be between 0 and 7, try again: ";
        std::cin >> bitPos;
    }

    // bitset<8> just prints the number as 8 bits, e.g. 00001010
    std::cout << "\nBinary: " << std::bitset<8>(number) << std::endl;

    // count how many bits are set by checking each one
    int setBits = 0;
    for (int i = 0; i < 8; i++)
    {
        // >> shifts the bit we want to position 0, & 1 checks if its a 1
        if ((number >> i) & 1)
            setBits++;
    }
    std::cout << "Number of bits set: " << setBits << std::endl;

    // check if the nth bit is set
    // 1 << bitPos moves a 1 to position n, then & checks if that bit is also 1 in number
    bool isSet = (number >> bitPos) & 1; // 1 in binary is just 00000001.
    if (isSet)
        std::cout << "Bit " << bitPos << " is set: true" << std::endl;
    else
        std::cout << "Bit " << bitPos << " is set: false" << std::endl;

    // set the nth bit (forces it to 1 no matter what it was)
    // | with a 1 in position n always makes that bit 1
    uint8_t afterSet = number | (1 << bitPos);
    std::cout << "\nAfter setting bit " << bitPos << ":" << std::endl;
    std::cout << "Binary: " << std::bitset<8>(afterSet) << std::endl;
    std::cout << "Decimal: " << (int)afterSet << std::endl;

    // clear the nth bit (forces it to 0)
    // ~ flips all bits so 00001000 becomes 11110111, then & clears just that bit
    uint8_t afterClear = number & ~(1 << bitPos);
    std::cout << "\nAfter clearing bit " << bitPos << ":" << std::endl;
    std::cout << "Binary: " << std::bitset<8>(afterClear) << std::endl;
    std::cout << "Decimal: " << (int)afterClear << std::endl;

    // invert the nth bit (flips it, 0 becomes 1 and 1 becomes 0)
    // ^ with a 1 in position n flips just that bit
    uint8_t afterInvert = number ^ (1 << bitPos);
    std::cout << "\nAfter inverting bit " << bitPos << ":" << std::endl;
    std::cout << "Binary: " << std::bitset<8>(afterInvert) << std::endl;
    std::cout << "Decimal: " << (int)afterInvert << std::endl;

    // left shift moves all bits left by n, zeros fill in on the right
    // cast to uint8_t to keep it at 8 bits
    uint8_t afterLeftShift = (uint8_t)(number << bitPos);
    std::cout << "\nAfter left shifting by " << bitPos << ":" << std::endl;
    std::cout << "Binary: " << std::bitset<8>(afterLeftShift) << std::endl;
    std::cout << "Decimal: " << (int)afterLeftShift << std::endl;

    // right shift moves all bits right by n, zeros fill in on the left
    uint8_t afterRightShift = number >> bitPos;
    std::cout << "\nAfter right shifting by " << bitPos << ":" << std::endl;
    std::cout << "Binary: " << std::bitset<8>(afterRightShift) << std::endl;
    std::cout << "Decimal: " << (int)afterRightShift << std::endl;

    return 0;
}