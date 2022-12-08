#include <iostream>
#include <bitset>
#include "Main.h"
#include "../../Util/Input.h"

namespace task1_5
{
    int Main::run()
    {
        std::cout << "Input 32-bit number:";
        int result = Input::readUnsignedInt();
        std::cout << "Input index of bit to set 1:";
        int index = Input::readRangedInt(0,31);

        std::cout << "Raw bits:\n";
        printBits(result);
        std::cout << "\n";

        int mask = createMaskWithTrueBit(index);

        result |= mask;

        std::cout << "Masked bits:\n";
        printBits(result);
        return 0;
    }
    int Main::createMaskWithTrueBit(int index){
        if (index > 31 || index < 0)
            throw std::errc::argument_out_of_domain;
        int mask = 1;
        mask = mask << index;
        return mask;
    }
    void Main::printBits(int value){
        std::cout << std::bitset<sizeof(value)*8> (value);
    }
}