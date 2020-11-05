struct Edge{

    int from, to;
    ll cost;

    // The operator is reversed to sort the priority_queue non-increasing
    bool operator < (const Edge &e) const {
        return cost > e.cost;
    }

};

bool vis[N];

ll Prim() {

    priority_queue<Edge> q;

    memset(vis, 0, sizeof vis);

    q.push({-1, 0, 0});

    ll ret = 0;

    while (!q.empty()) {
        auto e = q.top();
        q.pop();
        if(vis[e.to]) continue;
        vis[e.to] = true;
        ret += e.cost;
        for (int i = 0; i < n; ++i) {
            if(!vis[i]) {
                q.push({e.to, i, dist(e.to, i)});
            }
        }
    }

    return ret;

}
