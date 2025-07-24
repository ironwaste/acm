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

// 2025.07.22——12:27:28
/*
 *
 *
 *
*/


i64 ton(char c) {
    i64 ans = c - '0';
    return ans;
};

void solve() {
    i64 n, a;
    cin >> n >> a;
    string s;
    cin >> s;
    vector<pll>num;
    i64 ans = 0;
    i64 ok = ton(s[0]), cnt = 1;
    if (s[0] == '1')ans++;
    for (int i = 1;i < n;i++) {
        if (s[i] == '1')ans++;
        if (ok == ton(s[i])) {
            cnt++;
        } else {
            num.push_back({ ok,cnt });
            cnt = 1LL;
            ok = 1 - ok;
        }
    }
    num.push_back({ ok,cnt });

    i64 sz = num.size();
    i64 success = 0;
    for (int i = 0;i < sz;i++) {
        auto [v, cntv] = num[i];
        // de(v)deb(cntv)
        if (v == 0 && cntv >= a + 1LL) {
            success = 1;
        } else if(v == 1 && cntv >= a) {
            success = 1;
        }
    }
    cout << ((success) ? n : ans) << endl;
}
// 2025.07.22——12:38:59 accpted

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