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
字符串的拼接不熟悉
https://blog.csdn.net/u011974987/article/details/52504486
字符串效率比较 += 效率最高；
https://www.cnblogs.com/james6176/p/3222671.html
*/
void solve() {

    int n;
    cin >> n;
    vector<string>s(n);
    set<string>st;
    for (auto& x : s) { cin >> x; }
    for (int i = 0;i < n;i++) {
        string t1 = s[i];
        for (int j = 0;j < n;j++) {
            if (i == j)continue;
            string t2 = s[j];
            st.insert(t2 += t1);
        }
    }
    cout << st.size() << endl;


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