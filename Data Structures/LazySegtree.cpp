void build(int node, int l, int r){
    if(l == r){
        tree[node] = 1ll * pw[l] * (s[l - 1] - '0' + 1) % mod;
        return;
    }
    int mid = l + r >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    tree[node] = add(tree[node << 1], tree[node << 1 | 1]);
}
 
void propagate(int node, int l, int r){
    if(lazy[node] == 0) return;
    tree[node] = 1ll * lazy[node] * ((sum[r] - sum[l - 1] + mod) % mod) % mod;
    if(l != r){
        lazy[node << 1] = lazy[node << 1 | 1] = lazy[node];
    }
    lazy[node] = 0;
}
 
void update(int node, int l, int r, int a, int b, int val){
    propagate(node, l, r);
    if(l > b || r < a) return;
    if(a <= l && r <= b){
        lazy[node] = val;
        propagate(node, l, r);
        return;
    }
    int mid = l + r >> 1;
    update(node << 1, l, mid, a, b, val);
    update(node << 1 | 1, mid + 1, r, a, b, val);
    tree[node] = add(tree[node << 1], tree[node << 1 | 1]);
}
 
int get(int node, int l, int r, int a, int b){
    propagate(node, l, r);
    if(l > b || r < a) return 0;
    if(a <= l && r <= b) return tree[node];
    int mid = l + r >> 1;
    return add(get(node << 1, l, mid, a, b), get(node << 1 | 1, mid + 1, r, a, b));
}
