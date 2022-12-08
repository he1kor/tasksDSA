#pragma once

namespace task1_2 {

    class Main
    {
        public:
            Main() = default;

            int run();

        void printBits(int value);

        int createMaskWithFalseBit(int index);

        int createMaskWithFalseBits(int *indexes, int size);
    };

}
