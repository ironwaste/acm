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


void solve(){
    int n;
    cin >> n;
    vector<i64>a(n);

    for (auto& x : a) { cin >> x; x = abs(x); }

    vector<i64>pre(n + 1, 0);
    partial_sum(all(a), pre.begin() + 1);

    vector<i64>ans(n + 2, 0);
    partial_sum(all(pre), ans.begin() + 1);

    cout << ans.back() << endl;
}

int main(){
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}