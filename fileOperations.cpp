#include <iostream>
#include "fileOperations.h"
using namespace std;

void fileOperations::writeToFile(string fileName) {
    cout << "write here what you want add to the file, to quit enter :q" << endl;
    // open file
    string addToFile;
    do
    {
        std::ofstream out;
        out.open(fileName, std::ios::app);
        getline(cin, addToFile);
        if(addToFile!=":q")
        {
            out << endl << addToFile;
        }
        out.close();
    } while (addToFile!=":q");
}
