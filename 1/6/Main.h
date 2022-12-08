#pragma once
namespace task1_6 {
    class Main {
    public:
        int run();

        int createMaskWithTrueBit(int index);

        int countRequiredBytes(int bits);

        void initializeByteArray(char *byteArray, int size);

        void initializeWithRangedIntInput(int *array, int size, int rangeFrom, int rangeTo);

        void setIntsAsBitIndexes(int *intArray, int intsSize, char *byteArray,int startValue);

        void setBitTrue(char *value, int index);

        bool isBitTrue(char value, int index);

        void setBitIndexesAsInts(char *byteArray, int bytesSize, int *intArray,int startValue);

        void printArray(int *array, int size);
    };
}