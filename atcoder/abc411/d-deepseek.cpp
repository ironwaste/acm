#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<int> pc(N + 1, 0); // PC的当前节点指针（1-indexed）
    int server = 0;            // 服务器的当前节点指针
    
    // 节点存储：0号节点为根（空字符串）
    vector<int> parent(1, -1);      // 父节点数组
    vector<string> append_str(1, ""); // 追加字符串数组
    int node_count = 0;              // 节点计数器（0号已用）
    
    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int p;
            cin >> p;
            pc[p] = server; // 操作1：用服务器字符串覆盖PC p
        } else if (type == 2) {
            int p;
            string s;
            cin >> p >> s;
            node_count++; // 创建新节点
            parent.push_back(pc[p]); // 新节点的父节点为当前PC p的节点
            append_str.push_back(s);
            pc[p] = node_count;     // 更新PC p的指针
        } else if (type == 3) {
            int p;
            cin >> p;
            server = pc[p]; // 操作3：用PC p的字符串覆盖服务器
        }
    }
    
    // 回溯路径：从服务器节点到根节点
    vector<string> fragments;
    int cur = server;
    while (cur != 0) {
        fragments.push_back(append_str[cur]);
        cur = parent[cur];
    }
    reverse(fragments.begin(), fragments.end()); // 反转得到正确顺序
    
    // 拼接最终字符串
    string ans;
    for (const string& s : fragments) {
        ans += s;
    }
    cout << ans << endl;
    
    return 0;
}