struct node{
 
    node *lf, *rt;
    pair<int, int> val;
 
    node() {
        lf = rt = nullptr;
        val = {0, 0};
    }
 
};
 
node* root = new node();
 
pair<int, int> query(ll& a, ll& b, ll l = 0, ll r = OO, node* &cur = root) {
 
    if(a > r || l > b || !cur) return {0, 0};
    if(a <= l && r <= b) return cur->val;
    ll mid = l + (r - l) / 2;
    return max(query(a, b, l, mid, cur->lf), query(a, b, mid + 1, r, cur->rt));
 
}
 
void add(ll& a, pair<int, int>& val, ll l = 0, ll r = OO, node* &cur = root) {
 
    if(!cur) cur = new node();
    if(a > r || a < l) return;
    if(l == r) {
        cur->val = max(cur->val, val);
        return;
    }
    ll mid = l + (r - l) / 2;
    add(a, val, l, mid, cur->lf);
    add(a, val, mid + 1, r, cur->rt);
    cur->val = max(cur->lf->val, cur->rt->val);
 
}
