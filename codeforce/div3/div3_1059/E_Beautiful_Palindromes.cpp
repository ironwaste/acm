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

// 补题——题目链接: https://codeforces.com/contest/2162/problem/E
// 网址：
// 2025.10.18——00:09:40
/*
 *
 *
 *
*/
// uset 顺序是反的
void solve() {
    i64 n, k;
    cin >> n >> k;

    vector<i64>a(n);
    vector<i64>vis(n + 1, 0);
    vector<i64>us;
    // set<i64>s;
    for (auto& x : a) {
        cin >> x;
    }
    for (int i = n - 1;i >= 0; i--) {
        i64 x = a[i];
        if (vis[x] == 0)us.push_back(x);
        vis[x]++;
    }
    vector<i64>st;
    for (int i = 1;i <= n;i++) {
        if (vis[i] == 0) {
            st.push_back(i);
        }
    }
    i64 sz = st.size();
    // if (sz == 0) {
    //     for (int i = 0;i < k;i++) {
    //         cout << a[i] << " \n"[i == k - 1];
    //     }
    //     return;
    // } else {
    i64 ssz = us.size();
    for (int i = ssz-1;i >= 0;i --) {
        if (sz >= 3) { break; }
        sz++;
        st.push_back(us[i]);
    }
    for (int i = 0;i < k;i++) {
        cout << st[i % 3] << " \n"[i == k - 1];
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