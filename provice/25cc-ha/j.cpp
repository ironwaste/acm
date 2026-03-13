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
    cin >> n;
    string s;
    cin >> s;
    vector<vector<PII>> l(2, vector<PII>(n, {-1, -1})), r(2, vector<PII>(n, {-1, -1}));
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'o')
        {
            int j = i - 1, sum = 0;
            while (j >= 0 && s[j] != 'o')
            {
                if (s[j] == 'v') sum++;
                else sum += 2;
                l[sum & 1].fi = sum, l[sum & 1].se = j;
                j--;
            }

            j = i + 1, sum = 0;
            while (j < n && s[j] != 'o')
            {
                if (s[j] == 'v') sum++;
                else sum += 2;
                r[sum & 1] = { sum, j };
                j++;
            }
        }
    }

    string p;
    p += '$';
    vector<int> pos(n * 2 + 10);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'o') p += '#', p += s[i], pos[p.size() - 1] = i;
        else if (s[i] == 'v') p += '#', p += s[i];
        else
        {
            p += '#', p += 'v';
            p += '#', p += 'v';
        }
    }
    p += "#&";
    cout << p << endl;
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