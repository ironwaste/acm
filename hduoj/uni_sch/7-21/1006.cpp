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

// 2025.07.21——12:16:53
/*
 * 先把第一个映射成为1 2 3 4 5
 * 然后根据映射的值，将第二个数组中有多少个相同的
 * 两者的长度减去这个相同的就是答案
 *
 * 重点 树状数组不可以使用 0
 * 其次 树状数组不用使得最高位是2^n-1或者2^n
*/
const int N = 1e6 + 20;
i64 tree[N];
i64 lowbit(i64 x) {
    return x & (-x);
}

void up(i64 x,i64 n) {
    for (;x <= n;x += lowbit(x)) {
        tree[x]++;
    }
}
void init(int n) {
    for (int i = 0;i <= n;i++) {
        tree[i] = 0;
    }
}

i64 query(i64 x) {

    i64 res = 0;
    for (;x;x -= lowbit(x)) {
        res += tree[x];
    }
    return res;
}


void solve() {
    i64 n;
    cin >> n;
    init(n);
    vector<i64>a(n), b(n);
    map<i64, i64>mp;
    for (int i = 0;i < n;i ++) {
        cin >> a[i];
        a[i];
    }
    for (int i = 0;i < n;i ++) {
        cin >> b[i];
        b[i];
    }
    int cnt = 0;
    for (int i = 0;i < n;i ++) {
        mp[a[i]] = ++cnt;
    }
    
    i64 sub = 0;
    vector<i64>ans(n+1, n);
    for (int i = 0;i < n;i++) {
        i64 x = mp[b[i]];
        i64 prex = b[i];
        // de(x);
        sub = query(x);
        // de(sub)de(prex)deb(x + i -sub -1);
        ans[prex] = x + i - sub - 1;
        up(x,n);
    }
    for (int i = 1;i <= n;i ++) {
        cout << ans[i] << " \n"[i == n];
    }



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}