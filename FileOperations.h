#include <iostream>
#include <fstream>
using namespace std;

#ifndef FILES_FILEOPERATIONS_H
#define FILES_FILEOPERATIONS_H

class FileOperations
{
    public:
        static void writeToFile(const string& fileName);
        static bool isFileExists(const string& name);
        void printToScreen(string fileName);
};

#endif //FILES_FILEOPERATIONS_H
