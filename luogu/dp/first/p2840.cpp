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

/*
以求方案数 (排列数)
deep thinking
*/


void solve(){
    int n, w;
    cin >> n >> w;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x; }
    sort(all(a));
    vector<i64>dp(w + 10, 0);
    dp[0] = 1;
    for (int i = 1;i <= w;i ++) {
        for (int j = 0;j < n;j++) {
/*
注意这里改变 了for循环的先后顺序，将n作为第二个循环
也就是内循环，就可以用于模拟其最终的结果是进行了全排序的
这一部分可以再进行深入的去思考一下。
*/           int v = a[j];
if (i >= v) {
                (dp[i] += dp[i - v]) %= mod7;
            }// else { break; }
        }
    }

    cout << dp[w] << endl;

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