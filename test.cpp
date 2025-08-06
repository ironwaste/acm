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

    int m;
    cin >> m;
    // int s = m;
    // while (s > 0) {
        // deb(s);
        // int k = s;
    auto l2 = [&](int k)->void {
        de(k)
        while (k) {
                cout << k % 2 << " ";
                k /= 2;
            }cout << endl;
            };
        
    //     s = (s - 1) & m;
    // }
    for (int i = 1;i < (1 << m);++i) {
        deb(i);
        l2(i);
        int s = i;
        for (;s>0;s = (s - 1) & i) {
            de(s);
            l2(s);
        }cout << endl;
    }
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