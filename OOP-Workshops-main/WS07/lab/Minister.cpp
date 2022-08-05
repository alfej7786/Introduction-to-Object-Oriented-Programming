/* ------------------------------------------------------
                    Workshop - #7 
Full Name  : Alfej Savaya
Student ID#: 118823210
Email      : aasavaya@myseneca.ca
Section    : NFF
Date       : 15 July 2022

Authenticity Declaration:
I declare this submission is the result of my own work, 
only got some sort of help from professors functions 
used during lectures when explaining and used the same 
logic of the functions given in the Question.
Filename: Minister.cpp
 ------------------------------------------------------*/

#include <cstring>
#include <iomanip>
#include "Minister.h"

using namespace std;
namespace sdds {
    Minister::Minister() {
        setEmpty();
    }

    Minister::Minister(const char* id, int age, double year, const char* nameOfPM , const char* district) : MemberParliament(id, age) {
        MemberParliament::NewDistrict(district);
        strcpy(PM_name, nameOfPM);
        this->year = year;
    }

    // A mutator that updates the PM the minister reports to.
    void Minister::changePM(const char* pm) {
        strcpy(PM_name, pm);
    }

    // A mutator that updates the year the minister assumed office
    void Minister::assumeOffice(double year) {
        this->year = year;
    }

    // A query that inserts into os the content of the object in the format
    ostream& Minister::write(ostream& os) const {
        os << "| " << getID() << " | " << getAge() << " | " << getDistrict() << " | " << PM_name << "/" << year;
        return os;
    }

    // A mutator that reads from the stream in the data for the current object
    istream& Minister::read(istream& in) {
        char rpt[MAX_PM_NAME_LENGTH]{};
        double offYear{};

        MemberParliament::read(in);
        cout << "Reports TO: ";
        in >> rpt;
        cout << "Year Assumed Office: ";
        in >> offYear;

        setName(rpt);
        setYear(offYear);

        return in;
    }



    // Sets all members to empty state;
    void Minister::setEmpty() {
        MemberParliament::setEmpty();
        PM_name[0] = '\0';
        year = 0;
    }

    void Minister::setName(const char* m_name) {
        strcpy(PM_name, m_name);
    }


    void Minister::setYear(double year) {
        this->year = year;
    }

        // Overloading the insertion and extraction operators
    ostream& operator<<(std::ostream& os, const Minister& p_Minister) {
        return p_Minister.write(os);
    }
    istream& operator>>(std::istream& is, Minister& p_Minister) {
        return p_Minister.read(is);
    }
}