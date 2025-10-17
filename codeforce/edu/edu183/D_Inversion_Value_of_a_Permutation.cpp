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
// 2025.10.06——23:22:31
/*
 *
 *
 *
*/

vector<vector<vector<int>>> pre(31);
// 110001 个
// 1e 5 个
// 5e 7 
void dfs(i64 n, i64 min_val, vector<int>& cur, vector<vector<int>>& res) {
    if (n == 0) {
        res.push_back(cur);
        return;
    }
    for (int i = min_val; i <= n; i++) {
        cur.push_back(i);
        dfs(n - i, i, cur, res);
        cur.pop_back();
    }
}

void init() {
    for (int n = 1; n <= 30; n++) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(n, 1, cur, res);
        pre[n] = res;
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    int tot = n * (n - 1) / 2;
    int X = tot - k;
    vector<int> ans;
    bool ok = false;
    for (auto& p : pre[n]) {
        int sum = 0;
        for (auto v : p) {
            sum += v * (v - 1) / 2;
        }
        if (sum == X) {
            int total = n;
            for (auto v : p) {
                int start = total - v + 1;
                for (int j = start; j <= total; j++) {
                    ans.push_back(j);
                }
                total -= v;
            }
            ok = true;
            break;
        }
    }
    if (!ok) {
        cout << 0 << endl;
    } else {
        i64 sz = ans.size();
        for (i64 i = 0; i < sz; i++) {
            if (i > 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
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