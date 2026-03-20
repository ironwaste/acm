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

// 2026.03.20——21:03:03
/*
 *
 *
 *
*/

void solve() {

    i64 n, k;
    cin >> n >> k;
    // map<>
    if (n >= k) {
        cout << -1 << endl;
        return;
    }
    set<i64>st;
    st.insert(1);
    st.insert(k);
    vector<i64>ans;
    ans.pb(1);
    i64 prxv = 1;
    i64 sz = 1, v = 2;
    while (sz < n) {
        i64 res = v % k;
        if (!st.count(k-res)) {
            ans.pb(v);
            sz++;
            
        }
        
        v++;
    }
    for (auto x : ans) {
        cout << x << " ";
    }cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}