#include <iostream>
#include <string>
#include "Option.h"
#include "Tree.h"


using namespace std;

int main(int argc, char *argv[]) {
    Option option(argc, argv);
    if (option.getDirectories().empty()) {
        Printer printer(option);
        Tree tree(".", ".", option, 0);     //使用当前工作目录
        printer.print(tree);
    } else {
        for (string &dir:option.getDirectories()) {
            Printer printer(option);
            Tree tree(dir, dir, option, 0);
            printer.print(tree);
        }
    }
    return 0;
}