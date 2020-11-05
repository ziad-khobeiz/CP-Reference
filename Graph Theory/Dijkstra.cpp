// Dijkstra O(m * log)

struct edge {
    int to;
    long long cost;
};

long long dist[N];
vector<edge> adj[N];

void Dijkstra(int s) {
    //                 <dist,node>
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    fill(dist, dist + N, OO);
    pq.push({s, 0});
    dist[s] = 0;
    while (pq.size()) {
        int node = pq.top().second;
        long long cost = pq.top().first;
        pq.pop();
        if (dist[node] != cost) continue;
        for (auto &c : adj[node]) {
            if (dist[c.to] > dist[node] + c.cost) {
                dist[c.to] = dist[node] + c.cost;
                // par[c.to] = node;
                pq.push({dist[c.to], c.to});
            }
        }
    }
}
