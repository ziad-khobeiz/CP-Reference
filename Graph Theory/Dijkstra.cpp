
// Dijkstra 

const int N = 1e5 + 5;
struct edge {
    int to;
    long long cost;
};

long long dist[N];
vector<edge> adj[N];
void Dijkstra(int s) {
    //                 dist,node
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    fill(dist, dist + N, 1e18);
    pq.push({s, 0});
    dist[s] = 0;
    while (pq.size()) {
        int node = pq.top().second;
        long long cost = pq.top().first;
        pq.pop();
        if (dist[node] != cost) continue;
        for (auto &c : adj[node]) {
            if (dist[c.to] > dist[node] + c.cost) {
                dist[c.to] = dist[node] + c.cost;
                pq.push({c.to, dist[c.to]});
            }
        }
    }
}
///Dijkstra (n^2)
const int nSize = 100; // number of nodes;
int cost[nSize][nSize];
int d[nSize];
bool V[nSize];
int inf = 1 << 25;

void dijkstra(int start, int goal, int n) {

    for (int i = 0; i < n; i++)
        d[i] = inf; // take care of over flow when sum
    memset(V, 0, sizeof V);
    d[start] = 0;
    int current = start;
    int minD = inf;
    int nextInd = -1; // minmum to choose
    while (current != goal && current != -1) {
        V[current] = 1;
        minD = inf;
        nextInd = -1;
        for (int i = 0; i < n; ++i) {
            if (!V[i] && d[current] + cost[current][i] < d[i]) {
                d[i] = d[current] + cost[current][i];
                // law 3awez ageb el path we ana b relax bkhzn el parent
                // parent[i] = current;
            }
            
            if (!V[i] && d[i] < minD) {
                nextInd = i;
                minD = d[i];
            }
            // b3ml mimization bdal el for loop el zyada (sya3a y3ne)


        }
        current = nextInd;
    }
}


//Prim:
int cost[NSize][NSize];
int d[NSize];
bool V[NSize];
const int inf = 9999999;

// take care of multiple edges
void mstPrim(int start, int n) {
    // lazem undirected graph
    for (int i = 0; i < n; i++)
        d[i] = inf; // take care of over flow when sum
    memset(V, 0, sizeof V);
    d[start] = 0;
    int current = start;
    int minD = inf;
    int nextInd = -1; // minmum to choose
    while (current != -1) {
        V[current] = 1;
        minD = inf;
        nextInd = -1;
        for (int i = 0; i < n; ++i) {
            if (!V[i] && cost[current][i] < d[i]) {
                d[i] = cost[current][i];
                // law 3awez ageb el path we ana b relax bkhzn el parent
                // parent[i] = current;
            }
            if(!V[i] && d[i] < minD)
            {
                nextInd = i;    /* b3ml mimization bdal el for loop el zyada (sya3a y3ne)*/
                minD = d[i];
            }
        }
        current = nextInd;
    }
}

 
/// need targan
