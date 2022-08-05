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
Filename: ChequingAccount.cpp
 ------------------------------------------------------*/
#ifndef SDDS_CHEQUINGACCOUNT_H
#define SDDS_CHEQUINGACCOUNT_H
#include "Account.h"

namespace sdds {
    class ChequingAccount: public Account
    {
    private:
        double transactionFee; // transaction fee (double)
        double monthlyFee; // monthly fee (double)
    public:
        // This function stores the fees
        ChequingAccount(double, double, double);
        // returns true if the transaction succeeded; false otherwise.
        bool credit(double);
        // This function returns true if the transaction succeeded; false otherwise
        bool debit(double);
        // this modifier debits the monthly fee
        void monthEnd();
        // inserts the output 
        void display(std::ostream&) const;
    };
}

#endif // !SDDS_CHEQUINGACCOUNT_H