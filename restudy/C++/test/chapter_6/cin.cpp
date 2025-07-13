#include<iostream>

using namespace std;

int main() {
    // 不同类型变量对于cin对象输入的同一值的反馈是不同的
    // 输入为： 38.5 (中间存在空格) 19.2

    int ch;
    cin >> ch; // 输入进入的是38
    char ch[50];// 输入到空格则停止
    double ch;//则输入到 第一个小数截至才开始
    cin.getlin(ch,50);//则是输入到换行符或者到达数组上限为止

    return 0;
}