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

// 2025.08.05——12:44:31
// 2025.08.05——12:59:05
/*
 *
 *
 *
*/
const i64 N = 1e6 + 10;
i64 lim = 1e6;
// vector<i64> p;
// i64 pri[N], v[N];
// vector<i64>ans;
// void init() {
//     for (int i = 2;i <= lim;i++) {
//         if (!pri[i]) {
//             p.push_back(i);
//         }
//         for (auto x : p) {
//             if (i * x >= N)break;
//             pri[i * x] = 1;
//             if (i % x == 0)break;
//         }
//     }
// }

i64 minp[N],mx[N];

void init() {

    // N * log(N) + N
    for (int i = 2; i < N; i++)minp[i] = i;
    for (int i = 2; i < N; i++) {
        if (minp[i] != i)continue;
        for (int j = 2 * i; j < N; j += i) {
            if (minp[j] == j)minp[j] = i;
        }
    }
}
void solve() {
    i64 n;
    cin >> n;
    i64 cnt = n / 2;
    for (int i = 2;i <= n && cnt > 0;i++) {
        // deb(i);
        i64 v = i;
        // if (minp[v] == v)cout << v << " ";
        i64 ccnt = 0;
        while (v > 1) {
            v /= minp[v];
            ccnt++;
        }
        if (ccnt % 2 == 1) {
            cout << i << " ";
            cnt--;
        }
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    // cout << p.size() << endl;
    // cout << ans.size() << endl;
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}