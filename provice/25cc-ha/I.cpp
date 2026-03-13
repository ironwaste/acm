#include<bits/stdc++.h>
#include<climits>

#define fi first
#define se second
#define i64 long long 
#define all(x) x.begin(),x.end()
#define endl '\n'
#define de(x) cerr << #x << " " << x << " ";
#define deb(x) cerr << #x << " " << x << " \n";
using namespace std;
using pll = pair<i64, i64>;


void solve() {
    i64 n, m;
    cin >> n >> m;
    map<i64, i64>x, y, z;
    for (int i = 0;i < n;i++) {
        i64 a, b, c;
        cin >> a >> b >> c;
        x[a]++;
        y[b]++;
        z[c]++;
    }

    for (int i = 0;i < m;i++) {
        i64 a, b, c;
        cin >> a >> b >> c;
        x[a]++;
        y[b]++;
        z[c]++;
    }
    
    for (auto [fx, fy] : x) {
        if (fy % 2 == 1) {
            cout << "NO" << endl;
            return;
        }
    }
    for (auto [fx, fy] : x) {
        if (fy % 2 == 1) {
            cout << "NO" << endl;
            return;
        }
    }
    for (auto [fx, fy] : y) {
        if (fy % 2 == 1) {
            cout << "NO" << endl;
            return;
        }
    }
    for (auto [fx, fy] : z) {
        if (fy % 2 == 1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}