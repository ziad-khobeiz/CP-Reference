int pw[N], pw2[N], inv[N], inv2[N], pref[N], pref2[N];

int add(int a, int b){
    return (a + b) % mod;
}
 
int mul(int a, int b){
    return 1LL * a * b % mod;
}
 
int fp(int b, int p){
    if(p == 0) return 1;
    int ret = fp(b, p >> 1);
    ret = mul(ret, ret);
    if(p & 1) ret = mul(ret, b);
    return ret;
}

// O(n + log(n)) Preprocessing
void pre(){
    pw[0] = pw2[0] = inv[0] = inv2[0] = 1;
    int mul_inv = fp(b, mod - 2), mul_inv2 = fp(b2, mod - 2);
    for(int i = 1; i < N; i++){
        pw[i] = mul(pw[i - 1], b);
        pw2[i] = mul(pw2[i - 1], b2);
        inv[i] = mul(inv[i - 1], mul_inv);
        inv2[i] = mul(inv2[i - 1], mul_inv2);
    }
}
 
pair<int, int> get_hash(int l, int r){
    int ret = pref[r];
    if(l) ret = (ret - pref[l - 1] + mod) % mod;
    ret = mul(ret, inv[l]);
 
    int ret2 = pref2[r];
    if(l) ret2 = (ret2 - pref2[l - 1] + mod) % mod;
    ret2 = mul(ret2, inv2[l]);
 
    return {ret, ret2};
}

void build_hash(string &s){
    int n = s.size();
    pref[0] = pref2[0] = s[0] - 'a' + 1;
    for(int i = 1; i < n; i++){
        pref[i] = add(pref[i - 1], mul(pw[i], s[i] - 'a' + 1));
        pref2[i] = add(pref2[i - 1], mul(pw2[i], s[i] - 'a' + 1));
    }
}

int count_unique_substrings(string const& s) {
    int n = s.size();

    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    int cnt = 0;
    for (int l = 1; l <= n; l++) {
        set<long long> hs;
        for (int i = 0; i <= n - l; i++) {
            long long cur_h = (h[i + l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
}
