#include<bits/stdc++.h>
#include<climits>

#define i64 long long 
#define all(x) x.begin(),x.end()
#define endl '\n'
using namespace std;



void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n);

    for (auto& x : a) { cin >> x; }

    sort(a.begin(), a.end());

    vector<i64>diff(n);
    i64 gd = 0,ok = 1;
    for (int i = n - 1;i > 0;i--) {
        diff[i] = a[i] - a[i - 1];
        if (diff[i] != 0) { ok = 0; }
        gd = __gcd(diff[i], gd);
    }
    
    if (ok == 1) { cout << "infinite" << endl; return; }
    // k * a[0] = ? * gd
    i64 k = gd / __gcd(a[0], gd);
    
    // k = max(1LL, k);
    // cout << "a[0] " << a[0] << " " << __gcd(a[0], gd) << endl;
    cout << gd << " " << k << endl;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}