/* ------------------------------------------------------
                 Workshop - #5 Part - #2
Full Name  : Alfej Savaya
Student ID#: 118823210
Email      : aasavaya@myseneca.ca
Section    : NFF
Date       : 20 Jun 2022

Authenticity Declaration:
I declare this submission is the result of my own work, 
only got some sort of help from professors functions 
used during lectures when explaining and used the same 
logic of the functions given in the Question.
Filename: Hero.h
 ------------------------------------------------------*/
#ifndef SDDS_HERO_H
#define SDDS_HERO_H
#include <iostream>
#include "Power.h"
namespace sdds
{
const int MAX_NAME_LEN = 20; // name Length
    class Hero
    {
    private:
        /* data */
        char m_heroName[MAX_NAME_LEN + 1]{};
        Power *m_powers{};
        int numOfPower{};
        int levelPower{};
        void countpower();

        // int strlen(const char* str)const;
        // char* strcpy(char* des, const char* src)const;
        // void AlCpy(const char* cstr);
        // char* strcat(char* des, const char* src)const;
        // Hero& resize(int newsize);

    public:
        // constructors
        Hero();
        Hero(const char name[], Power ListOfPower[], int countOfPower);

        // Destructor
        ~Hero();

        // Print
        std::ostream& display(std::ostream& ostr=std::cout) const;

        // Operator and conversion overloads
        Hero& operator+=(const Power& ro);
        Hero& operator-=(int minuseValue);


        // Function created to get Power Level
        int powerLevel() const;
    };

    // Boolean helper operators
        bool operator<(const Hero& lefthnd, const Hero& righthnd);
        bool operator>(const Hero& lefthnd, const Hero& righthnd);

        bool operator>>(Power& lefthnd, Hero& righthnd);
        bool operator<<(Hero& lefthnd, Power& righthnd);
        std::ostream& operator<<(std::ostream& ostr, const Hero& ro);
        //std::istream& operator>>(std::istream& istr,Hero& ro);
    
}

#endif // SDDS_HERO_H