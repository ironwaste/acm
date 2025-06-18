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


void solve(){
    i64 k;
    vector<i64>a(3);
    cin >> k >> a[0] >> a[1] >> a[2];
    i64 ans = k;
    
    a.pb(a[0] + a[1]);
    a.pb(a[2] + a[1]);
    a.pb(a[0] + a[2]);
    a.pb(a[0] + a[1] + a[2]);
    a.pb(0LL);
    sort(all(a));
    i64 sz = a.size(),i=0;

    for (i = sz - 1;i >= 0;i--) {
        // de(i)de(a[i])
        if (a[i] <= ans) {
            break;
        }
    }

    cout << ans - a[i] << endl;
}

int main(){
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