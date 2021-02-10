#include <iostream>
#include "Arguments.h"

Arguments::Arguments(int argc, char **argv) {
    this->argc = argc;
}

int Arguments::getArgc() const {
    return this->argc;
}

void Arguments::setArgc(int argcTo) {
    this->argc = argcTo;
}

void Arguments::setArgv(char **argv) {
//    int j = this->argc;
    for (int i = 0; i < this->argc; ++i) {
        std::cout << "argv[i] " << argv[i] << std::endl;
    }
}

