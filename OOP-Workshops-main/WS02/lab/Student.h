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

#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_
#include "File.h"
namespace sdds {

struct Student {
      char* m_name;
      int m_studentNumber;
      char m_grade;
   };
void sort();
bool load(Student &students);
bool load(const char* filename);
void display(Student& students);
void display();
void deallocateMemory();
}
#endif // !SDDS_STUDENT_H_

