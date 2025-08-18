#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#ifdef LOCAL
#include <debug.h>
#else
#define dbg(x...)
#endif

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;

template <typename T>
vector<T> dijkstra(ll v, vector<vector<ll>> adj[], ll s)
{
    vector<bool> explored(v + 1, 0);
    vector<T> dist(v + 1, numeric_limits<T>::max());
    dist[s] = 0;
    ll count = v;
    while (count--)
    {
        ll node = -1;
        T value = 1e18;
        for (ll i = 1; i <= v; i++)
        {
            if (!explored[i] && value > dist[i])
            {
                node = i;
                value = dist[i];
            }
        }

        explored[node] = 1;
        for (ll j = 0; j < adj[node].size(); j++)
        {
            ll neighbour = adj[node][j][0];
            T weight = adj[node][j][1];
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
