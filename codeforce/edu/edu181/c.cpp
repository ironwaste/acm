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

// 2025.07.22——22:50:00
/*
 * 就是要找 2， 3 ，5 ，7的解呗，然后容斥一下
 * 总数 - 2 的倍数 - 3的倍数 - 5的倍数 - 7的倍数(2,3,5,7)
 * 总数 + 6的倍数 + 10的倍数 + 14的倍数 (2,3/2,5/2,7)
 * 总数 + 15的倍数 + 21 的倍数 (3,5/3,7)
 * 总数 + 35的倍数 (5,7)
 * 总数 - 30的倍数 - 42 的倍数 - 70的倍数 - 105的倍数 (2,3,5/2,3,7/2.5.7/3,5,7)
 * 总数 + 210的倍数
*/
i64 cal(i64 x, i64 l, i64 r) {
    return (r / x) - ( (l -1) / x);
}

vector<i64>b = { 6,10,14,15,21,35 ,210};
vector<i64>a = { 2,3,5,7,30,42,70,105 };

void solve() {
    i64 l, r;
    cin >> l >> r;
    // 下取整即可
    i64 sum = r - l + 1;
    for (auto x : a) {
        sum -= cal(x, l, r);
        // de(x)deb(cal(x, l, r));
    }
    for (auto x : b) {
        sum += cal(x,l,r);
        // de(x)deb(cal(x, l, r));
    }
    cout << sum << endl;
}
// 2025.07.22——23:05:26 accpted
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