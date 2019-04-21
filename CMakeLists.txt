cmake_minimum_required(VERSION 3.10)
project(myTree2)

set(CMAKE_CXX_STANDARD 17)

add_executable(myTree2 main.cpp Option.cpp Option.h Tree.cpp Tree.h Printer.cpp Printer.h)