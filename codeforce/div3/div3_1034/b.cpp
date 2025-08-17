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

// 2025.08.17——19:20:30
// 2025.08.17——19:23:27 wa 2 了
// 2025.08.17——19:27:55 accpted

/*
 *
 * 逆天题目 。。。但是还是很奇怪
 *
*/

void solve(){
    int n, j, k;
    cin >> n >> j >> k;
    vector<i64>a(n + 1);
    for (int i = 1;i <= n;i ++) {cin >> a[i];}
    i64 cnt = 0;
    for (int i = 1;i <= n;i++) {
        if (a[i] <= a[j])cnt++;
    }
    cnt--;
    if (k > 1) {
        cout << "YES" << endl;
    }else if (cnt == n-1) {
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

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