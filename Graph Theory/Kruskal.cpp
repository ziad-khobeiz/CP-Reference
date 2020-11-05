int find_par(int u){
    if(u == par[u]) return u;
    return par[u] = find_par(par[u]);
}

bool same_set(int u, int v){
    return find_par(u) == find_par(v);
}

void join(int u, int v){
    u = find_par(u);
    v = find_par(v);
    par[u] = v;
}


int kruskal(int n){
    iota(par, par + n + 1, 0);
    int ret = 0;
    /// cost, u, v
    /// pair<int, pair<int, int> >
    sort(edges.begin(), edges.end());
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].second.first, v = edges[i].second.second;
        ll cost = edges[i].first;
        if(!same_set(u, v)){
            join(u, v);
            ret += cost;
        }
    }
    return ret;
}
