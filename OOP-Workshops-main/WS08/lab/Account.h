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
Filename: Account.h
 ------------------------------------------------------*/
#ifndef SDDS_ACCOUNT_H
#define SDDS_ACCOUNT_H
#include "iAccount.h"

namespace sdds {
    class Account: public iAccount
    {
    private:
        double currentBalance; // The current balance (a double value);
    protected:
        double balance() const; // Returns the current balance of the account.
    public:
        Account(double); // Current balance of the account
        virtual bool credit(double); // Adds the amount received to the current balance.
        virtual bool debit(double); // Subtracts the amount received from the current balance.
    };
}
#endif // !SDDS_ACCOUNT_H