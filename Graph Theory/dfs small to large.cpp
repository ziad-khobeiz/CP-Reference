map<int, int> *mp[N];
vector<int> v[N];
ll ans[N];
int mx[N];
int col[N];
 
void dfs(int node, int par) {
    int bignode = -1;
    for (auto it:v[node])
        if (it != par) {
            dfs(it, node);
            if (bignode == -1 || mp[bignode]->size() < mp[it]->size())
                bignode = it;
        }
    int mx2 = 0;
    ll sum = 0;
    if (bignode == -1)
        mp[node] = new map<int, int>();
    else {
        mp[node] = mp[bignode];
        sum = ans[bignode];
        mx2 = mx[bignode];
    }
    (*mp[node])[col[node]]++;
    if ((*mp[node])[col[node]] >= mx2) {
        if ((*mp[node])[col[node]] != mx2)
            sum = 0;
        mx2 = (*mp[node])[col[node]];
        sum += (ll) col[node];
    }
 
    for (auto it:v[node]) {
        if (it != par && it != bignode) {
            for (auto x :*mp[it]) {
                (*mp[node])[x.first] += x.second;
                if ((*mp[node])[x.first] >= mx2) {
                    if ((*mp[node])[x.first] != mx2)
                        sum = 0;
                    mx2 = (*mp[node])[x.first];
                    sum += (ll) x.first;
                }
            }
         }
     }
    ans[node] = sum;
    mx[node] = mx2;
}
