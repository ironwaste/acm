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
    vector<i64>cnt(2,0);
    i64 ans = 0;
    vector<string>s(n);
    for (auto& x : s) {
        cin >> x;
        if (x == "Au") {
            ans++;
        } else if (x == "Ag") {
            cnt[0]++;
        } else if (x =="Cu") {
            cnt[1]++;
        }
    }

    cout << ans + min(cnt[0], cnt[1]) << endl;

    
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}