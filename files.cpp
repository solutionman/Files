#include <iostream>
#include <fstream>
#include "fileOperations.h"
using namespace std;

// check is file exists
inline bool isFileExists (const std::string& name)
{
    ifstream f(name.c_str());
    return f.good();
}

int main()
{
    cout << "write the name of the file: ";
    string fileName;
    getline(cin, fileName);

    fileOperations fileOperations;

    // check is file exists
    if( isFileExists(fileName) )
    {
        cout << "File " << fileName << " already exists. You want rewrite it? 'y/n' ";
        string feedback;
        getline(cin, feedback);
//        if( feedback.compare("y") != 0 ){ return 0; }
        if( feedback != "y" ){ return 0; }
        cout << "Open or create new it ? o/c ";
        getline(cin, feedback);
        if( feedback == "o" )
        {
            fileOperations.writeToFile(fileName);
            return 0;
        }
    }

    // create and open a text file
    ofstream MyFile(fileName);

    // write to the file
    MyFile << "Your notes here: " << endl;
    fileOperations.writeToFile(fileName);

    string myText;

    // read from text file
    ifstream MyReadFile(fileName);

    // use while loop thogether with the getline() function
    // to read the file line by line
    while(getline(MyReadFile, myText))
    {
        // Output the text from the file
	cout << myText << endl;
    }
    // close the file
    MyReadFile.close();


    return 0;
}
