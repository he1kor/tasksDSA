#include <iostream>
#include "Printer.h"

void Printer::printVector(std::vector<std::string> vector) {
    const std::vector<std::string>::size_type size = vector.size();
    for (int i = 0; i < size-1; i++)
    {
        std::cout << vector[i] + ", ";
    }
    std::cout << vector[size-1] << "\n";
}
