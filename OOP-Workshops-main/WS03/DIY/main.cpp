/* ------------------------------------------------------
                 Workshop - #3 Part - #2
Full Name  : Alfej Savaya
Student ID#: 118823210
Email      : aasavaya@myseneca.ca
Section    : NFF
Date       : 06 Jun 2022

Authenticity Declaration:
I declare this submission is the result of my own work,
only got some sort of help from professors functions
used during lectures when explaining and used the same
logic of the functions given in the previous Workshop.
Used Google to check on the possible ways to solve the
function 'draw()' in file BarChart.cpp

File : main.cpp
 ------------------------------------------------------
 ------------------------------------------------------
Workshop 3:
Version: 1.0
Author: Fardad Soleimanloo
Description:
This file tests the BarChart section of your DIY workshop
-----------------------------------------------------*/
#include <iostream>
#include "BarChart.h"
using namespace sdds;
using namespace std;
int main() {
   BarChart bc;
   bc.init("How much students like this lab.", 5, '=');
   bc.add("Best Lab Ever", 2);
   bc.add("Good Lab", 10);
   bc.add("Doable Lab", 63);
   cout << "Premature draw call:"<< endl; 
   bc.draw(); // will not draw; it will print an error instead
   bc.add("Bad Lab", 10);
   bc.add("Worst Lab Ever", 5);
   cout << "Proper draw call after all samples are entered:" << endl;
   bc.draw();
   bc.deallocate();
   return 0;
}