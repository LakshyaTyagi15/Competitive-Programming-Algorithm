#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, weight;

    DSU(int n) {
        parent.resize(n + 1);
        weight.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (weight[a] < weight[b])
                swap(a, b);
            parent[b] = a;
            weight[a] += weight[b];
        }
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    int size(int x) {
        return weight[find(x)];
    }
};

int main()
{
    return 0;
}
