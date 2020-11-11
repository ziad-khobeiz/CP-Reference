#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5 + 5, mod = 1e9 + 7;

unsigned long long tree[N << 2], lazy[N << 2];

vector<int> v[N], check[N];

int l[N], r[N], ans[N], ql[N], qr[N], z[N], kam[N];

void propogate(int node, int l, int r){
    if(lazy[node] == 0) return;
    tree[node] += (r - l + 1) * lazy[node];
    if(l != r){
        lazy[node << 1] += lazy[node];
        lazy[node << 1 | 1] += lazy[node];
    }
    lazy[node] = 0;
}

void build(int node, int l, int r){
    if(l == r){
        tree[node] = lazy[node] = 0;
        return;
    }
    int mid = l + r >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    tree[node] = lazy[node] = 0;
}

void update(int node, int l, int r, int a, int b, ll x){
    propogate(node, l, r);
    if(a > r || b < l) return;
    if(l >= a && r <= b){
        lazy[node] = x;
        propogate(node, l, r);
        return;
    }
    int mid = l + r >> 1;
    update(node << 1, l, mid, a, b, x);
    update(node << 1 | 1, mid + 1, r, a, b, x);
}

ll get(int node, int l, int r, int a, int b){
    if(a > r || b < l) return 0;
    propogate(node, l, r);
    if(l == r && l == a) return tree[node];
    int mid = l + r >> 1;
    if(a >= l && a <= mid) return get(node << 1, l, mid, a, a);
    else return get(node << 1 | 1, mid + 1, r, a, a);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x;
        cin >> x;
        v[x].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        cin >> kam[i];
    }
    int k;
    cin >> k;
    for(int i = 1; i <= k; i++){
        cin >> ql[i] >> qr[i] >> z[i];
    }
    for(int i = 1; i <= n; i++){
        l[i] = 1;
        r[i] = k;
        ans[i] = k + 5;
    }
    bool changed = 1;
    while(changed){
        changed = 0;
        build(1, 1, m);
        for(int i = 1; i <= k; i++) check[i].clear();
        for(int i = 1; i <= n; i++){
            if(l[i] <= r[i]){
                changed = 1;
                int mid = l[i] + r[i] >> 1;
                check[mid].push_back(i);
            }
        }
        for(int i = 1; i <= k; i++){
            if(ql[i] <= qr[i]){
                update(1, 1, m, ql[i], qr[i], z[i]);
            }
            else{
                update(1, 1, m, ql[i], m, z[i]);
                update(1, 1, m, 1, qr[i], z[i]);
            }
            for(auto j: check[i]){
                unsigned long long ans_j = 0;
                for(auto x: v[j]){
                    ans_j += get(1, 1, m, x, x);
                    
                }
                if(ans_j >= kam[j]){
                    ans[j] = i;
                    r[j] = i - 1;
                }
                else l[j] = i + 1;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(ans[i] > k) cout << "NIE";
        else cout << ans[i];
        cout << '\n';
    }

    return 0;

}
