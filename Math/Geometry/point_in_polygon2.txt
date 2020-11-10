#define point complex<ld>
#define X real()
#define Y imag()
#define cp(a, b) ((conj(a) * (b)).imag())
#define Dp(a, b) ((conj(a) * (b)).real())
#define EPS 1e-8
#define length(a) (hypot((a).imag(), (a).real()))


int dcmp(ld a, ld b){
    return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}

bool isPointOnSegment(point a, point b, point c) {
    ld acb = length(a-b), ac = length(a-c), cb = length(b-c);
    return dcmp(acb-(ac+cb), 0) == 0;
}

bool is_inside_polygon(vector<point> &p, point pt){
    // 3la 7asab el ms2ala.
    /// if(p.size() < 3) return 0;
    int wn = 0;
    p.push_back(p[0]);
    for(int i = 0; i + 1 < p.size(); i++){
        auto cur = p[i], nxt = p[i + 1];
        if(isPointOnSegment(cur, nxt, pt)){
            p.pop_back();
            /// 3la 7asb el ms2ala
            return 0;
        }
        if(cur.Y <= pt.Y){
            if(nxt.Y > pt.Y && cp(nxt - cur, pt - cur) > EPS) wn++;
        }
        else if(nxt.Y <= pt.Y && cp(nxt - cur, pt - cur) < -EPS) wn--;
    }
    p.pop_back();
    return wn != 0;
}
