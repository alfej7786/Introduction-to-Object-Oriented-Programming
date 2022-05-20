/*
*****************************************************************************
                          Workshop - #1 (P1)
Full Name  : Alfej Savaya
Student ID#: 118823210
Email      : aasavaya@myseneca.ca
Section    : NFF
Date       : 19 May 2022
Citation   : Work done by myself

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#ifndef SDDS_SHOPPINGLIST_H 
#define SDDS_SHOPPINGLIST_H
#include "File.h"
#include "Utils.h"

namespace sdds{


bool loadList();
void displayList();
void removeBoughtItems();
void removeItem(int index);
bool saveList();
void clearList();
void toggleBought();
void addItemToList();
void removeItemfromList();
bool listIsEmpty();


}
#endif
