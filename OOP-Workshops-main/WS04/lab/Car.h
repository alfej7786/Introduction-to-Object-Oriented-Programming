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
Filename: car.h
 ------------------------------------------------------*/
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_

namespace sdds {
    class Car {
    private:
        char* m_type;
        char* m_brand;
        char* m_model;
        int m_year;
        int m_code;
        double m_price;
        // Resets the values for all member variables
        void resetInfo();

    public:
        // Constructors
        Car();
        Car(const char* type, const char* brand, const char* model, 
            int year = 2022, int code = 100, double price = 1);
        // Destructor
        ~Car();    
        Car& setInfo(const char* type, const char* brand, const char* model, 
                    int year, int code, double price);
                    
        void printInfo() const;
        bool isValid() const;
        bool isSimilarTo(const Car& car) const;
        void deallocate();
        
        // Aditional Functions
        void readType(const char* type);
        void readBrand(const char* brand);
        void readModel(const char* model);
        void readYear(int year);
        void readCode(int code);
        void readPrice(double price);
    };
    bool has_similar(const Car car[], const int num_cars);
    bool has_invalid(const Car car[], const int num_cars);
    void print(const Car car[], const int num_cars);
}

#endif  // SDDS_CAR_H_