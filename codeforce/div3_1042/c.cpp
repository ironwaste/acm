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

// 2025.08.10——22:47:00
// 2025.08.10——22:52:01 wa2
// 2025.08.10——22:53:56 accpted
/*
 *
 * NOTE !!! 这题很重要啊 很经典的 绝对值减
 * 模除 之后的余数相同 或者 模数 - 余数 可以相互转化
 *
 */

void solve() {
    i64 n,k;
    cin >> n >> k;
    map<i64, i64>a, b;
    for (int i = 0;i < n;i ++) {
        i64 x;
        cin >> x;
        a[x % k]++;
    }

    for (int i = 0;i < n;i ++) {
        i64 x;
        cin >> x;
        b[x % k]++;
    }
    int ok = 1;
    for (auto [x,y] : a) {
        if (b[k - x] + b[x] != a[k - x] + a[x]) {
            ok = 0;
            break;
        }
    }
    cout << ((ok) ? "YES" : "NO") << endl;
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