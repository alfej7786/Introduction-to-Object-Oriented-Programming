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
 ------------------------------------------------------
 ------------------------------------------------------
Workshop 4 part 1
Filename: main.cpp
Version 1.0
Author: Asad Norouzi
-----------------------------------------------------------*/
#include<iostream>
#include<iomanip>
#include "Car.h"
using namespace std;
using namespace sdds;

int main()
{
	const int num_cars = 6;
	Car carInventory[num_cars] = {
		{},
		{"suv", "volvo", "xc90"},
		{"Truck", "Ford", "F 150", 2021, 105, 55000},
		{"Sedan", "BMW", "M550i", 2022, 101, 91000},
		{"Truck", "Tesla", "Cybertruck", 2021, 102, 65000},
		{"Sedan", "BMW", "M550i"}
	};
	
	if (carInventory[2].setInfo("SUV", "Volvo", "XC90", 2019, 109, 80000).isValid()) {
		cout << "Information was set correctly!" << endl;
	}
	else {
		cout << "Information was set incorrectly!" << endl;
	}
	if (carInventory[1].setInfo(nullptr, "Volvo", "XC90", 2019, 109, 80000).isValid()) {
		cout << "Information was set correctly!" << endl;
	}
	else {
		cout << "Information was set incorrectly!" << endl;
	}
	if (carInventory[1].setInfo("SUV", nullptr, "XC90", 2019, 109, 80000).isValid()) {
		cout << "Information was set correctly!" << endl;
	}
	else {
		cout << "Information was set incorrectly!" << endl;
	}
	if (carInventory[1].setInfo("SUV", "Volvo", nullptr, 2019, 109, 80000).isValid()) {
		cout << "Information was set correctly!" << endl;
	}
	else {
		cout << "Information was set incorrectly!" << endl;
	}
	if (carInventory[1].setInfo("SUV", "Volvo", "XC90", 1934, 109, 80000).isValid()) {
		cout << "Information was set correctly!" << endl;
	}
	else {
		cout << "Information was set incorrectly!" << endl;
	}
	if (carInventory[1].setInfo("SUV", "Volvo", "XC90", 2019, 1, 80000).isValid()) {
		cout << "Information was set correctly!" << endl;
	}
	else {
		cout << "Information was set incorrectly!" << endl;
	}
	if (carInventory[1].setInfo("SUV", "Volvo", "XC90", 2019, 109, 0).isValid()) {
		cout << "Information was set correctly!" << endl;
	}
	else {
		cout << "Information was set incorrectly!" << endl;
	}

	cout << setw(60) << "----- Testing printInfo function -----" << endl << endl;
	cout << "| Type       | Brand            | Model            | Year | Code |     Price |" << endl;
	cout << "+------------+------------------+------------------+------+------+-----------+" << endl;
	carInventory[4].printInfo();
	cout << endl << endl;
	cout << setw(60) << "----- Car Inventory Information -----" << endl << endl;
	cout << "| Type       | Brand            | Model            | Year | Code |     Price |" << endl;
	cout << "+------------+------------------+------------------+------+------+-----------+" << endl;
	print(carInventory, num_cars);

	if (has_invalid(carInventory, num_cars)) {
		cout << endl;
		cout << setfill('*') << setw(60) << "*" << endl;
		cout << "*  WARNING: There are invalid data in the inventory!      *" << endl;
		cout << setfill('*') << setw(60) << "*" << endl;
	}
	if (has_similar(carInventory, num_cars)) {
		cout << endl;
		cout << setfill('+') << setw(60) << "+" << endl;
		cout << "+  WARNING: There are similar entries in the inventory!   +" << endl;
		cout << setfill('+') << setw(60) << "+" << endl;
	}
	return 0;
}