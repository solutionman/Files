#include <iostream>
#include "Help.h"

void Help::getHelp(int argc, char **argv, std::string &fileName) {
    if (argc == 1 || (fileName == "-h" || fileName == "--h" || fileName == "-help" || fileName == "--help") ) {
//        fileName = argv[1];
        std::cout << "usage: \n"
                     "type name of file with extension, for example: test.txt\n"
                     "if file in another directory, then name of file and path to file:\n"
                     "for example: /home/dima/Documents/test.txt\n"
                     "program can take optional arguments: r or o\n"
                     "for example this command will create and replace current file (if it already exists) test.txt\n"
                     "./out test.txt r\n"
                     "and this command will open current file test.txt for editing\n"
                     "./out test.txt o" << std::endl;
        std::exit(0);
    }
}
