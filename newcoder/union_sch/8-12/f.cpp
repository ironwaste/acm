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

// 2025.08.12——12:40:05
/*
 *
 *
 *
*/


i64 dis(pll a, pll b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void solve() {
    vector<pll>a,b;
    i64 x, y;
    // i64 mi = 1e9 + 10;
    for (int i = 0;i < 2;i++) {
        cin >> x >> y;
        a.push_back({ x,y });
    }
    
    for (int i = 0;i < 2;i++) {
        cin >> x >> y;
        b.push_back({ x,y });
    }
    if (a[0] == a[2] && a[1] == a[3]) {
        cout << 0 << endl;
        return;
    } else if (a[0] == a[2]) {
        if (a[1].y == a[3].y) {
            cout << 2 << endl;
        } else {
            cout << 1 << endl;
        }
        return;
    } else if (a[0] == a[3]) {
        if (a[1].y == a[2].y) {
            cout << 2 << endl;
        } else {
            cout << 1 << endl;
        }
        return;
    }
    // sort(all(a));

    i64 xa = min(   )

    



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