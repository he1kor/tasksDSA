#pragma once
namespace task1_1
{
    class Main
    {
        public:
            Main() = default;

            int run();

        private:
            int createBitMaskWithTrueIndex(int index);

            int createBitMaskWithTrueIndexes(int *indexes, int size);

            void printBits(int value);
    };

}
