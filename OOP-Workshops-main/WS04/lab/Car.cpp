/* ------------------------------------------------------
                 Workshop - #4 Part - #1
Full Name  : Alfej Savaya
Student ID#: 118823210
Email      : aasavaya@myseneca.ca
Section    : NFF
Date       : 10 Jun 2022

Authenticity Declaration:
I declare this submission is the result of my own work, 
only got some sort of help from professors functions 
used during lectures when explaining and used the same 
logic of the functions given in the Question.
Filename: Car.cpp
 ------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include "Car.h"

using namespace std;

namespace sdds {
    // Constructor Car
    Car::Car() {
        resetInfo(); // Resets all to nullptr and 0
    }

    // Constructor Car
    Car::Car(const char* type, const char* brand, const char* model, int year, int code, double price) {
        readType(type);
        readBrand(brand);
        readModel(model);
        readYear(year);
        readCode(code);
        readPrice(price);
        if (!(isValid())) { // if not Valid reset all 
            resetInfo();
        }
    }

    // Destructor ~Car
    Car::~Car() {
        deallocate();
    }

    // Function resetInfo
    void Car::resetInfo() {
        m_type = nullptr; // nullptr
        m_brand = nullptr; // nullptr
        m_model = nullptr; // nullptr
        m_year = 0; // set to 0
        m_code = 0; // set to 0
        m_price = 0; // set to 0
    }

    // Function setInfo
    Car& Car::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {
        deallocate(); // deallocate first
        if ((type != nullptr && type[0] != '\0') && (brand != nullptr && brand[0] != '\0') && 
            (model != nullptr && model[0] != '\0') && (year >= 1990) && (price > 0)  && (code > 99 && code < 1000)) 
        {
            readType(type);
            readBrand(brand);
            readModel(model);
            readYear(year);
            readCode(code);
            readPrice(price);
        }
        return *this; // return this function
    }

    // Function printInfo
    void Car::printInfo() const {
        cout.setf(ios::left);
        cout << "| "; cout.width(10); cout << m_type;
        cout << " | "; cout.width(16); cout << m_brand;
        cout << " | "; cout.width(16); cout << m_model;
        cout << " | "; cout << m_year << " |  "; cout << m_code << " |  ";
        cout.unsetf(ios::left); cout.width(8);
        cout.setf(ios::fixed);
        cout.setf(ios::right); cout.precision(2); cout << m_price << " |";
        cout.unsetf(ios::right);
        cout.unsetf(ios::fixed); cout << "\n";
    }

    // Function isValid
    bool Car::isValid() const {
        bool done = false;
        // Checks if all the members are valid
        if ((m_type != nullptr && m_type[0] != '\0') && (m_brand != nullptr && m_brand[0] != '\0') 
            && (m_model != nullptr && m_model[0] != '\0') && (m_year >= 1990) && (m_price > 0)  
            && (m_code > 99 && m_code < 1000)) 
        {
            done = true;
        }
        return done;
    }

    // Function isSimilarTo
    bool Car::isSimilarTo(const Car& car) const {
        bool done = false;
        if ((strcmp(m_type, car.m_type) == 0) && (strcmp(m_model, car.m_model) == 0)  && 
            (strcmp(m_brand, car.m_brand) == 0) && (m_year == car.m_year)) 
        {
            done = true;
        }
        return done;
    }

    // Function has_similar
    // This was defined in the Question 
    bool has_similar(const Car car[], const int num_cars) {
        bool done = false;
        for (int i = 0; i < num_cars; i++) 
        {
            for (int j = i + 1; j < num_cars; j++)
            {
                if (car[i].isValid() && car[j].isValid() && (car[i].isSimilarTo(car[j])))
                {
                    done = true;
                }
            }
        }
        return done;
    }

    // Function has_invalid
    bool has_invalid(const Car car[], const int num_cars) {
        bool done = false;
        int flag = 1, i;
        for (i = 0; i < num_cars && flag == 1; i++) 
        {
            if (!car[i].isValid()) 
            {
                done = true;
                flag = 0;
            }
        }
        return done;
    }

    // Function print
    void print(const Car car[], const int num_cars) {
        int i;
        for (i = 0; i < num_cars; i++) {
            if (car[i].isValid()) {
                car[i].printInfo();
            }
        }
    }

    // Set the type
    void Car::readType(const char* type) {
        if (type != nullptr && type[0] != '\0') 
        {
            m_type = new char[strlen(type) + 1];
            strcpy(m_type, type);
        }
    }

    // Set the brand
    void Car::readBrand(const char* brand) {
        if (brand != nullptr && brand[0] != '\0') 
        {
            m_brand = new char[strlen(brand) + 1];
            strcpy(m_brand, brand);
        }
    }

    // Set the model
    void Car::readModel(const char* model) {
        if (model != nullptr && model[0] != '\0') 
        {
            m_model = new char[strlen(model) + 1];
            strcpy(m_model, model);
        }
    }

    // Sett the year
    void Car::readYear(int year) {
        if (year >= 1990) 
        {
            m_year = year;
        }
    }

    // Set the code
    void Car::readCode(int code) {
        if (code > 99 && code < 1000) 
        {
            m_code = code;
        }
    }

    // Set the price
    void Car::readPrice(double price) {
        if (price > 0) 
        {
            m_price = price;
        }
    }

    // Function Deallocate
    // Deallocates all the dynamically allocated memory
    void Car::deallocate() {
        delete[] m_type;  // type
        m_type = nullptr;

        delete[] m_model;  // model
        m_model = nullptr;

        delete[] m_brand;  // brand
        m_brand = nullptr;
    }
}