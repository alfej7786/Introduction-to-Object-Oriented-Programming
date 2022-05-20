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

#ifndef SDDS_UTILS_H 
#define SDDS_UTILS_H

namespace sdds{
void flushkeys();
bool ValidYesResponse(char ch);
bool yes();
void readCstr(char cstr[], int len);
int readInt(int min, int max);
}
#endif