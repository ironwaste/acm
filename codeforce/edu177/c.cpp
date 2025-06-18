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


void solve() {
    int n;
    cin >> n;
    vector<i64>p(n + 1, 0), d(n + 1, 0), ans(n + 1, n), fa(n + 1);
    // iota(all(da));
    for (int i = 1;i <= n;i++) { cin >> p[i]; }
    for (int i = 1;i <= n;i ++) { cin >> d[i]; }
    for (int i = 0;i <= n;i++) { fa[i] = -1; }
    // 找被变为 0 的数字的下标 中最大的一个。 和缺少的数字位置上的数字的取最大。
    // 
    // 
    // vecto<>
    auto fd = [&](auto slef, i64 x) -> i64 {
        if (fa[x] < 0) {
            return x;
        }
        return fa[x] = slef(slef, fa[x]);
        };

    auto uni = [&](i64 x, i64 y) -> void {
        i64 nx = fd(fd, x), ny = fd(fd, y);
        if (nx == ny) {
            return;
        }
        if (fa[nx] < fa[ny]) {
            fa[nx] += fa[ny];
            fa[ny] = nx;
        } else {
            fa[ny] += fa[nx];
            fa[nx] = ny;
        }
        };

    for (int i = 1;i <= n;i ++) {
        if (p[i]) {

            i64 tmp = p[i];
            p[i] = 0;
            while (tmp != 0 && tmp != i) {
                uni(tmp, i);
                i64 pretmp = tmp;
                tmp = p[tmp];
                p[pretmp] = 0;
            }

        }
    }
    ans[1] = fa[fd(fd,d[1])];
    for (int i = 2;i <= n;i++) {
        uni(d[i - 1], d[i]);
        ans[i] = fa[fd(fd,d[i])];
    }


    for (int i = 1;i <= n;i++) {
        cout << -ans[i] << " \n"[i == n];
    }

    return;
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