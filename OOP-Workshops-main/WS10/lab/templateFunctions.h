/* ------------------------------------------------------
                    Workshop - #10
Full Name  : Alfej Savaya
Student ID#: 118823210
Email      : aasavaya@myseneca.ca
Section    : NFF
Date       : 04 August 2022

Authenticity Declaration:
I declare this submission is the result of my own work, 
only got some sort of help from professors functions 
used during lectures when explaining and used the same 
logic of the functions given in the Question.
Filename: templateFunctions.h
 ------------------------------------------------------*/
//Name: Alfej Savaya
//ID: 118823210
//Email: aasavaya@myseneca.ca
// Date: 04 August 2022
//Section: NFF

#ifndef SDDS_TEMPLATEFUNCTIONS_H_
#define SDDS_TEMPLATEFUNCTIONS_H_
#include <iostream>
#include "Collection.h"
namespace sdds {
	//Find with 3 parameters
	//Checks if a key value matches an array item at a provided index Arguments
	template <typename type1, typename type2>
	bool find(type1 arr[], type2 key, int index) {
        return (arr[index] == key);
    }

	//Find with 4 parameters
	//Accepts four arguments in any order you prefer
	template <typename type1, typename type2, typename type3>
    int find(const type1 arg1[], int numberOfElements, const type2 arg2, const type3 arg3) {
        int i, result = -1, flag = 1;
        for (i = 0; i < numberOfElements && flag == 1; i++) 
        {
            if ((arg1[i] == arg2) && (arg1[i] == arg3)) 
            {
                result = i;
                flag = 0;
            }
        }

        return result;
    }

	//Insertion operator
	//Takes a reference to an ostream object and a collection template as parameters
	template <typename T>
	std::ostream& operator<<(std::ostream& os, Collection<T>& collection) {
        int i;
        for (i = 0; i < collection.size(); i++) 
        {
            os << collection[i] << std::endl;
        }

        return os;
    }


	//Load Collection
	//Takes a reference to a collection (of template type 1) and an object of the same type
	template <typename type1>
    const Collection<type1>& loadCollection(Collection<type1>& collection, type1 obj) {
        collection += obj;
        return collection;
    }
}
#endif // !SDDS_SEARCH_H_

