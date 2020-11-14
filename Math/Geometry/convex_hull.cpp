#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const int N = 3e5 + 5, mod = 1e9 + 7;

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

point cntr;

bool sort_ccw(point a, point b){
    a -= cntr;
    b -= cntr;

    if(cp(a, b) == 0){
        if(a.Y != b.Y){
            return a.Y < b.Y;
        }
        return a.X < b.X;
    }
    return cp(a, b) > 0;

}

vector<point> convex_hull(vector<point> p){
    if(p.size() <= 1) return p;
    for(int i = 1; i < (int) p.size(); i++){
        if(p[i].Y < p[0].Y) swap(p[i], p[0]);
        else if(p[i].Y == p[0].Y && p[i].X < p[0].X){
             swap(p[i], p[0]);
        }
    }
    cntr = p[0];
    sort(p.begin() + 1, p.end(), sort_ccw);
    vector<point> ch;
    p.push_back(p[0]);
    for(int i = 0; i < p.size(); i++){
        while(ch.size() > 1){
            auto cur = ch.back(), prv = ch[ch.size() - 2];
            if(cp(prv - cur, p[i] - cur) <= 0) break;
            ch.pop_back();
        }
        ch.push_back(p[i]);
    }
    ch.pop_back();
    return ch;
}

bool is_collinear(point a, point b, point c) {
    return fabs( cp(b-a, c-a) ) < EPS;
}

bool cmp(point a, point b){
    if(a.real() != b.real()) return a.real() < b.real();
    return a.imag() < b.imag();
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
        sort(p.begin(), p.end(), cmp);
        vector<point> tmp;
        tmp.push_back(p[0]);
        for(int i = 1; i < p.size(); i++){
            if(p[i] == p[i - 1]) continue;
            tmp.push_back(p[i]);
        }
        auto v = convex_hull(tmp);
        // cout << v.size() << '\n';
        vector<int> ans(v.size(), 0);
        for(int i = 1; i + 1 < v.size(); i++){
            if(is_collinear(v[i - 1], v[i], v[i + 1])){
                ans[i] = 1;
            }
        }
        int c = 0;
        for(int i = 0; i < (int) v.size(); i++){
            c += (ans[i] == 0);
        }
        cout << c << '\n';
        for(int i = 0; i < v.size(); i++){
            if(ans[i] == 1) continue;
            cout << v[i].real() << ' ' << v[i].imag() << '\n';
        }
    }

    return 0;
}
