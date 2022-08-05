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
Filename: FullName.cpp
 ------------------------------------------------------*/
#include <cstring>
#include "FullName.h"
#include "Name.h"

using namespace std;
namespace sdds {

    // Creates an empty FullName
    FullName::FullName() {
        m_value = nullptr;
    }

    // Passess name to the constructor of the base class and 
    // dynamically keeps a copy of lastName in the m_value of FullName
    FullName::FullName(const char* name, const char* lastName) : Name(name) {
        if (lastName)
        {
            m_value = new char[strlen(name) + 1];
            strcpy(m_value, name);
        } else
        {
            m_value = nullptr;
        }        
    }



    // Rule of three goes here:
    FullName::~FullName() {
        delete[] m_value;
        m_value = nullptr;
    }

    FullName::FullName(const FullName& fullname) : Name(fullname) {
        m_value  =new char[strlen(fullname.m_value) + 1];
        strcpy(m_value, fullname.m_value);
    }

    FullName& FullName::operator=(const FullName& fullname) {
        Name::operator=(fullname);
        if (m_value) 
        {
            delete[] m_value;
            m_value = nullptr;
        }
        m_value = new char[strlen(fullname.m_value) + 1];
        strcpy(m_value, fullname.m_value);
        return *this;
    }

    // Returns the address in the m_value of the FullName.
    FullName::operator const char* () const {
        return m_value;
    }

    // Returns true only if both FullName and Name are not empty.
    FullName::operator bool() const {
        return (m_value != nullptr && Name::operator bool());
    }

    // If the FullName is not empty it will insert the Name
    ostream& FullName::display(ostream& ostr) const {
        if (*this) 
        {
            Name::display(ostr) << " " << m_value;
        }
        return ostr;
    }

    // Reads the Name and then dynamically reads a Cstring into the m_value of FullName from istream
    istream& FullName::read(istream& istr) {
        char flag[1024];
        Name::read(istr);
        istr.getline(flag, 1024, '\n');

        if (m_value) 
        {
            delete[] m_value;
            m_value = nullptr;
        }

        if (istr) 
        {
            m_value = new char[strlen(flag) + 1];
            strcpy(m_value, flag);
        }
        return istr;
    }
}