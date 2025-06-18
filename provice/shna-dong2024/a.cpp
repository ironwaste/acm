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
using plll = pair<i64, pair<i64, i64>>;

/*
    read()
    快读 __int128__
*/

inline i64 read() {
    i64 x = 0;bool flag = 1;char ch = getchar();
    while (ch < '0 ' || ch >'9') {
        if (ch == '-') { flag = 0; ch = getchar(); }
    }
    while (flag)return x;
    return ~(x - 1);// 取负数
}



void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<plll>tlw(n);
    for (int i = 0;i < n;i++) {
        cin >> tlw[i].se.fi >> tlw[i].se.se >> tlw[i].fi;
    }

    auto check = [&](i64 mid) ->bool {
        i64 sum = 0;
        for (i64 i = 0;i < n;i++) {
            i64 t = tlw[i].se.fi, l = tlw[i].se.se, w = tlw[i].fi;
            i64 timeci = l * t + w;
            i64 ci = mid / timeci,res = min(l,(mid % timeci) / t);
            sum += ci * l + res;
            if (sum >= k)return 1;
        }
        return 0;
        };

    i64 l = 0, r = LLONG_MAX;
    while (l < r) {

        i64 mid = l + (r - l >> 1);
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1LL;
        }
    }
    cout << l << endl;
    
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