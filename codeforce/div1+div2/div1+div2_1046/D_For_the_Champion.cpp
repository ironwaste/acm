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
// 2025.08.29——17:19:26
/*
 *
 *
 *
*/

void qry(char c, i64 v) {
    cout <<"? " << c << " " << v << endl;;
}

void solve() {

    i64 n;
    cin >> n;
    i64 mxx =  INT_MIN, mxy = INT_MIN;
    for (int i = 0;i < n;i ++) {
        i64 x, y;
        cin >> x >> y;
        mxx = max(mxx, x + y);
        mxy = max(mxy, x - y);
    }

    i64 xy = 0, x_y;
    char l = 'L', r = 'R', d = 'D', u = 'U';
    i64 v = 1e9;
    qry(r, v);
    cin >> xy;
    qry(r, v);
    cin >> xy;
    qry(u, v);
    cin >> xy;
    qry(u, v);
    cin >> xy;

    qry(d, v);
    cin >> x_y;
    qry(d, v);
    cin >> x_y;
    qry(d, v);
    cin >> x_y;
    qry(d, v);
    cin >> x_y;

    i64 xy1 = x_y + mxy - 4 * v;
    i64 xy2 = xy + mxx - 4 * v;
    i64 x = xy1 + xy2;
    x /= 2;
    i64 y = xy2 - x;
    cout << "! " << x << " " << y << endl;

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