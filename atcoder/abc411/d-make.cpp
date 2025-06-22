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

/*
    这题涉及到我的思维盲区了，也就是我的思维方式对于这种题目非常的不熟练
    为什么，
    这到底是一种什么样的思维方式？

*/


void solve() {
    int n, q,nq;
    cin >> n >> nq;
    q = nq - 1;
    vector<i64>op(nq), p(nq);
    vector<string>s(nq);
    while (q >= 0) {
        cin >> op[q] >> p[q];
        if (op[q] == 2) {
            cin >> s[q];
            reverse(all(s[q]));
        }
        q--;
    }
    string ans = "";
    int index = 0;
    for (int i = 0;i < nq;i++) {
        if (op[i] == 1 && index == p[i]) {
            index = 0;
        } else if (op[i] == 3 && index == 0) {
            // continue;
            index = p[i];
        } else if (op[i] == 2 && p[i] == index) {
            ans += s[i];
        }
    }
    int sz = ans.size();
    for (int i = sz - 1;~i;i --) {
        cout << ans[i];
    }

    cout << endl;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}