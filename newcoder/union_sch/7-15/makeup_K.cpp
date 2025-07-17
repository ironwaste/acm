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

// 2025.07.15——18:48:56
/*
 * 每个房间最多3扇门,所以可以直接搞成一个三层图,
 * 房间u有du条走廊,这些门上标有1,2,du
 * 如果他们在u房间,并从标有i的门进入走廊,它们将会选择一个
 * 标有下一个数字的们(即,如果i < du,则选择i+1,入股i == du,则选择1)
 * 题目读错了，因为其按照的门的顺序，无论出入都是按照当前的房间的值来，而非出去的房间的门的标签来的
 *
 * 那么我们就需要两个存图，一个是根据房间存其1，2，3号门分别通往哪个房间
 * 第二个是 根据房间按照 当前房间和另外一个房间u，v找出其标号是多少
 * 第二个是方便向回找，这样子最后就会成为一个环。
 * 使用一个map来存遍历过的边，根据u ，v来存储，且需要将两者反存一遍，防止重复计算，在最后除以2即可
 * 其次使用map来存储一个遍历过的门和相应的标签，当回到自己的时候则结束，不需要bfs即可
*/


/**** 
 * 总结 ：题目读错导致补题有问题，没有将样例带入去试一下导致的
 * 其次当发现题目读题错误之后，最好将代码全部重构，或者将代码交给队友来写
 *
 * 其次，对于约瑟夫环已经不熟练了，尤其是求其逆向的时候。
 * next_v = pre_v % size +1LL  当初始值从1LL开始的时候
 * pre_v = (next_v + (size - 1LL)-1LL) % size 初始值为1LL的时候
 *
 * next_v = (pre_v + 1LL)% size 当初始值是从0LL开始的时候
 * pre_v = (pre_v + (size - 1LL)) % size  此处就是比初始值为零的部分在模除之前的部分加了个1LL
 *
 */
void solve() {
    i64 n;
    cin >> n;
    vector<array<i64, 4>>gl(n+10, { -1,-1,-1,-1 });
    for (int i = 1;i <= n;i++) {
        i64 du;
        cin >> du;
        gl[i][0] = du;
        for (i64 j = 1;j <= du;j++) {
            i64 k;
            cin >> k;
            gl[i][j] = k;
        }
    }
    vector<array<i64, 4> >ans(n + 10, { -1,-1,-1,-1 });
    vector<array<i64, 4>>vis(n + 10, { 0,0,0,0 });

    for (i64 i = 1;i <= n;i++) {
        if (ans[i][1] != -1) {
            continue;
        }
        set<pll>s, anspll;
        queue<pll>q;
        pll be = { i,1LL };
        q.push(be); // 房间号， 门号
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            i64 u = t.fi, label = t.se;

            anspll.insert({ u, label});
            // 出去
            i64 v = gl[u][label];
            i64 tdu = gl[v][0],v_label;
            for (int i = 1;i <= tdu;i ++) {
                if (gl[v][i] == u) {
                    v_label = i;
                    break;
                }
            }
            i64 nextlabel = v_label % tdu + 1LL;
            s.insert({ u,v });
            s.insert({ v,u });
            if (!vis[v][nextlabel]) {
                vis[v][nextlabel] = 1;
                q.push({ v,nextlabel });
            }
        }
        i64 w = s.size() / 2LL;
        for (auto t : anspll) {
            i64 v = t.fi, label = t.se;
            ans[v][label] = w;
        }
    }
    for (int i = 1;i <= n;i ++) {
        cout << ans[i][1] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}