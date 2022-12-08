#include <iostream>
#include <bitset>
#include "Main.h"
#include "../../Util/Input.h"

namespace task1_2 {
    int Main::run()
    {
        std::cout << "Input 32-bit number: ";
        int result = Input::readUnsignedInt();

        std::cout << "Raw bits:\n";
        printBits(result);
        std::cout << "\n";

        int trueIndexes[] = {0,5,8};
        int mask = createMaskWithFalseBits(trueIndexes, std::size(trueIndexes));

        result &= mask;

        std::cout << "Masked bits:\n";
        printBits(result);
        return 0;
    }
    int Main::createMaskWithFalseBits(int *indexes, int size){
        int mask = ~0;
        for (int i = 0; i < size; i++){
            mask &= createMaskWithFalseBit(indexes[i]);
        }
        return mask;
    }
    int Main::createMaskWithFalseBit(int index){
        if (index > 31 || index < 0)
            throw std::errc::argument_out_of_domain;
        int mask = 1;
        mask = mask << index;
        return ~mask;
    }
    void Main::printBits(int value){
        std::cout << std::bitset<sizeof(value)*8> (value);
    }

}