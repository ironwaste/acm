#include<iostream>
using namespace std;
int main() {
    char ch;
    cin >> ch;
    if (ch == 'o') {
        goto pp;
    } else {
        cout << "Noway\n";
    }
    if (ch == 'a') {
        pp: cout << "pp is been through" << endl;
    }
    return 0;
}