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


void solve(){
    int n;
    cin >> n;
    vector<vector<i64> >mar(n, vector<i64>(n, 0));
    mar[0][0] = 1;
    mar[0][1] = 2;
    mar[1][0] = 3;
    mar[1][1] = 4;
    int cnt = 5;
    for (int i = 2; i < n;i ++) {
        for (int j = 0;j < 2;j++) {
            mar[i][j] = cnt;
        }
        cnt++;
    }

    for (int i = 2; i < n;i ++) {
        for (int j = 0;j < n;j ++) {
            mar[j][i] = cnt;
        }
        cnt++;
    }
    cout << "Yes\n";
    for (int i = 0;i < n;i ++) {
        for (int j = 0;j < n;j ++) {
            cout << mar[i][j] << " \n"[j == n - 1];
        }
    }

    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}