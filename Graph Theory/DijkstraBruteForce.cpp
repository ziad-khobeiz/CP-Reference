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
