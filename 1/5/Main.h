#pragma once
namespace task1_5
{
    class Main
    {
        public:
            Main() = default;

            int run();

        private:
            int createBitMaskWithTrueIndex(int index);

            void printBits(int value);
    };

}
