#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, a, b;
ll dp[1000050];

int main() {
    cin >> n >> a >> b;
    dp[1] = 1;
    dp[2] = 5;
    for (int i = 3; i <= n; i++) {
        ll res = dp[i - 1] * 3 - dp[i - 2] * 3 + dp[i - 3];
        if (i % 2 == 0) res++;
        res++;
        dp[i] = res;
    }
    ll ans = dp[n];
    for (ll i = 1; i <= a; i++) {
        ll x = min(min(i, a - i + 1), min(a - b + 1, b));
        ans -= x;
        // cout << i << " " << x << endl;
    }
    // cout << ans << endl;

    ll dis = abs(a - n / 2);
    for (ll i = 1; i <= n / 2 + (n % 2 ? 1 : 0) - dis; i++) {
        ll x = min(min(i, a - i + 1), min(a - b + 1, b));
        ans -= x;
        // cout << i << " " << x << endl;
    }
    
    cout << ans << endl;
}