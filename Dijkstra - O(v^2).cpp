#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll mod = 1e9 + 7;
ll modd = 998244353;

vector<ll> dijkstra(ll v, vector<vector<ll>> adj[], ll s)
{
    vector<bool> explored(v + 1, 0);
    vector<ll> dist(v + 1, 1e18);
    dist[s] = 0;
    ll count = v;
    while (count--)
    {
        ll node = -1, value = 1e18;
        for (ll i = 1; i <= v; i++)
        {
            if (!explored[i] && value > dist[i])
            {
                node = i;
                value = dist[i];
            }
        }
        if (node == -1) break;
        explored[node] = 1;
        for (ll j = 0; j < adj[node].size(); j++)
        {
            ll neighbour = adj[node][j][0];
            ll weight = adj[node][j][1];
            if (!explored[neighbour] && dist[node] + weight < dist[neighbour])
            {
                dist[neighbour] = dist[node] + weight;
            }
        }
    }
    return dist;
}

void solve()
{
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
