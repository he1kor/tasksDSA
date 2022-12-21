#pragma once
namespace task2_1
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

        bool tryPrintFile(std::string fileName);

        void createFile(std::string fileName);

        bool printFile(std::string fileName);

        bool newEntry(std::string fileName, std::string entry);

        int readNumberAtIndex(std::string fileName, int index);
    };

}
