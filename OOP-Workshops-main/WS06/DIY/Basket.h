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
Filename: Basket.h
 ------------------------------------------------------*/
#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H
#include <iostream>

namespace sdds {
    struct Fruit    {
        char m_name[30 + 1]; // the name of the fruit
        double m_qty;        // quantity in kilograms
        };

    class Basket    {
    private:
        Fruit* m_fruits;
        int m_cnt;
        double m_price;
    public:
        // Constructors
        // Default Constructor
        Basket(/* args */);
        // Custom Constructor
        Basket(Fruit* fruitArray, int arraySize, double basketPrice);
        // Copy Constructor
        Basket(const Basket& Basket);
        // The Destructor 
        ~Basket();

        // Copy Assignment Operator
        Basket& operator=(const Basket& basket);

        void setPrice(double price);

        // Bool Operator
        operator bool() const;

        // An overload of the += operator
        Basket& operator+= (Fruit fruit);

        // Function to display the basket content
        std::ostream& display(std::ostream& ostr) const;

        // sets to empty
        void setEmpty();

};
    // Friend Helper Functions
    // Overloading the insertion operator
    std::ostream& operator<<(std::ostream& os, const Basket& basket);
}
#endif // !SDDS_BASKET_H