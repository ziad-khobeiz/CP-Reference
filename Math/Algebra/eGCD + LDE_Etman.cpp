ll e_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll tx, ty;
    ll g = e_gcd(b, a % b, tx, ty);
    x = ty;
    y = tx - ty * (a / b);
    return g;
}

bool LDE(ll a, ll b, ll c, ll &x, ll &y) {
    ll g = e_gcd(abs(a), abs(b), x, y);
    if (c % g) return 0;
    x *= c / g;
    y *= c / g;
    if (a < 0) x = -x;
    if (b < 0) y = -y;
    return 1;
}
 
