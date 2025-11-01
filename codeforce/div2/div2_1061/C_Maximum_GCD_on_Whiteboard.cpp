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
#define all(x) x.begin(),x.end()
#define de(x) cerr << #x <<" "<<x <<" ";
#define deb(x) cerr << #x <<" "<<x <<endl;
using namespace std;


using pii = pair<int,int>;
using pll = pair<i64, i64>;

// 补题——题目链接:
// 网址：
// 2025.10.24——22:57:15
/*
 * 一： 删除 最小的k个 然后 求剩余的 数字 /3 的最小值 ,不可能
 * 答案不可能小于情况一
 * 
 * 二： 根据因数 （300）？ 质因数分解
 * 2e5 内有质数 17984  2e4 个
 *
 * 好像可以二分哦
 * 全部便利 log
 * >= 4 * g;
 *
 * 
*/

void solve() {
    i64 n, k,mx = 0;
    cin >> n >> k;
    vector<i64>a(n);
    map<i64, i64>mp;
    for (auto& x : a) { cin >> x;mp[x]++; }
    sort(all(a));
    mx = a.back();
    // i64 ans = a[k] / 3;
    i64 ans = 1LL;
    for (i64 i = mx;i >= ans + 1;i --) {
        i64 cnt = 0;
        i64 up = min(mx, 4LL * i - 1);
        i64 re = n - (lower_bound(all(a), 4LL * i) - a.begin());
        

        for (i64 j = i;j <= up;j += i) {
            if (mp.count(j)) {
                cnt += mp[j];
            }
        }

        i64 res = n - (re + cnt);
        if (res <= k) { ans = i; break; }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}