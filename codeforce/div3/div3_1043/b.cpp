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
using i128 = __int128;
// 2025.08.21——22:40:58
// 2025.08.21——22:48:31 wa5
// 2025.08.21——22:49:47 accpted
/*
 *
 *
 *
*/

void solve() {
    i64 n,nn;
    cin >> n;
    nn = n;
    // 相当于 是 11 101  1001 等的倍数

    set<i64>s;
    i64 sz = 0;
    while (nn) {
        sz++;
        nn /= 10;
    }

    for (i128 i = 2,v = 10;i <= sz;i ++,v*=10) {
        if (n % (v + 1) == 0) { s.insert((n / (v+1))); }
    }
    i64 cnt = s.size();
    cout << s.size() << endl;
    if (!cnt)return;
    for (auto x : s) {
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