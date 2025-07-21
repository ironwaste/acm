#include<iostream>
using namespace std;

void simple_fuc(); // 函数声明 function prototype 函数原型别称
int fuc(int, int, int);// 函数原型 无需填写变量名称，只需要
// 填写参数类型的列表即可

int main() {
    cout << "main() will call the simple_fuc() function\n";
    simple_fuc();//函数调用 function call;
    cout << fuc(3, 4, 5) << endl;
    return 0;
}

int fuc(int a, int b, int c) {
    cout << a << " : " << b << " : " << c << endl;
    return 1;
}

void simple_fuc() {
    cout << "this is function definition\n";
    // 这里是函数定义
}