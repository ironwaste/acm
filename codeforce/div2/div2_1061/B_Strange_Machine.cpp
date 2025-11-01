#include<bits/stdc++.h>
#include<climits>


#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define i64 long long
#define fi first
#define se second

#define endl '\n'
#define mod3 998244353
#define mod7 1000000007
#define all(x) x.begin(),x.end()
#define de(x) cerr << #x <<" "<<x <<" ";
#define deb(x) cerr << #x <<" "<<x <<endl;
using namespace std;


using pii = pair<int, int>;
using pll = pair<i64, i64>;

// 补题——题目链接:
// 网址：
// 2025.10.24——22:45:38
/*
 *
 *
 *
*/

void solve() {
    i64 n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<i64>a;
    i64 idv = 0;
    i64 ok = 0;
    for (int i = 0;i < n;i++) {
        if (s[i] == 'A') {
            idv++;
        } else if (s[i] == 'B') {
            ok = 1;
            if (idv != 0) {
                a.push_back(idv);
                idv = 0;
            }
            a.push_back(-1);
        }
    }
    if (idv != 0) { a.push_back(idv); }
    i64 sz = a.size();
    while (q--) {
        i64 v;
        cin >> v;
        i64 time = 0, idx = 0;
        while (v) {
            if (!ok) {
                time = v;
                break;
            }
            if (a[idx] > 0) {
                i64 mi = min(v, a[idx]);
                time += mi;
                v -= mi;
            } else {
                v /= 2;
                time++;
            }
            idx++;
            idx %= sz;
        }
        cout << time << endl;

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}