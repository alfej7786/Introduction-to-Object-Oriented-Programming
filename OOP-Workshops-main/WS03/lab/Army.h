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

#ifndef SDDS_ARMY_H
#define SDDS_ARMY_H
#define MAX_NAME_LEN 50
namespace sdds {


class Army {
private:   // Private Member Functions
    char m_armyNationality[MAX_NAME_LEN + 1];
    int m_armyUnits{};
    double m_armyPower{};
public:    // Public Member Functions
    Army();
    void setEmpty();
    void createArmy(const char* country, double pow, int troops);
    void updateUnits(int troops);
    const char* checkNationality() const;
    int checkCapacity() const;
    double checkPower() const;
    bool isEmpty() const;
    bool isStrongerThan(const Army& army)const;
};
// Global (stand-alone) Functions
void battle(Army& arm1, Army& arm2);
void displayDetails(const Army* armies, int size);

}
#endif //!ARMY_H