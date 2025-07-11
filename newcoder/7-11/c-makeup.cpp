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
// https://ac.nowcoder.com/acm/contest/1032

// 补题——题目链接: https://ac.nowcoder.com/acm/contest/112575/B
// 网址：https://ac.nowcoder.com/discuss/1519571
// 2025.07.12——00:21:45
/*
 *
 *
 *
*/

void solve(){
    i64 m , n;
    cin >> n >>m;
    std::vector<int> pos(m);
    std::iota(pos.rbegin(), pos.rend(), 2 * n);
    for (auto x :pos) {
        de(x)
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}