#include<bits/stdc++.h>
#include<climits>

#define fi first
#define se second
#define i64 long long 
#define all(x) x.begin(),x.end()
#define endl '\n'
#define de(x) cerr << #x << " " << x << " ";
#define deb(x) cerr << #x << " " << x << " \n";
using namespace std;
using pll = pair<i64, i64>;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<PII>> l(2, vector<PII>(n, { -1, -1 })), r(2, vector<PII>(n, { -1, -1 }));

    string ans;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'o')
        {
            int j = i - 1, sum = 0;
            string tmp;
            while (j >= 0 && s[j] != 'o')
            {
                if (s[j] == 'v') sum++;
                else sum += 2;
                l[sum & 1][i].fi = sum, l[sum & 1][i].se = j;
                tmp += s[j];
                j--;
            }

            if (tmp.size() > ans.size()) ans = tmp;

            tmp.clear();
            j = i + 1, sum = 0;
            while (j < n && s[j] != 'o')
            {
                if (s[j] == 'v') sum++;
                else sum += 2;
                r[sum & 1][i] = { sum, j };
                tmp += s[j];
                j++;
            }

            if (tmp.size() > ans.size()) ans = tmp;
        }
    }

    string p;
    p += '$';
    vector<int> pos(n * 2 + 10);

    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'o') p += '#', p += s[i], pos[p.size() - 1] = i, vec.pb(p.size() - 1);
        else if (s[i] == 'v') p += '#', p += s[i];
        else
        {
            p += '#', p += 'v';
            p += '#', p += 'v';
        }
    }
    p += "#&";

    auto cal = [&](int x, int y) -> void {
        for(int i = 0; i < 2; i ++)
        {
            auto [w1, i] = l[i][x];
            auto [w2, j] = r[i][y];
            
        }
    };

    vector<int> rd(n * 2 + 10);
    int m = p.size();
    int r = 0, c = -1;
    for (int i = 1; i < m; i++)
    {
        if (i < r) rd[i] = min(rd[(c << 1) - i], rd[c] + c - i);
        else rd[i] = 1;
        while (p[i + rd[i]] == p[i - rd[i]]) rd[i]++;
        if (rd[i] + i > r)
        {
            r = rd[i] + i;
            c = i;
        }

        int L = i - rd[i] + 1, R = i + rd[i] - 1;
        auto ll = lower_bound(vec.begin(), vec.end(), L);
        auto rr = upper_bound(vec.begin(), vec.end(), R);
        if (ll != vec.end() && rr != vec.begin())
            cal(pos[*ll], pos[*rr]);
    }

    cout << ans << endl;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}