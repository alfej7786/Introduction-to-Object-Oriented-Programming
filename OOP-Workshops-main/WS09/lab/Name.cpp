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
Filename: Name.cpp
 ------------------------------------------------------*/
#include <cstring>
#include "Name.h"

using namespace std;
namespace sdds {

    // Creates an empty name
    Name::Name() {
        m_value = nullptr;
    }

    // Keeps a dynamic copy of the name in the Name object.
    Name::Name(const char* name) {
        if (name != nullptr)
        {
            m_value = new char[strlen(name) + 1];
            strcpy(m_value, name);
        } else
        {
            m_value = nullptr;
        }
    }


    // Rule of three goes here:
    Name::~Name() {
        delete[] m_value;
        m_value = nullptr;
    }
    
    Name::Name(const Name& name) {
        m_value = new char[strlen(name.m_value) + 1];
        strcpy(m_value, name.m_value);
    }

    Name& Name::operator=(const Name& name) {
        if (m_value)
        {
            delete[] m_value;
            m_value = nullptr;
        }
        m_value = new char[strlen(name.m_value) + 1];
        strcpy(m_value, name.m_value);
        return *this;        
    }

    // Returns the address of the dynamic Cstring.
    Name::operator const char *() const  {
        return m_value;
    }

    // Return true of name is not empty, otherwise, it returns false.
    Name::operator bool() const {
        return (m_value != nullptr);
    }


    // Inserts the Cstring value into ostr without going to new line
    ostream& Name::display(ostream& ostr) const {
        if (m_value != nullptr)
        {
            ostr << m_value;
        }
        return ostr;       
    }

    // Dynamically reads the Cstring from istr without any spaces
    istream& Name::read(istream& istr) {
        char flag[1024];
        istr.getline(flag, 1024, ' ');
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


    // Insertion and Extraction operator overloads
    ostream& operator<<(ostream& os, const Name& name) {
        name.display(os);
        return os;
    }

    istream& operator>>(istream& is, Name& name) {
        name.read(is);
        return is;
    }
}