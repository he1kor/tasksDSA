#pragma once

#include <functional>
#include <iostream>


class Input {
public:
    template<class className>
    ///\__EXIT__ output for input EXITCommand
    static std::string loopQuestion(const std::string& question, bool (className::*predicate)(const std::string&),className& object,const std::string& EXITCommand) {
        std::string answer;
        while (true) {
            std::cin >> answer;
            if (answer == "0") return "__EXIT__";
            if ((object.*predicate)(answer)) return answer;
            std::cout << "Wrong answer!\n";
        }
    }
};


