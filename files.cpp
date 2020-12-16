#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // create and open a text file
    ofstream MyFile("test.txt");

    // write to the file
    MyFile << "Your notes here: ";
    
    cout << "Write something to file " << endl;
    string fromUser;
    cin >> fromUser;
    MyFile << fromUser;

    // close file
    MyFile.close();

    string myText;

    // read from text file
    ifstream MyReadFile("test.txt");

    // use while loop thogether with the getline() function
    // to read the file line by line
    while(getline(MyReadFile, myText))
    {
        // Output the text from the file
	cout << myText;
    }
    // close the file
    MyReadFile.close();


    return 0;
}
