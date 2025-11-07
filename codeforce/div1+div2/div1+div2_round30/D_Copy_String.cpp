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
// 2025.11.07——00:13:33
/*
 *
 *
 *
*/

void solve() {
    i64 n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    auto res = s;
    auto ret = t;
    if (s[0] != t[0]) { cout << -1 << endl; return; }
    if (s == t) { cout << 0 << endl; return; }

    reverse(all(res));
    reverse(all(ret));

    vector<i64>idx[26];
    for (int i = 0;i < n;i++) {
        idx[res[i] - 'a'].push_back(i);
    }
    i64 ansk = 0;
    vector<string>ans;

    vector<pll>ch;
    for (i64 i = 0;i < n;i++) {
        if (res[i] != ret[i]) {
            i64 idv = ret[i] - 'a';
            ch.push_back({ i,idv });
        }
    }

    i64 ssz = ch.size();
    vector<pll>st;
    for (i64 i = 0;i < ssz;i++) {
        i64 pos = ch[i].fi, j = ch[i].se;
        i64 nexpos = pos;
        if (i > 0) { nexpos = max(nexpos + 1LL, st.back().se); }
        auto it = lower_bound(all(idx[j]), nexpos);
        if (it == idx[j].end()) {
            cout << -1 << endl;return;
        }

        i64 idv = idx[j][it - idx[j].begin()];
        st.push_back({ pos, idv });
        ansk = max(ansk, idv - pos);

        i64 ed = idv;
        if (i != ssz - 1LL) {
            ed = min(ed, ch[i + 1].fi);
        }
        
        for (i64 pi = pos + 1;pi < ed;pi++) {
            i64 jj = res[pi] - 'a';
            auto pit = lower_bound(all(idx[jj]), idv);
            if (pit == idx[jj].end()) {
                cout << -1 << endl;return;
            }
        
            idv = idx[jj][pit - idx[jj].begin()];
            ansk = max(ansk, idv - pi);
            st.push_back({ pi, idv });
            ed = min(idv, ch[i + 1].fi);
        }
    }

    if (ansk > k) {
        cout << -1 << endl;
        return;
    }

    cout << ansk << endl;
    i64 stsz = st.size();
    string tmpres = res;
    for (int i = 0;i < ansk;i++) {
        for (int j = 0;j < stsz;j++) {
            i64 eed = st[j].fi, cur = st[j].se;
            if (eed != cur) {
                tmpres[cur - 1] = tmpres[cur];
                st[j].se--;
            }
        }
        for (int j = n - 1;j >= 0;j--) {
            cout << tmpres[j];
        }cout << endl;
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
