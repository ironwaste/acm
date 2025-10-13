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

// 补题——题目链接: https://codeforces.com/problemset/problem/1209/C
// 题解网址： https://codeforces.com/blog/entry/69791
// 2025.09.19——20:25:58
// 2025.09.19——20:44:43 wa2  ... 
// 取值为int_MAX 导致赋值后再++ 爆范围了
// 2025.09.19——20:50:28 accpted
/*
 *
 * 对于这时的我 有点难度 ^_^
 * 其分析的 比较抓住要点， 比我的要清晰
 * 我的思路更像是一种 构造的思路
 * 而不是证明的思路
 * 我都是想 想从哪里分开然后可能有解
 * 虽然最后经过的答案相同 但是时间差距大
 * 
 *
*/

void solve(){
    i64 n;
    cin >> n;
    string s;
    cin >> s;
    vector<i64>idx[10];
    // char cnt = s[0]
    for (int i = 0;i < n;i++) {
        i64 id = s[i] - '0';
        idx[id].push_back(i);
    }
    i64 pidx = -1;
    i64 id = n, v = INT_MAX;
    for (int i = 0;i < 10;i++) {
        if (idx[i].size() == 0)continue;
        if (idx[i][0] > pidx) {
            pidx = idx[i].back();
            continue;
        } else {
            v = i;
            for (auto j : idx[i]) {
                if (j < pidx) {
                    id = j;
                } else { break; }
            }
            break;
        }
    }
    i64 ok = 1;
    pidx = id;
    // de(v)
    for (i64 i = v + 1;i < 10;i++) {
        if (idx[i].size() == 0)continue;
        if (idx[i][0] > pidx) {
            pidx = idx[i].back();
            continue;
        } else {
            ok = 0;
            break;
        }
    }

    if (!ok) { cout << "-" << endl; return; }
    for (int i = 0;i < n;i++) {
        if (s[i] - '0' > v) {
            cout << "2";
        } else if (s[i] - '0' == v && i <= id) {
            cout << "2";
        } else {
            cout << "1";
        }
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