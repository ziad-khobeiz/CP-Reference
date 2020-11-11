//#pragma GCC optimize ('O3')
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 3e5 + 5;
const int M = 5e5 + 5;
const int OO = 1e9;
const int mod = 1e9 + 7;

int n,m,x,y,compSz,mx=-1,mxNode,rnk[N],low[N],comp[N],nodes;
vector<int> g[N],cG[N];
stack<int> s;
bool vis[N];

void dfs(int u, int p) {

    if(vis[u]) return;
    vis[u] = 1;

    s.push(u);
    rnk[u] = low[u] = ++nodes;

    for(auto v : g[u]) {
        if(v == p) continue;
        bool visited = vis[v];
        dfs(v,u);
        low[u] = min(low[u], visited ? rnk[v] : low[v]);
    }

    if(low[u] == rnk[u]) {
        while (s.top() != u) {
            comp[s.top()] = compSz;
            s.pop();
        }
        comp[s.top()] = compSz++;
        s.pop();
    }
    
}

void dfs2(int u, int p, int lvl) {

    if(lvl > mx) {
        mx = lvl;
        mxNode = u;
    }

    for(auto v : cG[u]) {
        if(v != p) dfs2(v,u,lvl+1);
    }

}

int main() {

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    dfs(1,1);

    for (int u = 1; u <= n; ++u) {
        for(auto v : g[u]) {
            if(comp[u] != comp[v])
                cG[comp[u]].pb(comp[v]);
        }
    }

    dfs2(0,0,0);
    mx = -1;
    dfs2(mxNode,mxNode,0);

    cout << mx << '\n';

    return 0;
}
