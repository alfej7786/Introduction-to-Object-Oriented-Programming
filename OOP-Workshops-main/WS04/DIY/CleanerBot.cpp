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
Filename: CleanerBot.cpp
 ------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include "CleanerBot.h"
using namespace std;
namespace sdds
{   
    // Default constructor
    CleanerBot::CleanerBot()
    {
        // all set to empty state
        curent_location = nullptr;
        remain_battery = 0;
        numOf_Brush = 0;
        is_active = false;
    }

    // Constructor with 4 arguments
    CleanerBot::CleanerBot(const char *location, double battery, int brush, bool active)
    {
        curent_location = new char[strlen(location) + 1];
        strcpy(curent_location, location);
        remain_battery = battery;
        numOf_Brush = brush;
        is_active = active;
    }

    // Destructor
    // Handles memory leak
    CleanerBot::~CleanerBot()
    {
        delete[] curent_location;
        remain_battery = 0;
        curent_location = nullptr;
    }

    // Set Function
    // to set the robot information (same order as the constructor)
    void CleanerBot::set(const char *location, double battery, int brush, bool active)
    {   
        curent_location = new char[strlen(location) + 1];
        strcpy(curent_location, location);
        remain_battery = battery;
        numOf_Brush = brush;
        is_active = active;
    }

    // setLocation Function
    // to set the robot location
    void CleanerBot::setLocation(const char *location)
    {
        curent_location = new char[strlen(location) + 1];
        strcpy(curent_location, location);
    }

    // setActive Function
    // to set the robot active status (true or false)
    void CleanerBot::setActive(bool active)
    {
        is_active = active;
    }

    // getLocation function
    //  to return the robot location
    const char *CleanerBot::getLocation() const
    {
        return curent_location;
    }

    // getBattery Function
    // to return the robot remaining battery percentage
    double CleanerBot::getBattery() const
    {
        return remain_battery;
    }

    // getBrush Function
    // to return the robot number of brushes
    int CleanerBot::getBrush() const
    {
        return numOf_Brush;
    }

    // isActive Function
    // to return if a robot is active
    bool CleanerBot::isActive() const
    {
        if (is_active == true) // if is_active equal to true
        {
            return true; // return true
        }
        else
        {
            return false; // return false
        }
    }

    // isValid Function
    // to return if the robot information is valid
    bool CleanerBot::isValid() const
    {
        return remain_battery > 0 && numOf_Brush > 0;
    }

    // report Function
    // Display information and warning messages
    int report(CleanerBot *robot, short num_robot)
    {
        cout << "         ------ Cleaner Bots Report -----\n";
        cout << "     ---------------------------------------\n";
        printf("| Location   | Battery |  Number of Brushes | Active |\n");
        printf("|------------+---------+--------------------+--------|\n");
        for (int i = 0; i < num_robot; i++)
        {
            if (robot[i].isValid())
            {
                printf("| %-10s | %7.1lf | %18d | %-6s |\n", robot[i].getLocation(), 
                robot[i].getBattery(), robot[i].getBrush(), robot[i].isActive() ? "YES" : "NO");
            }
        }

        cout << "\n";
        cout << "|====================================================|\n";
        cout << "| LOW BATTERY WARNING:                               |\n";
        cout << "|====================================================|\n";
        int low_battery = 0;
        for (int i = 0; i < num_robot; i++)
        {
            if (robot[i].isValid() && robot[i].getBattery() < 30)
            {
                low_battery++;
            }
        }
        cout << "| Number of robots to be charged: " << low_battery<<"                  |\n";
        cout << "| Sorting robots based on their available power:     |\n";
        cout << "| Location   | Battery |  Number of Brushes | Active |\n";
        cout << "|------------+---------+--------------------+--------|\n";
       
       // sort percentage of low battery to descending
        CleanerBot sort;
        for(int i = 0; i < num_robot - 1; i++){
            for(int j = i + 1 ; j<num_robot; j++){
                if(robot[i].isValid() && robot[j].isValid()){
                    if(robot[i].getBattery() < robot[j].getBattery()){
                        sort = robot[i];
                        robot[i] = robot[j];
                        robot[j] = sort;
                    }
                }
            }
        }
       
       for (int i = 0; i < num_robot; i++)
        {
            if (robot[i].isValid())
            {
                printf("| %-10s | %7.1lf | %18d | %-6s |\n", robot[i].getLocation(), 
                robot[i].getBattery(), robot[i].getBrush(), robot[i].isActive() ? "YES" : "NO");
            }
        }
        cout << "|====================================================|\n";

        return 1;
    }
}
