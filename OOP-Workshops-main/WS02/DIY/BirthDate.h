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
 
#include <cstdio>
#ifndef BIRTTHDATE_H
#define BIRTTHDATE_H
using namespace std;
namespace sdds {


	// A Structure to keep personal details ...
	struct PersonDetails {
		char* name;
		int mm, dd, yyyy;
	};

	bool openFile(const char filename[]);
   	void closeFile();
   	int noOfRecords();

	// Mandatory functions ...
		void getAllRecords();
		bool beginSearch(const char* filename);
		bool readBirthDate(int month);
		void sort();
		void displayBirthdays();
		void deallocate();
		void endSearch();

	

	PersonDetails* details;
    PersonDetails* matches;
    int numOfRecords = 0;
    int numOfMatch = 0;
}
#include "BirthDate.cpp"
#endif