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

// 2025.08.07——22:36:33
// 2025.08.07——22:45:27 看错题面了 accpted 。。。
/*
 * 一种情况 全部都是一个值
 * 
 *
*/

void solve(){
    int n;
    cin >> n;
    vector<int>a;
    i64 cnt_1 = 0;
    map<i64, i64>mp;
    for (int i = 0;i < n;i++) {
        int x;
        cin >> x;
        if (x == -1) {
            cnt_1++;
        } else {
            a.push_back(x);
            mp[x]++;
        }
    }
    i64 sz = mp.size();
    if (sz == 0 ||(sz == 1 && mp[0] == 0)) { cout << "YES\n"; return; }
    else {
        cout << "NO\n";
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