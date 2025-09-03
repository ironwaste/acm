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
    int n, m;
    cin >> n >> m;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x;x = x % 2; }
    // i64 ans = min(n, m);
    // 分两个数组循环比较，
    i64 mm = m * 2;
    vector<vector<i64> >base(2, vector<i64>(mm));
    for (int i = 0;i < mm;i ++) {
        base[0][i] = i % 2;
        base[1][i] = 1 - (i % 2);
    }
    // 0 1 0 1 0 1
    // 1 0 1 0 1 0

    // 和数组做比较，然后去求解
    // 去找到应当的不一样的值有多少， 然后去找
    int index = 0, diff_0 = 0, diff_1 = 0,ans1 =n,ans2=n;
    // point at  index % m;
    for (int i = 0;i < m;i ++) {
        if (base[0][i] != a[i]) {diff_0++;}
        if (base[1][i] != a[i]) {diff_1++;}
    }
    ans1 = diff_0;
    ans2 = diff_1;
    for (int i = m;i < n;i ++,index ++) {
        if (base[0][index % mm] != a[index]) {diff_0--;}
        if (base[1][index % mm] != a[index]) {diff_1--;}
        if (base[0][i % mm] != a[i]) {diff_0++;}
        if (base[1][i % mm] != a[i]) {diff_1++;}
        ans1 = min(ans1, diff_0);
        ans2 = min(ans2, diff_1);
    }

    cout << min(ans1, ans2) << endl;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}