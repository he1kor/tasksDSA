#include <system_error>
#include "Main.h"
#include "../../Util/Input.h"

namespace task1_6{
    int Main::run() {
        const int MAX_SIZE = 10000000;
        const int VALUE_RANGE_FROM =  1000000;
        const int VALUE_RANGE_UP_TO = 9999999;

        int sourceSize;
        sourceSize = Input::readRangedInt(0, MAX_SIZE);
        int *source = new int[sourceSize];
        initializeWithRangedIntInput(source, sourceSize, VALUE_RANGE_FROM, VALUE_RANGE_UP_TO);


        int byteArraySize = countRequiredBytes(VALUE_RANGE_UP_TO - VALUE_RANGE_FROM + 1);
        std::cout << byteArraySize << " ";
        char byteArray[byteArraySize];
        initializeByteArray(byteArray, byteArraySize);

        setIntsAsBitIndexes(source, sourceSize, byteArray,VALUE_RANGE_FROM);

        int result[sourceSize];
        std::cout << result[sourceSize-1];
        setBitIndexesAsInts(byteArray, byteArraySize, result,VALUE_RANGE_FROM);

        printArray(result,sourceSize);
        delete[] source;
        return 0;
    }
    void Main::printArray(int *array, int size)
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << array[i] << " ";
        }
    }

    void Main::initializeWithRangedIntInput(int *array, int size, int rangeFrom, int rangeTo) {
        for (int i = 0; i < size; i++) {
            array[i] = Input::readRangedInt(rangeFrom, rangeTo);
        }
    }

    int Main::countRequiredBytes(int bits) {
        int bytes = bits % 8 == 0 ? 0 : 1;
        bytes += bits / 8;
        return bytes;
    }

    void Main::initializeByteArray(char *byteArray, int size) {
        for (int i = 0; i < size; i++) {
            byteArray[i] = 0;
        }
    }

    void Main::setIntsAsBitIndexes(int *intArray, int intsSize, char *byteArray,int startValue) {
        for (int i = 0; i < intsSize; i++) {
            int requiredByte = (intArray[i] - startValue) / 8;
            int requiredSubBit = (intArray[i] - startValue) % 8;
            setBitTrue(&(byteArray[requiredByte]), requiredSubBit);
        }
    }

    void Main::setBitIndexesAsInts(char *byteArray, int bytesSize, int *intArray,int startValue) {
        int intArrayCursor = 0;
        for (int byteIndex = 0; byteIndex < bytesSize; byteIndex++) {
            for (int bitIndex = 0; bitIndex < 8; bitIndex++) {
                if (!isBitTrue(byteArray[byteIndex], bitIndex))
                    continue;
                intArray[intArrayCursor] = byteIndex * 8 + bitIndex + startValue;
                intArrayCursor++;
            }
        }
    }

    void Main::setBitTrue(char *value, int index) {
        *value |= createMaskWithTrueBit(index);
    }

    bool Main::isBitTrue(char value, int index) {
        return (value & createMaskWithTrueBit(index)) != 0;
    }

    int Main::createMaskWithTrueBit(int index) {
        if (index > 31 || index < 0)
            throw std::errc::argument_out_of_domain;
        int mask = 1;
        mask = mask << index;
        return mask;
    }
}
