#include <iostream>
using namespace std;

int main() {
    // int* a = nullptr;
    // int i;
    // cout<<"Program strating"<<endl;
    // cout<<"10 int"<<endl;
    // a = new int[10];
    // for (i = 0; i < 10; i++)
    // {
    //     a[i] = i * 123;
    // }
    // for (i = 0; i < 10; i++)
    // {
    //     cout<<a[i]<<endl;
    // }
    // cout<<"before ending app, give the mem back to the OS"<<endl;
    // delete[] a;
    
    // a = nullptr;
    // cout<<"making a new array" << endl;
    // a = new int[20];
    // for (i = 0; i < 20; i++)
    // {
    //     a[i] = i * 123;
    // }
    // for (i = 0; i < 20; i++)
    // {
    //     cout<<a[i]<<endl;
    // }
    // delete[] a;
   
   
   
    int a[13] = {1,3,0,4,5,0,8,76,9,0,4,0,0 };
    int i;
    int x = 0;
    for (i = 0; i < 13; i++)
        x += !!a[i];
        cout << x;
    


    // int a = 10;
    // int b = 20;
    // int c = 30;
    // int* d[3] = {&c, &b, &a};
    // for (int i = 0; i < 3; i++) (*d[i])--;
    // for (int i = 0; i < 3; i++) cout<< *d[i];

    
    
    return 0;
}

// shared memory is called heap