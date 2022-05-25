#include <iostream>
#include <fstream>
#include<string>
using namespace std;

int main() {
    fstream myFile;
    myFile.open("quiz2.txt", ios::in);
    if (myFile.is_open())
    {
        string line;
        while (getline(myFile, line))
        {
            cout<<line<<endl;
        }
        myFile.close();
    } 
    return 0;
}