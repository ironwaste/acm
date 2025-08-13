#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using i128 = __int128_t;

// print __int128
void print_int128(i128 x) {
    if (x == 0) { putchar('0'); return; }
    if (x < 0) { putchar('-'); x = -x; }
    string s;
    while (x > 0) {
        int d = int(x % 10);
        s.push_back('0' + d);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    fputs(s.c_str(), stdout);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        long long n_ll, w_ll;
        cin >> n_ll >> w_ll;
        i128 n = (i128)n_ll;
        i128 w = (i128)w_ll;

        vector<i128> a;
        i128 m = n;
        while (true) {
            if (m < w) {
                a.push_back(m);
                break;
            } else {
                i128 d = m / w;

                a.push_back(d);
                m = m - d;

            }
        }

        i128 prefix = 0;
        i128 total = 0;
        for (size_t idx = 0; idx < a.size(); ++idx) {
            i128 cnt = a[idx];
            if (cnt == 0) continue;
            i128 L = prefix;
            i128 R = L + cnt;
            
            i128 sum_vals = cnt * ( (L + 1) + R ) / 2;
            i128 survive_times = (i128)(idx + 1); 
            total += survive_times * sum_vals;
            prefix += cnt;
        }

        print_int128(total);
        putchar('\n');
    }
    return 0;
}
