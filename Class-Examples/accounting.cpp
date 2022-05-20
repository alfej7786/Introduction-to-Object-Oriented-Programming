// // TEAM A
// // Accounting.cpp and Accounting.h
// namespace acc{
// struct Student
// {
//     int stNo;
//     int bankAcc;
//     char bankInfo[81];
//     double feesDue;
// };
// }

// // TEAM B
// // Admin.cpp and Admin.h
// namespace adm{
// struct Student
// {
//     int stNo;
//     int semester;
//     double GPA;
// };
// }

// // TEAM C
// // Loan.cpp and Loan.h
// namespace acc {
// struct Load
// {
//     double amountDue;
//     double monthlyPayment;
// };
// }

// // main.cpp
// // #iostream
// // #include 'accounting.h'
// // #include 'admin.h'
// // #include 'accounting.h'

// // using namspace acc; e.g no need to write acc::
// // 
// int main()  {
//     acc::Student student1; 
//     adm::Student student2;
//     return 0;
// }


// ========== Forwrd Declaration ===============
// struct Chicken; // forward declaration

// struct Chicken
// {
//     Egg e[6];
// };

// struct Egg
// {
//     int num_yolks;
//     Chicken* mom;
// };




// ========== Wrong Forwrd Declaration ===============
// struct Egg; // forward declaration

// struct Chicken
// {
//     Egg e[6];
// };

// struct Egg
// {
//     int num_yolks;
//     Chicken* mom;
// };



// <<<<<<<<<<<<<<<<<<< BOOLEAN >>>>>>>>>>>>>>>>>>>>

#include <iostream>
using namespace std;

void foo(int& R){
    R *= 2;
    return R;
};
int main()  {
    
    return 0;
}