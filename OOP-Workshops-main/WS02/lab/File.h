/* ------------------------------------------------------
                 Workshop - #2 Part - #1
Full Name  : Alfej Savaya
Student ID#: 118823210
Email      : aasavaya@myseneca.ca
Section    : NFF
Date       : 27 May 2022

Authenticity Declaration:
I declare this submission is the result of my own work, 
only got some sort of help from professors functions 
used during lectures when explaining.

 ------------------------------------------------------*/

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
#include "Student.h"
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char* student_name);
   bool read(int& studen_num);
   bool read(char& student_grade);  
}
#endif // !SDDS_FILE_H_
