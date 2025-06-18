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
    i64 n, q;
    cin >> n >> q;
    vector<i64>a(n);
    iota(all(a), 1);
    i64 index = 0;
    while (q--) {
        int op, p, x;
        cin >> op;
        if (op == 1) {
            cin >> p >> x;
            a[(index + p - 1) % n] = x;
            // de(op) deb(index + p - 1);
        } else if (op == 2) {
            cin >> p;
            cout << a[(index + p - 1) % n] << endl;
            // de(op) deb(index + p - 1);
        } else if (op == 3) {
            cin >> p;
            // de(op) de(index)deb((index + p) % n);
            index = (index + p) % n;
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