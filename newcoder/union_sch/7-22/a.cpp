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

// 2025.07.22——13:36:29
/*
 *
 *
 *
*/

void solve(){
    i64 n;
    cin >> n;
    vector<i64>f(n + 1, 0);
    for (int i = 1;i <= n;i++) { cin >> f[i]; }

    vector<vector<i64> >g(n + 1, vector<i64>(n + 1, 0));

    for (int i = n;i > 1;i --) {
        g[i][i] = 1;
    }
    for (int i = 3;i <= n;i++) {
        i64 cnt = 2;
        for (int j = 1;j <= i - 2;j++,cnt ++) {
            g[i][j] = g[j][i] = cnt;
        }
    }
    for (int i = 1;i <= n;i ++) {
        if (f[i] == 1) {
            g[i][i] = 0;
        } else {
            i64 v = f[i] - 1;
            g[v][i] = g[i][v] = 0;
        }
    }

    
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cout << g[i][j] << " ";
        }cout << endl;
    }
}

// 2025.07.22——14:09:19 wa
// 2025.07.22——14:21:23 accepted

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