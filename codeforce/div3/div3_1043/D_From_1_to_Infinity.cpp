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


// 补题——题目链接: https://codeforces.com/contest/2132/problem/D
// 网址：
// 2025.08.23——23:15:06
/*
 *
 *
 */
i64 ans = 0;
i64 pw(i64 a, i64 b) {
    if (b < 0)return 0;
    i64 res = 1LL;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

i64 calc(i64 n) {
    if (n == 0)return 0;
    else if (n < 10) {
        return n * (n + 1) / 2;
    }
    i64 res = 0;
    string s = to_string(n);

    i64 len = s.size();
    i64 p = pw(10LL, len - 1);
    i64 d = (i64) (s[0] - '0');
    i64 r = n % p;

    res += (d - 1) * d / 2 * p;
    res += (r + 1) * d;


    i64 pp = p / 10;
    res += 45LL * pp * d * (len - 1);
    res += calc(r);
    return res;
}
i64 calcn(i64 k) {
    // 9, 180, 2700,
    // 9 * pw(10,len-1) * len;
    i64 n = 0,len = 1,v = 9;
    while (k >= len * v) {
        k -= v * len;
        len++;
        v *= 10;
    }
    n = pw(10LL, len - 1) - 1;
    i64 r = k % len, cntn = k / len ;
    // de(r)deb(n)
    n += cntn;
    string s = to_string(n + 1LL);
    for (int i = 0;i < r;i ++) {
        ans += (i64)(s[i] - '0');
    }
    return n;
}

void solve() {
    i64 k;
    cin >> k;
    ans = 0;
    i64 n = calcn(k);
    // deb(n)
    ans += calc(n);
    cout << ans << endl;
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