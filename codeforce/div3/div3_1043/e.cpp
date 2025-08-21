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
/*
 *
 *
 *
*/

void solve(){
    int n, m,q;
    cin >> n >> m >> q;
    vector<i64>a(n), b(m),ans;
    for (auto& x : a) { cin >> x;}
    for (auto& x : b) {cin >> x; }
    sort(all(a), [&](i64 a, i64 b) {return a > b;});
    sort(all(b), [&](i64 a, i64 b) {return a > b;});
    vector<pll>id;
    pll tmp = { 0,0 };
    for (int i = 0, j = 0;i < n;i++) {

        i64 v = a[i];
        while (b[j] >= a[i]) {
            tmp.se++;
            ans.push_back(b[j]);
            id.push_back(tmp);
        }
        tmp.fi++;
        id.push_back(tmp);
        ans.push_back(a[i]);
    }

    // 大的在前小的在后
    // 然后 用 a数组下标标记 比其大的值的b数组的下标
    vector<i64>pos(n, 0);
    i64 bi = 0;
    for (int i = 0;i < n;i++) {
        i64 v = a[i];
        while (b[bi] < v) { bi++; }
        pos[i] = bi - 1;
    }
    vector<i64>prea(n), preb(m);
    partial_sum(all(a), prea.begin());
    partial_sum(all(b), preb.begin());
    for (int i = 0;i < q;i++) {
        i64 x, y, z,mx = 0;
        cin > x >> y >> z;
        mx = prea[x];
        mx += 


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