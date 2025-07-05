#include<iostream>
#include<cctype>
#include<set>

#define endl '\n'
#define i64 long long
#define fi first
#define se second
#define Endl endl
#define END endl
using namespace std;

using pii = pair<int,int>;
using pll = pair<i64, i64>;


// 补题
// 2025.06.29——10:11:44
// 题目链接：https://atcoder.jp/contests/abc412/tasks/abc412_b
/*
https://en.cppreference.com/w/cpp/string/byte/isupper
存在于 <cctype> 的头文件中 
int isupper( int ch );

优化：
一个是使用 isupper函数来判断字符是否为大写字母
二是将yes 或者 no 函数化 但是其实和使用三目运算符 ？的输入输出效率没差
如果使用代码片段的话是比较好的
*/
void yn(bool t) {
    cout << ((t) ? "Yes\n" : "No\n");
}


void solve() {
    string s, t;
    cin >> s >> t;
    set<char>st;
    for (auto c : t) {st.insert(c);}
    int sz = s.size(),ok = 1;
    for (int i = 1;i < sz;i ++) {
        char c = s[i];
        if ( (isupper(c) && !st.count(s[i - 1])) ) {
            ok = 0;
        }
    }
    yn(ok);
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