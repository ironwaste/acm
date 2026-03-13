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

// 补题——题目链接:
// 网址：
// 2025.11.17——21:14:40
/*
 *
 *
*/

void solve() {
    int n;
    cin >> n;
    vector<int>a(n + 1, 0);
    vector<int>b(n + 1, 0);
    map<int, int>mp;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];

    }
    for (int i = n;i >= 1;i--) {

        if (!mp.count(a[i])) {
            mp[a[i]]++;
        } else {
            b[i] = 1;
            mp[a[i]]++;
        }
    }
    vector<i64>idx, idv;
    vector<i64>ans(n + 1, 0);
    for (int i = 1;i <= n;i++) {
        if (mp[i] == 1) {

        } else if (mp[i] == 2) {

        } else { // 0
            idv.push_back(i);
        }
    }
    

    for (int i = 1;i <= n;i++) {
        if (mp[a[i]] == 1) {
            idx.push_back(a[i]);
        }
    }


    int idxsz = idx.size(), idvsz = idv.size() - 1;
    bool f = false;
    int cnt = 0, idvj = 0, idxj = 0;
    for (int i = 1;i <= n;i++) {
        // if( i== 1)
        if (b[i] == 1 && i != 1 && ((b[i - 1] != 1 && i - 1 != 1) || i - 1 == 1)) {
            // cout << i << '\n';
            ans[i - 1] = idv[idvj];
        } else if (b[i] == 0 && b[i - 1] == 1 && i - 1 != 1) {
            ans[i - 1] = idv[idvj++];
        } 
    }

    
    for (int i = 1; i <= n; i++) {
        if(ans[i] == 0){
            if (idvsz >= idvj ) {
                if (!f) {
                    f = true;
                    ans[i] = idv[idvsz];
                } else {
                    f = 0;
                    ans[i] = idv[idvsz--];
                }
                // de(i)deb(idxj);
            } else {
                ans[i] = idx[idxj++];
            }
        }
    }
    // cout << 1 << '\n';

    cout << ((b[1] == 1) ? 1 : 0) << endl;
    for (int i = 1;i <= n;i++) {
        cout << ans[i] << " \n"[i == n];
    }




}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        // deb(T);
        solve();
    }
    return 0;
}