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

// Workshop 1:
// Version: 1.0
//   fixed bug for deleting the first item. 
//   this fix will not effect submission results
// Date: 2021/10/16
// Author: Fardad Soleimanloo
// Description:
// w1p1.cpp
//
///////////////////////////////////////////////////
*/

#include <iostream>
#include <cstdlib>
#include "File.h"
#include "ShoppingList.h"
#include "Utils.h"

using namespace std;
using namespace sdds;

// set to false when compling on Linux
const bool APP_OS_WINDOWS = false;


int listMenu();

int main() {
   bool done = false;
   loadList();
   while (!done) {
      system(APP_OS_WINDOWS ? "cls" : "clear");
      switch (listMenu()) {
      case 1:
         toggleBought();
         break;
      case 2:
         addItemToList();
         break;
      case 3:
         removeItemfromList();
         break;
      case 4:
         removeBoughtItems();
         break;
      case 5:
         clearList();
         break;
      default:
         done = true;
      }
   }
   saveList();
   return 0;
}

int listMenu() {
   cout << "-->>> My Shopping List <<<--" << endl;
   displayList();
   cout << "----------------------------" << endl
      << "1- Toggle bought Item" << endl
      << "2- Add Shopping Item" << endl
      << "3- Remove Shopping Item" << endl
      << "4- Remove bought Items" << endl
      << "5- Clear List" << endl
      << "0- Exit" << endl << "> ";
   return readInt(0, 5);
}
