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
#include <iostream>
#include <iomanip>
#include "ChequingAccount.h"


namespace sdds {
    // This function stores the fees
    ChequingAccount::ChequingAccount(double initialAmount, double transactionFee, double monthlyFee): Account(initialAmount) {
        if (transactionFee > 0)
        {
            this->transactionFee = transactionFee;
        }
        else
        {
            this->transactionFee = 0.0;
        }

        if (monthlyFee > 0)
        {
            this->monthlyFee = monthlyFee;
        }
        else
        {
            this->monthlyFee = 0.0;
        }   
    }

    // returns true if the transaction succeeded; false otherwise.
    bool ChequingAccount::credit(double value) {
        bool done = false;
        if (Account::credit(value) && Account::debit(transactionFee))
        {
            done = true;
        }
        return done;        
    }


    // This function returns true if the transaction succeeded; false otherwise
    bool ChequingAccount::debit(double value) {
        bool done = false;
        if (Account::debit(value) && Account::debit(transactionFee))
        {
            done = true;
        }
        return done;
    }

    // this modifier debits the monthly fee
    void ChequingAccount::monthEnd() {
        Account::debit(monthlyFee);
    }

    // inserts the output 
    void ChequingAccount::display(std::ostream& os) const {
        os << "Account type: Chequing" << std::endl;
        os << "Balance: $" << std::setprecision(2) << std::fixed <<  Account::balance() << std::endl;
        os << "Per Transaction Fee: " << std::setprecision(2) << std::fixed << transactionFee << std::endl;
        os << "Monthly Fee: " << std::setprecision(2) << std::fixed << monthlyFee << std::endl;
    }
}