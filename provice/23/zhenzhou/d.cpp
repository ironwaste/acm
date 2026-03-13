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


using pii = pair<int, int>;
using pll = pair<i64, i64>;

// 补题——题目链接:
// 网址：
// 2025.11.18——21:42:52
/*
 *
 *
 *
*/
// const int N = 1e5 + 10;
// int minp[N];
// vector<i64>fac[N];
// void init() {
//     for (int i = 2;i < N;i++) {
//         for (int j = i;j < N;j += i) {
//             if (!minp[j]) { minp[j] = i; }
//             fac[j].push_back(i);
//         }
//     }
// }
const i64 N = 1e9 + 10;
vector<i64>f25;

void init() {
    for (i64 i = 1;i < N;i *= 2LL) {
        for (i64 j = 1;j * i < N;j *= 5LL) {
            f25.push_back(i * j);
        }
    }
    sort(all(f25));
}


void solve() {
    i64 a, b;
    cin >> a >> b;
    i64 v = b;

    while (v % 2 == 0 || v % 5 == 0) {
        if (v % 2 == 0) { v /= 2; }
        if (v % 5 == 0) { v /= 5; }
    }

    if (v == 1) {
        cout << 0 << " " << 1 << endl;
        return;
    }
    i64 mic = LLONG_MAX, mid = LLONG_MAX;
    mic = v - a % v;
    mid = b;
    i64 tmpgd = __gcd(mic, mid);
    mic /= tmpgd;
    mid /= tmpgd;
    // 是一个 同余循环节 
    // * 2 * 5 * 4 * 
    for (auto d : f25) {
        i64 da = a * d;
        i64 dd = d * b;
        i64 res = v - (da % v);

        i64 gd = __gcd(res, dd);
        i64 tmpc = res / gd;
        i64 tmpd = dd / gd;

        
        if (mic > tmpc && tmpd <= (i64) (1e9)) {
            mic = tmpc;
            mid = tmpd;
        }
        i64 vc = res;
    }
    cout << mic << " " << mid << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while (T--) {
        // deb(T);
        solve();
    }
    return 0;
}