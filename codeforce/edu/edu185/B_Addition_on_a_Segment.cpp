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
#define all(x) x.begin(),x.end()
#define de(x) cerr << #x <<" "<<x <<" ";
#define deb(x) cerr << #x <<" "<<x <<endl;
using namespace std;


using pii = pair<int,int>;
using pll = pair<i64, i64>;

// 补题——题目链接: https://codeforces.com/contest/2170/problem/B
// 网址：
// 2025.11.28——22:42:23
// 2025.11.28——22:49:20 
/*
 *
 *
 *
*/

void solve(){
    int n;
    cin >> n;
    vector<int>a;
    i64 res = 0;
    for (int i = 0;i < n;i++) {
        int x;
        cin >> x;
        if (x) {
            a.push_back(x);
            res += x - 1;
        }
    }
    sort(all(a));
    int sz = a.size();
    n--;
    cout << sz - max(0LL, (n - res)) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}