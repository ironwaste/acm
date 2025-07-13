#include<iostream>
#include<cctype>
#include<string>
using namespace std;
const string s = "asd1f23xcvz2asf13.,。，";
int main() {
    char ch;
    int sz = s.size();
    cout << "sz : " << sz << endl;
    for (auto ch : s) {
        cout << ch;
        if (isalpha(ch)) {
            cout << "is alpha\n";
        } else if (ispunct(ch)) {
            // 无法识别中文符号，因为其是全角符号
            // 占用两个字节位置，并非一个
            cout << "is punct\n";
        } else {
            cout << endl;
        }
        
    }


    return 0;
}
