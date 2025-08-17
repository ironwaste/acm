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


// 两个字符 的位置可以同时改变 以达到包含范围最小的部分
// 以此就可以 

void solve() {
    string s;
    cin >> s;
    int n;
    n = s.size();
    int ge = 40;
    map<char, int>mp;
    // for (auto x : s) {
    //     ge++;
    // }
    vector< vector<int> >id(ge + 10);
    int cnt = 0;
    for (int i = 0;i < n;i++) {
        if (!mp.count(s[i])) {
            id[cnt].pb(i);
            mp[s[i]] = cnt++;
        } else {
            id[mp[s[i]]].pb(i);
        }
    }
    for (auto v : id) {
        cout << "  ";
        for (auto u : v) {
            cout << u << " ";
        }cout << endl;
    }

    
    vector<pii>p1, p2;
    for (int i = 0;i < ge;i ++) {
        int sz = id[i].size();
        // de(sz);
        for (int j = 0;j < sz / 2;j++) {
            // de(j);
            int k1 = id[i][j], k2 = n - 1 - id[i][sz - j - 1];                if (k1 > k2) { swap(k1, k2); }
            if (k1 == k2) { continue; }
            p1.pb(make_pair(k1, k2));
            // cout << "p1 :  ";
            // de(k1)de(k2);
            k1 = id[i][sz - j - 1], k2 = n - 1 - id[i][j];
            if (k1 > k2) { swap(k1, k2); }
            p2.pb(make_pair(k1, k2));
            // cout << "p2 :  ";
            // de(k1)de(k2);
        }
        // cout << endl << "---------\n";
    }
    for (auto [x,y] : p1) {
        de(x)deb(y)
    }
    cout << "--------- under  is  p2 : " << endl;
    for (auto [x,y] : p2) {
        de(x)deb(y)
    }
    int ssz = p1.size();
    if (ssz == 0) { cout << 0 << endl; return; }
    vector<pii>dp(ssz + 10, { -1,-1 });
    auto dp2 = dp;
    // 存储左右边界 ？
    for (int i = 0;i < ssz;i++) {
        if ( !i ) {
            dp[i + 1] = p1[i];
            dp2[i + 1] = p2[i];
        } else {
            pii tmp1 = dp[i];
            auto tmp2 = tmp1;
            tmp1.fi = min(tmp1.fi, p1[i].fi);
            tmp1.se = max(tmp1.se, p1[i].se);

            tmp2.fi = min(tmp2.fi, p2[i].fi);
            tmp2.se = max(tmp2.se, p2[i].se);

            if (tmp1.se - tmp1.fi <= tmp2.se - tmp2.fi) {
                dp[i + 1] = tmp1;
            } else {
                dp[i + 1] = tmp2;
            }
            
            tmp1 = dp2[i];
            tmp2 = tmp1;
            tmp1.fi = min(tmp1.fi, p1[i].fi);
            tmp1.se = max(tmp1.se, p1[i].se);

            tmp2.fi = min(tmp2.fi, p2[i].fi);
            tmp2.se = max(tmp2.se, p2[i].se);

            if (tmp1.se - tmp1.fi <= tmp2.se - tmp2.fi) {
                dp2[i + 1] = tmp1;
            } else {
                dp2[i + 1] = tmp2;
            }
        }
    }
    
    for (int i = 0; i <= ssz;i++) {
        cout <<i<<"   :"<< dp[i].fi << " " << dp[i].se<< endl;
    }
    cout << "dp2 : ------------ " << endl;
    for (int i = 0; i <= ssz;i++) {
        cout <<i<<"   :"<< dp2[i].fi << " " << dp2[i].se<< endl;
    }

    
    cout << min(dp[ssz].se - dp[ssz].fi + 1,dp2[ssz].se - dp2[ssz].fi + 1) << endl;
    return ;
    
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}

/*

10
eteffeteefekfektetee
*/
