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

i64 pw(i64 a, i64 b) {
    // if (b == 0) { return 0LL; }
    i64 res = 1LL;
    while (b) {
        if (b & 1LL) res = res * a;
        b >>= 1;
        a = a * a;
    }
    return res;
}
int v_pos(int a,int pos){
    return (1 & (a >> pos));
}

// 需要的是，a , b, c
// a b c共同存在的
int v_sum(int a, int b) {
    // return 1 & (a >> pos);
    i64 res12 = 0,res1=0,res2=0;
    for (int i = 0;i <= 30;i++) {
        int v1 = v_pos(a, i), v2 = v_pos(b, i);
        if (v1 & v2) { res12++; }// 两个共同存在的
        if (v1 == 1 && v2 == 0) res1++;// 1 有,2 没有
        if (v1 == 0 && v2 == 1) res2++;// 2 有,1 没有
    }
    return pw(2, res1 + res12) - 1LL + pw(2, res2 + res12) - 1LL;
}
i64 v_3_sum(i64 a, i64 c, i64 b) {
    i64 res = 0;
    for (int i = 0;i <= 30;i++) {
        int v1 = v_pos(a, i), v2 = v_pos(b, i);
        if (v1 & v2) { res ++; }// 两个共同存在的
        // if (v1 == 1 && v2 == 0) res1++;// 1 有,2 没有
        // if (v1 == 0 && v2 == 1) res2++;// 2 有,1 没有
    }
    return pw(2, res) - 1LL;    
}

void solve() {
    i64 n,m;
    cin >> n >> m;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x; }
    i64 ans = 0;
    for (int i = 1;i < n- 1;i ++) {
        i64 v1 = a[i - 1], v2 = a[i], v3 = a[i + 1];
        ans += v_3_sum(v1, v2, v3);
    }
    ans += v_sum(a[0], a[1]);
    ans += v_sum(a[n-1], a[n-2]);
    cout << ans << endl;
}

/*
3 -> 011
4 -> 100
res12 = 0;
res1 = 1;
res2 = 2;

ans is 4
5 3
6 3
7 3
4 7
--------------------------
3 -> 011
6 -> 110
->4 - 1
1 6
3 6
5 6
7 6
->4 - 1 
3 4
3 5
3 6
3 7


*/



// 5 3
// 6 3
// 

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