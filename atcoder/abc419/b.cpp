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

// 2025.08.16——20:03:05
// 2025.08.16——20:05:58 accpted
/*
 *
 * multiset 中的erase 会将所有的 v值删除
 * 所以只能够使用迭代器方式
*/

void solve() {
    int q;
    cin >> q;
    multiset<i64>s;
    while (q--) {
        int op, x;
        cin >> op;
        if (op == 1) {
            cin >> x;
            s.insert(x);
        } else {
            i64 v = *s.begin();
            cout << v << endl;
            s.erase(s.begin());
        }
    }

    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}