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


void solve(){
    int f, v;
    cin >> f >> v;

    vector<vector<int> > a(f, vector<int>(v));
    for (int i = 0;i < f;i ++) {
        for (int j = 0;j < v;j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int> >dp(f + 10, vector<int>(v + 10, INT_MIN));
    for (int i = 0;i <= v;i ++) {
        dp[0][i] = 0;
    }
    vector<vector<vector<int> > >dpa(f + 10, vector<vector<int> >(v + 10));
    for (int i = 0;i < f;i ++) {
        for (int j = i;j < v;j++) {
            int k1 = dp[i][j] + a[i][j],k3 = dp[i + 1][j];
            if (k1 > k3) {
                dp[i + 1][j + 1] = k1;
                dpa[i + 1][j + 1] = dpa[i][j];
                dpa[i + 1][j + 1].pb(j + 1);

            } else {
                dp[i + 1][j + 1] = k3;
                // dpa[i + 1][j + 1] = dpa[i][j];
                dpa[i + 1][j + 1] = dpa[i+1][j];
            }
        }
    }
    // for (int i = 0;i <= f;i ++) {
    //     for (int j = 0;j <= v;j++) {
    //         cout << dp[i][j] << " ";
    //     }cout << endl;
    // }


    cout << dp[f][v] << endl;
    for (auto x : dpa[f][v]) {
        cout << x << " ";
    }
}

int main(){
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}
