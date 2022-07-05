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
Filename: Hero.cpp
 ------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include "Hero.h"

namespace sdds{
    // Default constructor
    Hero::Hero() {}

    //     char* Hero::strcpy(char* des, const char* src)const {
    //       int i;
    //       for(i = 0; src[i]; i++) des[i] = src[i];
    //       des[i] = char(0);
    //       return des;
    //    }

    //    int Hero::strlen(const char* str)const {
    //       int len;
    //       for(len = 0; str[len]; len++);
    //       return len;
    //    }

    //    void Hero::AlCpy(const char* cstr) {
    //       delete[] m_heroName;
    //       levelPower = strlen(cstr);
    //       m_heroName = new char[levelPower + 1];
    //       strcpy(levelPower, cstr);
    //    }

    // Overloaded constructor with 3 parameters
    Hero::Hero(const char *name, Power listOfPower[], int countOfPower) {
        strcpy(m_heroName, name);
        m_powers = new Power[countOfPower];
        for (int i = 0; i < countOfPower; i++)
        {
            m_powers[i] = listOfPower[i];
        }
        numOfPower = countOfPower;
        countpower();
    }

    // Destructor
    Hero::~Hero() {
        delete[] m_powers;
    }

    // Hero& Hero:: resize(int newsize) {
    //     char* temp = new char[newsize + 1];
    //     strcpy(temp, m_heroName);
    //     delete[] m_heroName;
    //     m_heroName = temp;
    //     return *this;
    // }

    // Display/Print
    std::ostream &Hero::display(std::ostream &ostr) const {
        ostr << "Name: " << m_heroName << '\n';
        displayDetails(m_powers, numOfPower);
        ostr << "Power Level: " << levelPower;
        return ostr;
    }

    // overload the += operator
    Hero &Hero::operator+=(const Power &ro) {

        Power *copy = new Power[numOfPower + 1];
        for (int i = 0; i < numOfPower; i++)
        {
            copy[i] = m_powers[i];
        }
        copy[numOfPower] = ro;
        numOfPower = numOfPower + 1;
        delete[] m_powers;
        m_powers = copy;
        countpower();
        return *this;
    }

    // overload the -= operator
    Hero &Hero::operator-=(int minuseValue) {
        levelPower -= minuseValue;
        return *this;
    }

    // operator<
    bool operator<(const Hero &lefthnd, const Hero &righthnd) {
        return lefthnd.powerLevel() < righthnd.powerLevel();
    }

    // operator>
    bool operator>(const Hero &lefthnd, const Hero &righthnd) {
        return lefthnd.powerLevel() > righthnd.powerLevel();
    }

    // operator>>
    bool operator>>(Power &lefthnd, Hero &righthnd) {
        righthnd += lefthnd;
        return true;
    }

    // operator<<
    bool operator<<(Hero &lefthnd, Power &righthnd) {
        lefthnd += righthnd;
        return true;
    }


    std::ostream &operator<<(std::ostream &os, const Hero &righthnd) {
        return righthnd.display(os);
    }

    // Additional Function Created
    // powerLevel to get the powerLevel
    int Hero::powerLevel() const  {
        return levelPower;
    }

    // countPower
    void Hero::countpower(){
        levelPower = 0;
        for(int i = 0;i < numOfPower; i++){
            levelPower += m_powers[i].checkRarity();
        }
        levelPower *= numOfPower;
    }

};
