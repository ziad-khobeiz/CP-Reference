int par[N], rnk[N], comps;

struct Edge{

    int from, to;
    ll cost;

    bool operator < (const Edge & e) const {
        return cost > e.cost;
    }

};

void build_dsu() {
    iota(par + 1, par + 1 + n, 1);
    fill(rnk + 1, rnk + 1 + n, 1);
    comps = n;
}

int find_set(int a) {
    if(par[a] == a) return a;
    return par[a] = find_set(par[a]);
}

bool connect(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a == b) return false;
    if(rnk[a] > rnk[b]) swap(a, b);
    par[a] = b;
    rnk[b] += (rnk[a] == rnk[b]);
    --comps;
    return true;

}

vector<Edge> Kruskal() {

    vector<Edge> ret;
    priority_queue<Edge> edges;
    
    // Put edges in priority queue
    
    while (comps != 1) {
        auto e = edges.top();
        edges.pop();
        if(connect(e.from, e.to)) ret.push_back(e);
    }

    return ret;

}
