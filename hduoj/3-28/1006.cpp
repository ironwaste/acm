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

const int N = 2e5 + 10;
i64 tree[N];
i64 n, q;
void init() {
    for (int i = 0;i < N;i++) {
        tree[i] = 0;
    }
}

i64 lowbit(i64 x) { return x & (-x); }

void add(i64 x, i64 y) {
    while (x <= N) {
        tree[x] += y;
        x += lowbit(x);
    }
}
i64 ser(i64 x) {
    i64 ans = 0;
    while (x>0) {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}

i64 query(i64 x, i64 y) {
    return trunc(ser(y)/100) - trunc(ser(x-1LL)/100);
}


void solve() {
    init();
    cin >> n >> q;

    vector<i64>a(n + 1,0);
    for (i64 i = 1;i <= n;i++) {
        cin >> a[i];
        add(i, a[i]);
    }

    vector<i64>ans;
    
    for (int i = 0;i < q;i++) {
        i64 op, x, y;
        cin >> op >> x >> y;
        if (op == 1) { add(x,y - a[x]);a[x] = y; }
        else {
            ans.pb(query(x,y));
        }
    }
    i64 answer = 0,sz = ans.size();
    
    for (i64 i = 0;i < sz;i++) {
        // de(ans[i])deb(ans[i] * i)
        answer ^= ans[i] * (i + 1LL);
    }
    cout << answer << endl;



}
// 2 4 -1 
// 28 -41 90 120 -63 134 161 -21
// 
// 28 -13 32 152 89 
// -13 -> 0
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