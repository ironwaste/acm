#include <bits/stdc++.h>
using namespace std;
 
vector<long long> z;
 
void precalc()
{
    z = {1ll};
    while(z.back() < 1e18)
        z.push_back(4 * z.back() + 1);
}
 
map<pair<long long, long long>, long long> dp;
 
long long get(long long r, long long x)
{
    if(dp.count(make_pair(r, x))) return dp[make_pair(r, x)];
    long long& d = dp[make_pair(r, x)];
    if(x > 4 * z.size()) return d = 0;
    if(x < 0) return d = 0;
    if(r == 0) return d = 0;
    if(r == 1)
    {
        if(x == 0) return d = 1;
        return d = 0;
    }
    auto it = lower_bound(z.begin(), z.end(), r);
    --it;
    long long y = *it;
    return d = get(y, x) + get(r - y, x - 1);
}
 
int main() 
{
    precalc();
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        long long l, r, x;
        cin >> l >> r >> x;
        cout << get(r + 1, x) - get(l, x) << endl;
    }
}