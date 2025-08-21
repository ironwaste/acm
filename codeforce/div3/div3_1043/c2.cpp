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

// 2025.08.21——23:01:06
// 2025.08.21——23:34:51  tle - 4
// 2025.08.21——23:40:15  accpted
/*
 * 1,3,9,27 
 *
 *
*/
vector<i64>a3;
i64 pw(i64 a, i64 b) {
    i64 res = 1LL;
    if (b == 0)return 1LL;
    else if (b == 1)return a;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

i64 calc(i64 x) {
    i64 res = pw(3, x + 1LL);
    if (x - 1LL >= 0) {
        res += pw(3, x - 1LL) * x;
    }
    return  res;
}


void solve() {
    i64 n,k;
    cin >> n >> k;
    i64 cntk = 0;
    vector<i64> ans;
    while (n) {
        ans.push_back((n % 3));
        cntk += n % 3;
        n /= 3;
    }
    if (cntk > k) {
        cout << -1 << endl;
        return;
    }
    i64 sz = ans.size(),ansv = 0;
    for (int i = sz - 1;i;i--) {
        if (ans[i] != 0) {
            i64 ck = ans[i];
            i64 free = k - cntk;
            i64 vk = min(free / 2,ck);

            cntk += vk * 2;
            ans[i] -= vk;
            ans[i - 1] += 3 * vk;
        }
    }
    for (int i = 0;i < sz;i++) {
        ansv += calc(i) * ans[i];
    }

    cout << ansv << endl;
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