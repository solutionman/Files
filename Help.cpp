#include <iostream>
#include "Help.h"

void Help::getHelp(int argc, char **argv, std::string &fileName) {
    if (argc > 1) {
        fileName = argv[1];
        if (fileName == "-h" || fileName == "--h" || fileName == "-help" || fileName == "--help") {
            std::cout << "if file in current folder just type name of file with extension:\n"
                         "./out\n"
                         "test.txt\n"
                         "\n"
                         "out.exe\n"
                         "test.txt\n"
                         "\n"
                         "if file in another directory, then name of file and path to file:\n"
                         "./out\n"
                         "write the name of the file: /home/dima/Documents/test.txt\n"
                         "\n"
                         "program can take optional arguments: nameOfFile and r\n"
                         "for example this command will create or open file test.txt\n"
                         "./out test.txt\n"
                         "and this command will create and replace current file (if it already exists) test.txt\n"
                         "./out test.txt r" << std::endl;
            std::exit(0);
        }
    }
}
