vector< vector<int> > scc;
vector<int> adj[N];
int dfsn[N], low[N], cost[N], timer, in_stack[N];
stack<int> st;

// to detect all the cycles in a directed graph
void tarjan(int node){
    dfsn[node] = low[node] = ++timer;
    in_stack[node] = 1;
    st.push(node);
    for(auto i: adj[node]){
        if(dfsn[i] == 0){
            tarjan(i);
            low[node] = min(low[node], low[i]);
        }
        else if(in_stack[i]) low[node] = min(low[node], dfsn[i]);
    }
    if(dfsn[node] == low[node]){
        scc.push_back(vector<int>());
        while(1){
            int cur = st.top();
            st.pop();
            in_stack[cur] = 0;
            scc.back().push_back(cur);
            if(cur == node) break;
        }
    }
}
int main(){
    int m;
    cin >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 1; i <= n; i++){
        if(dfsn[i] == 0){
            tarjan(i);
        }
    }
    
    return 0;
}
