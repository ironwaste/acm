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
    int n;
    cin >> n;
    n-=2;
    vector<int>b(n );
    for (int i = 0;i < n;i ++) {
        cin >> b[i];
    }
    int ok = 0;
    for (int i = 1;i < n - 1;i++) {
        if (b[i] == 0 && b[i-1] == b[i+1] && b[i+1] == 1) {
            ok = 1;
        }
    }

    cout << ((!ok) ? "YES" : "NO") << endl;
    
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}