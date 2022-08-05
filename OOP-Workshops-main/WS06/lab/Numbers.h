/* ------------------------------------------------------
                 Workshop - #6 Part - #1
Full Name  : Alfej Savaya
Student ID#: 118823210
Email      : aasavaya@myseneca.ca
Section    : NFF
Date       : 07 July 2022

Authenticity Declaration:
I declare this submission is the result of my own work, 
only got some sort of help from professors functions 
used during lectures when explaining and used the same 
logic of the functions given in the Question.
Filename: Numbers.h
 ------------------------------------------------------*/
#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
   class Numbers {
      double* m_numbers;
      char* m_filename;
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const;
      void setEmpty();
      void setFilename(const char* filename);
      void sort();
   public:
      Numbers();
      Numbers(const char* filename);
      ~Numbers();
      double average()const;
      double max()const;
      double min()const;

      // ==================================== //
      Numbers(const Numbers& num);
      //Number Count Function
      int numberCount();
      // Load Function
      bool load();
      // Save Function
      void save();
      // Operator =
      Numbers& operator=(const Numbers& num);
      // Operator +=
      Numbers& operator+=(double number);
      // Display Function
      std::ostream& display(std::ostream& ostr) const;
   };
   // Helper function overlaods
   std::ostream& operator<<(std::ostream& os, const Numbers& Nums);
   std::istream& operator>>(std::istream& istr, Numbers& Nums);
}
#endif // !SDDS_NUMBERS_H_
 