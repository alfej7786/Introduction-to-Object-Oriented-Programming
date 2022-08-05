/* ------------------------------------------------------
                 Workshop - #6 Part - #2
Full Name  : Alfej Savaya
Student ID#: 118823210
Email      : aasavaya@myseneca.ca
Section    : NFF
Date       : 11 July 2022

Authenticity Declaration:
I declare this submission is the result of my own work, 
only got some sort of help from professors functions 
used during lectures when explaining and used the same 
logic of the functions given in the Question.
Filename: Basket.cpp
 ------------------------------------------------------*/
#include "Basket.h"
#include <iomanip>

using namespace std;
namespace sdds {
    // sets to empty
    void Basket::setEmpty() {
    m_fruits = nullptr;
    m_cnt = 0;
    m_price = 0;
    }

    // Default Constructor
    Basket::Basket() {
        setEmpty();
    }

    // Custom Constructor
    Basket::Basket(Fruit* fruitArray, int arraySize, double basketPrice) {
        if (fruitArray != nullptr && arraySize > 0 && basketPrice > 0)
        {
            m_fruits = new Fruit[arraySize];
            for (int i = 0; i < arraySize; i++)
            {
                m_fruits[i] = fruitArray[i];
            }
            m_cnt = arraySize;
            m_price = basketPrice;
        }   
    }

    // Copy Constructor
    Basket::Basket(const Basket& basket) {
        setEmpty();
        *this = basket;
    }

    // The Destructor 
    Basket::~Basket() {
        delete[] m_fruits;
    }

    // Copy Assignment Operator
    Basket& Basket::operator=(const Basket& basket) {
        delete[] m_fruits;
        m_fruits = new Fruit[basket.m_cnt];

        m_cnt = basket.m_cnt;
        m_price = basket.m_price;

        for (int i = 0; i < basket.m_cnt; i++)
        {
            m_fruits[i] = basket.m_fruits[i];
        }
        return *this;
    }

    // bool operator
    Basket::operator bool () const {
        return (m_cnt != 0);
    }

    // Updates the m_price attribute
    void Basket::setPrice(double price)  {
        m_price = price;
    }


    // An overload of the += operator
    Basket& Basket::operator+=(Fruit fruit) {
        Fruit* temp = new Fruit[m_cnt + 1];
        for (int i = 0; i < m_cnt; i++)
        {
            temp[i] = m_fruits[i];
        }
        m_cnt++;
        temp[m_cnt - 1] = fruit;
        delete[] m_fruits;
        m_fruits = temp;

        return *this;
    }

    // Function to Print
    ostream& Basket::display(ostream& ostr) const {
        if (m_cnt == 0)
        {
            ostr << "The basket is empty!" << endl;
        } else
        {
            ostr << "Basket Content:" << endl;
            for (int i = 0; i < m_cnt; i++)
            {
                ostr << setw(10) << right << m_fruits[i].m_name;
                ostr << ": ";
                ostr << setprecision(2) << fixed << showpoint << m_fruits[i].m_qty;
                ostr << "kg" << endl;
            }
            ostr << "Price: " << m_price << endl;
        }
        return ostr; 
    }

    // Overloading the insertion operator
    ostream& operator<<(ostream& os, const Basket& basket) {
        return basket.display(os);
    }
}