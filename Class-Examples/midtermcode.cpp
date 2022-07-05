#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
class Book {
private:
   char m_title[51];
public:
   ostream& display(ostream& ostr) const {
      return ostr << m_title;
   }
   Book(const char* title = nullptr) {
      if (title)
         strcpy(m_title, title);
   }
};
ostream& operator<<(ostream ostr,  Book& B) {
   return B.display(ostr);
}
class Library {
public:
   bool operator!()const {
      return m_count == 0;
   }
   operator int() {
      return m_count;
   }
   Book& operator[](int index) {
      return m_books[index % m_count];
   }
   Library& operator<<(const Book& B) {
      Book* temp = new Book[m_count + 1];
      temp[m_count] = B;
      for (int i = 0; i < m_count; i++)
         temp[i] = m_books[i];
      m_books = temp;
      m_count++;
      return *this;
   }
   ~Library() {
      delete[] m_books;
   }
private:
   int m_count{};
   Book* m_books{};
};
ostream& operator<<(ostream& ostr, const Library& L) {
   for (int i = 0; i < L; i++) {
      cout << i + 1 << ":" << L[i] << " ";
   }
   return ostr;
}
void listBooks(const Library& L, const char* title) {
   cout << title;
   if (!L)
      cout << " is empty!";
   else
      cout << endl << L;
   cout << endl << "--------------" << endl;
}
int main() {
   Library L;
   Book P;
   listBooks(L, "Shelf");
   L << "Lord of the Rings" << "Harry Potter" << "C++ Reference";
   listBooks(L, "Seneca Library");
   cout << "Empty: " << P << endl;
   P = "Oliver Twist";
   cout << "Not Empty: " << P << endl;
   return 0;
}


/*
* Intended output
Shelf is empty!
--------------
Seneca Library
1:Lord of the Rings 2:Harry Potter 3:C++ Reference
--------------
Empty:
Not Empty: Oliver Twist
*/