//
// Created by Sam on 2018/6/8.
//

#ifndef MYTREE17_PRINTER_H
#define MYTREE17_PRINTER_H


#include <cstddef>
#include <string>
#include <fstream>
#include "Option.h"
#include "Tree.h"

struct Tree;

class Printer {
public:
    Printer(Option &opt);

    void print(Tree &tree);


private:
    Option &option;
    std::string prefix;
    std::ofstream ofs;
    bool didInit = false;
};


#endif //MYTREE17_PRINTER_H
