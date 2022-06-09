#include <iostream>
using namespace std;
// class foo{
//     char F;
//     public:
//     Foo(char ch='X'){
//         cout << (F = ch);
//     }
//     ~Foo(){
//         cout << F;
//     }
// };

// int main() {
//     Foo f[2] = {'Z'};
//     Foo* p = new Foo('Y');
//     cout << foo();

//     return 0;
// }
class Foo{
    int M;
    public:
    Foo(){
        M = 1;
        Foo(M + 1);
    }
    Foo(int f) {
        M = f;
    }
    ~Foo(){
        cout << M;
    }
};
int main(){
    Foo F;
    return 0;
}