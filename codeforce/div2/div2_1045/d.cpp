#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> tree;

// 用于找直径：返回最远点和路径
pair<int, vector<int>> bfs(int start) {
    vector<int> dist(n, -1);
    vector<int> parent(n, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : tree[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    int farthest = start;
    for (int i = 0; i < n; ++i) {
        if (dist[i] > dist[farthest]) {
            farthest = i;
        }
    }

    return {farthest, parent};
}

int solve() {
    cin >> n;
    tree.assign(n, vector<int>());
    vector<int> degree(n, 0);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    // 快速判断是否已经是路径图
    bool is_path = true;
    for (int i = 0; i < n; ++i) {
        if (degree[i] > 2) {
            is_path = false;
            break;
        }
    }

    if (is_path) {
        cout << -1 << '\n';
        return 0;
    }

    // 找直径两端点
    auto [u, _] = bfs(0);
    auto [v, parent] = bfs(u);

    // 构建直径路径
    vector<int> path;
    int cur = v;
    while (cur != -1) {
        path.push_back(cur);
        cur = parent[cur];
    }

    int len = path.size();
    int midL = (len - 1) / 2;
    int midR = len / 2;

    // 从中间向两边扩展，找到第一个度数 > 2 的点
    for (int i = 0; midL - i > 0 || midR + i + 1 < len; ++i) {
        // 左半边扩展
        if (midL - i > 0 && midL - i + 1 < len) {
            int b = path[midL - i];
            if (degree[b] > 2) {
                int a = path[midL - i - 1];
                int c = path[midL - i + 1];
                // 可选地选择 degree 更大的作为 c
                if (degree[a] > degree[c]) swap(a, c);
                cout << a + 1 << " " << b + 1 << " " << c + 1 << '\n';
                return 0;
            }
        }

        // 右半边扩展
        if (midR + i + 1 < len && midR + i - 1 >= 0) {
            int b = path[midR + i];
            if (degree[b] > 2) {
                int a = path[midR + i - 1];
                int c = path[midR + i + 1];
                if (degree[a] > degree[c]) swap(a, c);
                cout << a + 1 << " " << b + 1 << " " << c + 1 << '\n';
                return 0;
            }
        }
    }

    // 没找到
    cout << -1 << '\n';
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
