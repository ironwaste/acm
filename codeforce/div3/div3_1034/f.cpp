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

// 2025.08.17——20:04:50
// 2025.08.17——20:25:36 accpted
/*
 * 线性筛  但是没想明白，想了个大概就过了。。。
*/
const i64 N = 1e5 + 10;
i64 minp[N];
set<i64>pri;
void init() {
    minp[1] = 1;
    for (int i = 2;i < N;i ++) {
        if (!minp[i]) {
            pri.insert(i);
        }
        for (auto p : pri) {
            if (i * p >= N)break;
            minp[i * p] = i;
            if (i % p == 0)break;
        }
    }
}


void solve() {
    int n;
    cin >> n;
    vector<i64>a(n + 1);
    iota(all(a), 0);
    vector<i64>vis(n + 1, 0);
    for (int i = n;i > 1;i --) {
        if (minp[i]) {
            swap(a[i], a[minp[i]]);
        }
    }
    for (int i = 1;i <= n;i++) {
        cout << a[i] << " \n"[i==n];
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    for (int i = 0;i < 1000;i ++) {
        de(i)deb(minp[i]);
    }
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}