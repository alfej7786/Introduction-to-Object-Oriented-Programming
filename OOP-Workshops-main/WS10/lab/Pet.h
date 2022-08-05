/* ------------------------------------------------------
                    Workshop - #10
Full Name  : Alfej Savaya
Student ID#: 118823210
Email      : aasavaya@myseneca.ca
Section    : NFF
Date       : 04 August 2022

Authenticity Declaration:
I declare this submission is the result of my own work, 
only got some sort of help from professors functions 
used during lectures when explaining and used the same 
logic of the functions given in the Question.
Filename: Pet.h
 ------------------------------------------------------*/
// Workshop 10:
// Pet.h
// 2022-02-25
// Version: 1.0 
// Author: Nathan Misener
// Revised by: 
/////////////////////////////////////////////
#include <iostream>
#ifndef SDDS_PET_H_
#define SDDS_PET_H_
#include "Write.h"
namespace sdds {
    class Pet : public ReadWrite {
        char m_name[41];
        char m_type[41];
        int m_age;
    public:
        Pet();
        Pet(const char* name, const char* type, int age);
        void set(const char* name, const char* type, int age);
        std::ostream& display(std::ostream& os)const;
        bool operator==(const char* type)const;
        bool operator==(const int age)const;
    };
    std::ostream& operator<<(std::ostream& os, const Pet& Pet);
}
#endif // !SDDS_PET_H_

