#include "FileOperations.h"
#include <iostream>
#include <cstdio>

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

void FileOperations::replaceInFile(const std::string &fileName) {
    std::cout << "Print line to replace";
    std::string searchLine;
    getline(std::cin, searchLine);
    std::cout << "Print what to write instead";
    std::string replacement;
    getline(std::cin, replacement);

    std::string myText;
    std::ifstream currentFile(fileName);
    std::ofstream temporaryFile("tempFile.txt");
    while (getline(currentFile, myText)) {
        if(myText == searchLine){
            temporaryFile << std::endl << replacement;
        } else {
            temporaryFile << std::endl << myText;
        }
    }
    currentFile.close();
    temporaryFile.close();
    if(rename("tempFile.txt",  "test.txt") != 0 ){
        std::cout << "error in replacing in file" << std::endl;
    }
}
