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

#ifndef SDDS_SHOPPINGREC_H 
#define SDDS_SHOPPINGREC_H

namespace sdds{
const int MAX_TITLE_LENGTH = 50;
const int MAX_QUANTITY_VALUE = 50;

struct ShoppingRec {
   char m_title[MAX_TITLE_LENGTH + 1];
   int m_quantity;
   bool m_bought;
};

void displayShoppingRec(const ShoppingRec* shp);
void toggleBoughtFlag(ShoppingRec* rec);
bool isShoppingRecEmpty(const ShoppingRec* shp);
ShoppingRec getShoppingRec();
}


#endif