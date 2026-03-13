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

// 2026.03.13——19:48:01
// 2026.03.13——20:12:07 ac
/*
 *
 *
 *
*/

void solve(){
    i64 n;
    cin >> n;
    vector<i64>a(n + 2,0);
    vector<i64>prx(n + 2, 0), suf(n + 2, 0);
    for (int i = 1;i <= n;i++) { cin >> a[i]; }

    for (int i = 1;i <= n;i ++) {
        prx[i] = a[i] + prx[i - 1];
        // de(i) deb(prx[i]);
    }
    for (int i = n;i >= 1;i--) {
        suf[i] = a[i] + suf[i + 1];
        // de(i) deb(suf[i]);
    }


    vector<i64>pmx(n + 2, 0), smx(n + 2, 0);
    i64 pmi = 0, smi = 0;
    for (int i = 1;i <= n;i++) {
        pmx[i] = prx[i] - pmi;
        pmi = min(prx[i], pmi);
        // de(i)deb(pmx[i]);
    }
    for (int i = n;i >= 1;i --) {
        smx[i] = suf[i] - smi;
        smi = min(suf[i], smi);
        // de(i)deb(smx[i]);
    }

    for (int i = 2;i <= n;i++) {
        pmx[i] = max(pmx[i],pmx[i-1]);
        // de(i)deb(pmx[i]);

    }
    for (int i = n - 1;i >= 1;i--) {
        smx[i] = max(smx[i], smx[i + 1]);
        // de(i)deb(smx[i]);
    }
    i64 ans = a[1] + a[3] + a[5];
    for (int i = 3;i <= n - 2;i++) {
        // de(i)de(ans)
        //     de(pmx[i - 2])de(smx[i + 2]);
        ans = max(ans, pmx[i - 2] + a[i] + smx[i + 2]);
        // deb(ans);
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