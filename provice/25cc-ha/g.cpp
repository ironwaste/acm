#include<bits/stdc++.h>
#include<climits>

#define i64 long long 
#define all(x) x.begin(),x.end()
#define endl '\n'
using namespace std;



void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<vector<i64> >g(n, vector<i64>(m));
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> g[i][j];
        }
    }

    i64 sum_ne = 0;
    vector<i64>po(m, 0);
    for (int i = 0;i < n;i++) {
        i64 tmp_sum = 0;
        for (int j = m - 1;j > 0;j--) {
            if (g[i][j] < 0) {
                if (po[j] > 0) {
                    i64 t = min(po[j], -g[i][j]);
                    po[j] -= t;
                    g[i][j] += t;
                }
                g[i][j - 1] += g[i][j];
            } else {
                po[j] += g[i][j];
            }
        }
        if (po[0] > 0) {
            i64 t = min(po[0], -g[i][0]);
            po[0] -= t;
            g[i][0] += t;
        }

        if (g[i][0] < 0)sum_ne -= g[i][0];
        else { po[0] += g[i][0]; }
    }

    for (auto x:po) {
        sum_ne += x;
    }
    cout << sum_ne << endl;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}