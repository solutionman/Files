#include "FileOperations.h"
#include <iostream>

int main(int argc, char **argv) {

    cout << " You entered  " << argc << " arguments: " << endl;
    for (int i = 0; i < argc; i++) {
        cout << argv[i] << endl;
    }
    string fileName;
    if (argc > 1) {
        fileName = argv[1];
        if (fileName == "-h" || fileName == "--h" || fileName == "-help" || fileName == "--help") {
            cout << "if file in current folder just type name of file with extension:\n"
                    "./out\n"
                    "test.txt\n"
                    "\n"
                    "out.exe\n"
                    "test.txt\n"
                    "\n"
                    "if file in another directory, then name of file and path to file:\n"
                    "./out\n"
                    "write the name of the file: /home/dima/Documents/test.txt\n"
                    "\n"
                    "program can take optional arguments: nameOfFile and r\n"
                    "for example this command will create or open file test.txt\n"
                    "./out test.txt\n"
                    "and this command will create and replace current file (if it already exists) test.txt\n"
                    "./out test.txt r" << endl;
            return 0;
        }
    } else {
        cout << "write the name of the file: ";
        getline(cin, fileName);
    }
    string rewrite = "r";
    string doRewrite;
    if (argc > 2) {
        doRewrite = argv[2];
        cout << "rewrite.compare(doRewrite) " << rewrite.compare(doRewrite) << endl;
    }
    if (FileOperations::isFileExists(fileName) && rewrite != doRewrite) {
        cout << "File " << fileName
             << " already exists. You want rewrite it? 'y/n' ";
        string feedback;
        getline(cin, feedback);
        //        if( feedback.compare("y") != 0 ){ return 0; }
        if (feedback != "y") {
            return 0;
        }
        cout << "Open or create new? o/c ";
        getline(cin, feedback);
        if (feedback == "o") {
            FileOperations::printToScreen(fileName);
            FileOperations::writeToFile(fileName);
            FileOperations::printToScreen(fileName);
            return 0;
        }
    }

    // create and open a text file
    ofstream MyFile(fileName);

    // write to the file
    MyFile << "Your notes here: " << endl;
    FileOperations::writeToFile(fileName);

    FileOperations::printToScreen(fileName);

    return 0;
}
