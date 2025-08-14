// 看什么看,以为我厉害吗？
// 我只是戾气很重,不厉害只需要114514分钟就能变厉害了
// 而你我的朋友只需要2.5年就可以了
#pragma GCC optimize(2)
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

// 2025.08.14——14:30:37
/*
 *
 *
 *
*/

i64 read() {
    i64 x = 0, f = 1;
    char ch = getchar();
    while (ch <'0' || ch >'9') {
        if (ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <='9') {x = x * 10 + ch - '0', ch = getchar();}
    return x * f;
}

const int N = 1e6 + 10;
using a3 = array<i64, 3>;
void solve() {
    i64 n = read();
    int sq = sqrt(n);
    vector<i64>st(sq + 3), ed(sq + 3);
    vector<i64>a(n + 1);
    map<i64, i64>mp;
    for (int i = 1;i <= n;i++) {
        i64 x = read();
        a[i] = x;
        mp[x]++;
    }
    vector<multiset<i64> >blockst(sq + 3);
    vector<i64>blo(n + 3, 0);
    for (int i = 1;i <= sq;i++) {
        st[i] = n / sq * (i - 1) + 1;
        ed[i] = n / sq * i;

        for (int j = st[i];j <= ed[i];j++) {
            blockst[i].insert(a[j]);
            blo[j] = i;
        }
    }
    
    for (int j = ed[sq] + 1;j <= n;j++) {
        blockst[sq].insert(a[j]);
        blo[j] = sq;
    }
    ed[sq] = n;
    for (int i = 1;i < sq;i++) {
        deb(i);
        for (auto x : blockst[i]) {
            de(x)
        }
        deb(i);
        // cout << endl;
    }

    auto check = [&](i64 l, i64 r, i64 v) ->i64 {
        i64 bl = blo[l], br = blo[r];
        for (int i = br;i >= bl ;i--) {
            if (blockst[i].count(v)) {
                for (int j = ed[i];j >= st[i];j --) {
                    if (a[j] == v) {
                        return j - 1;
                    }
                }
            }
        }
        return 0;
        };

    i64 l = 1, r = n, midl = l + (r - l >> 1);
    i64 ansl = 1, ansr = n, ans = 0;
    set<i64>mid;
    mid.insert(l);
    mid.insert(r);
    while (l < r) {
        i64 v = a[l];
        l++;
        if (mp[v] < 3) { continue; }
        i64 rok = 0, midok = 0;
        de(l)de(r);
        rok = check(l, n, v);
        de(rok)
        i64 mir = min(rok, r);
        de(mir)
        midok = check(l + 1, mir, v);
        deb(midok);
        if (midok != 0 && rok != 0) {
            r = mir;
            ans++;
            ansl = l + 1;
            ansr = mir;
        }
        
    }
    cout << ans << endl << ansl << " " << ansr << endl;




}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = read();
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}