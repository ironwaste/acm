#include <bits/stdc++.h>
#define dg(x) std::cout << #x << ": " << x << "\n"
using namespace std;
using i64 = long long;
using i128 = __int128_t;
const i64 mod = 998244353;
void print(i128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
i128 read() {
    i128 x = 0;
    char ch = getchar();
    bool neg = false;
    if (ch == '-') {
        neg = true;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return neg ? -x : x;
}
void solve() {
    // i64 N,M;
    i128 n,m;
    n = read();
    m = read();
    // print(n);
    // scanf("%ld %ld",&n,&m);

    i128 ans = 0;
    i128 l = 1;
    i128 t = n;
    i128 cnt = 1;
    i128 last = 0;
    // i128 K = 0;
    while ( 1 ) {
        if ( t < m ) {
            // cout << cnt << '\n';
            ans += cnt*(l+n)*(n-l+1)/2;
            break;
        } else {
            i128 del = t/m;
            i128 tur = (t%m+del)/del;
            i128 b = l-(cnt*del);
            // i128 k = l-cnt;
            i128 res = (2*b+del-1)*(cnt+cnt+tur-1)*tur/2;
            res += 2*del*((cnt+tur-1)*(cnt+tur)*(2*(cnt+tur-1)+1)/6-last);
            last = (cnt+tur-1)*(cnt+tur)*(2*(cnt+tur-1)+1)/6;
            ans += res*(del)/2;
            l += tur*del; 
            t -= tur*del;
            cnt += tur;
            // print(ans);
            // printf("\n");
        }
    }
    print(ans);
    printf("\n");
    // cout << ans << '\n';
    return;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    int T = 1;
    // T = read();
    // cin >> T;
    while ( T-- ) {
        solve();
    }
    return 0;
}