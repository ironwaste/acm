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


using pii = pair<int,int>;
using pll = pair<i64, i64>;

// 补题——题目链接:
// 网址：
// 2025.10.06——22:36:55
/*
 *
 *
 *
*/

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k >= n) {
        for (int i = 0;i < n;i++) {
            cout << '-';
        }cout << endl;
        return;
    }
    i64 cnt1 = 0, cnt0 = 0, cnt2 = 0;
    for (int i = 0;i < k;i++) {
        if (s[i] == '1') {
            cnt1++;
        } else if (s[i] == '0') {
            cnt0++;
        } else {
            cnt2++;
        }
    }
    vector<char>ans(n,'+');
    i64 res = n - cnt1 - cnt0;
    int l = 0, r = n - 1;
    for (;l < cnt0;l++) {
        ans[l] = '-';
    }
    for (int j = 0;j < cnt1;j++,r--) {
        ans[r] = '-';
    }

    for (int i = 0;i < cnt2;i ++,r--,l++) {
        if (l < n && ans[l] != '-') {
            ans[l] = '?';
        }
        if (r >= 0 && ans[r] != '-') {
            ans[r] = '?';
        }
    }
    for (int i = 0;i < n;i++) {
        cout << ans[i];
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}