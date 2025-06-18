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


void solve(){
    int k = 0;
    string n;
    string s;
    cin >> s >> n;
    // deb(n.size())
    if (n.size() >= 3) { k = 100; }
    else {
        int cnt = 1;
        for (int i = n.size()-1;~i;i--, cnt *= 10) {
            k += cnt * (int) (n[i] - '0');
        }
    }
    int sz = s.size();
    vector<int>a;
    for (int i = 0;i < sz;i++) {
        a.push_back((int) (s[i] - 'a'));
    }

    vector<int>num;

    for (int i = 0;i < min(k, 100); i++) {
        for (int j = 0;j < sz;j++) {
            if (num.size() == 0) {
                num.pb(a[j]);
                // dp[j] = 1;
            } else if (num.back() < a[j]) {
                num.pb(a[j]);
                // dp[j] = num.size();
            } else {
                int id = lower_bound(all(num), a[j]) - num.begin();
                num[id] = a[j];
                // dp[j] = id;
            }
            // mx = max(mx,(int)num.size());
        }

    }
    cout << num.size() << endl;

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