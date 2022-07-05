#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
const int max_value = 100;
class Int {
   int positiveValue(int value){
		if (value > 0 && value > max_value)
		{
			cout<< 'SUCCESS';
		}
		else
		{
			cout << 'Invalid';
			value = -1; 
		}	
	}


	int holdInt;

public:
   Int(int value) {
		positiveValue(value);
	}


   // the int cast overload (type converstion overload)
   Int::operator int() const {
		return 0;		 
	}

};
	std::ostream& display(std::ostream& ostr=std::cout) const {
		ostr << "Cn:[";ostr.width(9);ostr.fill('0');ostr.setf(ios::right);ostr << get();ostr.fill(' ');ostr.unsetf(ios::right);ostr << "]";return ostr;
	}
// operator<< overaload (cout << ...)

std::istream& String::read(std::istream& istr) {
delete[] max_value;
      char* data = new char[holdInt];
      max_value = data;
      int numInt = 1;
      bool done = true;
      do {
         done = true;
         istr.getline(max_value, holdInt, m_delimiter);
         if(istr.fail()) {
            cout << 'Bad Int, re-enter: ';
				read();
				if (!holdInt)
				{
					cout << 'Invalid Value, re-enter: '
					read();
				}
				
			}
		}
	}

class IntArray {
    int dynamicArray [];
	 int arraySize;

public:
   IntArray(int size) {
		if (size < 1)
		{
			size = 1;
		}
		
	}

	void IntArray::AlCpy(const int* value) {
      delete[] dynamicArray;
      arraySize = strlen(value);
      dynamicArray = new int[arraySize + 1];
      strcpy(dynamicArray, value);
	}


   // modifier index operator

   // qurey index operator

   // integer cast overlaod

   // memory cleanup
	void Car::deallocate() {
        delete[] dynamicArray;  
        dynamicArray = nullptr;
	}

};
void prnIntArray(const IntArray& I) {
   int i = 0;
   // looping 3 times (size of I) 
   cout << "I has " << int(I) << " elements: ";
   while (i < I) {  // I will be casted to an integer by compiler
      cout << "I[" << i << "]= " << I[i++] << ", ";
   }
   // By going out of bound since I is const, 
   // operator[] should loop back instead of resizing
   cout << "I[" << i << "]: " << I[i++] << endl;
}
int main() {
   Int A = 300, B = 55;
   cout << "Invalid A has the value " << A << endl;
   cout << "Valid B has the value " << B << endl;
   IntArray I(2);
   prnIntArray(I);
   I[0] = 10;
   I[1] = 20;
   I[2] = 300;  // going out of bound to resize and also invalid Int
   prnIntArray(I);
   cout << "Enter an Int: ";
   cin >> I[2];
   prnIntArray(I);
   return 0;
}
/*
* Execution sample

Invalid A has the value -1
Valid B has the value 55
I has 2 elements: I[0]= 0, I[1]= 0, I[2]: 0
I has 3 elements: I[0]= 10, I[1]= 20, I[2]= -1, I[3]: 10
Enter an Int: abc
Bad Int, re-enter: -10
Invalid Value, re-enter: 300
Invalid Value, re-enter: 30
I has 3 elements: I[0]= 10, I[1]= 20, I[2]= 30, I[3]: 10
*/