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
Filename: Chapter.h
 ------------------------------------------------------*/
#ifndef SDDS_CHAPTER_H_
#define SDDS_CHAPTER_H_
#include <iostream>
namespace sdds {
   const int MAX_CHAPTER_TITLE = 20;
    class Chapter
    {
        char m_title[MAX_CHAPTER_TITLE+1];
        int m_num_pages;
        int m_num_words;
        unsigned int m_chapter_number;
        void init_chapter();
    public:
        Chapter();
        Chapter(const char* title_);
        Chapter(const char* title_, int chapter_num, int n_pages, int n_words);
        std::ostream& display(std::ostream&)const;
        //             <<< LAB >>>
        operator int() const;
        operator double() const;
        operator const char *() const;
        Chapter& operator=(const Chapter& ro);
        void operator++();
        void operator--();
        int get_num_pages();
    };
std::ostream& operator<<(std::ostream& os,Chapter& chapter);
}
#endif


