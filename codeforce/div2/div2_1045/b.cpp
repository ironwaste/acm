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

// 2025.08.26——22:50:41
// 2025.08.26——23:06:40 end
// 2025.08.26——23:24:29 start 
// 2025.08.26——23:43:19 wa1 .。。。
// 2025.08.26——23:47:47 accpted 忘记特判1 了
/*
 *
 *
 *
*/
const i64 N = 1e5 + 10;
i64 pri[N];
vector<i64>p;
void init() {

    for (int i = 2;i < N;i ++) {
        if (!pri[i]) {p.push_back(i);}
        for (auto x : p) {
            if (i * x >= N)break;
            pri[i * x] = 1;
            if (i % x == 0)break;
        }
    }
}

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64>a(n);
    
    for (auto& x : a) {cin >> x;}
    

    for (auto d : p) {
        // deb(d)
        if (k!=1&&(d % k == 0 || k % d == 0))continue;
        vector<i64>b = a;
        i64 ok = 1;
        for (auto& x : b) {
            // de(x)
            i64 cnt = 0;
            while (x % d != 0) {
                cnt++;
                x += k;
            }
            if (cnt > k) {
                ok = 0;break;
            }

        }
        if (ok) {
            for (int i = 0;i < n;i ++) {
                cout << b[i] << " \n"[i == n - 1];
            }
            return;
        }
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    // for (auto x : p) {
    //     cout << x << " ";
    // }
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}