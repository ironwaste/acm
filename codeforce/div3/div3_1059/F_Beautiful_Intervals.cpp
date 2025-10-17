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


using pii = pair<int,int>;
using pll = pair<i64, i64>;

// 补题——题目链接:
// 网址：
// 2025.10.18——00:28:40
/*
 *
 *
 *
*/

void solve(){
    i64 n, m;
    cin >> n >> m;
    vector<pll> lr;
    bool ok = false;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        lr.push_back({l, r});
        if (l == 1 && r == n) {
            ok = true;
        }
    }
    
    if (ok) {
        for (int i = 0; i < n; i++) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    
    vector<int> diff(n + 2, 0);
    for (auto [l, r] : lr) {
        diff[l]++;
        diff[r + 1]--;
    }
    
    vector<bool> vis(n + 1, false);
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += diff[i];
        vis[i] = (cur > 0);
    }
    
    int idx = -1;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            idx = i;
            break;
        }
    }
    
    if (idx != -1) {
        vector<int> mex(n);
        mex[idx - 1] = 0;
        int num = 1;
        for (int i = 0; i < n; i++) {
            if (i != idx - 1) {
                mex[i] = num++;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << mex[i] << " ";
        }
        cout << endl;
    } else {
        vector<int> mex(n);
        mex[0] = 0;
        mex[n - 1] = 1;
        int num = 2;
        for (int i = 1; i < n - 1; i++) {
            mex[i] = num++;
        }
        for (int i = 0; i < n; i++) {
            cout << mex[i] << " ";
        }
        cout << endl;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}