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

// 2025.08.07——12:16:07
// 2025.08.07——12:21:43 accpted
/*
 *
 *
 *
*/

struct po {
    i64 h, ht,id;
};

void solve() {
    i64 n,H;
    cin >> n >> H;
    vector<po>a(n);
    for (int i = 0;i < n;i ++) {
        cin >> a[i].h;
        a[i].ht = H - a[i].h;
        a[i].id = i + 1;
    }
    sort(all(a), [&](po a, po b) {
        return a.h * a.ht < b.h * b.ht;
        });
    for (int i = 0;i < n;i ++) {
        cout << a[i].id << " \n"[n-1 == i];
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