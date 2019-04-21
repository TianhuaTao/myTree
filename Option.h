//
// Created by Sam on 2018/6/8.
//

#ifndef MYTREE17_OPTION_H
#define MYTREE17_OPTION_H


#include <cstddef>
#include <string>
#include <vector>
#include <ostream>
#include <dirent.h>

/**
 * 一个Option类是一个负责参数解析的类。
 * 接受命令行参数并得到对应属性
 */


class Option {
public:
    Option(int argc, char *argv[]);

    Option(const Option &opt);

    static void showUsage();

    static void showVersion();

    static void issueError(std::string errMsg);

    std::vector<std::string> getDirectories() {
        return directories;
    }

    size_t getLevel() const {
        return level;
    }

    bool isGreenDir() const {
        return greenDir;
    }

    std::string getOutFilename() const {
        return outFilename;
    }

    bool isDirOnly() const {
        return dirOnly;
    }

    bool check(dirent *file_dirent);

private:
    bool greenDir = false;
    bool dirOnly = false;
    std::vector<std::string> directories;
    std::string findFilename;
    std::string outFilename;
    size_t level = static_cast<size_t >(-1);   // expand all levels

};


#endif //MYTREE17_OPTION_H
