#pragma once
namespace task1_1
{
    class Main
    {
        public:
            Main() = default;

            int run();

        private:
            int createMaskWithTrueBit(int index);

            int createMaskWithTrueBits(int *indexes, int size);

            void printBits(int value);
    };

}
