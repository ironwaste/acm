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

// 2025.09.20——20:03:34
// 2025.09.20——20:06:59 ac
// https://atcoder.jp/contests/abc424/tasks/abc424_b
/*
 *
 *
 *
*/

void solve(){

    i64 n, m, k;
    cin >> n >> m >> k;
    vector<set<i64>>p(n + 1);
    vector<i64>num(n + 1, 0);
    for (int i = 0;i < k;i++) {
        i64 a, b;
        cin >> a >> b;
        if (p[a].count(b))continue;
        p[a].insert(b);
        num[a]++;
        if (num[a] >= m) {
            cout << a << " ";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}