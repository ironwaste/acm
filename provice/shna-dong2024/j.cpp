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
using prr = pair<i64, pair<i64, i64>>;

prr make_prr(i64 a, i64 b, i64 c) {
    prr k;
    k.fi = a, k.se.fi = b, k.se.se=c;
    return k;
}
void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n),fa(n,-1);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    vector<vector<i64> >b(n, vector<i64>(n, 0));
    pair<i64, pair<i64, i64> >prk;
    // prr fi 是 w 权值 
    // 然后根据 se 是 i， j
    // i64 w = prk.fi;

    priority_queue<prr, vector<prr>, greater<> >q;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j ++) {
            cin >> b[i][j];
        }
    }
    
    for (i64 i = 0;i < n;i++) {
        for (i64 j = 0;j < n;j ++) {
            prk = make_prr(b[i][j], i, j);
            q.push(prk);
        }
    }

    auto fd = [&](auto self, i64 x) -> i64 {
        if (fa[x] < 0) {
            return x;
        }
        return fa[x] = self(self,fa[x]);
        };


    auto uni = [&](i64 x,i64 y) -> void {
        i64 nx = fd(fd, x), ny = fd(fd, y);
        if (nx > ny) {swap(nx, ny);}
        if (nx != ny) { fa[ny] = nx; }
        a[x] = 1, a[y] = 1;
        };

    i64 ans = 0;
    while (!q.empty()) {
        prr tmp = q.top();
        i64 w, x, y;
        q.pop();
        w = tmp.fi, x = tmp.se.fi, y = tmp.se.se;
        // if (fd(fd, x) == fd(fd, y))continue;
        if (fd(fd, x) == fd(fd, y)) { ans += (a[x] - 1) * w; a[x] = 1; }
        else { ans += (a[y] + a[x] - 1) * w; a[y] = a[x] = 1; }
        // de(w)de(x)de(y)deb(ans)
        uni(x, y);
        i64 tm = 0;
        for (auto x : fa) {
            tm += (x == -1);
        }
        if (tm == 1)break;
    }
    // de(ans);
    cout << ans << endl;
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