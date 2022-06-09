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
    // Opens the datafile. If successful it will print Birthdate search program and returns true otherwise it will print Data file "filename goes here" not found! and return false;
    bool beginSearch(const char* filename) {
        if (openFile(filename))
        {
            cout << "Birthdate search program" << endl;
            numOfRecords = noOfRecords();
            getAllRecords();
            return true;
        }
        cout << "Data file " << filename << "not found!" << endl;
        return false;
    }

    // Reads Birth Date that matches the Birth Month ...
    bool readBirthDate(int month) {
        int i;
        matches = new PersonDetails[numOfRecords];
        for (i = 0; i < numOfRecords; i++)
        {
            if (details[i].mm == month)
            {
                matches[numOfMatch++] = details[i];
            }
        }
        cout << numOfMatch << "birthdates found:" << endl;
        if (numOfMatch <= 0)
        {
            return false;
        }
        return true;
    }

    // Sorts the records based on the year of birth in descending order ...
    void sort() {
        int i, j;
        for (i = 0; i < numOfMatch; ++i)
        {
            for (j = i + 1; j < numOfMatch; ++j)
            {
                if (matches[i].yyyy > matches[j].yyyy)
                {
                    swap(matches[i], matches[j]);
                }
            }
        }
    }


    // Displays the found records as displayed in the execution sample ...
    void displayBirthdays() {
        for (int i = 0; i < numOfMatch; ++i) {
            std::cout << i + 1 << ") " << matches[i].name << ":" << std::endl;
            std::cout << matches[i].yyyy << "-" << matches[i].mm << "-" << matches[i].dd << std::endl;
            std::cout << "===================================" << std::endl;
        }
    }

    // Releases all the Dynamically allocated memory ...
    void deallocate() {
        int i;
        for (i = 0; i < numOfMatch; i++)
        {
        delete[] matches[i].name;
        matches[i].name = nullptr;
        }
        delete[] matches;
        numOfMatch = 0;
        matches = nullptr;

    }

    // Program End ...
    void endSearch() {
        cout << "Birthdate Search Program Closed." << endl;
    }
}