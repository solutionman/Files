#include "FileOperations.h"
#include <iostream>
#include <cstdio>
#include <cstring>

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
    std::cout << "Print line to replace" << std::endl;
    std::string searchLine;
    getline(std::cin, searchLine);
    std::cout << "Print what to write instead" << std::endl;
    std::string replacement;
    getline(std::cin, replacement);

    std::string myText;
    std::ifstream currentFile(fileName);
    std::ofstream temporaryFile("tempFile.txt");
    bool first = true;
    while (getline(currentFile, myText)) {
        if (myText == searchLine) {
            if (first) {
                temporaryFile << replacement;
            } else {
                temporaryFile << std::endl << replacement;
            }
        } else {
            if (first) {
                temporaryFile << myText;
            } else {
                temporaryFile << std::endl << myText;
            }
        }
        first = false;
    }
    currentFile.close();
    temporaryFile.close();
    int length = fileName.length();
    char origName[length + 1];
    strcpy(origName, fileName.c_str());
    if (rename("tempFile.txt", origName) != 0) {
        std::cout << "error in replacing in file" << std::endl;
    }
}

void FileOperations::deleteLine(const std::string &fileName) {
    std::cout << "Print line to delete" << std::endl;
    std::string searchLine;
    getline(std::cin, searchLine);
    std::string lineInFile;
    std::ifstream currentFile(fileName);
    std::ofstream tempFile("tempFile.txt");
    bool first = true;
    while (getline(currentFile, lineInFile)){
        if(lineInFile != searchLine){
            if(first){
                tempFile << lineInFile;
            } else {
                tempFile << std::endl << lineInFile;
            }
            first = false;
        }
    }
    currentFile.close();
    tempFile.close();
    char origName[fileName.length() + 1];
    strcpy(origName, fileName.c_str());
    if(rename("tempFile.txt", origName) != 0){
        std::cout << "error in deleting in file" << std::endl;
    }
}
