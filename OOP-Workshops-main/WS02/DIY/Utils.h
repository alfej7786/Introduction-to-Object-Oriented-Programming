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

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds {
    
    struct PersonDetails {
		char* name;
		int mm, dd, yyyy;
	};
    bool openFile(const char filename[]);
   	void closeFile();
   	int noOfRecords();
    void getAllRecords();

 
}
#endif // !Utils