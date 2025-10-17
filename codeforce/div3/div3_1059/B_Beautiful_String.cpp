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

// 补题——题目链接: https://codeforces.com/contest/2162/problem/B
// 网址：
// 2025.10.17——22:39:01
/*
 *
 *
 *
*/

void solve(){
    i64 n;
    cin >> n;
    string s;
    cin >> s;
    vector<i64>idx;
    for (int i = 0;i < n;i ++) {
        if (s[i] == '0') {
            idx.push_back(i + 1);
        }
    }
    cout << idx.size() << endl;
    for (auto x : idx) {
        cout << x << " ";
    }cout << endl;
    // vector<i64>ans;
    // set<i64>st;

    // auto check = [&]()->bool {
    //     string k;
    //     for (int i = 0;i < n;i++) {
    //         if (st.count(i)) { continue; }
    //         k += s[i];
    //     }
    //     i64 sz = k.size();
    //     // deb(sz);
    //     for (int i = 0;i < sz / 2;i++) {
    //         // de(i)de(sz - i - 1);
    //         if (k[i] != k[sz - i - 1]) {
    //             return false;
    //         }
    //     }
    //     return true;
    //     };

    // auto dfs = [&](auto dfs,i64 idx,char prx)->i64 {
    //     i64 ok = 0;
    //     if (check()) {
    //         return 1;
    //     }
    //     for (int i = idx;i < n;i++) {
    //         if (prx <= s[i]) {
    //             st.insert(i);
    //             if (dfs(dfs, i + 1, s[i]))return 1;
    //             st.erase(i);
    //         }
    //     }
    //     return ok;
    //     };

    // if (dfs(dfs, 0, '0')) {
    //     cout << st.size() <<endl;
    //     for (auto x : st) {
    //         cout << x+1 << " ";
    //     }cout << endl;
    // } else {
    //     cout << -1 << endl;
    // }


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