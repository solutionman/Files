#include "FileOperations.h"
#include "Help.h"
#include "Arguments.h"
#include <iostream>

int main(int argc, char **argv) {

//    std::cout << " You entered  " << argc << " arguments: " << std::endl;
//    for (int i = 0; i < argc; i++) {
//        std::cout << argv[i] << std::endl;
//    }
    Arguments arguments(argc, argv);
//    std::cout << "arguments.getArgc() " << arguments.getArgc() << std::endl;
//    arguments.setArgv(argv);
    if (arguments.getArgv().count(1)) {
        auto firstArg = arguments.getArgv().find(1);
        std::cout << "your first argument: " << firstArg->second << std::endl;
    }
    if (arguments.getArgv().count(2)) {
        auto secondArg = arguments.getArgv().find(2);
        std::cout << "your second argument: " << secondArg->second << std::endl;
    }
//    auto element = arguments.getArgv().find(0);
//    std::cout << element->second << std::endl;

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
