#include<iostream>
using namespace std;
// g++ extern.cpp extern2.cpp;./a.exe

extern int x1;
// undefined reference to 'x2'
extern const int x2;
extern const int x3;



int main() {
    cout << x1 << x3;
}