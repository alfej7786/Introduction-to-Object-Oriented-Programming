/* ------------------------------------------------------
                 Workshop - #5 Part - #1
Full Name  : Alfej Savaya
Student ID#: 118823210
Email      : aasavaya@myseneca.ca
Section    : NFF
Date       : 17 Jun 2022

Authenticity Declaration:
I declare this submission is the result of my own work, 
only got some sort of help from professors functions 
used during lectures when explaining and used the same 
logic of the functions given in the Question.
Filename: Book.h
 ------------------------------------------------------*/
#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include <iostream>
#include "Chapter.h"

namespace sdds {
   const int MAX_NUM_CHAPTERS = 10;
   const int MAX_BOOK_TITEL = 40;
   const int MAX_AUTHOR_NAME = 20;
    class Book
    {
        char m_title[MAX_BOOK_TITEL+1];
        char m_author[MAX_AUTHOR_NAME+1];
        int m_num_chapters;
        int m_num_pages;
        double m_price;
        Chapter m_chapters[MAX_NUM_CHAPTERS];

        void init_book();
        int add_chapter(Chapter* chapter);
    public:
        Book();
        Book(const char* title_);
        Book(const char* title_, const char* author_, double price_);
        void summary(); // Print a book summary
        //                  <<< LAB >>>
        void operator++(int);
        std::ostream& display(std::ostream& os); // Print
        operator int() const;
        operator bool() const;
        operator double() const;
        operator const char *() const;
        bool operator!() const;
        Book& operator+=(Chapter& chapter);
        Book& operator-=(double discount);
    };
    std::ostream& operator<<(std::ostream& os,Book& book);
}
#endif // ! SDDS_BOOK_H_
