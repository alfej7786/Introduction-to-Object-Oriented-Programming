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
Filename: MemberParliament.h
 ------------------------------------------------------*/

#ifndef SDDS_MEMBERPARLIAMENT_H
#define SDDS_MEMBERPARLIAMENT_H
#include <iostream>

#define MAX_ID_CHAR_SIZE 32 // characters of size 32
#define MAX_MP_DISTRICT 64 // characters of size 64

namespace sdds {
    class MemberParliament {
    private:
        char parliament_ID [MAX_ID_CHAR_SIZE + 1]; // Statically allocated array
        char MP_district [MAX_MP_DISTRICT + 1]; // MP represents as a statically allocated array
        int MP_age; // The age of the MP
    public:
        MemberParliament(); // Default Constructor
        MemberParliament(const char* MP_ID, int age); // A custom constructor
        void NewDistrict(const char* district); // Assigns the MP to new district

        // A query that inserts into os the content of the object in the format
        std::ostream& write(std::ostream& os = std::cout) const;

        // A mutator that reads from the stream in the data for the current object
        std::istream& read(std::istream& in = std::cin);

        // Additional Functions
        void setEmpty();
        const char* getID() const; // Gets ID
        const char* getDistrict() const; // Gets District
        int getAge() const; // Gets age
    };
    // Overloading the insertion and extraction operators
    // std::ostream& operator<<(std::ostream& ostr, MemberParliament& p_Member);
    // std::istream& operator>>(std::istream& istr, MemberParliament& p_Member);
    std::ostream& operator<<(std::ostream& os, const MemberParliament& member);
    std::istream& operator>>(std::istream& is, MemberParliament& member);
}

#endif // SDDS_MEMBERPARLIAMENT_H