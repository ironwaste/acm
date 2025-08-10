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

// 2025.08.10——23:10:41
/*
 *
 * 除了最后一位其他 所有位置可以异或其后一位
 * 然后将所有的
 *
 * 前缀异或和 ，然后正序判断 存当前位置 所需要到的下标位置
 *
*/

void solve() {
    int n;
    cin >> n;
    vector<i64>a(n), b(n);
    for (int i = 0;i < n;i ++) {cin >> a[i];}
    for (int i = 0;i < n;i ++) {cin >> b[i];}
    vector<i64>prx(n);
    set<i64>st;
    map<i64, i64>mp;
    i64 cnt = 0;
    vector<vector<i64> >id;
    for (int i = 0;i < n;i++) {
        if (!i)prx[i] = a[i];
        else {
            prx[i] = prx[i - 1] ^ a[i];
        }
        // st.insert(prx[i]);
        if (mp.count(prx[i])) {
            i64 k = mp[prx[i]];
            id[k].push_back(i);
        } else {
            vector<i64>k;
            k.push_back(i);
            id.push_back(k);
            mp[prx[i]] = cnt++;
        }
    }
    i64 needi = -1,ok = 1,cntv = 0;
    //  需要知道 需要的异或值的下标，且取其中下标最小的
    for (int i = 0;i < n;i++) {
        if (st.count(b[i] ^ cntv)) {
            i64 k = mp[b[i] ^ cntv];
            i64 cntid = -1;
            for (auto vid : id[k]) {
                if (vid > needi) {
                    cntid = vid;
                    break;
                }
            }
            if (cntid == -1) {
                ok = 0;
                break;
            } else {
                needi = cntid;
            }

            
        } else {
            ok = 0;
            break;
        }

        
        cntv ^= a[i];
        st.erase(cntv);
    }

    cout << ((ok) ? "YES" : "NO") << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}