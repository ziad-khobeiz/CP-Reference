// Time complexity: 
// Build -> O(n * log(n)) 
// Get -> O(log(n))

int n, q, level[N], sp[N][lg];
vector<int> adj[N];

void dfs(int node, int par)
{
    level[node] = level[par] + 1;
    sp[node][0] = par;
    for(int i = 1; i<lg; i++)
    {
        int tmp = sp[node][i-1];
        sp[node][i] = sp[tmp][i-1];
    }
    for(auto i: adj[node])
    {
        if(i == par) continue;
        dfs(i, node);
    }
}

int get_kth(int node, int k)
{
    for(int i = 0; i<lg; i++)
        if(k >> i & 1)
            node = sp[node][i];
    return node;
}

int lca(int u, int v)
{
    if(level[u] > level[v])
        swap(u, v);
    v = get_kth(v, level[v] - level[u]);
    if(u == v) return v;
    for(int i = lg - 1; i>=0; i--)
    {
        if(sp[u][i] != sp[v][i])
        {
            u = sp[u][i];
            v = sp[v][i];
        }
    }
    return sp[u][0];
}
