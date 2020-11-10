#define point complex<ld>
#define X real()
#define Y imag()
#define cp(a, b) ((conj(a) * (b)).imag())
#define Dp(a, b) ((conj(a) * (b)).real())
#define EPS 1e-8
#define length(a) (hypot((a).imag(), (a).real()))

int ccw(complex<ld> a, complex<ld> b, complex<ld> c) {
  complex<ld> v1(b - a), v2(c - a);
  ld t = cp(v1, v2);
  if (t > +EPS)
	return +1;
  if (t < -EPS)
	return -1;
  if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
	return -1;
  if (norm(v1) < norm(v2) - EPS)
	return +1;
  return 0;
}

ld fixAngle(ld ang){
    if(ang > 1) return 1;
    if(ang < -1) return -1;
    return ang;
}

ld get_angle(point a, point pt, point b){
    ld dot_product = Dp(a - pt, b - pt);
    point v1(a - pt);
    point v2(b - pt);
    return acos(fixAngle(dot_product / (length(v1) * length(v2))));
}

bool is_inside_polygon(vector<point> &p, point pt){
    if(p.size() < 3) return 0;
    ld sum = 0;
    p.push_back(p[0]);
    for(int i = 0; i + 1 < (int) p.size(); i++){
        /// lw el pt 3la el edge p[i] -> p[i + 1]
        if(ccw(p[i], p[i + 1], pt) == 0){
            p.pop_back();
            return 0;
        }
        sum += (get_angle(p[i], pt, p[i + 1])) * ccw(pt, p[i], p[i + 1]);
    }
    p.pop_back();
    return fabs(sum) >= (2*acos(0));
}
