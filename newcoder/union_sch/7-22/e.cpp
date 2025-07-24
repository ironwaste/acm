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

// 2025.07.22——14:29:32
/*
 *
 *
 *
*/
const int N = 5e6+10;
// vector<i64>p;
i64 minp[N],mx[N],sum[N];

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
    vector<i64>a(n);
    for (auto& x : a) { cin >> x;}
    if (n % 2 == 1LL) { cout << "YES\n"; return; }
    vector<i64>pos_num;
    memset(mx, 0, sizeof mx);
    memset(sum, 0, sizeof sum);
    for (int i = 0;i < n;i++) { // n * 
        i64 v = a[i];
        i64 pv = 0;
        while (v != 1) { // log(n);
            i64 cnt = 0;
            pv = minp[v]; // O 1
            while (v % pv == 0) { // 
                v /= pv;
                cnt++;
            }
            mx[pv] = max(mx[pv], cnt);
            sum[pv] += cnt;
            pos_num.push_back(pv);
        }
    }
    i64 ok = 1;
    for (auto pos : pos_num) {
        i64 sumv = sum[pos], need = mx[pos] * n;
        if ((need - sumv) % 2LL == 1LL) {
            ok = 0;
            break;
        }
        sum[pos] = 0, mx[pos] = 0;
    }
    cout << ((ok) ? "YES\n" : "NO\n");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}