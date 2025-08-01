// 看什么看,以为我厉害吗？
// 我只是戾气很重,不厉害只需要114514分钟就能变厉害了
// 而你我的朋友只需要2.5年就可以了
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
#define de(x) cerr << #x <<" "<<x <<" ";
#define deb(x) cerr << #x <<" "<<x <<endl;
using namespace std;

using pii = pair<int,int>;
using pll = pair<i64, i64>;

// 2025.07.31——12:45:52
/*
 *
 *
 *
*/

void solve() {
    i64 n;
    cin >> n;
    for (int i = 1;i <= n;i ++) {
        vector<i64>a(i);
        iota(all(a), 1);
        vector<vector<i64>>g;
        int cnt = 0, sum = 0;

        deb(i);
        do {
            auto b = a;
            // reverse(all(b));
            g.push_back(b);
            // for (auto x : b) { cout << x << " "; }
            // cout << endl;
            // cnt++;
        } while (next_permutation(a.begin(), a.end()));
        map<i64, i64>mp;
        for (auto p : g) {
            stack<i64>stk;
            for (auto x : p) {
                while (!stk.empty() && stk.top() > x) {
                    stk.pop();
                }
                stk.push(x);
            }
            i64 sz = stk.size();
            mp[sz]++;
            // cnt++;
            sum += sz * sz * sz;
        }
        for (auto [sz,cnt] : mp) {
            de(sz) deb(cnt);
        }
        de(i)deb(sum);
    }
    // sort(all(g));
    // for (auto x : g) {
    //     for (auto y : x) {
    //         cout << y << " ";
    //     }cout << endl;
    // }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}

