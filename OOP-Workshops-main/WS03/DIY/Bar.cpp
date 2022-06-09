/* ------------------------------------------------------
                 Workshop - #3 Part - #2
Full Name  : Alfej Savaya
Student ID#: 118823210
Email      : aasavaya@myseneca.ca
Section    : NFF
Date       : 06 Jun 2022

Authenticity Declaration:
I declare this submission is the result of my own work,
only got some sort of help from professors functions
used during lectures when explaining and used the same
logic of the functions given in the previous Workshop.
Used Google to check on the possible ways to solve the
function 'draw()' in file BarChart.cpp

File : Bar.cpp
 ------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Bar.h"
using namespace std;
namespace sdds  {

// Function setEmpty
void Bar::setEmpty() {  // set to Invalid state
    m_Value = -1;
    strcpy(m_barTitle, "");
}

// Function init
void Bar::init(const char* title, char fill, int value)  {
    if (value < 0 || value > 100)
    {
        setEmpty(); // set to invalid state
    }
    else
    {   // set members
        strcpy(m_barTitle, title);
        m_fill = fill;
        m_Value = value;
    }
}

// Function isValid
bool Bar::isValid()const    {
    bool valid = false;
    if (m_Value > 0 && m_Value < 100)
    {
        valid = true;
    }
    return valid; // return if Valid
}

//Function draw
void Bar::draw()const {
    if (isValid()) // if Valid
    {   // Print Title, Dots, and pipe charater
        cout << setw(20) << left << setfill('.') << m_barTitle << "|";
        for (int i = 0; i < m_Value / 2; i++) 
        {
            cout << m_fill;    // print fill characters
        }
        cout << endl;
    }
}
}