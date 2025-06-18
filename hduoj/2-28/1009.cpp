// 看什么看,以为我厉害吗？
// 我只是戾气很重,不厉害只需要114514分钟就能变厉害了
// 而你我的朋友只需要2.5年就可以了
#include<bits/stdc++.h>
#include<climits>
#pragma GCC optimize(3,"Ofast","inline")

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

// const string hex = "01234566789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// 直接用 从 A开始 的acsii码


inline string itoa(int x, int A) {
    string s = "";
    while (x) {
        s += char('a' + x%A);
        x /= A;
    }
    return s;
}

inline string maax(string a, string b) {
    int sza = a.size(), szb = b.size();
    if (sza < szb) {
        swap(a, b);
    }
    int mi = min(sza, szb), mx = max(sza, szb);
    string ans = "";
    for (int i = 0;i < mi;i++) {
        ans += char('a' + max(int(a[i] - 'a'),int(b[i]-'a')));
    }

    for (int i = mi;i < mx;i++) { ans += a[i]; }
    return ans;
}

inline string miix(string a, string b) {
    int sza = a.size(), szb = b.size();
    if (sza < szb) {
        swap(a, b);
    }
    // a i s longer
    int mi = min(sza, szb), mx = max(sza, szb);
    string ans = "";
    for (int i = 0;i < mi;i++) {
        ans += char('a' + min(int(a[i] - 'a'),int(b[i]-'a')));
    }
    for (int i = mi;i < mx;i++) { ans += 'a'; }
    return ans;
}
inline string xxor(string a, string b,int A) {
    int sza = a.size(), szb = b.size();
    if (sza < szb) {
        swap(a, b);
    }
    // a i s longer
    int mi = min(sza, szb), mx = max(sza, szb);
    string ans = "";

    for (int i = 0;i < mi;i++) {
        ans += char('a' + ((int(a[i] - 'a') + int(b[i] - 'a')) % A));
    }
    for (int i = mi;i < mx;i++) { ans += a[i]; }
    return ans;
}
inline i64 atoi(string a, int A) {
    int sz = a.size();
    i64 sum = 0,cntA = 1;
    
    for (int i = 0;i < sz;i++,cntA*=A) {
        sum += cntA * int(a[i] - 'a');
    }
    return sum ;
}


inline void solve() {
    i64 n,x,A;
    cin >> n >> A >> x;
    vector<i64>a(n);
    for (auto& xk : a) { cin >> xk; }
    i64 xx = x;
    string s = "";
    while (xx) {
        s += char('a' + xx % A);
        xx /= A;
    }

    set<string>st, nst;
    st.insert(s);
    vector<string>sa;
    
    for (int i = 0;i < n;i++) {
        string tmp = itoa(a[i], A);
        sa.pb(tmp);
    }

    
    for (int i = 0;i < n;i++) {
        if (i % 2 == 0) {
            for (auto xx : st) {
                string nxts = maax(xx, sa[i]);
                nst.insert(nxts);
                nxts = miix(xx, sa[i]);
                nst.insert(nxts);
                nxts = xxor(xx, sa[i], A);
                nst.insert(nxts);
            }
            st.clear();
        } else {
            for (auto xx : nst) {
                string nxts = maax(xx, sa[i]);
                st.insert(nxts);
                nxts = miix(xx, sa[i]);
                st.insert(nxts);
                nxts = xxor(xx, sa[i], A);
                st.insert(nxts);
            }
            nst.clear();
        }
    }
    i64 ans = 0;
    if (st.size() != 0) {
        for (auto ss : st) { ans += atoi(ss, A); }
    } else {
        for (auto ss : nst) { ans += atoi(ss, A); }
    }
    cout << ans << endl;
}

int main() {
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