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
            std::cout << "\"" << answer << "\"";
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
};
