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
const int N = 1e6 + 10;
vector<int>numid[N];

void solve(){
    int n;
    cin >> n;
    vector<i64>a(n);

    // map<int, int>pre, suf;
    vector<int>q(n,0);
    set<int>st, pre;
    // map<int, int>suf;
    vector<int>suf(N,0);
    // map<int, int> sf;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        suf[a[i]]++;
        // suf.insert(a[i]);
        numid[a[i]].pb(i);
    }
    

    for (int i = n - 1;~i;i--) {
        q[i] = st.size();
        if(a[i])st.insert(a[i]);
    }
    // n * (log n + 1 or pre?n * logn)
    i64 ans = 0;
    for (int i = 0;i < n;i++) {
        if (a[i] != 0) {
            if (suf[a[i]] != 1) {
                pre.insert(a[i]);
            }suf[a[i]]--;
        } else if (a[i] == 0) {
            for (auto x : pre) {
                if (suf[x] > 0) {
                    int id = upper_bound(all(numid[x]), i) - numid[x].begin();
                    int index = numid[x][id];
                    // de(i)de(id)deb(index)
                    ans += q[index];
                    // deb(ans)
                    pre.erase(x);
                }
            }
        }
    }
    cout << ans << endl;
    // n
 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        solve();
        for (auto &x : numid) {
            x.clear();
        }
    }
    return 0;
}