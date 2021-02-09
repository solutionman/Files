#include "FileOperations.h"
#include "Help.h"
#include <iostream>

int main(int argc, char **argv) {

    std::cout << " You entered  " << argc << " arguments: " << std::endl;
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }
    std::string fileName;

    if (argc > 1) {
        Help::getHelp(argc, argv, fileName);
    } else {
        std::cout << "write the name of the file: ";
        getline(std::cin, fileName);
    }
    std::string rewrite = "r";
    std::string open = "o";
    std::string secondArg;
    if (argc > 2) {
        secondArg = argv[2];
        std::cout << "rewrite.compare(secondArg) " << rewrite.compare(secondArg) << std::endl;
        std::cout << "open.compare(secondArg) " << open.compare(secondArg) << std::endl;
    }
    if (FileOperations::isFileExists(fileName) && rewrite != secondArg) {
        if (open == secondArg) {
            FileOperations::printToScreen(fileName);
            FileOperations::writeToFile(fileName);
            FileOperations::printToScreen(fileName);
            return 0;
        }
        std::cout << "File " << fileName
                  << " already exists. You want rewrite it? 'y/n' ";
        std::string feedback;
        getline(std::cin, feedback);
        //        if( feedback.compare("y") != 0 ){ return 0; }
        if (feedback != "y") {
            return 0;
        }
        std::cout << "Open or create new? o/c ";
        getline(std::cin, feedback);
        if (feedback == "o") {
            FileOperations::printToScreen(fileName);
            FileOperations::writeToFile(fileName);
            FileOperations::printToScreen(fileName);
            return 0;
        }
    }

    // create and open a text file
    std::ofstream MyFile(fileName);

    // write to the file
    MyFile << "Your notes here: " << std::endl;
    FileOperations::writeToFile(fileName);

    FileOperations::printToScreen(fileName);

    return 0;
}
