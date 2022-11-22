#include <iostream>
#include <bitset>
#include "Main.h"

namespace task1_1
{
    int Main::run()
    {
        int result = 0x0;

        std::cout << "Raw bits:\n";
        printBits(result);
        std::cout << "\n";

        int trueIndexes[] = {0,5,8};
        int mask = createBitMaskWithTrueIndexes(trueIndexes,std::size(trueIndexes));

        result |= mask;

        std::cout << "Masked bits:\n";
        printBits(result);
        return 0;
    }
    int Main::createBitMaskWithTrueIndexes(int *indexes, int size){
        int mask = 0;
        for (int i = 0; i < size; i++){
            mask |= createBitMaskWithTrueIndex(indexes[i]);
        }
        return mask;
    }
    int Main::createBitMaskWithTrueIndex(int index){
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