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
    i64 n, k;
    cin >> n >> k;

    vector<pll>lr(n);
    for (int i = 0;i < n;i ++) {
        cin >> lr[i].fi >> lr[i].se;
    }
    sort(all(lr));
    priority_queue<i64,vector<i64>,greater<> >q;
    i64 res = 1LL;
    for (int i = 0;i < n;i++) {
        i64 l = lr[i].fi, r = lr[i].se;
        
        while (!q.empty() && q.top() < l) {
            q.pop();
        }
        // de(i)deb(q.size())
        (res *= max(0LL, (i64)(0LL + k - q.size()) )) %= mod3;
        q.push(r);
    }

    
    cout << res << endl;
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