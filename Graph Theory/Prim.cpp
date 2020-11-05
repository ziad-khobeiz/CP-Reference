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
