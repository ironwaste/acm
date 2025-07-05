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

/* 几何序列  等差或者等比数列*/
/*
vector erase 方法 不熟悉
https://cplusplus.com/reference/vector/vector/erase/
*/

void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n), absa(n);
    vector<i64>ne, po;
    set<i64>st;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        if (a[i] < 0) {ne.pb(a[i]);
        } else {po.pb(a[i]);}
        // absa[i] = abs(a[i]);
        // st.insert(a[i]);
    }
    // sort(all(absa));
    i64 ok = 1,nesz = ne.size(), posz = po.size();
    if (n == 2) {
        ok = 1;
    }else if (nesz == 0) {
        sort(all(po));
        // i64 q = a[1]/a[0];
        // a[i]/a[i-1] == a[i + 1]/a[i]
        // a[i] * a[i] == a[i-1] * a[i+1];
        for (int i = 1;i < posz - 1;i++) {
            if (po[i] * po[i] == po[i - 1] * po[i + 1]) {
            } else {
                ok = 0;
                break;
            }
        }
    } else if (posz == 0) {
        sort(all(ne));
        for (int i = 1;i < nesz - 1;i++) {
            if (ne[i] * ne[i] == ne[i - 1] * ne[i + 1]) {
            } else {
                ok = 0;
                break;
            }
        }

    } else {
        sort(all(po));
        sort(all(ne), greater<i64>());
        i64 pof = po[0], nef = abs(ne[0]);
        if (abs(nesz - posz) > 1 || (pof < nef && posz < nesz) ||(pof > nef && posz > nesz)) {
            ok = 0;
        } else {
            vector<i64>ans;
            if (pof == nef) {
                if (posz > nesz) {
                    for (int i = 0;i < n / 2;i++) {
                        ans.pb(po[i]);
                        ans.pb(ne[i]);
                    }
                    ans.pb(po[posz - 1]);
                } else if (nesz > posz) {
                    for (int i = 0;i < n / 2;i++) {
                        ans.pb(ne[i]);
                        ans.pb(po[i]);
                    }
                    ans.pb(ne[nesz - 1]);
                } else {
                    for (int i = 0;i < n / 2;i++) {
                        ans.pb(ne[i]);
                        ans.pb(po[i]);
                    }
                }
            } else if (pof < nef) {
                for (int i = 0;i < n / 2;i++) {
                    ans.pb(po[i]);
                    ans.pb(ne[i]);
                }
                if (nesz < posz) { ans.pb(po[posz - 1]); }

            } else {
                for (int i = 0;i < n / 2;i++) {
                    ans.pb(ne[i]);
                    ans.pb(po[i]);
                }
                if (nesz > posz) { ans.pb(ne[nesz - 1]); }

            }
            i64 sz = ans.size();
            // for (int i = 0;i < sz;i++) {
            //     de(ans[i])
            // }cout << endl;
            // deb(sz);
            if (ok) {
                for (int i = 1;i < sz - 1;i++) {
                    if (ans[i] * ans[i] == ans[i - 1] * ans[i + 1]) {
                    } else {
                        ok = 0;
                        break;
                    }
                }
            }
        }
    }
    cout << ((ok) ? "Yes\n" : "No\n");
}

int main(){
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


/*
2
4
-16 24 -36 54
4
36 16 -24 -54
*/