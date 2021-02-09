#include "FileOperations.h"
#include <iostream>

void FileOperations::writeToFile(const std::string &fileName) {
    std::cout << std::endl;
    std::cout << "write here what you want add to the file, to quit enter :q" << std::endl;
    // open file
    std::string addToFile;
    do {
        std::ofstream out;
        out.open(fileName, std::ios::app);
        getline(std::cin, addToFile);
        if (addToFile != ":q") {
            out << std::endl << addToFile;
        }
        out.close();
    } while (addToFile != ":q");
}

bool FileOperations::isFileExists(const std::string &name) {
    std::ifstream f(name.c_str());
    return f.good();
}

void FileOperations::printToScreen(const std::string &fileName) {

    std::cout << "Show what file contains? y/n ";
    std::string feedBack;
    getline(std::cin, feedBack);
    if (feedBack == "y") {
        std::string myText;

        // read from text file
        std::ifstream MyReadFile(fileName);

        // use while loop thogether with the getline() function
        // to read the file line by line
        while (getline(MyReadFile, myText)) {
            // Output the text from the file
            std::cout << myText << std::endl;
        }
        // close the file
        MyReadFile.close();
    }
}
