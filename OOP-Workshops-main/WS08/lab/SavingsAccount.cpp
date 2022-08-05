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
Filename: SavingsAccount.cpp
 ------------------------------------------------------*/
#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"

namespace sdds {
    // stores the rate.
    SavingsAccount::SavingsAccount(double initialAmount,double interestRate): Account(initialAmount) {
        if (interestRate > 0)
        {
            this->interestRate = interestRate;
        }
        else
        {
            this->interestRate = 0.0;
        }        
    }

    // alculates the interest earned
    void SavingsAccount::monthEnd() {
        double totalInterest = 0;
        totalInterest = (Account::balance() * interestRate);
        Account::credit(totalInterest);
    }

    // Display/Print
    void SavingsAccount::display(std::ostream& os) const {
        os << "Account type: Savings" << std::endl;
        os << "Balance: $" << std::setprecision(2) << std::fixed << Account::balance() <<std::endl;
        os << "Interest Rate (%): " << std::setprecision(2) << std::fixed << interestRate * 100 << std::endl;
    }
}