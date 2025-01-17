#include <bits/stdc++.h>
using namespace std;
int n, node, d, ret, root;
vector<int> adj[52];

void dfs(int u) {
    bool isLeaf = true;
    for (int v : adj[u]) {
        isLeaf = false;
        dfs(v);
    }
    if (isLeaf) ret++;
}

int main() {
    cin >> n;
    root = -1;
    for (int i = 0; i < n; i++) {
        cin >> node;
        if (node == -1) {
            root = i;
        } else {
            adj[node].push_back(i);
        }
    }
    cin >> d;
    if (d == root) {
        cout << 0 << endl;
        return 0;
    }
    
    for (int i = 0; i < n; i++) {
        adj[i].erase(remove(adj[i].begin(), adj[i].end(), d), adj[i].end());
    }
    dfs(root);
    cout << ret << endl;
}
