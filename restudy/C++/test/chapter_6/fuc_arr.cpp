#include<bits/stdc++.h>

#define de(x) cerr<<#x << " " <<x <<" "

using namespace std;
// 2025.07.21——10:49:15
int main(){
    int cookie[3] = { 1,2,3 };
    int a = 8;
    int* p = &a;
    cout << "cookie address is : " << *cookie << endl;
    cout << "cookie[1] address is :  " << &cookie[1] << endl;
    cout << p << endl;cout << *p << endl;

    return 0;
}