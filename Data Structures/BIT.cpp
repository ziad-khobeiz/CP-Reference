void update(int idx, int val) {
    if(idx == 0) return;
    // if(idx == 0) assert(0);
    while (idx < N) {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}
 
int get(int idx) {
    int ret = 0;
    while (idx > 0) {
        ret += bit[idx];
        idx -= (idx & -idx);
    }
    return ret;
}
