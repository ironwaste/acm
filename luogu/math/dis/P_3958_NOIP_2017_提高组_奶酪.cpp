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
#define all(x) x.begin(),x.end()
#define de(x) cerr << #x <<" "<<x <<" ";
#define deb(x) cerr << #x <<" "<<x <<endl;
using namespace std;


// 补题——题目链接: https://www.luogu.com.cn/problem/P3958
// 网址：
// 2025.08.31——23:43:49
/*
 *
 *
 *
*/
using a3 = array<i64, 3>;
i64 dist(a3 a,a3 b){
    i64 x1 = a[0], y1 = a[1], z1 = a[2];
    i64 x2 = b[0], y2 = b[1], z2 = b[2];
    auto squ = [&](i64 x)->i64 {
        return x * x;
        };

    return squ(x1 - x2) + squ(y1 - y2) + squ(z1 - z2);
}

bool check(a3 a, a3 b, i64 r) {
    auto squ = [&](i64 x)->i64 {return x * x;};
    i64 r2 = squ(r * 2);
    i64 dis = dist(a, b);
    if (r2 >= dis)return true;
    else return false;
}

void solve() {
    i64 n, h, r;
    cin >> n >> h >> r;
    vector<a3>a(n);
    for (int i = 0;i < n;i++) { cin >> a[i][0] >> a[i][1] >> a[i][2]; }
    vector<i64>fa(n);
    iota(all(fa), 0);
    vector<i64>st, ed;
    auto fd = [&](auto self,i64 x)->i64 {
        if (fa[x] == x) { return x; }
        return fa[x] = self(self, fa[x]);
        };

    auto uni = [&](i64 x, i64 y)->void {
        i64 nx = fd(fd, x), ny = fd(fd, y);
        if (nx > ny) { swap(nx, ny); } else if (nx == ny)return;
        fa[ny] = nx;
        };


    for (int i = 0;i < n;i++) {
        if (a[i][2] <= r) {st.push_back(i);}
        if (a[i][2] + r >= h) { ed.push_back(i); }
        for (int j = i + 1;j < n;j++) {
            if (check(a[i], a[j], r)) { uni(i, j); }
        }
    }
    // for (int i = 0;i < n;i++) {
    //     de(i)deb(fa[i]);
    // }
    set<i64>s;
    for (auto x : ed) {
        i64 nx = fd(fd, x);
        s.insert(nx);
    }
    i64 ok = 0;
    for (auto x : st) {
        i64 ny = fd(fd, x);
        if (s.count(ny)) {
            ok = 1;break;
        }
    }

    cout << ((ok) ? "Yes" : "No") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}