#include <iostream>
#include <bitset>
#include "Main.h"
#include "../../Util/Input.h"

namespace task1_4
{
    int Main::run()
    {
        std::cout << "Input 32-bit number:";
        int result = Input::readUnsignedInt();

        std::cout << "Raw value bits:\n";
        printBits(result);
        std::cout << "\n";

        divideByPowerOfTwo(&result, 3);

        std::cout << "Divided value bits:\n";
        printBits(result);
        return 0;
    }
    void Main::divideByPowerOfTwo(int *value,int power)
    {
        *value >>= power;
    }

    void Main::printBits(int value)
    {
        std::cout << std::bitset<sizeof(value)*8> (value);
    }
}