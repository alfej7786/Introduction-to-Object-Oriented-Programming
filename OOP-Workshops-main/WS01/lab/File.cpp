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

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include "File.h"

using namespace std;
namespace sdds {

const char* const SHOPPING_DATA_FILE = "shoppinglist.csv";
FILE* sfptr = nullptr;

bool openFileForRead() {
   sfptr = fopen(SHOPPING_DATA_FILE, "r");
   return sfptr != NULL;
}

bool openFileForOverwrite() {
   sfptr = fopen(SHOPPING_DATA_FILE, "w");
   return sfptr != NULL;
}

void closeFile() {
   if (sfptr) fclose(sfptr);
}

bool freadShoppingRec(ShoppingRec* rec) {
   int flag = 0;
   bool success = fscanf(sfptr, "%[^,],%d,%d\n",
      rec->m_title, &rec->m_quantity, &flag) == 3;
   rec->m_bought = !!flag;
   return success;
}

void fwriteShoppintRec(const ShoppingRec* rec) {
   fprintf(sfptr, "%s,%d,%d\n", rec->m_title, rec->m_quantity, rec->m_bought);
}
}
