#include<bits/stdc++.h>
#include<climits>

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

// 补题——题目链接: https://qoj.ac/contest/1885/problem/9925
// 网址：
// 2025.11.12——15:58:52
/*
 * LR 之间不能有别的字符
 * L 的 右边不能有别的字符
 * R 的 左边不能有别的字符
 * 如果 当前的最右边 是 L 则判断
 * 如果 当前的左边 是 R
*/
int id(char c) {
    return ((c == 'L') ? 1 : 0);
}

void solve() {
    string s;
    cin >> s;
    i64 q, szr = 0, szl = 0;
    cin >> q;
    i64 sz = s.size();

    array<vector<int>, 2>pos;
    for (int i = 0;i < sz;i++) {
        pos[id(s[i])].push_back(i);
    }

    pos[0].push_back(sz);
    pos[1].push_back(sz);

    while (q--) {
        string t;
        cin >> t;

        if (t[0] == 'R' && s[0] != 'R') {
            cout << "NO" << endl;continue;
        }

        if (t.back() == 'L' && s.back() != 'L') {
            cout << "NO" << endl;continue;
        }

        int idx = 0;
        for (auto x : t) {
            idx = (*lower_bound(all(pos[id(x)]), idx)) + 1;
            if (idx > sz) break;
        }

        cout << ((idx <= sz) ? "YES" : "NO") << endl;
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