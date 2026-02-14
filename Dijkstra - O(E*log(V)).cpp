#include <bits/stdc++.h>
using namespace std;

template <typename T>
vector<T> dijkstra(int v, vector<vector<pair<int, T>>>& adj, int s) {
    vector<bool> explored(v + 1, false);
    vector<T> dist(v + 1, numeric_limits<T>::max());
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        T current_dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (explored[node]) continue;
        explored[node] = true;

        for (auto& edge : adj[node]) {
            int neighbour = edge.first;
            T weight = edge.second;

            if (!explored[neighbour] && dist[node] + weight < dist[neighbour]) {
                dist[neighbour] = dist[node] + weight;
                pq.push({dist[neighbour], neighbour});
            }
        }
    }
    return dist;
}

int main()
{
    return 0;
}
