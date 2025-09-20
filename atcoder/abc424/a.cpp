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

// 2025.09.20——20:00:47
// 2025.09.20——20:02:50 ac
// https://atcoder.jp/contests/abc424/tasks/abc424_a
/*
 *
 *
 *
*/

void solve(){
    i64 a, b, c;
    cin >> a >> b >> c;
    set<i64>st;
    st.insert(a);
    st.insert(b);
    st.insert(c);
    if (st.size() < 3) {
        cout << "Yes" << endl;
    } else {
        cout << " No" << endl;
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