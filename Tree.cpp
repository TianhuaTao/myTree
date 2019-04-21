//
// Created by Sam on 2018/6/8.
//
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <dirent.h>
#include <cstdlib>
#include "Tree.h"
#include "Printer.h"

using namespace std;

/**
 * Tree构造函数
 * @param directory 完整的目录
 * @param name 当前项名字
 * @param opt 选项参数
 * @param level 展开次数
 */

Tree::Tree(std::string directory, std::string name, Option &opt, int level) : option(opt), name(name), isLast(false) {

    DIR *dir_handle = opendir(directory.c_str());
    //不成功则说明不是目录
    if (dir_handle == nullptr) {
        if (level == 0) {
            option.issueError("error opening " + directory);
            exit(1);
        }
        isDir = false;
        return;
    }
    isDir = true;
    dirent *file_dirent;

    //展开最多level层
    if (level + 1 <= opt.getLevel()) {
        //以此读出本目录下所有项目
        while ((file_dirent = readdir(dir_handle)) != nullptr) {
            if (option.check(file_dirent)) {    //符合参数的
                if (file_dirent->d_type == DT_LNK) {
                    continue;
                }
                string theName = directory + "/" + file_dirent->d_name;
                entries.emplace_back(theName, file_dirent->d_name, option, level + 1);
            }
        }
    }

    //最后一个做标记
    if (!entries.empty()) {
        entries[entries.size() - 1].isLast = true;
    }

    closedir(dir_handle);

}






