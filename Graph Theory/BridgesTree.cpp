#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5 + 5, mod = 1e9 + 7;

vector<int> adj[N], bridge_tree[N];
int dfsn[N], low[N], cost[N], timer, cnt, comp_id[N], kam[N], ans;
stack<int> st;


void dfs(int node, int par){
    dfsn[node] = low[node] = ++timer;
    st.push(node);
    for(auto i: adj[node]){
        if(i == par) continue;
        if(dfsn[i] == 0){
            dfs(i, node);
            low[node] = min(low[node], low[i]);
        }
        else low[node] = min(low[node], dfsn[i]);
    }
    if(dfsn[node] == low[node]){
        cnt++;
        while(1){
            int cur = st.top();
            st.pop();
            comp_id[cur] = cnt;
            if(cur == node) break;
        }
    }
}

void dfs2(int node, int par){
    kam[node] = 0;
    int mx = 0, second_mx = 0;
    for(auto i: bridge_tree[node]){
        if(i == par) continue;
        dfs2(i, node);
        kam[node] = max(kam[node], 1 + kam[i]);
        if(kam[i] > mx){
            second_mx = mx;
            mx = kam[i];
        }
        else second_mx = max(second_mx, kam[i]);
    }
    ans = max(ans, kam[node]);
    if(second_mx) ans = max(ans, 2 + mx + second_mx);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++){
        for(auto j: adj[i]){
            if(comp_id[i] != comp_id[j]){
                bridge_tree[comp_id[i]].push_back(comp_id[j]);
            }
        }
    }
    dfs2(1, 0);
    cout << ans;

    return 0;
}
