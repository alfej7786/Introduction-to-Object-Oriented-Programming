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
Filename: Book.cpp
 ------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Book.h"

using namespace std;
namespace sdds {
	void Book::init_book() {
		m_title[0] = '\0';
		m_author[0] = '\0';
		m_num_chapters=0;
		m_num_pages=0;
	}

	Book::Book() {
		init_book();
	}

	Book::Book(const char* title_) {
		init_book();
		strcpy(m_title, title_);
	}

	Book::Book(const char* title_, const char* author_, double price_) {
		init_book();
		strcpy(m_title, title_);
		strcpy(m_author, author_);
		m_price = price_;
	}

	// Print a book summary
	void Book::summary() {
		cout.setf(ios::left);
		cout << "| ";
		cout.width(MAX_BOOK_TITEL);
		cout << m_title << " | ";
		cout.width(MAX_AUTHOR_NAME);
		cout << m_author << " | ";
		cout.width(3);
		cout << m_num_chapters << "  ";
		cout.width(4);
		cout << m_num_pages << " | ";
		cout.width(6);
		cout << m_price << " |" << endl;
	}
	// 				<<< LAB >>>
	// A postfix ++ operator overload
	// Increase the number of chapters by one.
	void Book:: operator++(int) {
		m_num_chapters += 1;
	}

	// Function add_chapter
	// Receives a pointer to a chapter
	int Book::add_chapter(Chapter *chapter) {
		m_num_pages += int(*chapter);
		m_chapters[m_num_chapters] = *chapter;
		(*this)++;
		return int(*this);
	}

	// Member function called display
	// Print a book object according to the provided sample output.
    std::ostream& Book:: display(std::ostream& os) {
		os << "Title:'" << m_title << "'" << std::endl;
  		os << "Author: '" << m_author << "'" << std::endl;
  		for (int i=0;i<m_num_chapters;i++) 
		{
    		os << m_chapters[i];
		}
		return os;
	}

	// An int type cast operator
	// It will return the number of chapters of a book object.
    Book:: operator int() const {
		return m_num_chapters;
	}

	// A bool type cast operator
	// It will return true if title and author
    Book:: operator bool() const {
		if (m_author[0] != '\0' && m_title[0] != '\0' && m_num_chapters > 0) 
		{
			if (int(m_chapters[0]) > 0) 
			{
			return true;
			}
		}
		return false;
	}

	// A double type cast operator
	// It will return the book price.
    Book:: operator double() const {
		return m_price;
	}

	// A const char* type cast operator
	// It will return title of the book.
    Book:: operator const char *() const {
		return m_title;
	}

	// A logical not operator overload
	// return true if any of the conditions mentioned 
	// for the bool operator overload are not true.
    bool Book:: operator!() const {
		if (m_author[0] == '\0' || m_title[0] == '\0' || m_num_chapters == 0) 
		{
    		return true;
		}
		if (m_num_chapters > 0) 
		{
    		if (int(m_chapters[0]) == 0) 
			{
      		return true;
   			}
  		}
  		return false;
	}	

	// A += operator overload
	// Allow adding a chapter to a book.
    Book& Book:: operator+=(Chapter& chapter) {
		add_chapter(&chapter);
		return *this;
	}

	// A -= operator overload
	// apply a dollar value discount to the book price.
    Book& Book:: operator-=(double discount) {
		m_price -= discount;
		return *this;
	}

	// An insertion operator overload
	// Allow printing of a book object to the output console
    std::ostream& operator<<(std::ostream& os,Book& book) {
		book.display(os);
		return os;
	}
}
