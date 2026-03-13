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

using LL = long long;
using pii = pair<int,int>;
using pll = pair<i64, i64>;

// 补题——题目链接:
// 网址：
// 2025.11.18——21:15:07
/*
 *
 *
 *
*/

/*
4 1 1 1 0 0 0 0 0
1 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 2
95 88 77 66 55 44 33 22 11
100 90 80 70 60 50 40 30 20
*/

void solve() {
    vector<int> a(10);

    for (int i = 0; i < 9; i ++) cin >> a[i];

    auto qmi = [&](LL x, LL k) -> LL {
        LL ans = 1;
        while (k)
        {
            if (k & 1) ans = ans * x % mod3;
            x = x * x % mod3;
            k >>= 1;
        }
        return ans;
        };

    if (a[0] > a[1] && a[1])
    {
        a[2] += a[1], a[0] -= a[1], a[1] = 0;
        // cout << a[0] << " " << a[1] << " " << a[2] << endl;
        LL x, y;
        x = a[0] / 3;
        y = a[0] % 3;
        if (y == 1)
        {
            a[2] += x;
            a[2]--;
            a[1] += 2;
        }
        else
        {
            a[2] += x;
            if (y == 2) a[1]++;
        }
    }
    else
    {
        a[0] -= a[1], a[2] += a[1], a[1] = 0;
        LL x, y;
        x = a[0] / 3;
        y = a[0] % 3;
        if (!x && y)
        {
            for (int i = 1; i < 9; i++)
            {
                if (a[i])
                {
                    a[i]--;
                    a[i + 1]++;
                    break;
                }
            }
        }
        else if (y == 1) a[1]--, a[2]++;
        else if (y == 2) {
            a[1]++;
            a[2] += x;
        } else a[2] += x;
    }

    if (a[1] < 0) a[2] -= 2, a[1] += 2;

    // for (int i = 0; i < 9; i++) cout << a[i] << " ";
    // cout << endl;

    LL ans = 1;
    for (int i = 1; i <= 9; i++)
    {
        ans *= qmi(i + 1, a[i]);
        ans %= mod3;
    }

    cout << ans << endl;
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