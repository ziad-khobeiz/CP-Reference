vector< complex<ld> > p;

#define EPS 1e-8
#define X real()
#define Y imag()
#define cp(a, b) ((conj(a) * b).imag())

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

bool is_convex(vector< complex<ld> > &p){
    p.push_back(p[0]);
    p.push_back(p[1]);
    int sign = ccw(p[0], p[1], p[2]);
    bool found = 0;
    for(int i = 1; i + 2 < p.size(); i++){
        if(ccw(p[i], p[i + 1], p[i + 2]) != sign){
            found = 1;
            break;
        }
    }
    p.pop_back();
    p.pop_back();
    return found == 0;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin >> n, n){
        p.clear();
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            p.push_back(complex<ld>(x, y));
        }
        if(is_convex(p)){
            cout << "No";
        }
        else cout << "Yes";
        cout << '\n';
    }

    return 0;
}
