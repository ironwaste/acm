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

// 2025.07.21——12:09:15
/*
 *
 *
 *
*/

i64 lowbit(i64 x) {
    return x & (-x);
}
i64 count(i64 x) {
    i64 res = 0;
    while (x) {
        res += (x % 2);
        x /= 2;
    }
    return res;
}


void solve() {
    i64 x, y, n;
    cin >> n >> x >> y;
    i64 lbx = lowbit(x), lby = lowbit(y);
    i64 cx = count(x), cy = count(y);
    if (x == y) {
        cout << 0 << endl;
    }
    else if ((lbx == lby) || (cx == cy)) {
        cout << 1LL << endl;
    } else {
        cout << 2LL << endl;
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