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


void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n),b(n),c(n);
    i64 A = 0, B = 0, C = 0;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        A += a[i];
    }

    for (int i = 0;i < n;i++) {
        cin >> b[i];
        B += b[i];
    }

    for (int i = 0;i < n;i++) {
        cin >> c[i];
        C += c[i];
    }
    
    // de(A)de(B)de(C)
    cout << (C - B) / A << endl;    

}

int main() {
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