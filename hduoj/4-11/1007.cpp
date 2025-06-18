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


void solve(){
    int n;
    cin >> n;
    vector<i64>a(n);
    string s;
    for (auto& x : a) { cin >> x; }
    cin >> s;
    vector<i64>r, b;

    for (int i = 0;i < n;i++) {
        if (s[i] == 'R') {
            r.pb(a[i]);
        }else{
            b.pb(a[i]);
        }
    }
    sort(all(r));
    sort(all(b));
    i64 szr=r.size(),szb=b.size(),sz = min(r.size(), b.size());
    i64 rmx = 0, bmx = 0;
    for (i64 i = szr - 1,cnt=0;cnt <= sz&&i >= 0;cnt++,i--) {
        rmx += r[i];
    }

    for (i64 i = szb - 1,cnt=0;cnt < sz&&i >= 0;cnt++,i--) {
        bmx += b[i];
    }
    cout << rmx + bmx << endl;
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