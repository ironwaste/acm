#include<bits/stdc++.h>
#define de(x) cerr << #x <<" " << x <<" ";
#define deb(x) cerr << #x <<" " << x << endl;
using namespace std;

int main() {
    // vector<int>a(10, 0);
    // iota(a.begin(),a.end(), 0);
    // int x = 10;
    // int upid = lower_bound(a.begin(),a.end(), x) - a.begin();
    // cout << upid << "  " << a[upid]<< endl;
    // vector<int>a(10);
    // for (auto x : a) {
    //     cout << x << " ";
    // }
    int a = 3, b = -2, c = -11, d = -4;


    cout << a % b << endl;
    // a = 3 b = -2 ans is 1
    // a = -1 b = 2 ans is -1
    // a = -1 b = -2 ans is -1
    cout << c % d << endl;
    c = -c;
    cout << c % d << endl;
    d = -d;
    cout << c % d << endl;
    c = -c;
    cout << c % d << endl;

    // c = -11 d = -4 ans is -3
    // c =  11 d = -4 ans is  3
    // c =  11 d = 4 ans is  3
    // c = -11 d = 4 ans is -3

    // cout << a << endl;

    // cout << "llong_max is : " << LLONG_MAX << endl;
    // cout << INT_MAX << endl;
    // cout << (2LL << 30) << endl;
    return 0;
}

/*
    s -> 3
    1 1
    s = s - 1 = 1 0(2)
    s = s - 1 = 0 1(1)
    ?
*/