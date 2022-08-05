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
Filename: Numbers.cpp
 ------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
#include "Numbers.h"  // intentional

using namespace std;
namespace sdds {


   Numbers::Numbers() { 
      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const char* filename) { 
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         delete[] m_numbers;
         delete[] m_filename;
         setEmpty();
         m_isOriginal = false; 
      }
      else {
         sort();
      }
   }
   Numbers::~Numbers() {
      save();
      delete[] m_numbers;
      delete[] m_filename;
   }
   
   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }
   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }
   void Numbers::sort() {
      int i, j;
      double temp;
      for (i = m_numCount - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (m_numbers[j] > m_numbers[j + 1]) {
               temp = m_numbers[j];
               m_numbers[j] = m_numbers[j + 1];
               m_numbers[j + 1] = temp;
            }
         }
      }
   }

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }
   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   double Numbers::max() const {
      double maxVal = 0.0;
      if (!isEmpty()) {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }


    // ==================================================== //
    Numbers::Numbers(const Numbers& num) {
      setEmpty();
      m_isOriginal = false;
      *this = num;
   }



   //Number Count Function
   int Numbers::numberCount() {
      ifstream inFile(this->m_filename);
      int count{};
      if (inFile.is_open())
      {
         double flag{};
         while (inFile >> flag)
         {
            count += 1;
         }
      }
      return count;
   }



   // Load Function
   bool Numbers::load() {
      if (m_numCount > 0)
      {
         this->m_numbers = new double[m_numCount];
         ifstream inFile(this->m_filename);

         double flag{};
         int i{};

         if (inFile.is_open())
         {
            while (inFile >> flag)
            {
                  m_numbers[i] = flag;
                  i += 1;
            }   
         }
         return (m_numCount == i);
      }
      return false;
   }

   // Save Function
   void Numbers::save(){
      if (this->m_isOriginal && !this->isEmpty())
      {
         ofstream outFile("numbers.txt");

         for (int i = 0; i < m_numCount; i++)
         {
            outFile << m_numbers[i] << endl;
         }
      }
   }



   // Operator =
   Numbers& Numbers::operator=(const Numbers& num) {
      delete[] this->m_numbers;
      this->m_numbers = new double[num.m_numCount];

      for (int i = 0; i < num.m_numCount; i++) 
      {
         this->m_numbers[i] = num.m_numbers[i];
      }
      this->m_numCount = num.m_numCount;
      setFilename(num.m_filename);
      return *this;
   }


   // Operator +=
   Numbers& Numbers::operator+=(double number){
      if (!this->isEmpty())
      {
         double* opt = new double[m_numCount + 1];
         for (int i = 0; i < m_numCount; i++)
         {
            opt[i] = m_numbers[i];
         }
         m_numCount += 1;
         opt[m_numCount - 1] = number;

         delete[] m_numbers; // Delete
         m_numbers = opt;
         sort();
      }
      return (*this);
   }

   // Display Function
   ostream& Numbers::display(ostream& ostr) const {
      if (this->isEmpty()) 
      {
         ostr << "Empty list";
      }
      else 
      {
         ostr << "=========================" << endl;
         if (!m_isOriginal) 
         {
               ostr << "*** COPY ***" << endl;
         }
         else 
         {
               ostr << this->m_filename << endl;
         }
         for (int i = 0;i < m_numCount;i++) 
         {
            ostr << m_numbers[i];

            if (i != m_numCount - 1) 
            {
               ostr << ", ";
            }
         }

         ostr << endl;
         ostr << "-------------------------" << endl;
         ostr << "Total of " << m_numCount << " number(s)" << endl;
         ostr << "Largest number:  " << this->max() << endl;
         ostr << "Smallest number: " << this->min() << endl;
         ostr << "Average :        " << this->average() << endl;
         ostr << "=========================";
      }
      return ostr;
   }

   // Helper function overlaods
   ostream& operator<<(ostream& os, const Numbers& Nums) {
      return Nums.display(os);
   }

   istream& operator>>(istream& istr, Numbers& Nums) {
      double i{};
      istr >> i;
      Nums += i;
      return istr;
   }
}
