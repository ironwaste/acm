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

// 2025.09.13——23:11:54
/*
 *
 *
 *
*/

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64>a(n);
    map<i64, i64>freq;
    for (auto& x : a) {
        cin >> x;
        freq[x]++;
    }
    for (auto &[x, y] : freq) {
        if (y % k != 0) { cout << 0 << endl; return; }
        y /= k;
    }
    i64 ans = 0;
    map<i64, i64>cnt;
    // cnt[a[i]]
    for (int i = 0, j = -1;i < n;i++) {
        while (j + 1 < n &&
            (freq[a[j + 1]] >= cnt[a[j + 1]] + 1)) {
            // de(j + 1)de(a[j + 1])deb(freq[a[j + 1]]);
            cnt[a[j + 1]]++;
            j++;
        }
        ans += j - i + 1LL;
        cnt[a[i]]--;
    }
    cout << ans << endl;
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