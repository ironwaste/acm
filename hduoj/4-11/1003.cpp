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
    
    i64 n;
    cin >> n;
    vector<i64>a(n,0LL), b(n,0LL), pre(n + 1, 0LL);
    i64 tmpsum = 0;
    for (auto &x : a) { cin >> x; }
    for (auto &x : b) { cin >> x; }
    for (int i = 0;i < n;i ++) { tmpsum = max(tmpsum, a[i] + b[i]); }
    partial_sum(all(a), pre.begin() + 1);
    
    i64 l = 0LL, r = 0LL;
    while (l < n && r < n) {
        r = l;
        i64 tmpv = a[l] + b[l];
        while (r < n && (a[r] + b[r]) == tmpv) {
            tmpsum = max(tmpsum, (pre[r + 1] - pre[l]) * (r - l + 1LL));
            r++;
        }
        l = r;
    }


    cout << tmpsum << endl;
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