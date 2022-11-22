#pragma once

namespace task1_2 {

    class Main
    {
        public:
            Main() = default;

            int run();

        void printBits(int value);

        int createBitMaskWithFalseIndex(int index);

        int createBitMaskWithFalseIndexes(int *indexes, int size);
    };

}
