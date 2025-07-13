#include<iostream>

enum { red, orange, yellow, green, blue, violet, indigo };

int main() {
    using namespace std;
    cout << "Enter color code(0-6) : ";
    int code;
    cin >> code;
    while (code >= red && code <= indigo) {
        switch(code) {
            case red    : cout << "red.\n";     break;
            case orange : cout << "orange";     break;
            case yellow : cout << "yellow\n";   break;
            case green  : cout << "green\n";    break;
            case blue   : cout << "blue\n";     break;
            case violet : cout << "violet\n";   break;
            case indigo : cout << "indigo\n";   break;
        }
        cin >> code;
    }
}
// 可输入 数字从0~6，
// 这样可以将数字进行对应和
// enum 枚举变量中的值
// switch语句在将int值和枚举量标签进行比较的时候，会将枚举量
// 提升到int类型。此外在while循环测试条件中，也会将枚举变量提升为int类型
// 即在存在逻辑判断的时候都会提升到int类型