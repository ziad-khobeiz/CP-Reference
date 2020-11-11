typedef tuple<ll, ll, ll> line;
typedef pair<ll, ll> point;
typedef pair<point, point> segment;

void canonize(line &t){
    ll g = __gcd(get<0>(t), get<1>(t));
    g = abs(__gcd(g, get<2>(t)));
    if(get<0>(t) < 0 || (get<0>(t) == 0 && get<1>(t) < 0))
        g *= -1;
    get<0>(t) /= g;
    get<1>(t) /= g;
    get<2>(t) /= g;
    return;
}

line getLine(const segment &seg){
    ll dx = seg.second.X - seg.first.X;
    ll dy = seg.second.Y - seg.first.Y;
    ll A = dy;
    ll B = -dx;
    ll C = -A * seg.first.X - B * seg.first.Y;
    line t(A, B, C);
    canonize(t);
    return t;
}

// Doubles:
struct line {
    double a, b, c;
    line(const point &p, const point &q) {
        a = p.Y - q.Y;
        b = q.X - p.X;
        c = -a * p.X - b * p.Y;
        double z = sqrt(a * a + b * b);
        a /= z, b /= z, c /= z;
    }
}
