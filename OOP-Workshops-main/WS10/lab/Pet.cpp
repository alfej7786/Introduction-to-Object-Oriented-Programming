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
Filename: Pet.cpp
 ------------------------------------------------------*/
// Workshop 10:
// Pet.cpp
// 2022-02-25
// Version: 1.0 
// Author: Nathan Misener
// Revised by: 
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

using namespace std;
#include "Pet.h"
namespace sdds {
    Pet::Pet() {
        set("", "", 0);
    }
    Pet::Pet(const char* name, const char* type, int age) {
        set(name, type, age);
    }
    void Pet::set(const char* name, const char* type, int age) {
        strcpy(m_name, name);
        strcpy(m_type, type);
        m_age = age;
    }
    ostream& Pet::display(ostream& os)const {
        return os <<"Type: " << m_type << ", Name: " << m_name << " Age: " << m_age;
    }
    bool Pet::operator==(int age)const {
        return m_age == age;
    }
    bool Pet::operator==(const char* type)const {
        return strcmp(m_type, type) == 0;
    }

    std::ostream& operator<<(std::ostream& os,const Pet& pet) {
        pet.display(os);
        return os;
    }
}