#ifndef FILES_ARGUMENTS_H
#define FILES_ARGUMENTS_H


#include <string>
#include <vector>
#include <map>

class Arguments {
public:
    Arguments(int argc, char **argv);

    int getArgc() const;

    void setArgc(int argc);

    void setArgv(char **argv);

    std::map<int,std::string> getArgv();

private:
    int argc;
    std::map<int,std::string> argv;
};


#endif //FILES_ARGUMENTS_H
