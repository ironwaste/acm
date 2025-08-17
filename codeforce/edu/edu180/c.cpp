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
const i64 N = 1e5 + 10;
cont int NN = 5e3 + 10;
i64 frac[NN][NN];

void init_c(){
    for (int i = 1;i < NN;i ++ ) {
        frac[i][i] = 1;
        frac[i][1] = 1;
    }
}

i64 C(i64 m,i64 n){
    if (n == m || m == 1 ) {
        return 1LL;
    }
    if (frac[n][m]) {
        return frac[n][m];
    }
    if () {
        
    }

}

// 条件一： 三个数字加起来要大于最大值
// 条件二： 其中小的两个数字加起来要大于 选中的最大的那个数字




void solve() {
    int n;
    cin >> n;
    vector<i64>a(n);
    vector<i64>cnt(N, 0), cntsum(N + 1, 0);
    // n ^ 2;
    for (auto& x : a) { cin >> x;cnt[x]++; }
    partial_sum(all(cnt), cntsum.begin() + 1);
    i64 ans = 0;
    for (int i = n - 1;i >= 2;i--) {
        int vi = a[i];
        for (int j = i;j >= 1;j--) {
            int vj = a[j];
            if (vj == vi && cnt[vj] >= 1) {
                
            }

        }
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