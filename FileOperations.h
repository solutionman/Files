#include <iostream>
#include <fstream>


#ifndef FILES_FILEOPERATIONS_H
#define FILES_FILEOPERATIONS_H

class FileOperations {
public:
    static void writeToFile(const std::string &fileName);

    static bool isFileExists(const std::string &name);

    static void printToScreen(const std::string &fileName);

    void replaceInFile(const std::string &fileName);
};

#endif //FILES_FILEOPERATIONS_H
