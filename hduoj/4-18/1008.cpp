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
const int N = 110;
i64 frac[N];

void init() {
    frac[0] = 1LL;
    for (i64 i = 1LL;i < N;i++) {
        frac[i] = frac[i - 1] * i;
        de(i)deb(frac[i]);
    }
}

i64 C(i64 a, i64 b) {
    return frac[a]/frac[a - b]/frac[b];
}


void solve() {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    if (!a || !b || !c || (d + e == 0)) {
        cout << 0 << endl;return;
    }
    i64 res = 1LL;
    // d = d + e;
    res *= a * b * c;
    res = (res * (d * (d - 1LL) / 2) + res * (d * e));

    cout << res << endl;

    return;
}

int main() {
    // init();
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