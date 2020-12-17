#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    cout << "write the name of the file: ";
    string fileName;
    cin >> fileName;
    // create and open a text file
    ofstream MyFile(fileName);

    // write to the file
    MyFile << "Your notes here: " << endl;
    
    cout << "Write something to file " << endl;
    string fromUser;
    cin >> fromUser;
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
