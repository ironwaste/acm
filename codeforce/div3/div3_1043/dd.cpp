// 看什么看,以为我厉害吗？
// 我只是戾气很重,不厉害只需要114514分钟就能变厉害了
// 而你我的朋友只需要2.5年就可以了
#include<bits/stdc++.h>
#include<climits>


#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define i64 unsigned long long
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

i64 calc(i64 n) {
    if (n <= 0) return 0;
    if (n < 10) return n * (n + 1) / 2;
    
    string s = to_string(n);
    int len = s.length();
    i64 base = 1;
    for (int i = 0; i < len; i++) base *= 10;
    if (n + 1 == base) {
        return 45 * len * (base / 10);
    }

    i64 p = 1;
    for (int i = 0; i < len - 1; i++) p *= 10;
    i64 a = n / p;
    i64 r = n % p;

    i64 F = 45 * (len - 1) * (p / 10);
    i64 res = (a - 1) * a / 2 * p + a * F;
    res += a * (r + 1) + calc(r);
    return res;
}



void solve() {
    i64 k;
    cin >> k;
    if (k == 0) {
        cout << 0 << endl;
        return ;
    }

    i64 prev = 0,di = 0;
    while (true) {
        di++;
        i64 num_dig = 9 * pow(10, di - 1) * di;
        if (prev + num_dig >= k) break;
        prev += num_dig;
    }

    i64 low = pow(10, di - 1);
    i64 pos = k - prev;
    i64 idx = (pos - 1) / di;
    i64 n = low + idx;
    i64 digi = (pos - 1) % di + 1;

    i64 ans = calc(n - 1);
    string s_n = to_string(n);
    for (i64 i = 0; i < digi; i++) {
        ans += s_n[i] - '0';
    }
    cout << ans << endl;
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

