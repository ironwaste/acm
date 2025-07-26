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

// 2025.07.26——20:23:19
// 2025.07.26——20:31:10 wa
// 2025.07.26——20:36:21 wa
// 2025.07.26——20:36:25 wa ???? 
// 2025.07.26——21:51:31 accepted
/*
 *
 * 相当于将x转换为 n进制，然后根据每一位上的值选择字符串
 * 不对不对
 * 特例，当有重复的时候，其不是按照顺序来的
 * 会产生（当 1， 2 相同还存在 3 的情况）
 * 原本是 ：
 * 时间复杂度算错了，导致原本dfs秒解决的问题，在这里瞎搞
*/

void solve() {
    i64 n, k, x;
    cin >> n >> k >> x;
    vector<string>s(n);
    vector<i64>is(n, 0);
    for (int i = 0;i < n;i++) { cin >> s[i]; }
    vector<string>ans;
    auto dfs = [&](auto self,string c,i64 step)->void {
        if (step == k) {
            ans.push_back(c);
            return;
        }
        for (auto ss:s) {
            self(self, c + ss, step + 1);
        }
        };
    dfs(dfs, "", 0);
    sort(all(ans));
    cout << ans[x - 1] << endl;

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