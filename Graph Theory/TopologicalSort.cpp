void dfs(int u) {

    vis[u] = true;
    for(auto & v : g[u]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
    ans.push_back(u);
}

void topological_sort() {

    ans.clear();
    memset(vis, false, sizeof vis);
    for (int i = 1; i <= n; ++i) {
        if(!vis[i]) dfs(i);
    }

}

// Put edges in vector g where v[j].push_back(i) means that i should happen before j 
// Check that the graph is acyclic (DAG)
