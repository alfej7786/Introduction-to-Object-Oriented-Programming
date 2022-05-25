#include <iostream>
#include <fstream>
#include<string>
#include "quiz.h"

using namespace std;

int LoadQuiz(const char* filename){
    fstream myFile;
    myFile.open("quiz1.txt", ios::in);
    if (myFile.is_open())
    {
		cout << "SUCCESS\n";
        myFile.close();
    }
    else {
        cout << "ERROR: There is no file; the function 'LoadTest()' should return non-zero value.\n";
        cout << "       Keep working on your code.\n";
    }

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

    myFile.open("quiz3.txt", ios::in);
    if (myFile.is_open())
    {
        string line;
        while (getline(myFile, line))
        {
            cout<<line<<endl;
        }
        myFile.close();
    }

    myFile.open("quiz4.txt", ios::in);
    if (myFile.is_open())
    {
        string line;
        while (getline(myFile, line))
        {
            cout<<line<<endl;
        }
        myFile.close();
    }

    myFile.open("quiz5.txt", ios::in);
    if (myFile.is_open())
    {
        string line;
        while (getline(myFile, line))
        {
            cout<<line<<endl;
        }
        myFile.close();
    }
}






