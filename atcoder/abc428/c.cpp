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

// 补题——题目链接: https://atcoder.jp/contests/abc428/tasks/abc428_c
// 网址：
// 2025.10.19——11:45:39
/*
 *
 *
 *
*/

void solve() {
    i64 q;
    cin >> q;
    vector<i64>vis;
    // 0 is left 1 is right
    // 2 is 有对应的 right
    // bool ok = true;
    i64 sz = 0;
    stack<i64>stk;
    while (q--) {
        i64 op;
        char c;
        cin >> op;
        // de(c)deb(vc);
        if (op == 1) {
            cin >> c;
            i64 vc = (c == ')');

            if (!stk.empty() && stk.top() == 0 && vc == 1) {
                vis.push_back(2);
                stk.pop();
                sz--;
            } else if (vc == 0) {
                stk.push(0);
                vis.push_back(0);
                sz++;
            } else {
                stk.push(1);
                vis.push_back(1);
                sz++;
            }
        } else if (op == 2) {
            i64 v = vis.back();
            if (v == 2) {
                stk.push(0);
                sz++;
            } else if (v == 1) {
                stk.pop();
                sz--;
            } else if (v == 0) {
                stk.pop();
                sz--;
            }
            vis.pop_back();
        }

        cout << ((sz == 0) ? "Yes" : "No") << endl;
    }



}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}