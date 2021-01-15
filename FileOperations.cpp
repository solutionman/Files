#include "FileOperations.h"
#include <iostream>

void FileOperations::writeToFile(const string &fileName) {
    cout << endl;
    cout << "write here what you want add to the file, to quit enter :q" << endl;
    // open file
    string addToFile;
    do {
        std::ofstream out;
        out.open(fileName, std::ios::app);
        getline(cin, addToFile);
        if (addToFile != ":q") {
            out << endl << addToFile;
        }
        out.close();
    } while (addToFile != ":q");
}

bool FileOperations::isFileExists(const string &name) {
    ifstream f(name.c_str());
    return f.good();
}

void FileOperations::printToScreen(const string &fileName) {

    cout << "Show what file contains? y/n ";
    string feedBack;
    getline(cin, feedBack);
    if (feedBack == "y") {
        string myText;

        // read from text file
        ifstream MyReadFile(fileName);

        // use while loop thogether with the getline() function
        // to read the file line by line
        while (getline(MyReadFile, myText)) {
            // Output the text from the file
            cout << myText << endl;
        }
        // close the file
        MyReadFile.close();
    }
}
