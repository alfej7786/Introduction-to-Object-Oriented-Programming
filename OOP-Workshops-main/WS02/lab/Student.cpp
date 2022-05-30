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

#include <iostream>
#include <cstring>
#include "Student.h"
#include "File.h"
#define FILE "students.csv"

using namespace std;

namespace sdds{
int noOfStudents;
Student* students = nullptr;

   void sort() {
      int i, j;
      Student temp;
      for (i = noOfStudents - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (students[j].m_grade > students[j + 1].m_grade) {
               temp = students[j];
               students[j] = students[j + 1];
               students[j + 1] = temp;
            }
         }
      }
   }

//    void load(Student& students) {
//     char SchoolName[128];
//     read(SchoolName);
//     students.m_name = new char[strlen(SchoolName) + 1];
//     strcpy(students.m_name, SchoolName);
//     read(students.m_studentNumber);
//     read(students.m_grade);
//   }

   bool load(Student& students) {
      bool done = false;
      char student_name[128];
      if (read(student_name))
      {
         students.m_name = new char[strlen(student_name) + 1];
         strcpy(students.m_name, student_name);
         // read(students.m_studentNumber);
         // read(students.m_grade);
         done = read(students.m_studentNumber) && read(students.m_grade);
         // done = true;
      }
      return done;
   }

   bool load(const char* filename){
      bool done = false;
      int i{};
      
      if (openFile(FILE))
      {
         noOfStudents = noOfRecords();
         students = new Student[noOfStudents];
         for (i = 0; i < noOfStudents; i++)
         {
            load(students[i]);
         }
         if (i != noOfStudents)
         {
            cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
         }
         else {
            done = true;
         }
         closeFile();
      }else {
         cout << "File can not open" << FILE << endl;
      }
      return done;
   }

   // Display Function
    void display(const Student& students){
        cout <<students.m_name<<","<<students.m_studentNumber<< ","<<students.m_grade<<endl;
    }

   // Display Sort Function
    void display(){
       int i, j;
       sort();
       for (i = 0, j = 1; i < noOfStudents; i++)
       {
          cout << j++ << ": ";
          display(students[i]);
       }
    }

   // Function Delocate Memory
    void deallocateMemory(){
       int i;
       for (i = 0; i < noOfStudents; i++)
       {
          delete [] students[i].m_name;
          students[i].m_name = nullptr;
       }
       delete[] students;
       students = nullptr;
    }
}
