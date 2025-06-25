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

const int SIZE = 70;
const int N = 3e6;
struct TireNode {
    char ch;
    int isEnd, num;
    // num 是前缀的出现次数
    // TireNode* son[SIZE];
    int son[SIZE]; // 这里面存储的是其子节点的下标值
    // 以代表其结构体数组
    TireNode() {};
    TireNode(int a):num(a) {};
    TireNode(int x, int a) :isEnd(x), num(a) {};
}t[N];
/*
 *  void insert(char * s){ 
 *      int now = 0;
 *      if(int i = 0;s[i];i ++){
 *          int ch = s[i] - 'a';    
 *          if(t[now].son[ch] == 0){ //  该前缀未存储过
 *              t[now].son[ch] = cnt ++; // 这个代表的是把结构体数组的位置cnt分配
 *          }
 *          now = t[now].son[ch];
 *          t[now].num ++; //代表的是，该前缀的个数 
 *      }
 *  }
*/
int Ccto_num(char ch) {
    // return int(ch);
    if (ch >= 'a' && ch <= 'z') {
        return int(ch - 'a');
    }else if (ch >= 'A' && ch <= 'Z') {
        return int(ch - 'A') + 26;
    } else if (ch >= '0' && ch <= '9') {
        return int(ch - '0') + 53;
    }
}

int cnt = 1; // cnt = 0 is root node
void insert(string s) {
    int sz = s.size();
    int now = 0;
    for (int i = 0;i < sz;i ++) {
        int ch = Ccto_num(s[i]);
        if (t[now].son[ch] == 0) {
            t[now].son[ch] = cnt++;
        }
        now = t[now].son[ch];
        t[now].num++;
    }
}
void init() {
    // int cntt = 0;
    for (int i = 0;i < cnt;i ++) {
        t[i].num = 0;
        for (int j = 0;j < SIZE;j ++) {
            t[i].son[j] = 0;
        }
    }
    cnt = 1;
}
/*
 *  int Find(char *s){
 *      int now = 0;
 *      for (int i = 0;s[i];i ++){
 *          int ch = s[i] - 'a';
 *          if(t[now].son[ch] == 0)return 3;
 *          now = t[now].son[ch];
 *      }
 *      if(t[now].num == 0) return 3// （可更改为何时未出现）该前缀未出现
 *  }
*/

int find(string s) {
    int now = 0, sz;
    sz = s.size();
    for (int i = 0;i < sz;i++) {
        int ch = Ccto_num(s[i]);
        if (t[now].son[ch] == 0) return 0;
        now = t[now].son[ch];
    }
    // if (t[now].num == 0) { return 0; }
    return t[now].num;
}


void solve() {
    init();
    int n, q;
    cin >> n >> q;
    for (int i = 0;i < n;i ++) {
        string s;
        cin >> s;
        insert(s);
    }

    for (int i = 0;i < q;i ++) {
        string s;
        cin >> s;
        cout << find(s) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}