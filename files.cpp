#include <iostream>
#include <fstream>
using namespace std;

// check is file exists
inline bool isFileExists (const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}

int main()
{
    cout << "write the name of the file: ";
    string fileName;
    getline(cin, fileName);

    // check is file exists
    if( isFileExists(fileName) )
    {
        cout << "File " << fileName << " already exists. You want rewrite it? y/n ";
        string feedback;
        getline(cin, feedback);
//        if( feedback.compare("y") != 0 ){ return 0; }
        if( feedback != "y" ){ return 0;}
    }

    // create and open a text file
    ofstream MyFile(fileName);

    // write to the file
    MyFile << "Your notes here: " << endl;
    
    cout << "Write something to file " << endl;
    string fromUser;
    //cin >> fromUser;
    getline(cin, fromUser);
    MyFile << fromUser;

    // close file
    MyFile.close();

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
