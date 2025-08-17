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
    i64 a, b, x, y;
    cin >> a >> b >> x >> y;
    swap(a, b);
    if (a == b) {
        cout << 0 << endl;
        return;
    }else if (a < (b & ((1LL << 10) - 2LL))) {
        cout << -1 << endl;
        return;
    } else if (a == b - 1 && (b & 1LL)) {
        cout << y << endl;
        return;
    }
    if (x >= y) {
        // i64 op = a - b,opy = (b & 1LL);
        i64 op = a - b,opy = (b & 1LL) ^1LL;

        // if (a < b) { cout << y << endl; return; }
        i64 nuy = ((op + opy) / 2);
        // i64 nuy = ((op - 1LL + opy) / 2);
        i64 nux = op - nuy;
        cout << y * nuy + x * nux << endl;
    } else {
        i64 op = a - b;
        // if (a < b) { cout << y << endl; return; }
        cout << x * op << endl;
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