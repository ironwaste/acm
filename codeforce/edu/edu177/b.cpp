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
    i64 n, k,x;
    cin >> n >> k >> x;
    vector<i64>a(n),pre(n);
    for (auto& x : a) { cin >> x; }

    partial_sum(all(a), pre.begin());
    i64 sum = pre[n-1];
    i64 stk = x / sum;
    i64 res = x % sum;
    i64 tmp = 0, cnt = 0;
    for (int i = n - 1;~i;i --,cnt ++) {
        tmp += a[i];
        if (tmp >= res) { break; }
    }
    if (stk > k || (stk == k && res != 0)) {
        cout << 0LL << endl;
        return;
    }
    // cnt = n - cnt;
    if (res == 0) {
        cout << n * k - stk * n + 1LL << endl;
        return;
    }
    cout << max(0LL,n * k - stk * n - cnt)<< endl;
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