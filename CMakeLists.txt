cmake_minimum_required(VERSION 3.23)
project(tasksDSA)

set(CMAKE_CXX_STANDARD 23)


add_executable(tasksDSA main.cpp 1/Main.cpp 1/Main.h 2/Main.cpp 2/Main.h TaskSelector.cpp TaskSelector.h Printer.cpp Printer.h Util/Input.h)
