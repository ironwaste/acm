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
#define yes "Yes\n"
#define no "No\n"
#define endl '\n'
#define mod3 998244353
#define mod7 1000000007
#define de(x) cerr << #x <<" "<<x <<" ";
#define deb(x) cerr << #x <<" "<<x <<endl;
using namespace std;

using pii = pair<int,int>;
using pll = pair<i64, i64>;




void solve() {
    i64 n,dis;
    cin >> n;
    pll p, q;
    vector<i64>a(n);
    cin >> p.fi >> p.se >> q.fi >> q.se;
    dis = (p.fi - q.fi) * (p.fi - q.fi) + (p.se - q.se) * (p.se - q.se);
    // i64 sum = 0;
    i64 l = -1, r = -1;

    for (auto& x : a) {
        cin >> x;
        if (l == -1 || r == -1) { l = r = x; }
        else {
            l = max(0LL, l - x);
            r = r + x;
        }
    }
    if (n == 1) {
        if (a[0] * a[0] == dis) { cout << yes; }
        else { cout << no; }
        return;
    }
    l = l * l, r = r * r;
    if (l <= dis && r >= dis) {
        cout << yes;
    } else {
        cout << no;
    }



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