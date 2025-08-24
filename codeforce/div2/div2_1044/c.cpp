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

// 2025.08.24——22:56:34
// 2025.08.24——23:35:23 accpted
/*
 *
 *
 *
*/



void solve() {
    i64 n,cnt, mx = 0, mxid = 0;
    cin >> n;
    vector<i64>g[n + 1];
    vector<i64>ans;
    vector<i64>qry(n);
    iota(all(qry), 1);
    set<i64>miss;

    for (i64 i = 1;i <= n;i ++) {
        printf("? %lld %lld",i,n);
        for (int i = 0;i < n;i++) {
            printf(" %lld", qry[i]);
        }cout << endl;
        cnt = 0;
        cin >> cnt;
        g[cnt].push_back(i);
        if(cnt > mx){
            mx = cnt;
            mxid = i;
        }
    }
    cnt = 1;
    ans.push_back(mxid);
    i64 sz = n - g[mx].size();
    
    for (i64 i = mx - 1;i >= 0;i--) {
        i64 gsz = g[i].size();
        sz -= gsz;
        if (gsz == 1) {
            ans.push_back(g[i][0]);
            cnt++;
            continue;
        }
        for (auto x : g[i]) {
            printf("? %lld %lld",ans[0],sz + cnt + 1);
            for (auto v : ans) {
                printf(" %lld", v);
            }
            printf(" %lld", x);
        
            for (i64 j = i - 1;j >= 0;j--) {
                for (auto xx : g[j]) {
                    printf(" %lld", xx);
                }

            }
            printf("\n");
            i64 ret;
            cin >> ret;
            if (ret == mx) {
                ans.push_back(x);
                cnt++;
                break;
            }
        }
    }

    printf("! %lld", cnt);
    for (auto x: ans) {
        printf(" %lld", x);
    }
    cout << endl;

}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}