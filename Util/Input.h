#pragma once

#include <functional>
#include <iostream>
#include <limits>

class Input {
public:
    template<class className>
    ///\__EXIT__ output for input EXITCommand
    static std::string loopQuestion(bool (className::*predicate)(const std::string&),className& object,const std::string& EXITCommand) {
        std::string answer;
        while (true) {
            std::cin >> answer;
            if (answer == "0") return "__EXIT__";
            if ((object.*predicate)(answer)) return answer;
            std::cout << "Wrong answer!\n";
        }
    }
    static unsigned int readUnsignedInt(){
        std::cin.unsetf(std::ios::dec);
        std::cin.unsetf(std::ios::hex);
        std::cin.unsetf(std::ios::oct);
        unsigned int answer;
        while (true)
        {
            std::cin >> answer;
            if (std::cin.good())
                return answer;
            std::cout << "Not integer!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    static int readRangedInt(int from, int to){
        std::cin.unsetf(std::ios::dec);
        std::cin.unsetf(std::ios::hex);
        std::cin.unsetf(std::ios::oct);
        int answer;
        while (true)
        {
            std::cin >> answer;
            if (!std::cin.good())
            {
                std::cout << "Not integer!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            if (answer < from || to < answer){
                std::cout << "Not in range!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            return answer;
        }
    }
};
