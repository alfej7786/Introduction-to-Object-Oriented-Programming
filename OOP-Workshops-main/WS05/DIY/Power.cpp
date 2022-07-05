/* ------------------------------------------------------
                 Workshop - #5 Part - #2
Full Name  : Alfej Savaya
Student ID#: 118823210
Email      : aasavaya@myseneca.ca
Section    : NFF
Date       : 20 Jun 2022

Authenticity Declaration:
I declare this submission is the result of my own work, 
only got some sort of help from professors functions 
used during lectures when explaining and used the same 
logic of the functions given in the Question.
Filename: Power.cpp
 ------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include "Power.h"

using namespace std;

namespace sdds {

	Power::Power() {
		this->setEmpty();
	}
	Power::Power(const char* name, int rarity) {
		this->createPower(name, rarity);
	}
	void Power::setEmpty() {
		m_name[0] = '\0';
		m_rarity = 0;
	}
	void Power::createPower(const char* name, int rarity) {
		if (name && name[0] != '\0' && rarity > 0) {
			strncpy(this->m_name, name, MAX_NAME_LENGTH);
			this->m_rarity = rarity;
		}
		else {
			this->setEmpty();
		}
	}
	const char* Power::checkName() const {
		return m_name;
	}
	int Power::checkRarity() const {
		return m_rarity;
	}
	bool Power::isEmpty() const {
		return (m_name[0] == '\0' || m_rarity == 0 );
	}
	void displayDetails(Power* powers, int size) {
		cout << "List of available powers: " << endl;
		for (int i = 0; i < size; i++) {
			if (!powers[i].isEmpty()) {
				cout << "  Name: " << powers[i].checkName() << ", "
					<< "Rarity: " << powers[i].checkRarity() << endl;
			}
		}
	}
}