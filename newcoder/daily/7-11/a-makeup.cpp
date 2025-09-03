#include<bits/stdc++.h>
#include<climits>


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


// 补题——题目链接:https://ac.nowcoder.com/acm/contest/112575#submit/%7B%22problemIdFilter%22%3A296302%7D
// 网址：https://ac.nowcoder.com/discuss/1519571
// 2025.07.11——23:54:26
/* 
 * 总结： 可以 使用to_string 将数字转化为字符串
 * 在使用 stoi将字符串转换成为数字
 * 使用replace(it,it,'','')将其中进行替换
 * 可以对于各种类型进行替换
 * replace 函数链接标准：https://en.cppreference.com/w/cpp/algorithm/replace.html
 * 
*/

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<i64>a(n);
    for (auto& x : a) {
        cin >> x;
        ans -= x;
        string s = to_string(x);
        replace(all(s), '0', '8');
        i64 k = stoi(s);
        ans += k;
    }

    cout << ans << endl;
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