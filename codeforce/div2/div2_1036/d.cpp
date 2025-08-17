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


void solve() {
    i64 n, k, mi = LLONG_MAX;
    cin >> n >> k;
    vector<i64>a(n), cnt(2e5 + 10, 0);
    for (auto& x : a) { cin >> x; cnt[x]++; mi = min(mi, x); }
    auto b = a;
    sort(all(b));
    // 需要长度为 k-1 个的回文串
    // 如果存在k-1 长度的回文串即满足要求
    // 其中排好序后，前k个 元素中如果被全部覆盖的元素无法被删除
    // 其他都可以被删除
    if (cnt[mi] >= k - 1) {
        cout << "YES\n";
        return;
    }
    // 必须选择的数字 的下标，也就是现在所选的个数
    i64 num = lower_bound(all(b), b[k - 2]) - b.begin();
    i64 v = b[num - 1];
    vector<i64>xiabiao;
    xiabiao.pb(0);
    for (int i = 0;i < n;i++) {
        if (a[i] <= v) {xiabiao.pb(i);}
    }
    xiabiao.pb(n - 1);
    i64 ok = 1;
    // 判断必选是否为回文串
    i64 sz = xiabiao.size();
    for (i64 i = 0, j = xiabiao.size() - 2;i < j;i++, j--) {
        i64 ai = xiabiao[i], aj = xiaobiao[j];
        if (a[ai] != a[aj]) {
            ok = 0;
            break;
        }
    }
    if (!ok) { cout << "NO\n";return; }
    // 0 2 3 5 (4)
    // 1 2
    // 0 4 5 (3)
    // 1 1
    // 添加非必选是否存在大于等于 k-1大小的回文串
    if (sz % 2 == 0) {
        i64 i = sz / 2, j = (sz - 1) / 2;
        i64 ai = xiabiao[i], aj = xiaobiao[j];
        i64 ok = 1,l = aj, r = ai;
        while (ai > aj && ai > l && ok) {
            while (ai > aj && a[ai] != a[aj]) {
                aj++;
            }
            if (ai != aj && a[ai] == a[aj]) {
                num += 2;
                ok = 0;
                break;
            }
            aj = l, ai--;
        }
        if (ok)num++;
    }
    if (num >= k - 1) {
        cout << "YES\n";
        return;
    }
    for (i64 i = (sz - 1) / 2, j = sz / 2;i >= 0 && j < sz;i--, j++) {
        i64 ai = xiabiao[i], aj = xiaobiao[j],ok = 1;
        while (ai > xiabiao[i-1] && aj <xiabiao[j+1] && ok) {

        }
        
    }



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    // 2025.07.07——00:00:13
    while(T--){
        solve();
    }
    return 0;
}