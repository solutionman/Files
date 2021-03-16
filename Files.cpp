#include "FileOperations.h"
#include "Help.h"
#include "Arguments.h"
#include <iostream>

int main(int argc, char **argv) {

    Arguments arguments(argc, argv);
    if (arguments.getArgv().count(1)) {
        auto firstArg = arguments.getArgv().find(1);
    }
    if (arguments.getArgv().count(2)) {
        auto secondArg = arguments.getArgv().find(2);
    }

    std::string fileName;
    Help::getHelp(argc, argv, fileName);
    if (argc > 1) {
        fileName = argv[1];
        Help::getHelp(argc, argv, fileName);
    }
    std::string rewrite = "r";
    std::string open = "o";
    std::string secondArg;
    if (argc > 2) {
        secondArg = argv[2];
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
        if (feedback != "y") {
            return 0;
        }
        std::cout << "Open or create new or open and change line? o/c/ch ";
        getline(std::cin, feedback);
        if (feedback == "o") {
            FileOperations::printToScreen(fileName);
            FileOperations::writeToFile(fileName);
            FileOperations::printToScreen(fileName);
            return 0;
        } else if (feedback == "ch"){
            FileOperations::printToScreen(fileName);
            FileOperations fileOperations;
            fileOperations.replaceInFile(fileName);
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
