ll egcd(ll r0, ll r1, ll &x0, ll &y0)
{
    ll y1 = x0 = 1, x1 = y0 = 0;
    while(r1)
    {
        ll q = r0 / r1;
        ll t = r0 - q * r1;
        r0 = r1;
        r1 = t;
        t = x0 - q * x1;
        x0 = x1;
        x1 = t;
        t = y0 - q * y1;
        y0 = y1;
        y1 = t;
    }
    return r0;
}

bool solveLDE(ll a, ll b, ll c, ll &x, ll &y, ll &g)
{
    g = egcd(a, b, x, y);
    ll m = c / g;
    x *= m;
    y *= m;
    return !(c - m * g);
}

int main() {
    ll x, y, a = 6, b = 8, c = 10, g;
    scanf("%lld%lld%lld", &a, &b, &c);
    if(solveLDE(a, b, -c, x, y, g)) printf("%lld %lld\n", x, y);
    else puts("-1");
    return 0;
}
