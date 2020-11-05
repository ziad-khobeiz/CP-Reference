// Take care of multiple edges (assign the cost of the edge with the minimum edge among the multiple edges)

void initFloyd() {
     for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dis[i][j] = OO;
        }
        dis[i][i] = 0;
    }
}

void Floyd(){
    for (int k = 1; k <= n; ++k) {
         for (int i = 1; i <= n; ++i) {
             for (int j = 1; j <= n; ++j) {
                 // if condition for negative edges
                 if (d[i][k] < OO && d[k][j] < OO)
                     d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
             }
         }
     }
}
