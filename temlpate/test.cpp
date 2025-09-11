#include<bits/stdc++.h>
#define de(x) cerr << #x <<" " << x <<" ";
#define deb(x) cerr << #x <<" " << x << endl;
#define i64 long long
using namespace std;

int main() {



    // --------------------------------------


    priority_queue<i64>q1;
    priority_queue<i64, vector<i64>, greater<i64>>q2;
    priority_queue<i64,vector<i64>,less<i64>>q3;
    vector<i64>a(10);
    iota(a.begin(), a.end(), 0);
    for (int i = 0;i < 10;i ++) {
        i64 v = a[i];
        q1.push(v);
        q2.push(v);
        q3.push(v);
    }
    deb(q1.top());
    deb(q2.top());
    deb(q3.top());

    // --------------------------------------
    // vector<int>a(10, 0);
    // iota(a.begin(),a.end(), 0);
    // int x = 10;
    // int upid = lower_bound(a.begin(),a.end(), x) - a.begin();
    // cout << upid << "  " << a[upid]<< endl;
    // vector<int>a(10);
    // for (auto x : a) {
    //     cout << x << " ";
    // }
    // int a = 3, b = -2, c = -11, d = -4;


    // cout << a % b << endl;
    // a = 3 b = -2 ans is 1
    // a = -1 b = 2 ans is -1
    // a = -1 b = -2 ans is -1
    // cout << c % d << endl;
    // c = -c;
    // cout << c % d << endl;
    // d = -d;
    // cout << c % d << endl;
    // c = -c;
    // cout << c % d << endl;

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