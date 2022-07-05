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
Filename: Chapter.cpp
 ------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Chapter.h"

using namespace std;

namespace sdds {
	void Chapter::init_chapter() {
		m_title[0] = '\0';
		m_num_pages = 0;
		m_num_words = 0;
		m_chapter_number = 0;
	}
	Chapter::Chapter() {
		init_chapter();
	}

	Chapter::Chapter(const char* title_) {
		init_chapter();
		strcpy(m_title , title_);
	}
	Chapter::Chapter(const char* title_, int chapter_num,  int n_pages, int n_words) {
		strcpy(m_title, title_);
		m_chapter_number = chapter_num;
		m_num_pages = n_pages;
		m_num_words = n_words;
	}
	ostream& Chapter::display(std::ostream& os)const
	{
		cout.setf(std::ios::left);
		os << "| Chapter ";
		os.width(2);
		os << m_chapter_number << " | ";
		os.width(MAX_CHAPTER_TITLE);
		os << m_title << " |" << endl;
		return os;
	}

	//						 <<< LAB >>>
	// int type cast operator
	// It will return the number of the pages in the Chapter object.
	Chapter:: operator int() const{
		return m_num_pages;
	}

	// double type cast operator
	// It will return the average number of words per page.
    Chapter:: operator double() const{
		return ((double)m_num_words / m_num_pages);
	}

	// const char* type cast operator
	// It will return the title of a chapter object.
    Chapter:: operator const char *() const{
		return m_title;
	}

	// An assignment operator overload
	// Allow setting a chapter to another chapter object.
    Chapter& Chapter:: operator=(const Chapter& ro){
		strcpy(m_title, (const char *)ro);
  		m_chapter_number = ro.m_chapter_number;
  		m_num_pages = ro.m_num_pages;
  		m_num_words = ro.m_num_words;
  		return *this;
	}

	// A prefix ++ operator overload
	// It will increase the number of pages for a chapter object by one.
    void Chapter:: operator++(){
		m_num_pages += 1;
	}

	// A prefix -- operator overload
	// It will decreases the number of pages for a chapter object by one.
    void Chapter:: operator--(){
		m_num_pages -= 1;
	}

	// gets number of PagesS
    int Chapter:: get_num_pages(){
		return m_num_pages;
	}

	// An insertion helper operator overload
	std::ostream& operator<<(std::ostream& os,Chapter& chapter) {
		chapter.display(os);
		return os;
	}	
}