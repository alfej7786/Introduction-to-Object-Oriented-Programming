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

File : BarChart.h
 ------------------------------------------------------*/
#ifndef SDDS_BARCHART_H
#define SDDS_BARCHART_H
#include "Bar.h"
namespace sdds  {
    // class BarChart
    class BarChart {
    private:    // Private
        Bar* m_bars;
        char* m_chartTitle;
        char m_fill;
        int m_noOfBars;
        int m_add;
        void setEmpty();
        bool isValid() const;
    public:     // Public
        void init(const char* title, int noOfBars, char fill);
        void add(const char* bar_title, int value);
        void draw() const;
        void deallocate();
    };
}
#endif // ! SDDS_BARCHART_H