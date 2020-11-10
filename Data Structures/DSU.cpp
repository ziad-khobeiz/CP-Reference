int par[N], rnk[N], comps;

void build_dsu() {
    iota(par + 1, par + 1 + n, 1);
    fill(rnk + 1, rnk + 1 + n, 1);
    comps = n;
}

int find_set(int a) {
    if(par[a] == a) return a;
    return par[a] = find_set(par[a]);
}

bool connect(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a == b) return false;
    if(rnk[a] > rnk[b]) swap(a, b);
    par[a] = b;
    rnk[b] += (rnk[a] == rnk[b]);
    --comps;
    return true;
}
