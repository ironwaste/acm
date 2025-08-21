// 看什么看,以为我厉害吗？
// 我只是戾气很重,不厉害只需要114514分钟就能变厉害了
// 而你我的朋友只需要2.5年就可以了
#include<bits/stdc++.h>
#include<climits>
#include<deque>

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

// 2025.08.21——22:16:18
// 2025.08.21——22:25:57 stop
/*
 * https://codeforces.com/problemset/problem/1905/D
 *
 *
*/

void solve() {
    int n;
    cin >> n;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x; }
    deque<pll>q;
    i64 mex = n,cnt = 1,ans = 0;
    for (int i = n - 1;i >= 0;i--) {
        if (a[i] < mex) {
            ans += mex * cnt;
            q.emplace_front({ mex ,cnt });
            cnt = 1;
            mex = a[i];
        } else {
            cnt ++ ;
        }
    }
    q.emplace_front({ mex ,cnt});
    ans += mex * cnt;

    for (int i = 0;i < n;i++) {
        q.pop_front();


        
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