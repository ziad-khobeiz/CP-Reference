// The code calculates "Bipartite graph maximum matching" in O(n*m)
// In any bipartite graph, the number of edges in a maximum matching equals the number of vertices in a minimum vertex cover (set of vertices that includes at least one endpoint of every edge of the graph).
// Total no. of nodes = Minimum vertix cover + Maximum Independent set (a set of vertices in a graph, no two of which are adjacent).


#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;
int left_m[M], right_m[N];
vector<int> adj[N];

bool can(int node){
    if(vis[node]) return 0;
    vis[node] = 1;
    for(auto i: adj[node]){
        if(left_m[i] == -1 || can(left_m[i])){
            left_m[i] = node;
            right_m[node] = i;
            return 1;
        }
    }
    return 0;
}

void init() {
    memset(left_m, -1, sizeof left_m);
}

int main(){
    int c = 0;
    for(int i = 0; i < n; i++){
        // Memset vis between calls of can() function
        for(int j = 0; j < n; j++) vis[j] = 0;
        if(can(i)) c++;
    }
    return 0;
}
