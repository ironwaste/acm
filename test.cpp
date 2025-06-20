#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int>a(10, 0);
    iota(a.begin(),a.end(), 0);
    int x = 10;
    int upid = lower_bound(a.begin(),a.end(), x) - a.begin();
    cout << upid << "  " << a[upid]<< endl;


    
    // cout << "llong_max is : " << LLONG_MAX << endl;
    // cout << INT_MAX << endl;
    // cout << (2LL << 30) << endl;
    return 0;
}