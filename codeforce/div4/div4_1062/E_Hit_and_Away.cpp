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
using plll = pair<i64, pair<i64, i64>>;

// 补题——题目链接:
// 网址：
// 2025.10.25——21:06:10
/*
 *
 *
 *
*/
plll make_plll(i64 a, i64 b, i64 c) {
    plll tmp;
    tmp.fi = a;
    tmp.se.fi = b;
    tmp.se.se = c;
    return tmp;
}

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<vector<i64> >g(n);
    for (int i = 0;i < m;i++) {
        i64 v, u;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<pll>mi1(n, { INT_MAX, -1 }), mi2(n, { INT_MAX ,-1 });
    priority_queue<plll, vector<plll>, greater<plll>> q;
    string s;
    cin >> s;
    for (int i = 0;i < n;i++) {
        if (s[i] == 'S') {
            plll tmp = make_plll(0, i, i);
            q.push(tmp);
        }
    }
    while (!q.empty()) {
        auto tp = q.top();
        i64 d = tp.fi;
        i64 u = tp.se.fi;
        i64 sv = tp.se.se;
        q.pop();
        if (d < mi1[u].fi) {
            mi2[u] = mi1[u];
            mi1[u] = { d,sv };
            for (auto v : g[u]) {
                plll tmp = make_plll(d + 1, v, sv);
                q.push(tmp);
            }
        } else if (d < mi2[u].fi && sv != mi1[u].se) {
            mi2[u] = { d,sv };
            for (auto v : g[u]) {
                plll tmp = make_plll(d + 1, v, sv);
                q.push(tmp);
            }
        }
    }

    for (int i = 0;i < n;i++) {
        if (s[i] == 'D') {
            cout << mi1[i].fi + mi2[i].fi << endl;
        }
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}