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
using a3 = array<i64, 3>;
// 2025.08.22——00:13:51
// 2025.08.24——01:57:18 accpted
/*
 *
 *
 *
*/

void solve(){
    int n, m,q;
    cin >> n >> m >> q;
    vector<i64>a(n), b(m);
    for (int i = 0;i < n;i ++) { cin >> a[i]; }
    for (int i = 0;i < m;i ++) { cin >> b[i]; }
    sort(all(a), greater<i64>());
    sort(all(b), greater<i64>());
    vector<pll>id;
    i64 i = 0, j = 0;
    id.push_back({ i,j });
    while (i < n || j < m) {
        if (i < n && j < m) {
            if (a[i] >= b[j]) {
                id.push_back({i + 1, j});
                i++;
            } else {
                id.push_back({i, j + 1});
                j++;
            }
        } else if (i < n) {
            id.push_back({i + 1, j});
            i++;
        } else {
            id.push_back({i, j + 1});
            j++;
        }
    }

    // 大的在前小的在后
    // 然后 用 a数组下标标记 比其大的值的b数组的下标

    vector<i64>prea(n+1,0), preb(m + 1,0);
    partial_sum(all(a), prea.begin() + 1);
    partial_sum(all(b), preb.begin() + 1);
    for (int i = 0;i < q;i++) {
        i64 x, y, z,mx = 0;
        cin >> x >> y >> z;
        i64 xx = id[z].fi, yy = id[z].se;
        if (xx <= x && yy > y) {
            xx += yy - y;
            yy = y;
        } else if (xx > x && yy <= y) {
            yy += xx - x;            
            xx = x;
        }
        cout << prea[xx] + preb[yy] << endl;
    }
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