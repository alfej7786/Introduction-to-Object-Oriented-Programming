/* ------------------------------------------------------
                    Workshop - #9
Full Name  : Alfej Savaya
Student ID#: 118823210
Email      : aasavaya@myseneca.ca
Section    : NFF
Date       : 30 July 2022

Authenticity Declaration:
I declare this submission is the result of my own work, 
only got some sort of help from professors functions 
used during lectures when explaining and used the same 
logic of the functions given in the Question.
Filename: Name.h
 ------------------------------------------------------*/
#ifndef SDDS_NAME_H
#define SDDS_NAME_H

#include <iostream>

namespace sdds {
    class Name {
      char* m_value;
   public:
      Name();  
      Name(const char* m_name);
      // Rule of three goes here:
      virtual ~Name();
      Name(const Name& m_name);
      Name& operator=(const Name& m_name);

      operator const char* ()const;
      virtual operator bool()const;
      virtual std::ostream& display(std::ostream& ostr = std::cout)const;
      virtual std::istream& read(std::istream& istr = std::cin);  
   };
    // Insertion and Extraction operator overloads
    std::ostream& operator<<(std::ostream& os, const Name& m_name);
    std::istream& operator>>(std::istream& is, Name& m_name);
}
#endif // !SDDS_NAME_H