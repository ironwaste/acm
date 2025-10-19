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

// 补题——题目链接: https://codeforces.com/contest/2154/problem/C1
// 网址：
// 2025.10.19——22:50:37
/*
 *
 *
 *
*/
const i64 N = 2e5 + 10;
i64 minp[N];
void init() {
    minp[1] = 1;
    for (int i = 2;i < N;i++) {
        for (int j = i;j < N;j += i) {
            if (!minp[j])minp[j] = i;
        }
    }
}


void solve() {
    i64 n;
    cin >> n;
    i64 odd = 0, even = 0;
    vector<i64>a(n), b(n);
    for (auto& x : a) {
        cin >> x;
        if (x % 2 == 1) {
            odd++;
        } else {
            even++;
        }
    }
    for (auto& x : b) { cin >> x; }

    set<i64>frac;
    for (int i = 0;i < n;i ++) {
        i64 v = a[i];
        while (v > 1) {
            i64 tmpf = minp[v];
            if (frac.count(tmpf)) {
                cout << 0 << endl;
                return;
            }
            frac.insert(tmpf);
            v /= tmpf;
            while (tmpf == minp[v]) {
                v /= tmpf;
            }
        }
    }
    i64 ok = 0;
    for (int i = 0;i < n;i ++) {
        i64 av = a[i] + 1;
        while (av > 1) {
            i64 tmpf = minp[av];
            if (frac.count(tmpf)) {
                cout << 1 << endl;
                return;
            }
            while (tmpf == minp[av]) {
                av /= tmpf;
            }
        }

    }
    cout << 2 << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}