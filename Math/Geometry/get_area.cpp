#define point complex<ld>
#define EPS 1e-8
#define X real()
#define Y imag()
#define cp(a, b) ((conj(a) * b).imag())

ld get_area(vector<point> &p){
    ld area = 0;
    p.push_back(p[0]);
    for(int i = 0; i + 1 < (int) p.size(); i++){
        area += cp(p[i], p[i + 1]);
    }
    p.pop_back();
    /// if area > 0, then points are ordered ccw.
    return fabs(area / 2.00);
}
