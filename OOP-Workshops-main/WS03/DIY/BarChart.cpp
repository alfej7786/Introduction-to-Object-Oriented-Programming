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

File : BarChart.cpp
 ------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "BarChart.h"
using namespace std;
namespace sdds {

// Function Empty
void BarChart::setEmpty() {
    m_chartTitle = nullptr;
    m_bars = nullptr;
}

// Function init
void BarChart::init(const char* title, int noOfBars, char fill) {
    if (title == NULL || noOfBars < 1)
    {
        setEmpty();
    }
    else
    {
        m_noOfBars = noOfBars; 
        m_fill = fill;  // set char
        m_add = 0;

        m_chartTitle = new char[strlen(title) + 1]; // set Title
        strcpy(m_chartTitle, title);
        m_bars = new Bar[m_noOfBars];   // Set Max num of Bars

        for (int i = 0; i < m_noOfBars; i++)
        {
            m_bars[i].setEmpty();
        }
    }
}

// Function isValid
bool BarChart::isValid() const {
    bool valid = false;
    bool Notvalid = true;
    if (m_chartTitle != nullptr && m_bars != nullptr)
    {
        for (int i = 0; i < m_noOfBars && Notvalid; i++)
        {
            Notvalid = m_bars[i].isValid();
        }
        if (Notvalid)
        {
            valid = true;
        }
    }
    return valid;
}

// Function add
void BarChart::add(const char* bar_title, int value) {
    bool done = true;
    // add Bar
    if (m_add < m_noOfBars)
    {
        for (int i = 0; i < m_noOfBars && done; i++)
        {
            if (!m_bars[i].isValid())
            {
                m_bars[i].init(bar_title, m_fill, value);
                done = false;
            }
        }
        m_add++;
    }
}

// Function draw
void BarChart::draw() const  {
    if (isValid())
    {   // print Valid
        cout << m_chartTitle << endl;
        cout << setw(71)<<setfill('-') <<"-"<< endl; // Print '-'
        for (int i = 0; i < m_noOfBars; i++)
        {
            m_bars[i].draw();
        }
        cout << setw(71) << setfill('-') <<"-"<< endl;
    }
    else
    {   // print Invalid
        cout << "Invalid Chart!" << endl;
    }
}

// Function deallocate
void BarChart::deallocate()  {
    delete[] m_chartTitle;
    delete[] m_bars;
    m_chartTitle = nullptr;
    m_bars = nullptr;
}
}