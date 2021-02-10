#include "Arguments.h"

Arguments::Arguments(int argc, char **argv) {
    this->argc = argc;
}

int Arguments::getArgc() {
    return this->argc;
}
