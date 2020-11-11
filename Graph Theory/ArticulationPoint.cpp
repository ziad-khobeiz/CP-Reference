vector<int> adj[N];
int dfsn[N], low[N], instack[N], ar_point[N], timer;
stack<int> st;

void dfs(int node, int par){
    dfsn[node] = low[node] = ++timer;
    int kam = 0;
    for(auto i: adj[node]){
        if(i == par) continue;
        if(dfsn[i] == 0){
            kam++;
            dfs(i, node);
            low[node] = min(low[node], low[i]);
            if(dfsn[node] <= low[i] && par != 0) ar_point[node] = 1;
        }
        else low[node] = min(low[node], dfsn[i]);
    }
    if(par == 0 && kam > 1) ar_point[node] = 1;
}

void init(int n){
    for(int i = 1; i <= n; i++){
        adj[i].clear();
        low[i] = dfsn[i] = 0;
        instack[i] = 0;
        ar_point[i] = 0;
    }
    timer = 0;
}

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        // Input
        init(n);
        for(int i = 1; i <= n; i++){
            if(dfsn[i] == 0) dfs(i, 0);
        }
        int c = 0;
        for(int i = 1; i <= n; i++){
            if(ar_point[i]) c++;
        }
        cout << c << '\n';
    }
    return 0;
}
