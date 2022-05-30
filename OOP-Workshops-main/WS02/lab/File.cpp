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

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"
#include "Student.h"


namespace sdds{
   
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   
   // Read Student Name
   bool read(char* student_name){
      bool done = fscanf(fptr, "%[^,],", student_name) == 1;
      return done;
   }

      // Read Student Number
   bool read(int& student_num){
      bool done = fscanf(fptr, "%d,", &student_num) == 1;
      return done;
   }

      // Read Student Grade
   bool read(char& student_grade){
      bool done = fscanf(fptr, "%c\n", &student_grade) == 1;
      return done;
   }
}