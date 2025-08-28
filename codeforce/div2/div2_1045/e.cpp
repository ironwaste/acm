#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'
#define mod3 998244353
#define mod7 1000000007
#define de(x) cerr << #x <<" "<<x <<" ";
#define deb(x) cerr << #x <<" "<<x <<endl;
using namespace std;

int n;
vector<vector<int>> tree;

// BFS 找从 start 出发最远的点，并记录 parent 路径
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
        if (dist[i] > dist[farthest]) farthest = i;
    }
    return {farthest, parent};
}

int solve() {
    cin >> n;
    tree.assign(n, vector<int>());
    vector<int>du(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;  // 转为0-indexed
        tree[u].push_back(v);
        tree[v].push_back(u);
        du[v]++;
        du[u]++;
    }
    int ok = 1;
    for (int i = 0;i < n;i++) {
        
        if (du[i] >= 3)ok = 0;
        
    }
    if (ok) {
        cout << -1 << endl;
        return 0;
    }
    // deb(ok);
    // 第一次BFS找到最远点u
    auto [u, _] = bfs(0);

    // 第二次BFS找到从u出发最远的点v，并记录路径
    auto [v, parent] = bfs(u);

    // 回溯路径u->v，得到直径路径
    vector<int> path;
    int cur = v;
    while (cur != -1) {
        path.push_back(cur);
        cur = parent[cur];
    }
    reverse(path.begin(), path.end());

    int L = path.size();
    vector<int> centers;

    if (L % 2 == 1) {
        int mid = L / 2;
        // i64 mmid = path[L / 2];
        for (int i = 0;i < L / 2;i++) {
            int a = path[mid - i + 1];
            int b = path[mid - i];
            int c = path[mid - i - 1];
            if (du[b] > 2) {
                if (du[a] < du[c]) { swap(a, c); }

                cout << a + 1 << " " << b + 1 << " " << c + 1 << endl;
                return 0;
            }
            a = path[mid + i - 1];
            b = path[mid + i];
            c = path[mid + i + 1];
            if (du[b] > 2) {
                if (du[a] < du[c]) { swap(a, c); }

                cout << a + 1 << " " << b + 1 << " " << c + 1 << endl;
                return 0;
            }
        }
    } else {
        int mid1 = L / 2 - 1, mid2 = L / 2 ;
        for (int i = 0;i < L / 2;i++) {
            int a = path[mid1 - i + 1];
            int b = path[mid1 - i];
            int c = path[mid1 - i - 1];
            if (du[b] > 2) {
                if (du[a] < du[c]) { swap(a, c); }
                cout << a + 1 << " " << b + 1 << " " << c + 1 << endl;
                return 0;
            }
            a = path[mid2 + i - 1];
            b = path[mid2 + i];
            c = path[mid2 + i + 1];
            if (du[b] > 2) {
                if (du[a] < du[c]) { swap(a, c); }
                cout << a + 1 << " " << b + 1 << " " << c + 1 << endl;
                return 0;
            }
        }



    }
    cout << -1 << endl;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}