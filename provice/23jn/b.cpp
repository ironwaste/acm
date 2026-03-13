
#include <bits/stdc++.h>

#define pb push_back
#define x first
#define y second

using namespace std;

using LL = long long;
using PII = pair<int, int>;
using PLL = pair < LL, LL>;

const int N = 1e5 + 10;

LL n, m, k;

struct p {
    int x1, x2, y;
};

void solve()
{
    cin >> n >> m >> k;
    vector<p> a(k);
    vector<int> vec;
    vec.pb(0), vec.pb(m + 1);
    for (auto& [x1, x2, y] : a) cin >> x1 >> x2 >> y, vec.pb(y);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    int len = vec.size();

    for (int i = 1; i < len; i++)
    {
        if (vec[i] - vec[i - 1] >= 3)
        {
            cout << "NO" << endl;
            return;
        }
    }

    vector<vector<PII>> v(m + 1);

    for (auto& [x1, x2, y] : a)
        v[y].pb({ x1, x2 });

    for (int i = 1; i <= m; i++)
    {
        v[i].pb({ 0, 0 });
        v[i].pb({ n + 1, n + 1 });
    }

    vector<vector<PII>> li(m + 1);

    int sum = -1;
    for (int i = 1; i <= m; i++)
    {
        sort(v[i].begin(), v[i].end());

        for (int j = 1; j < v[i].size(); j++)
        {
            int l = v[j - 1].y + 1;
            int r = v[j].x - 1;
            if (l <= r)
                li[i].pb({ l, r }), sum ++;
        }
    }

    LL ans = 0;

    int i = 1;
    while (i <= m && !li[i].size()) i++;


    for (; i <= m; i++)
    {
        if (!li[i].size()) break;

        int i1 = 0;
        int i2 = 0;

        while (i1 < li[i - 1].size() && i2 < li[i].size())
        {
            auto [l1, r1] = li[i - 1][i1];
            auto [l2, r2] = li[i][i2];

            if (r1 < l2) i1++;
            else if (r2 < l1) i2++;
            else
            {
                int x = max(l1, l2) - min(r1, r2) + 1;
                if (x >= 2)
                {
                    cout << "NO" << endl;
                    return;
                }
                sum--;

                if (sum < 0)
                {
                    cout << "NO" << endl;
                    return;
                }

                if (r1 < r2) l1++;
                else if (r1 > r2) l2++;
                else l1++, l2++;
            }
        }
    }

    cout << "YES" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}