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


void solve(){
    i64 n;
    cin >> n;
    string s;
    cin >> s;
    // s += '0';
    if (s[n - 1] == '0') s += '1';
    else s += '0';
    i64 ans = n;
    vector<pll>cnt01;
    i64 l = 0, r = 0, sum = 0, cnt0 = 0, cnt1 = 0;
    for (int i = 0;i < n;i++) {
        if (s[i] == '1') {
            if (cnt0) cnt01.pb({0, cnt0 });
            cnt0 = 0;
            sum++;
            cnt1++;
        }else if (s[i] == '0') {
            if (cnt1) cnt01.pb({ 1,cnt1 });
            cnt1 = 0;
            cnt0++;
        }
    }
    cnt1 = 0, cnt0 = 0;
    i64 sz = cnt01.size();
    for (int i = 0;i < sz;i++) {
        i64 iv = cnt01[i].fi,icnt = cnt01[i].se;
        if (iv == 1) {
            cnt1 += icnt;
        } else {
            cnt0 += icnt;
        }
    }
    // 区间内的 1 的个数为 cnt1 
    // 区间外的 1 的个数为 sum - cnt1;
    // 区间内的 0 的个数为 cnt0
    // 区间外的 0 的个数为 n - cnt1 - cnt0
    // 需要改变的个数 sum - cnt1 + cnt0;
    i64 lv = 0,rv=0,l_pos = 0, r_pos = cnt01.size() - 1;
    lv = cnt01[l_pos].fi, rv = cnt01[l_pos].fi;
    i64 lcnt = cnt01[l_pos].se, rcnt = cnt01[r_pos].se;
    i64 ans = sum - cnt1 + cnt0;
    while (l < r) {
        if (lv == rv && lv == 1) {
            if (lcnt < rcnt) {
                    
            }

            
        }



        
    }




}
int main() {
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