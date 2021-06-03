#include <iostream>
using namespace std;
// g++ .\const.cpp;./a.exe 

/*
常类型是指使用类型修饰符 const 说明的类型，常类型的变量或对象的值是不能被更新的。

const 定义的变量只有类型为整数或枚举，且以常量表达式初始化时才能作为常量表达式。
其他情况下它只是一个 const 限定的变量，不要将与常量混淆。
*/

// const 的作用
//（1）可以定义常量
const int X = 1;
//（2）类型检查
// #define 宏定义没有数据类型，只是简单的字符串替换，不能进行安全检查
#define Y = 100x0;

const int Z = 1;

//（3）防止修改，起保护作用，增加程序健壮性
void foo(const int i) {
    // error: increment of read-only parameter 'i'
    // i++;
}

//（4）可以节省空间，避免不必要的内存分配
// const 定义常量从汇编的角度来看，只是给出了对应的内存地址，而不是像 #define 一样给出的是立即数，
// 所以，const 定义的常量在程序运行过程中只有一份拷贝，而 #define 定义的常量在内存中有若干个拷贝。

// 由于之后无法修改，因此其定义时必须初始化
// error: uninitialized const 'F' [-fpermissive]
// const int F;

int main() {
    cout << "X: " << X << "\nZ: " << Z;
    // const 与指针
    int i = 0;
    const int j = 0;
    const int * p1 = &i;
    int const * p2 = &i;
    // const 指针和 const 变量一样必须初始化
    // error: uninitialized const 'p3'
    // int * const p3;
    const int * const p4 = &i;
    // 不能通过  const 指针修改所指对象的值，即使其非 const
    // error: assignment of read-only location '*(const int*)p4'
    // *p4 = 1;
    // 非 const 指针不能指向 const 对象
    // error: invalid conversion from 'const int*' to 'int*'
    // int * p5 = &j;
    return 0;
}

