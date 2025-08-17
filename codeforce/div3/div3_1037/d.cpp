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
    i64 n, k;
    cin >> n >> k;
    vector<pll>l_re(n);
    for (int i = 0;i < n;i ++) {
        int tmp;
        cin >> l_re[i].fi >> tmp >> l_re[i].se;
        // cin >> tmp;
    }
    sort(all(l_re));
    i64 cnt = k;
    for (int i = 0;i < n;i++) {
        i64 real = l_re[i].se, l = l_re[i].fi;
        if (real <= cnt) {
            continue;
        }else if (l <= cnt && real > cnt) {
            cnt = real;
        } else if (l > cnt) {
            break;
        }
    }

    cout << cnt << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    // 2025.07.17——23:07:26
/*
 *
 *
 *
*/
    while(T--){
        solve();
    }
    return 0;
}