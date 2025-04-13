#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;
const ll modd = 998244353;

class DSU {
public:
    vector<ll> parent, rank;

    DSU(ll n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (ll i = 1; i <= n; ++i)
            parent[i] = i;
    }

    ll find(ll x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void join(ll a, ll b) {
        ll rootA = find(a);
        ll rootB = find(b);
        if (rootA != rootB) {
            if (rank[rootA] < rank[rootB]) {
                swap(rootA, rootB);
            }
            parent[rootB] = rootA;
            if (rank[rootA] == rank[rootB])
                rank[rootA]++;
        }
    }

    bool same_set(ll a, ll b) {
        return find(a) == find(b);
    }
};


void solve() {

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--) solve();

    return 0;
}
