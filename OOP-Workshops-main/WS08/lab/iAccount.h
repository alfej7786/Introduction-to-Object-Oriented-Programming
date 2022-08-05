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
Filename: iAccount.h
 ------------------------------------------------------*/
#ifndef SDDS_IACCOUNT_H
#define SDDS_IACCOUNT_H
#include <iostream>

namespace sdds {
    class iAccount
    {
    private:
        /* data */
    public:
        // Destructor
        virtual ~iAccount(){};

        // adds a positive amount to the account balance
        virtual bool credit(double) = 0;
        // subtracts a positive amount from the account balance
        virtual bool debit(double) = 0;
        // applies month-end transactions to the account
        virtual void monthEnd() = 0;

        // inserts account information into an ostream object
        virtual void display(std::ostream&) const = 0;
        
    };
    // creates the account with the starting balance and returns its address.
    iAccount* CreateAccount(const char*, double);
}

#endif // !SDDS_IACCOUNT_H