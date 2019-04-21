//
// Created by Sam on 2018/6/8.
//

#ifndef MYTREE17_TREE_H
#define MYTREE17_TREE_H

#include <vector>
#include <string>
#include "Option.h"
#include "Printer.h"

class Printer;

struct Tree {


    Tree(std::string entry_name, std::string name, Option &opt, int level);

    //是否是一个目录
    bool isDir;

    //是否为一组中最后一个，为了显示时区分
    bool isLast;

    Option &option;

    //本节点的name
    std::string name;

    //表示一个目录下所有的项目
    //如果是一个文件，则为空
    std::vector<Tree> entries;
};


#endif //MYTREE17_TREE_H
