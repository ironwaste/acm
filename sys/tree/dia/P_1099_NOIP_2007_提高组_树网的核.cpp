#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int N = 500005;
const i64 INF = 1e18;

vector<pair<int, i64>> E[N];
i64 dis[N], pre[N];
int fa[N], path[N], vis[N];
i64 h[N];

void dfs(int u, int f) {
    fa[u] = f;
    for (auto &[v, w] : E[u]) {
        if (v == f) continue;
        dis[v] = dis[u] + w;
        dfs(v, u);
    }
}

void calc_h(int u, int f) {
    h[u] = 0;
    for (auto &[v, w] : E[u]) {
        if (v == f || vis[v]) continue;
        calc_h(v, u);
        h[u] = max(h[u], h[v] + w);
    }
}

int main() {
    int n, s;
    cin >> n >> s;
    for (int i = 1; i < n; i++) {
        int u, v;
        i64 w;
        cin >> u >> v >> w;
        E[u].push_back({v, w});
        E[v].push_back({u, w});
    }
    
    dis[1] = 0;
    dfs(1, 0);
    int u = 1;
    for (int i = 1; i <= n; i++) {
        if (dis[i] > dis[u]) u = i;
    }
    
    dis[u] = 0;
    dfs(u, 0);
    int v = u;
    for (int i = 1; i <= n; i++) {
        if (dis[i] > dis[v]) v = i;
    }
    
    int cnt = 0;
    for (int i = v; i != 0; i = fa[i]) {
        path[++cnt] = i;
        vis[i] = 1;
    }
    reverse(path + 1, path + cnt + 1);
    
    for (int i = 1; i <= cnt; i++) {
        calc_h(path[i], 0);
    }
    
    pre[1] = 0;
    for (int i = 2; i <= cnt; i++) {
        int u = path[i-1], v = path[i];
        i64 w = 0;
        for (auto &[x, len] : E[u]) {
            if (x == v) {
                w = len;
                break;
            }
        }
        pre[i] = pre[i-1] + w;
    }
    
    i64 ans = INF;
    int l = 1, r = 1;
    for (; l <= cnt; l++) {
        while (r < cnt && pre[r+1] - pre[l] <= s) {
            r++;
        }
        if (pre[r] - pre[l] <= s) {
            i64 ecc = max(pre[l], pre[cnt] - pre[r]);
            for (int i = l; i <= r; i++) {
                ecc = max(ecc, h[path[i]]);
            }
            ans = min(ans, ecc);
        }
    }
    cout << ans << endl;
    return 0;
}