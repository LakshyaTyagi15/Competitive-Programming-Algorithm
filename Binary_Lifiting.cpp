#include <bits/stdc++.h>

using namespace std;

struct BinaryLifting {
    int n, m;
    vector<vector<int>> adj;
    vector<int> depth;
    vector<vector<int>> up;

    BinaryLifting(int n)
        : n(n),
          m(__lg(n) + 1),
          adj(n + 1),
          depth(n + 1),
          up(n + 1, vector<int>(m)) {}

    BinaryLifting(const vector<vector<int>>& graph)
        : n(graph.size()),
          m(__lg(n) + 1),
          adj(graph),
          depth(n),
          up(n, vector<int>(m)) {
        build();
    }

    void connect(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int p) {
        up[u][0] = p;

        for (int j = 1; j < m; j++) {
            up[u][j] = up[up[u][j - 1]][j - 1];
        }

        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }

    void build(int root = 0) {
        depth[root] = 0;
        dfs(root, root);
    }

    int ancestor(int u, int k) {
        for (int j = 0; j < m; j++) {
            if (k & (1 << j)) {
                u = up[u][j];
            }
        }
        return u;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        u = ancestor(u, depth[u] - depth[v]);

        if (u == v) return u;

        for (int j = m - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }
};

int main() { return 0; }
