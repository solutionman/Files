#include <iostream>
#include <fstream>

#ifndef FILES_HELP_H
#define FILES_HELP_H


class Help {
public:
    static void getHelp(int argc, char **argv, std::string &fileName);
};


#endif //FILES_HELP_H
