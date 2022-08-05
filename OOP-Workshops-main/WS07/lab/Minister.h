/* ------------------------------------------------------
                    Workshop - #7 
Full Name  : Alfej Savaya
Student ID#: 118823210
Email      : aasavaya@myseneca.ca
Section    : NFF
Date       : 15 July 2022

Authenticity Declaration:
I declare this submission is the result of my own work, 
only got some sort of help from professors functions 
used during lectures when explaining and used the same 
logic of the functions given in the Question.
Filename: Minister.h
 ------------------------------------------------------*/

#ifndef SDDS_MINISTER_H
#define SDDS_MINISTER_H
#include <iostream>
#include "MemberParliament.h"

#define MAX_PM_NAME_LENGTH 50 // Maximum name length

namespace sdds {
    class Minister : public MemberParliament {
    private:
        char PM_name[MAX_PM_NAME_LENGTH];
        double year;
    public:
        Minister(/* args */);
        Minister(const char* id, int age, double year, const char* nameOfPM , const char* district);
        void changePM(const char* pm); // A mutator that updates the PM the minister reports to.
        void assumeOffice(double year); // A mutator that updates the year the minister assumed office

        std::ostream& write(std::ostream& os = std::cout) const;
        std::istream& read(std::istream& in = std::cin);

        // Sets all members to empty state;
        void setEmpty();

        // Setters
        void setName(const char* m_name);
        void setYear(double year);
    };
    // Overloading the insertion and extraction operators
    // std::ostream& operator<<(std::ostream& ostr, Minister& p_Minister);
    // std::istream& operator>>(std::istream& istr, Minister& p_Minister);
    std::ostream& operator<<(std::ostream& os, const Minister& p_Minister);
    std::istream& operator>>(std::istream& is, Minister& p_Minister);
};

#endif //SDDS_MINISTER_H