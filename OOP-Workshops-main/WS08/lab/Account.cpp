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
Filename: Account.cpp
 ------------------------------------------------------*/

#include <iostream>
#include "Account.h"

namespace sdds {
    // Returns the current balance of the account.
    double Account::balance() const {
        return currentBalance;
    }


    // Current balance of the account
    Account::Account(double value) {
        if (value < 0)
        {
            currentBalance = 0.0;
        }
        else
        {
            currentBalance = value;
        }        
    }

    // Adds the amount received to the current balance.
    bool Account::credit(double value) {
        bool done = false;
        if (value > 0)
        {
            currentBalance += value;
            done = true;
        }
        return done;        
    }

    // Subtracts the amount received from the current balance.
    bool Account::debit(double value) {
        bool done = false;
        if (value > 0)
        {
            currentBalance -= value;
            done = true;
        }
        return done;
    }
}