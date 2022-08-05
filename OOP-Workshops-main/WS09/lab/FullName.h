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
Filename: FullName.h
 ------------------------------------------------------*/
#ifndef SDDS_FULLNAME_H
#define SDDS_FULLNAME_H

#include <iostream>
#include "Name.h"

namespace sdds {
      class FullName : public Name {
      char* m_value;
   public:
      FullName();
      FullName(const char* name, const char* lastName);
      // Rule of three goes here:
      ~FullName();
      FullName(const FullName& fullname);
      FullName& operator=(const FullName& fullname);
      
      operator const char* ()const;
      virtual operator bool()const;
      virtual std::ostream& display(std::ostream& ostr = std::cout)const;
      virtual std::istream& read(std::istream& istr = std::cin);  
   };

}
#endif // !SDDS_FULLNAME_H