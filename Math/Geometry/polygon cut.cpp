#define point complex<ld>
#define X real()
#define Y imag()
#define cp(a, b) ((conj(a) * b).imag())
#define EPS 1e-8

bool intersectSegments(point a, point b, point c, point d, point &intersect) {
  ld d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
  if (fabs(d1) < EPS)
    return false;  // Parllel || identical

  ld t1 = d2 / d1, t2 = d3 / d1;
  intersect = a + (b - a) * t1;

  if (t1 < -EPS || t1 > 1 + EPS || t2 < -EPS || t2 > 1 + EPS)
    return false;  //e.g ab is segment here, cd is segment ... change to whatever
  return true;
}

/// ordered(cw)
pair< vector<point>, vector<point> > polygon_cut(vector<point> &p, point a, point b){
    vector<point> left, right;
    point intersect;
    p.push_back(p[0]);
    for(int i = 0; i + 1 < (int) p.size(); i++){
        auto cur = p[i], nxt = p[i + 1];
        if(cp(b - a, cur - a) >= 0){
            right.push_back(cur);
        }
        if(intersectSegments(a, b, cur, nxt, intersect)){
            right.push_back(intersect);
            left.push_back(intersect);
        }
        if(cp(b - a, cur - a) <= 0){
            left.push_back(cur);
        }
    }
    p.pop_back();
    return {right, left};
}
