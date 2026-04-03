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

// 2026.04.03——20:29:30
/*
 *
 *
 *
*/

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<i64>a(n), b(n + 1);
    for (auto &x : a) {cin >> x;}
    for (auto &x : b) {cin >> x;}
    sort(all(a), greater<i64>());
    sort(all(b), greater<i64>());
    i64 cntv = 0;
    for (int i = 0;i < n;i ++) {
        cntv += a[i] * b[i];
        if (cntv >= m) {
            cout << 0 << endl;
            return;
        }
    }

    i64 v = (m - cntv + b[n] - 1) / b[n];
    for (int i = n;i > 0;i --) {
        cntv -= a[i - 1] * b[i - 1];
        cntv += a[i - 1] * b[i];
        v = min((m - cntv + b[i - 1] - 1) / b[i - 1],v);
    }
    cout << v << endl;
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