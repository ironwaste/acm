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

using pii = pair<int, int>;
using pll = pair<i64, i64>;



// 条件一： 三个数字加起来要大于最大值
// 条件二： 其中小的两个数字加起来要大于 选中的最大的那个数字
// 2025.09.06——03:59:55 accpted



void solve() {
    int n;
    cin >> n;
    vector<i64>a(n);
    for (auto& x : a) {
        cin >> x;
    }
    sort(all(a));
    i64 ans = 0, mx = a[n - 1];
    vector<i64>sum2, sum[n];
    for (int i = 0;i < n;i++) {
        i64 v = a[i];
        for (int j = i + 1;j < n;j++) {
            i64 vv = a[j];
            i64 w = v + vv;
            i64 le = max(vv - v + 1, mx - w + 1);
            i64 ge = w - 1;
            i64 lep = lower_bound(all(a), le) - a.begin();
            i64 gep = upper_bound(all(a), ge) - a.begin();
            i64 cnt = 0;
            if (le <= v && ge >= vv) {
                cnt+=2;
            } else if (le <= v && ge >= v) {
                cnt++;
            } else if (le <= vv && ge >= vv) {
                cnt++;
            }
            ans += max(0LL, gep - lep - cnt);
        }
    }
    cout << ans/3 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}