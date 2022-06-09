/* ------------------------------------------------------
                 Workshop - #3 Part - #1
Full Name  : Alfej Savaya
Student ID#: 118823210
Email      : aasavaya@myseneca.ca
Section    : NFF
Date       : 02 Jun 2022

Authenticity Declaration:
I declare this submission is the result of my own work, 
only got some sort of help from professors functions 
used during lectures when explaining and used the same 
logic of the functions given in the previous Workshop.

 ------------------------------------------------------*/

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Army.h"
namespace sdds {

Army:: Army(){
    setEmpty();
}
// Set Empty
void Army:: setEmpty() {
    m_armyNationality[0] = '\0';
    m_armyUnits = 0;
    m_armyPower = 0;
}
// Function to Create Army
void Army:: createArmy(const char* country, double pow, int troops){
    if (country != nullptr && strlen(country) > 0)
    {
        if (strlen(country) > MAX_NAME_LEN)
        {
            strncpy(m_armyNationality, country, MAX_NAME_LEN);
        if (pow > 0)
        {
            m_armyPower = pow;
        }
        if (troops > 0)
        {
            m_armyUnits = troops;
        }
        
        }else
        {
            strcpy(m_armyNationality, country);
            m_armyUnits = troops;
            m_armyPower = pow;
        }
    }
    else
        setEmpty();
}

// Function to Update Troops
void Army:: updateUnits(int troops) {
    m_armyUnits += troops;
    m_armyPower += (troops * 0.25);
}
// Function to chech Army Nationality
const char* Army:: checkNationality()const {
    return m_armyNationality;
}
// Function to check Army units
int Army:: checkCapacity() const{
    return m_armyUnits;
}
// Function to check Army power
double Army:: checkPower() const{
    return m_armyPower;
}
// Function to check if it is empty
bool Army:: isEmpty() const{
    if (strlen(m_armyNationality) == 0 && m_armyUnits <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Function to check is a team is stronger than other
bool Army:: isStrongerThan(const Army& army)const {
    if (m_armyPower > army.m_armyPower)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Function to create battle
void battle( Army& arm1, Army& arm2) {
    if (!arm1.isEmpty() && !arm2.isEmpty())
    {
        cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality();
        if (arm1.isStrongerThan(arm2))
        {
            arm2.updateUnits(-arm2.checkCapacity()/2);
            cout << ", " << arm1.checkNationality() << " is victorious!" << endl;
        }
        else
        {
            cout << ", " << arm2.checkNationality() << " is victorious!" << endl;
            arm1.updateUnits(-arm1.checkCapacity()/2);
        }  
    }
}
// Function to display
void displayDetails(const Army* armies, int size) {
    cout << "Armies reporting to battle: " << endl;
    for (int i = 0; i < size; i++)
    {
        if (!armies[i].isEmpty())
        {
            cout << "Nationality: " << armies[i].checkNationality() 
            << ", Units Count: " << armies[i].checkCapacity() 
            << ", Power left: " << fixed << setprecision(1) << armies[i].checkPower() << endl;
        }
    }    
}
}