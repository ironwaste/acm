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

// 2025.07.29——12:35:35
// 2025.07.29——14:37:12 跳题了 。。。 
/*
 * 题目意思 ：给出 n个数值，然后进行奇异异或
 * 异或 进行按位给贡献
 *
*/

const i64 N = 2e5 + 10;
i64 cnt = 1;
struct Tire {
    i64 num;
    i64 c;
    // i64 nodel, noder;
    int son[2];
}tree[N];


i64 dfs(i64 x,i64 cnt1,i64 p,i64 step) {
    // 用于求 字典树内，偶数位的1 
    // cnt1 代表的是 当前层数 异或后是第几个1
    // 应初始化 cnt1 为 1，当cnt1 %2 == 0且当前位置上的 异或后的值为 1
    i64 res = 0LL;
    // res 代表最后的返回值
    // 将所有的 0 1 的值都需要遍历
    // 所以应该是 dfs 进去
    // step 代表的是 第几位
    i64 cntv = x % 2LL, nexv = x / 2;
    i64 lson = tree[p].son[0], rson = tree[p].son[1];
    if (!lson && !rson) {
        i64 sp = step;
        i64 ccnt = cnt1;
        while (x) {
            i64 v = x % 2;
            if (v == 1) {
                if (ccnt % 2 == 1) {
                    res += (1LL << sp);
                }
                ccnt++;
            }
            sp ++;
            x /= 2;
        }
    }
    if (cnt1 % 2 == 1) {
        if (lson) {
            res += tree[lson].num * (1LL << step) * (cntv ^ 0LL);
            // de(lson)deb(res)
            res += dfs(nexv, cnt1 + (cntv ^ 0LL), lson, step + 1LL);
        }
        
        if (rson) {
            res += tree[rson].num * (1LL << step) * (cntv ^ 1LL);
            // de(rson)deb(res)
            res += dfs(nexv, cnt1 + (cntv ^ 1LL), rson, step + 1LL);
        }
    } else {
        // 当 该位置 是 被变成0 的值的时候
        if (lson) {
            // res += tree[lson].num * (1LL << step) * (cntv ^ 0LL);
            res += dfs(nexv,cnt1 + (cntv ^ 0LL),lson , step + 1LL);
        }
        if (rson) {
            // res += tree[rson].num * (1LL << step) * (cntv ^ 1LL);
            res += dfs(nexv, cnt1 + (cntv ^ 1LL), rson, step + 1LL);
        }
    }
    return res;
}
void insert(i64 x) {
    i64 now = 0;
    while (x) {
        i64 cntv = x % 2;
        if (!tree[now].son[cntv]) {
            tree[now].son[cntv] = cnt++;
        }
        now = tree[now].son[cntv];
        tree[now].num++;
        x /= 2;
    }
}

void init() {
    for (int i = 0;i < cnt;i ++) {
        tree[i].num = 0;
        for (int j = 0;j < 2;j ++) {
            tree[i].son[j] = 0;
        }
    }
    cnt = 1;
}



void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x; }
    sort(all(a));
    i64 ans = 0;
    for (int i = 0;i < n;i++) {
        if(i)ans += dfs(a[i], 1LL, 0LL, 0LL);
        insert(a[i]);
        // deb(ans);
    }
    deb(ans)
    // cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        init();
        solve();
    }
    return 0;
}