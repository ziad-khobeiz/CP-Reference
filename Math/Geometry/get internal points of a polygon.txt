#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const int N = 3e5 + 5, mod = 1e9 + 7;

#define point complex<ld>
#define X real()
#define Y imag()
#define cp(a, b) ((conj(a) * b).imag())
#define Dp(a, b) ((conj(a) * b).real())
#define EPS 1e-8
#define length(a) (hypot((a).imag(), (a).real()))


ld get_area(vector<point> &p){
    p.push_back(p[0]);
    ld area = 0;
    for(int i = 0; i + 1 < p.size(); i++){
        area += cp(p[i], p[i + 1]);
    }
    p.pop_back();
    return fabs(area / 2);
}

int get_boundry(vector<point> &p){
    int c = 0;
    p.push_back(p[0]);
    for(int i = 0; i + 1 < (int) p.size(); i++){
        int x = abs(p[i].X - p[i + 1].X);
        int y = abs(p[i].Y - p[i + 1].Y);
        c += __gcd(x, y);
    }
    p.pop_back();
    return c;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin >> n, n){
        vector<point> p;
        for(int i = 0; i < n; i++){
            ld x, y;
            cin >> x >> y;
            p.push_back(point(x, y));
        }
        ld area = get_area(p);
        ll B = get_boundry(p);
        ll ans = (area * 2 - B + 2) / 2;
        cout << ans << '\n';
    }

    return 0;
}
