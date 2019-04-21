cmake_minimum_required(VERSION 3.10)
project(myTree)

set(CMAKE_CXX_STANDARD 17)

add_executable(myTree main.cpp Option.cpp Option.h Tree.cpp Tree.h Printer.cpp Printer.h)
