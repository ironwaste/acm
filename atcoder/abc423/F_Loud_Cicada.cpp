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
#define all(x) x.begin(),x.end()
#define de(x) cerr << #x <<" "<<x <<" ";
#define deb(x) cerr << #x <<" "<<x <<endl;
using namespace std;


using pii = pair<int,int>;
using pll = pair<i64, i64>;

// 补题——题目链接: https://codeforces.com/problemset/problem/1542/C
// 网址：
// 2025.09.16——15:08:42
/*
 *
 *
 *
*/
// const i64 N = 70;
// i64 notis_p[N];
// vector<i64>pri;
// void init() {
//     for (int i = 2;i < N;i ++) {
//         if (!notis_p[i])pri.push_back(i);
//         for (auto p : pri) {
//             if (p * i >= N)break;
//             pri[p * i] = 1;
//             if (i % p)break;
//         }
//     }
// }

const i64 N = 43;
i64 pw(i64 a, i64 b) {
    i64 res = 1LL;
    while (b) {
        if (b & 1) res = res * a % mod7;
        a = a * a % mod7;
        b >>= 1;
    }
    return res;
}

i64 inv(i64 x) {
    return pw(x, mod7 - 2);
}

i64 LCM[N];
void init() {
    LCM[1] = 1;
    for (i64 i = 2;i < N;i++) {
        i64 v = LCM[i - 1];
        i64 gd = __gcd(v, i);
        LCM[i] = LCM[i - 1] / gd * i;
        // de(i)deb(LCM[i])
    }
}


void solve() {
    i64 nn;
    cin >> nn;
    i64 n = nn;
    i64 ans = 0;
    for (i64 i = 1,c = 0;c <= n;i++) {
        (ans += n * inv(LCM[i])% (i64)(mod7)) %= mod7;
        c = LCM[i];
        // if (cntv == 0)break;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}