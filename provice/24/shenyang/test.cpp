#include <bits/stdc++.h>

#define x first
#define y second
#define pb push_back

using namespace std;

using LL = long long;
using PLL = pair<LL, LL>;
using PII = pair<int, int>;

const int N = 2010;

LL n, m, k;

void solve()
{
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    vector<int> c(n + 1);
    for (int i = n; i >= 1; i--)
    {
        char c;
        cin >> c;
        a[i] = c ^ 48;
    }

    for (int i = n; i >= 1; i--)
    {
        char c;
        cin >> c;
        b[i] = c ^ 48;
    }

    for (int i = 1; i <= n; i++)
        c[i] = a[i] + b[i];

    set<PII> st;
    for (int i = 1; i <= n; i++)
    {
        if (c[i] == 9)
        {
            int r = i;
            while (r <= n && c[r] == 9) r++;
            r--;
            st.insert({ i, r });
            i = r;
        }
    }

    auto cal = [&](int i) -> int {
        auto it = st.lower_bound({ i + 1, -1 });
        if (it != st.begin() && (--it)->y >= i) {
            return c[it->x - 1] / 10;
        } else
            return c[i] / 10;
        };
    
    while (m--)
    {
        int r, i, d;
        cin >> r >> i >> d;
        i = n - i + 1;
        int add = 0;
        if (r == 1)
        {
            if (a[i] != d) add++;
            a[i] = d;
        }
        else
        {
            if (b[i] != d) add++;
            b[i] = d;
        }

        auto it = st.lower_bound({ i + 1, -1 }); //l < i的最近的区间
        if (it != st.begin() && (--it)->y >= i) 
        {
            if (a[i] + b[i] == 9)
            {
                cout << (b[i] + a[i] + cal(i - 1)) % 10 << " " << 0 << endl;
            }
            else
            {
                int l = it->x, r = it->y;
                if (c[l - 1] / 10)
                {
                    if (a[i] + b[i] < 9)
                    {
                        int ans = r - i + 1;
                        if (r != n) ans++;
                        cout << a[i] + b[i] + 1 << " " << ans + 1 << endl;
                    }
                    else
                        cout << (a[i] + b[i] + 1) % 10 << " " << 2 << endl;
                }
                else
                {
                    if (a[i] + b[i] < 9)
                        cout << a[i] + b[i] << " " << 2 << endl;
                    else
                    {
                        int ans = r - i + 1;
                        if (r != n) ans++;
                        cout << (a[i] + b[i]) % 10 << " " << ans + 1 << endl;
                    }
                }
            }
        }
        else
        {
            auto p = st.lower_bound({ i + 1, -1 });
            int x = c[i] + cal(i - 1);
            int y = b[i] + a[i] + cal(i - 1);
            //在当前后面的最近的9的区间
            if (p == st.end() || p->x != i + 1)
            {
                int ans = 0;
                if (add) ans += 2;
                if (x / 10 != y / 10 && i != n)
                    ans++;
                cout << y % 10 << " " << ans << endl;
            }
            else
            {
                int ans = 0;
                if (add) ans += 2;
                if (x / 10 != y / 10)
                {
                    ans += p->y - p->x + 1;
                    if (p->y != n) ans++;
                }
                cout << y % 10 << " " << ans << endl;
            }
        }

        c[i] = a[i] + b[i];
        it = st.lower_bound({ i + 1, -1 });
        if (it != st.begin() && (--it)->y >= i)
        {
            int l = it->x, r = it->y;
            st.erase(it);
            if (c[i] == 9) st.insert({ l, r });
            else
            {
                if(l <= i - 1) st.insert({ l, i - 1 });
                if(i + 1 <= r) st.insert({ i + 1, r });
            }
        }
        else if(c[i] == 9)
        {
            auto rs = st.lower_bound({ i + 1, -1 });
            if (rs == st.end() || rs->x != i + 1)
            {
                auto ls = rs;
                if (ls != st.begin() && (--ls)->y == i - 1) {
                    st.insert({ ls->x, ls->y + 1 });
                    st.erase(ls);
                } else st.insert({ i, i });
            }
            else
            {
                auto ls = rs;
                if (ls != st.begin() && (--ls)->y == i - 1)
                {
                    st.insert({ ls->x, rs->y });
                    st.erase(ls), st.erase(rs);
                }
                else
                {
                    st.insert({ i, rs->y });
                    st.erase(rs);
                }
            }
        }
    }
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