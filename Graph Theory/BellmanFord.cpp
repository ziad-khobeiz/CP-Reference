struct Edge{

    int from, to, cost;

};

/// Bellman Ford Algorithm:
// Time Complexity: O(n * m)
// 1- to find single source shortest path for weighted directed graphs with negative edges.
// 2- to detect negative cycles

bool BellmanFord(int src, vector<Edge> & edges, vector<int> & d, int nodes) {

    // returns true if there's no negative cycle and the vector d (sent by reference) will have the shortest path from the source to node v stored in d[v].
    // returns false if there's a negative cycle
    // don't forget to assign OO bigger than any possible path

    d.assign(nodes, OO);
    d[src] = 0;

    for (int i = 1; i <= nodes; ++i) {

        bool relaxed = false;

        for(auto & e : edges) {

            if(d[e.from] < OO) {

                if(d[e.to] > d[e.from] + e.cost) {

                    d[e.to] = max(-OO, d[e.from] + e.cost);
                    relaxed = true;

                }

            }

        }

        if(!relaxed) return true;
        if(i == nodes) return false;

    }

}
