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

// int dir[][2] = { {-1,0},{0,-1} };

void solve(){
    int n, m;
    cin >> n >> m;
    // cout << n << m << endl;
    vector<string>mp(n);
    for (int i = 0;i < n;i++) { cin >> mp[i];  }

    
    i64 ans = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            int ok = 0;
            if (mp[i][j] == '1') {
                int nx = i, ny = j;
                while (nx >= 0 && ny >= 0&&mp[nx][ny] == '1'  ) {
                    nx -= 1;
                }
                if (nx < 0) { ok = 1; }
                nx = i, ny = j;
                while (nx >= 0 && ny >= 0 && mp[nx][ny] == '1' ) {
                    ny -= 1;
                }
                if (ny < 0) { ok = 1; }
                if (!ok) { ans = 1; break; }
            }
        }
    }
    
    cout << ((ans) ? "NO\n" : "YES\n");



    
}

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