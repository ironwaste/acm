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


void solve(){
    int n, A, x;
    cin >> n >> A >> x;

    vector<int>a(n);
    for (auto& x : a) { cin >> x; }
    vector<int>num(33000, 0);
    num[x] = 1;
    for (int i = 0;i < n;i++) {
        vector<int>dnum(33000, 0);
        for (int j = 0;j < 33000;j++) {
            if (num[j]) {
                int xx = j, k = a[i];
                int a1=0, a2=0, a3=0;
                int cnt = 1;
                while (xx || k) {
                    a1 += max(xx % A, k % A) * cnt;
                    a2 += min(xx % A, k % A) * cnt;
                    a3 += ((xx + k) % A) * cnt;
                    cnt *= A;
                    xx /= A;
                    k /= A;
                }
                dnum[a1] = 1;
                dnum[a2] = 1;
                dnum[a3] = 1;  
            }
        }
        num = dnum;
    }
    i64 ans = 0;
    for (int i = 0;i < 33000;i++) {
        if (num[i]) { ans += i; }
    }
    cout << ans << endl;




    
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}