/* ------------------------------------------------------
                    Workshop - #10
Full Name  : Alfej Savaya
Student ID#: 118823210
Email      : aasavaya@myseneca.ca
Section    : NFF
Date       : 04 August 2022

Authenticity Declaration:
I declare this submission is the result of my own work, 
only got some sort of help from professors functions 
used during lectures when explaining and used the same 
logic of the functions given in the Question.
Filename: Book.h
 ------------------------------------------------------*/
// Workshop 10:
// Collection template
// 2022-02-25
// Version: 1.0 
// Author: Nathan Misener
// Revised by: 
/////////////////////////////////////////////
#include <iostream>
#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include "Write.h"
namespace sdds {
    class Book : public ReadWrite {
        int m_upc;
        char m_title[41];
        char m_author[41];
        double m_price;
    public:
        Book();
        Book(int upc, const char* title, const char* author, double price);
        void set(int upc, const char* title, const char* author, double price);
        std::ostream& display(std::ostream& os)const;
        bool operator==(int upc)const;
        bool operator==(const char * title)const;
    };
    std::ostream& operator<<(std::ostream& os,const Book& book);
}
#endif // !SDDS_BOOK_H_