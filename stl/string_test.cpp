#include "string.h"

int main() {
    string a;
    string b("Hello");
    string c(5);
    string d(10, 'a');
    string e(b);
    std::cout << a << std::endl << b << std::endl << c << std::endl << d << std::endl << e << std::endl;
    string f = std::move(b);  // call move constructor
    std::cout << f << std::endl;
    f = std::move(d);  // call move assignment operator
    std::cout << f << std::endl;
}