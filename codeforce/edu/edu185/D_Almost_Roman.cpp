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


using pii = pair<int, int>;
using pll = pair<i64, i64>;

// 补题——题目链接: https://codeforces.com/contest/2170/problem/D
// 网址：
// 2025.11.28——23:20:24
/*
 * 1. i?  -> sum -= 2
 * 2. ?X / ? V -> -1
 * 3. ?? -> iV 4 iX 9
 * 4. ，没有了
*/

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<i64>v(n + 1, 0);
    i64 num = 0, pre = 0, suf = 0, sufxv = 0;
    i64 ans = 0,sufxx = 0;
    vector<i64>xvsuf, preI, toget;
    vector<bool>vis(n, false);
    i64 mx = 0;
    for (int i = 0;i < n;i++) {
        char c = s[i];
        if (c == '?') { v[i + 1] = v[i] + 1; }
    }
    for (int j = n;j >= 0;j--) {
        if (v[j] == 0) { mx = 0;continue; }
        if (v[j] < mx) { v[j] = mx; } else { mx = v[j]; }
    }
    for (int i = 0;i < n;i++) {
        char c = s[i];
        if (c == '?') { num++; } else {
            if (s[i] == 'I' && i + 1 < n && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                ans--;
            } else if (s[i] == 'I') {
                ans++;
            } else if (s[i] == 'X') {
                ans += 10;
            } else {
                ans += 5;
            }
        }
        if (c == '?' && i - 1 >= 0 && s[i - 1] == 'I') {
            i64 idx = i + v[i + 1];
            if (s[idx] == 'X' || s[idx] == 'V') {
                toget.push_back(v[i + 1]);
                vis[idx] = true;
                continue;
            }
            pre++;
            preI.push_back(v[i + 1]);
        } else if (c == '?' && i + 1 < n && (s[i + 1] == 'X' || s[i + 1] == 'V')) {
            if (vis[i]) { continue; }
            sufxv++;
            if (v[i + 1] % 2 == 1) { sufxo++; }
            xvsuf.push_back(v[i + 1]);
        }
    }
    sort(all(preI), [&](auto i, auto j) {
        if (i % 2 != j % 2) { return i % 2 == 1; }
        return i < j;
        });
    sort(all(xvsuf), [&](auto i, auto j) {
        if (i % 2 != j % 2) { return i % 2 == 1; }
        return i < j;
        });
    sort(all(toget), [&](auto i, auto j) {
        if (i % 2 != j % 2) { return i % 2 == 1; }
        return i < j;
        });
    i64 szI = preI.size();
    i64 sufx = xvsuf.size();
    i64 szt = toget.size();
    i64 cx, cv, ci;
    while (q--) {
        cin >> cx >> cv >> ci;
        if (num <= ci) {
            cout << ans + num - (sufxv * 2LL) << endl;
            continue;
        }

        i64 tmpans = ans;
        i64 cnt1 = ci;
        i64 res = num - ci;
        i64 tmpnum = num;
        i64 cnt5 = min(res, cv);
        i64 cnt10 = res - cnt5;

        tmpans += cnt1 * 1LL;
        tmpans += cnt5 * 5LL;
        tmpans += cnt10 * 10LL;
        // 不知道有多少个前后相链接的 
        // 最多产生多少个 -1呗  cnt个 * -2 为答案呗
        /*
        策略 ： 先算 自己可以组多少个 ，然后移位计算呢
        */
        i64 ne = min(res, cnt1);
        




    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        deb(T)
        solve();
    }
    return 0;
}

//-----------------------
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        long long fixed_x = 0, fixed_v = 0, fixed_i = 0, mm = 0;
        long long nsub = 0;
        for (int j = 0; j < n; j++) {
            char c = s[j];
            if (c == 'X') fixed_x++;
            else if (c == 'V') fixed_v++;
            else if (c == 'I') fixed_i++;
            else mm++;
            if (j < n - 1) {
                bool lpot = (c == 'I' || c == '?');
                char nr = s[j + 1];
                bool rxv = (nr == 'X' || nr == 'V');
                if (lpot && rxv) nsub++;
            }
        }
        long long bval = 10 * fixed_x + 5 * fixed_v + 1 * (fixed_i + mm) - 2 * nsub;
        long long tp1 = 0, tz = 0;
        int jj = 0;
        while (jj < n) {
            if (s[jj] != '?') {
                jj++;
                continue;
            }
            int st = jj;
            while (jj < n && s[jj] == '?') jj++;
            int le = jj - st;
            int lb = (st == 0 ? 0 : (s[st - 1] == 'I' ? 1 : 0));
            int rp = (jj == n ? 0 : (s[jj] == 'X' || s[jj] == 'V' ? 1 : 0));
            int nsubt = 0;
            if (lb == 0) nsubt++;
            if (rp == 1) nsubt++;
            long long hh = le - nsubt;
            long long p1r = (hh + 1) / 2;
            tp1 += p1r;
            if (hh >= 0 && (hh % 2 == 0)) tz++;
        }
        for (int qq = 0; qq < q; qq++) {
            int cx, cvv, cii;
            cin >> cx >> cvv >> cii;
            long long fcd = max(0LL, mm - (long long)cii);
            if (fcd == 0) {
                cout << bval << '\n';
                continue;
            }
            long long dnum = 0;
            long long rrem = fcd;
            if (rrem <= tp1) {
                dnum = rrem;
            } else {
                dnum = tp1;
                rrem -= tp1;
                long long zus = min(rrem, tz);
                rrem -= zus;
                dnum -= rrem;
            }
            long long eb = 4LL * min(fcd, (long long)cvv) + 9LL * max(0LL, fcd - (long long)cvv);
            long long anss = bval + eb - 2 * dnum;
            cout << anss << '\n';
        }
    }
    return 0;
}