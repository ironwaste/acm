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

// 2025.08.14——13:36:13
// 2025.08.14——14:30:29 accpteds
/*
 *
 *
 *
*/
const i64 N = 1e6 + 10;
set<i64>p;
i64 pri[N];
void init() {
    for (i64 i = 2;i < N;i ++) {
        if (!pri[i]) {
            pri[i] = 1;
            p.insert(i);
        }
        for (auto x : p) {
            if (x * i >= N)break;
            pri[x * i] = 1;
            if (i % x == 0)break;
        }
    }
}

void solve(){
    i64 n, m;
    cin >> n >> m;
    if (n == 1 || m == 1) {
        cout << "YES" << endl;
        
    } else if (__gcd(n, m) != 1) {
        cout << "NO" << endl;
        return;
    }else{
        cout << "YES" << endl;
    }
    vector<vector<i64> >g(n + 2, vector<i64>(m + 2, 0));
    i64 cnt = 0;
    i64 x = 0,y = 0;
    if (m >= n) {
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                cnt++;
                // de(cnt)de(x)deb(y);
                g[x][y] = cnt;
                if (cnt % 2 == 1) {
                    y = (y + cnt) % m;
                } else {
                    y = (y - (cnt % m) + m) % m;
                }
            }
            if (i % 2 == 0) {x = (x + (cnt % n)) % n;}
            else {x = (x - (cnt % n) + n) % n;}
        }
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                cout << g[i][j] << " ";
            }cout << endl;
        }
    }else {
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                g[x][y] = ++cnt;
                if (cnt % 2 == 1) {
                    x = (x + cnt) % n;
                } else {
                    x = (x - cnt % n + n) % n;
                }
            }
            if(i % 2 == 0)y = (y + cnt % m) % m;
            else {y = (y - cnt % m + m )% m;}
            
        }

        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                cout << g[i][j] << " ";
            }cout << endl;
        }
    }




}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}