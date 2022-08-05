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
Filename: MemberParliament.cpp
 ------------------------------------------------------*/

#include "MemberParliament.h"
#include <iomanip>
#include <cstring>

namespace sdds {
    // Sets to empty
    MemberParliament::MemberParliament(){
        setEmpty();
    }

    // A custom constructor
    MemberParliament::MemberParliament(const char* MP_ID, int age) {
        strcpy(parliament_ID, MP_ID);
        MP_age = age;
        strcpy(MP_district, "Unassigned");
    }

    // Assigns the MP to new district
    void MemberParliament::NewDistrict(const char* district) {
        std::cout << "|  " << parliament_ID << "| |" << std::setw(20) << std::right << MP_district << " ---> " << std::setw(23) << std::left << district << "|" << std::endl;
        strcpy(MP_district, district);
    }

    // A query that inserts into os the content of the object in the format
    std::ostream& MemberParliament::write(std::ostream& os) const {
        os << "| " << parliament_ID << " | " << MP_age << " | " << MP_district;
        return os;
    }

    // A mutator that reads from the stream in the data for the current object
    std::istream& MemberParliament::read(std::istream& in) {
        std::cout << "Age: ";
        in >> MP_age;
        std::cout << "Id: ";
        in >> parliament_ID;
        std::cout << "District: ";
        in >> MP_district;

        return in;
    }

    // Additional Functions
    void MemberParliament::setEmpty() {
        parliament_ID[0] = '\0';
        MP_district[0] = '\0';
        MP_age = 0;
    }


    // Gets ID
    const char* MemberParliament::getID() const {
        return parliament_ID;
    }


    // Gets District
    const char* MemberParliament::getDistrict() const {
        return MP_district;
    }
        

    // Gets Age    
    int MemberParliament::getAge() const {
        return MP_age;
    }

    
    // Overloading the insertion and extraction operators
    std::ostream& operator<<(std::ostream& os, const MemberParliament& member) {
        return member.write(os);
    }

    std::istream& operator>>(std::istream& is, MemberParliament& member) {
        return member.read(is);
    }
}