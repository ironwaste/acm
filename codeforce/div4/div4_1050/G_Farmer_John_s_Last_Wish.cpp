// 看什么看,以为我厉害吗？
// 我只是戾气很重,不厉害只需要114514分钟就能变厉害了
// 而你我的朋友只需要2.5年就可以了
#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define all(x) x.begin(), x.end()
#define pb push_back
#define i64 long long
#define fi first
#define se second
#define endl '\n'
#define de(x) cerr << #x << "=" << x << " "
#define deb(x) cerr << #x << "=" << x << endl

using pii = pair<int,int>;
using pll = pair<i64,i64>;

// 2025.09.14 —— 00:40:00
/*
 * 
 * 对每个前缀p, g(p) = max{ cnt[d] | cnt[d]<|p| }
 */

void solve() {
    int n; cin >> n;
    vector<int>a(n);
    for (int i=0;i<n;i++) cin >> a[i];

    vector<int>cnt(n+1,0), ccnt(n+1,0);
    ccnt[0]=n; 
    set<int>st; st.insert(0);

    static vector<vector<int>> divisors;
    static int maxPre = 0;
    if (maxPre < n) {
        maxPre = n;
        divisors.assign(n+1,{});
        for (int d=1; d<=n; d++) {
            for (int m=d; m<=n; m+=d) {
                divisors[m].pb(d);
            }
        }
    }

    for (int i=1;i<=n;i++) {
        int x=a[i-1];
        for (int d: divisors[x]) {
            int oldc=cnt[d];
            if (--ccnt[oldc]==0) st.erase(oldc);
            cnt[d]=oldc+1;
            if (ccnt[cnt[d]]++==0) st.insert(cnt[d]);
        }
        // 找 < i 的最大值
        auto it=st.lower_bound(i);
        int ans=0;
        if(it==st.begin()) ans=0;
        else { --it; ans=*it; }
        cout << ans << (i==n?'\n':' ');
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
