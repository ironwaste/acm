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


// 补题——题目链接: https://codeforces.com/contest/2124/problem/E
// 网址：https://codeforces.com/blog/entry/144382
// 2025.07.08——00:08:22

void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n);
    i64 sum = 0, mx = 0;
    for (auto& x : a) { cin >> x; mx = max(x, mx); sum += x; }
    if (sum % 2 == 1 || sum - mx < mx) {
        cout << -1 << endl;
        return;
    }
    i64 prefix = 0;
    for (i64 i = 0;i < n;i++) {
        prefix += a[i];
        if (prefix * 2LL == sum) {
            cout << 1 << endl;
            for (int j = 0;j < n;j++) {
                cout << a[j] << " ";
            }cout << endl;
            return;
        }
    }

    cout << 2 << endl;
    prefix = 0;
    i64 pos = 0;
    for (int i = 0;i < n;i++) {
        i64 v = a[i];
        if (prefix < sum / 2 && prefix + v >= sum / 2) {
            pos = i;
            break;
        }
        prefix += v;
    }
    // a3 a2 
    // a1 
    // a2 -= a1/2 + max(a2-a3,0) / 2;
    // a3 -= max(a3 - a2, 0) / 2;
    // 2025.07.08——00:51:48 wa 1
    // 2025.07.08——01:03:02 wa 2  如果w3 是为零的话，则后面会有一部分数据不输出 (0)，
    // 导致一行内的长度不为数组长度导致会出错
    i64 a1 = prefix, a2 = a[pos], a3 = sum - prefix - a[pos];
    i64 vv = abs(a2 - a3);
    i64 sub = a1, w = (a1 - vv) / 2 + (a2 > a3) * vv;
    i64 w3 = sub - w;
    for (int i = 0;i < pos;i++) {
        cout << a[i] << " ";
        a[i] = 0;
    }
    cout << w << " ";
    a[pos] -= w;
    i64 i = pos + 1;
    
        while (w3) {
            i64 ww = min(a[i], w3);
            cout << ww << " ";
            a[i] -= ww;
            i++, w3 -= ww;
        }
        for (;i < n;i ++) {
            cout << 0 << " ";
        }
    cout << endl;
    for (int i = 0;i < n;i++) {
        cout << a[i] << " ";
    }cout << endl;


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

/*
1
3
1 2 1
*/