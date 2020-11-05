typedef valarray<ll> hashing;
hashing MOD = {(ll)1e9 + 7, (ll)1e9 + 9};
hashing B = {(ll)31, (ll)53};
hashing h[N], pw[N];
set<pair<ll, ll> > hashes;

hashing add(const hashing & a, const hashing & b) {

    return (a + b) % MOD;

}

hashing mul(const hashing & a, const hashing & b) {

    return (a * b) % MOD;

}

void init() {

    hashes.clear();

}

int main() {

    pw[0] = {1, 1};
    for (int i = 1; i < N; ++i) {
        pw[i] = mul(pw[i - 1], B);
    }
    
    int tt;
    cin >> tt;
    while (tt--) {
        
        int n, k;
        string s;
        cin >> n >> k >> s;
        init();
        
        h[0] = {0, 0};
        for (int i = 1; i <= n; ++i) {
            h[i] = add(h[i - 1], mul(hashing(s[i - 1] - 'a' + 1, 2), pw[i - 1]));
        }
        for (int i = 0; i <= n - k; ++i) {
            auto cur = mul(add(h[i + k], MOD - h[i]), pw[n - k - i]);
            hashes.emplace(cur[0], cur[1]);
        }
        cout << hashes.size() << '\n';
    }

    return 0;
}
