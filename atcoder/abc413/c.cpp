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
    int q;
    cin >> q;
    vector<pll>sq;
    i64 cnt = -1,f = 0;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            i64 c, x;
            cin >> c >> x;
            sq.pb(make_pair(x,c));
            cnt++;
        } else if (op == 2) {
            i64 k, sum = 0;
            cin >> k;
            while (k) {
                i64 de = min(sq[f].se, k);
                sum += de * sq[f].fi;
                sq[f].se -= de;
                k -= de;
                if (sq[f].se == 0) {
                    f++;
                    // sq.erase(sq.end());
                }
            }
            cout << sum << endl;
        }

    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}