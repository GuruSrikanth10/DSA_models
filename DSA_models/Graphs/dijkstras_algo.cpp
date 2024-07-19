// Dijkstra's alogrithm to find minimum distances from source node using priotity queue;
#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});
    vector<int> distance(V, INT_MAX);
    distance[S] = 0;
    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto it : adj[node])
        {
            int dis = it[1];
            int adjnode = it[0];
            if (dis + dist < distance[adjnode])
            {
                distance[adjnode] = dis + dist;
                pq.push({distance[adjnode], adjnode});
            }
        }
    }
    return distance;
}
