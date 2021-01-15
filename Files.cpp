#include "FileOperations.h"
#include <iostream>

int main() {
    cout << "write the name of the file: ";
    string fileName;
    getline(cin, fileName);

    if (FileOperations::isFileExists(fileName)) {
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
