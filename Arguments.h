#ifndef FILES_ARGUMENTS_H
#define FILES_ARGUMENTS_H


#include <string>

class Arguments {
    public:
        Arguments(int argc, char **argv);
        int getArgc();
    private:
        int argc;
        std::string argv;
};


#endif //FILES_ARGUMENTS_H
