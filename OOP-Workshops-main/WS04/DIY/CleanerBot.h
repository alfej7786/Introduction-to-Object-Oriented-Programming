/* ------------------------------------------------------
                 Workshop - #4 Part - #1
Full Name  : Alfej Savaya
Student ID#: 118823210
Email      : aasavaya@myseneca.ca
Section    : NFF
Date       : 13 Jun 2022

Authenticity Declaration:
I declare this submission is the result of my own work, 
only got some sort of help from professors functions 
used during lectures when explaining and used the same 
logic of the functions given in the Question.
Filename: CleanerBot.h
 ------------------------------------------------------*/

#ifndef SDDS_CLEANERBOT_H
#define SDDS_CLEANERBOT_H
namespace sdds{
    class CleanerBot{
        char *curent_location; // indicates the robot's current location
        double remain_battery; // holds the robot's remaining battery percentage
        int numOf_Brush; // holds the robot's number of brushes
        bool is_active; // indicated whether the robot is active or not
        public:
        // Constructor
        CleanerBot(); // default
        CleanerBot(const char *location, double battery, int brush, bool active); // 4 arguments
        // Destructor
        ~CleanerBot();
        // FUNCTIONS
        // Modifiers:
        void set(const char *location, double battery, int brush, bool active);
        void setLocation(const char *location);
        void setActive(bool active);
        // Quiries
        const char *getLocation() const;
        double getBattery() const;
        int getBrush() const;
        bool isActive() const;
        bool isValid() const;
        // Display
        void display() const;
    };
    // The Robots Information stand alone report function
    int report(CleanerBot* robot, short num_robot);
    void sort(CleanerBot* robot, int num_robot);
}
#endif // ! SDDS_CLEANERBOT_H