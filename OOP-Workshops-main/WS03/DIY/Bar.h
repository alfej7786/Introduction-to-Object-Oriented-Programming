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

File : Bar.h
 ------------------------------------------------------*/
#ifndef SDDS_BAR_H
#define SDDS_BAR_H
namespace sdds  {   
    // Class Bar
    class Bar {
    private: // Private
        char m_barTitle[20];
        char m_fill;
        int m_Value;
    public:  // Public
        void setEmpty();
        void init(const char* title, char fill, int value);
        bool isValid()const;
        void draw()const;

    };
}
#endif // ! SDDS_BAR_H