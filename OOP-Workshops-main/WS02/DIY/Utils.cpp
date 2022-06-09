/* ------------------------------------------------------
                 Workshop - #2 Part - #2
Full Name  : Alfej Savaya
Student ID#: 118823210
Email      : aasavaya@myseneca.ca
Section    : NFF
Date       : 30 May 2022

Authenticity Declaration:
I declare this submission is the result of my own work, 
only got some sort of help from professors functions 
used during lectures when explaining and used the same 
logic of the functions given in the previous Workshop.

 ------------------------------------------------------*/
#include <iostream>
#include "BirthDate.h"
#include "Utils.h"
using namespace std;
namespace sdds {
    PersonDetails* details;
    PersonDetails* matches;
	int numOfRecords = 0;
    int numOfMatch = 0;
 FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1)
        {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }
    void getAllRecords() {
        int i;
        details = new PersonDetails[numOfRecords];
        for (i = 0; i < numOfRecords; ++i)
        {
            int index = 0;
            char name[30], ch;
            // Scanning the Employee Name
            while (fscanf(fptr, "%c", &ch) == 1)
            {
                if (ch == ',') break;
                else
                {
                    name[index++] = ch;
                }
            }
            details[i].name = new char[index];
            details[i].name[index] = '\0';
            while (index--)
            {
                details[i].name[index] = name[index];
            }
            // Scanning the Birth Date mm/dd/yyyy 
            details[i].mm = 0;
            details[i].dd = 0;
            details[i].yyyy = 0;
            while (fscanf(fptr, "%c", &ch) == 1) {
                if (ch == '/') break;
                else details[i].mm = (details[i].mm * 10) + ((int)ch - 48);
            }
            while (fscanf(fptr, "%c", &ch) == 1) {
                if (ch == '/') break;
                else details[i].dd = (details[i].dd * 10) + ((int)ch - 48);
            }
            while (fscanf(fptr, "%c", &ch) == 1) {
                if (ch == '\n') break;
                else details[i].yyyy = (details[i].yyyy * 10) + ((int)ch - 48);
            }
        }
        cout << endl;
    }
}
