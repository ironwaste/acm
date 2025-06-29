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
    int n;
    cin >> n;
    i64 a1, an;
    cin >> a1;
    if (n - 2 ) {
        vector<i64>a(n - 2);
        for (auto& x : a) { cin >> x; }

        cin >> an;
        sort(all(a));
        i64 cnt = 2, v = a1;
        while (v * 2 < an && cnt < n) {
            i64 id = upper_bound(all(a), v * 2) - a.begin() - 1;
            if (!(id >= 0 && id < n - 2)) { cout << -1 << endl; return; }
            // de(cnt)de(v)de(tmp);
            v = a[id];
            cnt++;
        }
        if (cnt == n && v * 2 < an) { cout << -1 << endl; return; }
        cout << cnt << endl;

    } else {
        cin >> an;
        if (a1 * 2 >= an)cout << 2 << endl;
        else { cout << -1 << endl; }
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