ll ex_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll tx, ty;
    ll g = ex_gcd(b, a % b, tx, ty);
    x = ty;
    y = tx - ty * (a / b);
    return g;
}

bool solve(ll a1, ll mod1, ll a2, ll mod2, ll &rem, ll &lcm) {
    ll k1, k2;
    ll g = ex_gcd(mod1, mod2, k1, k2);
    if ((a2 - a1) % g) return 0;
    lcm = mod1 / g * mod2;
    rem = k1 * (a2 - a1) / g * mod1 + a1;
    rem = (rem % lcm + lcm) % lcm;
    return 1;
}

/// x = as[i] + mods[i] * C -> x = as[i] (mod mods[i])
/// as must be >= 0
bool CRT(vector <ll> as, vector <ll> mods, ll &a, ll &l) {
    a = 0;
    l = 1;
    for (int i = 0; i < (int) as.size(); i++) {
        if (!solve(as[i], mods[i], a, l, a, l)) return 0;
    }
    return 1;
}
