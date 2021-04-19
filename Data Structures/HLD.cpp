class HLD {
public:
    vector<int> par, chainHead, chain, chainsz, index, nodesz, level;
    vector <vector<int>> sgtree, chainV;
    vector <vector<int>> adj;
    vector<int> val;
    int n, curchain = 0, root;
    void init(int n) {
        n++;
        curchain = 0;
        par.resize(n);
        chainHead.resize(n, -1);
        chain.resize(n, -1);
        index.resize(n, -1);
        chainsz.resize(n, 0);
        nodesz.resize(n, 0);
        level.resize(n);
    }
    void build_hld(int node) {
        if (chainHead[curchain] == -1) {
            chainHead[curchain] = node;
            chainV.push_back(vector<int>());
        }
        chainV.back().push_back(val[node]);
        chain[node] = curchain;
        index[node] = chainsz[curchain];
        chainsz[curchain]++;
        int mxnode = -1;
        int mxval = -1;
        for (auto it : adj[node]) {
            if (it != par[node] && nodesz[it] > mxval) {
                mxval = nodesz[it];
                mxnode = it;
            }
        }
        if (mxnode != -1) build_hld(mxnode);
        for (auto it:adj[node]) {
            if (it != par[node] && it != mxnode) {
                curchain++;
                build_hld(it);
            }
        }
    }
    void dfs(int node, int p) {
        level[node] = level[p] + 1;
        par[node] = p;
        nodesz[node] = 1;
        for (auto it:adj[node]) {
            if (it != p) {
                dfs(it, node);
                nodesz[node] += nodesz[it];
            }
        }
    }
    void build_seg(int i, int l, int r, int ind) {
        if (l == r) {
            sgtree[ind][i] = chainV[ind][l];
            return;
        }
        int mid = (l + r) / 2;
        build_seg(i * 2, l, mid, ind);
        build_seg(i * 2 + 1, mid + 1, r, ind);
        sgtree[ind][i] = (sgtree[ind][i * 2] + sgtree[ind][i * 2 + 1]);
    }

    void update_seg(int i, int l, int r, int a, int x, int ind) {
        if (l == r && a == l) {
            sgtree[ind][i] = x;
            return;
        }
        if (a > r || l > a)return;
        int mid = (l + r) / 2;
        update_seg(i * 2, l, mid, a, x, ind);
        update_seg(i * 2 + 1, mid + 1, r, a, x, ind);
        sgtree[ind][i] = (sgtree[ind][i * 2] + sgtree[ind][i * 2 + 1]);
    }
    int seg_qurue(int i, int l, int r, int a, int b, int ind) {
        if (a <= l && r <= b)return sgtree[ind][i];
        if (a > r || l > b)return 0;
        int mid = (l + r) / 2;
        return (seg_qurue(i * 2, l, mid, a, b, ind) + seg_qurue(i * 2 + 1, mid + 1, r, a, b, ind));
    }
    HLD(int n, vector <vector<int>> v, vector<int> nodesval, int root = 1) {
        this->n = n;
        this->root = root;
        val = nodesval;
        adj = v;
        init(n);
        dfs(root, 0);
        build_hld(root);
        curchain++;
        sgtree.resize(curchain + 2);
        for (int i = 0; i < curchain; i++) {
            sgtree[i].resize(4 * chainsz[i]);
            build_seg(1, 0, chainsz[i] - 1, i);
        }
    }
    int qurue(int a, int b) {
        int ans = 0;
        while (chain[a] != chain[b]) {
            if (level[chainHead[chain[b]]] > level[chainHead[chain[a]]])
                swap(a, b);
            ans = (ans + seg_qurue(1, 0, chainsz[chain[a]] - 1, 0, index[a], chain[a]));
            a = par[chainHead[chain[a]]];
        }
        if (index[b] > index[a])
            swap(a, b);
        ans = (ans + seg_qurue(1, 0, chainsz[chain[a]] - 1, index[b], index[a], chain[a]));
        return ans;
    }
    void update(int a, int x) {
        update_seg(1, 0, chainsz[chain[a]] - 1, index[a], x, chain[a]);
    }
};
