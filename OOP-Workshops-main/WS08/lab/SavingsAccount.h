/* ------------------------------------------------------
                    Workshop - #8
Full Name  : Alfej Savaya
Student ID#: 118823210
Email      : aasavaya@myseneca.ca
Section    : NFF
Date       : 19 July 2022

Authenticity Declaration:
I declare this submission is the result of my own work, 
only got some sort of help from professors functions 
used during lectures when explaining and used the same 
logic of the functions given in the Question.
Filename: SavingsAccount.h
 ------------------------------------------------------*/
#ifndef SDDS_SAVINGSACCOUNT_H
#define SDDS_SAVINGSACCOUNT_H
#include "Account.h"

namespace sdds {
    class SavingsAccount: public Account
    {
    private:
        double interestRate; //  Holds the interest rate
    public:
        // stores the rate.
        SavingsAccount(double, double);
        // alculates the interest earned
        void monthEnd();
        // Display/Print
        void display(std::ostream&) const;
    };
}
#endif // !SDDS_SAVINGSACCOUNT_H