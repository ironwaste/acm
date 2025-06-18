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
const int N = 1e7 + 10;
int pri[N];
vector<i64>p,cnt(N,0),pre(N+1,0);
// 664579
// 6e6
void init() {
    for (int i = 2;i < N;i++) {
        if (!pri[i]) {
            p.pb(i);
        }
            for (auto k : p) {
                if (k * i >= N)break;
                pri[k * i] = 1;
                if (i % k == 0)break;
            }
        
    }
    int n = p.size();
    for (int i = 0;i < n;i ++) {
        i64 cntk = 1LL,k = p[i];
        while (cntk * k < N) {
            cnt[cntk * k]++;
            cntk++;
        }
    }
    partial_sum(all(cnt), pre.begin());
}




void solve(){

    int n;
    cin >> n;

    cout << pre[n] << endl;


    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    // cout << p.size() << endl;
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}