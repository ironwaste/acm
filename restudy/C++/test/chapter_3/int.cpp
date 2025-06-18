#include<bits/stdc++.h>
#include<windows.h>
#define de(x) cerr<<x << " " <<#x <<" "

using namespace std;

int main() {
    // 3.6
    // char ch = 'm';
    // cin >> ch;
    // int c = ch;
    // cout <<'\v' <<ch << endl << c <<'\v' << endl << '$' << endl;
    cout << " asdada" << endl << "asdasdasddsd" << endl;

    // cout << " \vasdada\v" << endl << "asdasdasddsd\v" << endl;
    char ctrlz = '\011';// '\011' -> \t 制表符
    cout << ctrlz << "AAAA"; //
    cout << "\b\b\b\b\b"; // 退格键 有意思
    // int k;
    // cin >> k;
    // cout << k << endl;
    SetConsoleOutputCP(65001); // windows 下设置编码为 unicode
    cout << "\u222B";
    // cout << kk << endl;
    cout << "let them eat gt\u00E2eau.";
    // before c++ release 2.0 
    // cout << '$' <<endl; will form the acsii's value
    // const char value will form the acssi's value

    // '\a' belling charater it will make bell ringing <^-_-^>
    /*
        \t  水平制表符号
        \v  垂直制表符号  -> 暂时未知用处 有点像换行符 \n
    */
    char alarm = '\a';
    // only one voice 
    cout << alarm << "\a\n\a\n\a\n\a\n\a\n\a\n\a\n" << endl;

    // int a = 022;
    // int b= 014;
    // int c = 013;
    // int aa, bb, cc;
    // aa = 22, bb = 12, cc = 0x13;
    // cout << a << " " << b << " " << " " << c << endl;
    // cout << aa << " " << bb << " " << " " << cc << endl;
    // cout << oct << cc << endl;
    // cout << dec << cc << endl;
    // cout << hex << cc << endl;
    


    
    // cout << dec << a << endl;
    return 0;
}
