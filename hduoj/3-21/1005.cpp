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

vector<i64>fa(2);
int fd(i64 x) {
    if (fa[x] == x) {
        return x;
    } 
    return fa[x] = fd(fa[x]);
}

void uio(i64 x,i64 y) {
    i64 nx = fd(fa[x]), ny = fd(fa[y]);

    if (nx < ny)fa[ny] = fa[nx];
    else{
        fa[nx] = fa[ny];
    }
}



void solve() {
    int n;

    cin >> n;
    vector<i64>a(n,0);
    fa.resize(n);
    // for (auto x : a) { cout << x << " ";}
    iota(all(fa), 0);
    // for (auto x : fa) { cout << x << " ";}

    for (auto& x : a) { cin >> x; }

    for (int i = 0;i < n;i++) {
        if (i + a[i] < n)uio(i, i + a[i]);
        if (i - a[i] >= 0)uio(i - a[i], i);
    }
    i64 ans = 0;
    for (int i = 0;i < n;i ++) {
        if (fa[i] == i) ans++;
    }
    // deb(ans)
    cout << ans - 1LL << endl;
    
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