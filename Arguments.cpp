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
