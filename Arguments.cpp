#include <iostream>
#include "Arguments.h"

Arguments::Arguments(int argc, char **argv) {
    this->argc = argc;
    for (int i = 0; i < this->argc; ++i) {
//        std::cout << "argv[i] " << argv[i] << std::endl;
        this->argv.insert(std::pair<int,std::string>(i, argv[i]));
    }
}

int Arguments::getArgc() const {
    return this->argc;
}

void Arguments::setArgc(int argcTo) {
    this->argc = argcTo;
}

void Arguments::setArgv(char **argvs) {
    for (int i = 0; i < this->argc; ++i) {
        std::cout << "argv[i] " << argvs[i] << std::endl;
        this->argv.insert(std::pair<int,std::string>(i, argvs[i]));
    }
}

std::map<int,std::string> Arguments::getArgv(){
    return this->argv;
}

