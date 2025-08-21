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

// 2025.08.21——22:35:37
// 2025.08.21——22:40:45 accpted
/*
 *
 *
 *
*/

void solve() {
    int n1, n2;
    string a, b, c;
    cin >> n1 >> a >> n2 >> b >> c;
    i64 sz = c.size();
    // sz == n2
    for (int i = sz - 1;i >= 0;i--) {
        if (c[i] == 'V') {cout << b[i];}
    }
    cout << a;
    for (int i = 0;i < sz;i++) {
        if (c[i] == 'D') { cout << b[i]; }
    }cout << endl;
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