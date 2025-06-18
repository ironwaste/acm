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
using pis = pair<i64, string>;
void print(string anst) {

    anst[0] = char(anst[0] - 32);
    cout << "Stage: " << anst << endl;

    
}


void solve() {
    int n;
    cin >> n;
    vector<pis>a(n);
    for (int i = 0;i < n;i++) { cin >> a[i].se >> a[i].fi; }
    vector<i64>two;
    for (int i = 0;i < n;i++) { two.pb(a[i].fi); }
    sort(all(two));
    vector<i64>r(n, 0);
    for (i64 i = 0;i < n;i ++) {
        i64 num = n - (upper_bound(all(two), a[i].fi) - two.begin()) + 1;
        r[i] = num;
    }

    string anst = "";
    for (int i = 0;i < n;i++) {
        i64 sz = a[i].se.size();
        i64 len = sz - r[i];
        if (r[i] >= sz) { continue; }
        else {
            anst += a[i].se.substr(0, len);
        }
    }

    // cout << anst << endl;
    print(anst);


    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}