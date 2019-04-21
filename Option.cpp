//
// Created by Sam on 2018/6/8.
//
#include <string>
#include <cstdlib>
#include "Option.h"
#include "iostream"

using std::cout;
using std::endl;
using std::string;

void Option::showUsage() {
    cout << "Usage: tree [<directory list>] [-d] [-c] [-f filename] [-o filename] [-l level] [--help] [--version]\n"
            "[directory …] expand directory as root (or use cwd as root if not given)\n"
            "[-d] Print directories only\n"
            "[-c] Print directories in green\n"
            //            "[-f filename] 查找 filename 文件，并将从根目录到该文件的路径上所有目录用红色显 示，若没有找到，则正常输出\n"
            "[-o filename] Set output to file\n"
            "[-l [level]] Expand at most level times (or 1 if level not given)\n"
            "[--help] Print usage and exit\n"
            "[--version] Print version information and exit"
         << endl;
}


/**
 * 直接接受命令行参数
 * @param argc
 * @param argv
 */
Option::Option(int argc, char **argv) {
    if (argc == 1) {
        return;
    }
    if (argc > 1) {
        int i = 1;
        while (i < argc) {
            string par(argv[i]);

            if (par == "--help") {
                showUsage();
                exit(0);
            }
            if (par == "--version") {
                showVersion();
                exit(0);
            }

            if (par == "-d") {
                dirOnly = true;
            } else if (par == "-c") {
                greenDir = true;
            } else if (par == "-f") {
                //原本准备的为查找预留参数
            } else if (par == "-o") {
                i++;
                if (i < argc) {
                    outFilename = argv[i];
                    greenDir = false;
                } else {
                    issueError("illegal parameter for -o");
                    exit(1);
                }
            } else if (par == "-l") {
                if (i + 1 < argc) {
                    if (argv[i + 1][0] != '-') {
                        int l = std::atoi(argv[i + 1]);
                        if (l > 0)
                            level = l;
                        else {
                            issueError("illegal parameter for -l");
                            exit(1);
                        }
                        i++;
                    } else {
                        level = 1;
                    }
                } else {
                    level = 1;
                }
            } else {
                string d = argv[i];
                directories.push_back(d);
            }
            i++;
        }
    }
}

void Option::showVersion() {
    cout << "tree v1.0 by Sam Tao" << endl;
}

void Option::issueError(std::string errMsg) {
    cout << "error: " << errMsg << endl;
}

// unnecessary
Option::Option(const Option &opt) : greenDir(opt.greenDir),
                                    dirOnly(opt.dirOnly),
                                    directories(opt.directories),
                                    findFilename(opt.findFilename),
                                    outFilename(opt.outFilename),
                                    level(opt.level) {}


//判断是否满足参数所要求的条件
bool Option::check(dirent *file_dirent) {
    if (file_dirent->d_name[0] == '.')  //隐藏文件
        return false;
    if (dirOnly) {
        if (file_dirent->d_type != DT_DIR)
            return false;
    }
    return true;
}
