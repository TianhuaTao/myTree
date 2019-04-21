//
// Created by Sam on 2018/6/8.
//
#include <dirent.h>
#include <iostream>
#include "Printer.h"
#include "Option.h"

#define GREEN "\e[1;32m"
#define NONE  "\e[0m"


using namespace std;

Printer::Printer(Option &opt) : option(opt) {}


/**
 * 使用了Unicode字符
 * @param tree
 */
void Printer::print(Tree &tree) {
    if (option.getOutFilename() == "") {        // using cout
        if (!didInit) {
            didInit = true;
            cout << tree.name << endl;
        }
        for (auto it = tree.entries.begin(); it != tree.entries.end(); it++) {
            cout << prefix;

            //目录用绿色显示
            string color;
            if (option.isGreenDir()) {
                if (it->isDir) {
                    color = GREEN;
                } else {
                    color = NONE;
                }
            }

            //判断是不是一组的最后一个，对应字符有不同
            if (it->isLast) {
                cout << "\u2514\u2500\u2500 " << color << it->name << NONE << endl;     // └──
            } else {
                cout << "\u251c\u2500\u2500 " << color << it->name << NONE << endl;     // ├──
            }
            if (it->isDir) {
                if (it->isLast) {
                    prefix += "    ";
                    print(*it);
                    prefix.erase(prefix.length() - 4, prefix.length());
                } else {
                    prefix += "\u2502   ";
                    print(*it);
                    prefix.erase(prefix.length() - 6, prefix.length());
                }
            }
        }
    } else {
        //首次需要初始化输出流
        if (!didInit) {
            ofs.open(option.getOutFilename());
            didInit = true;
            ofs << tree.name << endl;
        }
        for (auto it = tree.entries.begin(); it != tree.entries.end(); it++) {
            ofs << prefix;
            if (it->isLast) {
                ofs << "\u2514\u2500\u2500 " << it->name << endl;
            } else {
                ofs << "\u251c\u2500\u2500 " << it->name << endl;

            }
            if (it->isDir) {
                if (it->isLast) {
                    prefix += "    ";
                    print(*it);
                    prefix.erase(prefix.length() - 4, prefix.length());
                } else {
                    prefix += "\u2502   ";
                    print(*it);
                    prefix.erase(prefix.length() - 6, prefix.length());
                }
            }
        }

    }
}
