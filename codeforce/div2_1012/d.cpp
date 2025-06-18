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

const int N = 1e5 + 10;
int pri[N];
vector<i64>p;

void init() {
    for (int i = 2;i < N;i++) {
        if (!pri[i]) {p.pb(i);}

        for (auto k : p) {
            if (k * i >= N)break;
            pri[k * i] = 1;
            if (k % i == 0)break;
        }
    }
}



void solve(){

    int n;
    cin >> n;
    i64 mid = n / 3 ;
    i64 v = p[lower_bound(all(p), mid) - p.begin()];
    vector<int>cnt(n + 1, 0);
    cout << v << " ";
    cnt[v] = 1;
    for (int i = 1;i < v && i + v <= n;i++) {
        cout << v-i << " " << i + v << " ";
        cnt[v-i] = 1;
        cnt[i + v] = 1;
    }
    for (int i = 1;i <= n;i ++) {
        if (!cnt[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}