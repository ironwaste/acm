#include<iostream>
using namespace std;

void simple_fuc(); // 函数声明 function prototype

int main() {
    cout << "main() will call the simple_fuc() function\n";
    simple_fuc()//函数调用 function call;
    return 0;
}

void simple_fuc() {
    cout << "this is function definition\n";
    // 这里是函数定义
}