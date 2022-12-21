#include <iostream>
#include <bitset>
#include <fstream>
#include <istream>
#include "Main.h"

namespace task2_1
{
    int Main::run()
    {
        createFile("test");
        std::cout << readNumberAtIndex("test",0) << "\n";
        newEntry("test","21 5125 25 66 111");
        printFile("test");
        std::cout << readNumberAtIndex("test",5);

        return 0;
    }
    bool Main::printFile(std::string fileName)
    {
        std::ifstream file;
        file.open(fileName);

        if (!file.is_open())
        {
            return false;
        }

        int number;
        while (!file.eof()) {
            file >> number;
            std::cout << number << " ";
        }
        std::cout << "\n";
        file.close();
        return true;
    }
    void Main::createFile(std::string fileName)
    {
        std::ofstream file;
        file.open(fileName);
    }
    bool Main::newEntry(std::string fileName,std::string entry)
    {
        std::ofstream file;
        file.open(fileName);
        if (!file.good())
        {
            file.close();
            return false;
        }
        file << entry;
        return true;
    }
    int Main::readNumberAtIndex(std::string fileName,int index)
    {
        if (index < 0)
        {
            throw std::errc::argument_out_of_domain;
        }
        std::ifstream file;
        file.open(fileName);

        int number;

        for (int i = 0; i <= index; i++)
        {
            if (file.eof())
            {
                throw std::errc::argument_out_of_domain;
            }
            file >> number;
        }
        return number;
    }


}