vector<pair<pair<int, int>, int>> edges;
ll dis[N];
bool bad[N], ans[N];
int par[N],n;
  
void init(int n) {
    for (int i = 0; i <= n; i++) {
        dis[i] =bad[i] =ans[i] = 0;
    }
    edges.clear();
}

void billman() {
 
    int x = -1;
 
    for (int i = 0; i < n; i++) {
        x = -1;
        for (auto it:edges) {
            if (dis[it.first.second] > dis[it.first.first] + it.second) {
                dis[it.first.second] = dis[it.first.first] + it.second;
                par[it.first.second] = it.first.first;
                x = it.first.second;
            }
        }
    }
    if (x == -1)
        return;
 
    for (int z = 0; z < n && x != -1; z++) {
 
        int y = x;
        bad[y] = 1;
        for (int i = 0; i < n; ++i)
            y = par[y];
 
        for (int cur = y;; cur = par[cur]) {
            ans[cur] = 1;
            if (cur == par[y])
                break;
        }
        x = -1;
        for (auto it:edges) {
            if (ans[it.first.second] && ans[it.first.first])
                continue;
            if (dis[it.first.second] > dis[it.first.first] + it.second) {
                dis[it.first.second] = dis[it.first.first] + it.second;
                par[it.first.second] = it.first.first;
                if (bad[it.first.second] || ans[it.first.second])
                    continue;
                x = it.first.second;
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
        for (auto it:edges) {
            if (ans[it.first.second])
                ans[it.first.first] = 1;
        }
 
}
