#ifndef FILES_ARGUMENTS_H
#define FILES_ARGUMENTS_H


#include <string>
#include <vector>

class Arguments {
    public:
        Arguments(int argc, char **argv);
        int getArgc() const;
        void setArgc(int argc);
        void setArgv(char **argv);
    private:
        int argc;
        std::vector<std::string> argv;
};


#endif //FILES_ARGUMENTS_H
