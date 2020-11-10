#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const int N = 3e5 + 5, mod = 1e9 + 7;

#define point complex<ld>
#define cp(a, b) ((conj(a) * (b)).imag())
#define X real()
#define Y imag()
#define EPS 1e-8

point cntr;


bool sort_ccw(point a, point b){
    a -= cntr;
    b -= cntr;

    if(cp(a, b) == 0){
        if(a.imag() != b.imag()){
            return a.imag() < b.imag();
        }
        return a.X < b.X;
    }
    return cp(a, b) > 0;

}

vector<point> convex_hull(vector<point> p){
    if(p.size() <= 1) return p;
    for(int i = 1; i < (int) p.size(); i++){
        if(p[i].imag() < p[0].imag()) swap(p[i], p[0]);
        else if(p[i].imag() == p[0].imag() && p[i].X < p[0].X){
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

ld get_ang(point a, point b, point c){
    ld a2 = (a.X - b.X) * (a.X - b.X) + (a.imag() - b.imag()) * (a.imag() - b.imag());
    ld c2 = (b.X - c.X) * (b.X - c.X) + (b.imag() - c.imag()) * (b.imag() - c.imag());
    ld b2 = (c.X - a.X) * (c.X - a.X) + (c.imag() - a.imag()) * (c.imag() - a.imag());
    return acos( (a2 + b2 - c2) / (2 * (sqrt(a2) * (sqrt(b2)))));
}

ld area(point a, point b, point c){
    ld ret = cp(b - a, c - a);
    return fabs(ret / 2);
}

bool tmam = 0;

int solve(vector<point> polygon, vector<point> v){
    int n = polygon.size(), m = v.size();
    if(n < 3) return 0;
    vector<ld> ang;
    for(int i = 2; i < n; i++){
        ld tmp = get_ang(polygon[0], polygon[1], polygon[i]);
        ang.push_back(tmp);
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
        ld tmp = get_ang(polygon[0], polygon[1], v[i]);
        int idx = lower_bound(ang.begin(), ang.end(), tmp) - ang.begin();
        if(idx == m - 2) continue;
        idx += 2;
        ld tmp_area = area(polygon[0], polygon[idx - 1], v[i]) + area(polygon[0], polygon[idx], v[i]);
        tmp_area += area(polygon[idx - 1], polygon[idx], v[i]);
        // if(tmam && i == 2) cout << fabs(tmp_area - area(polygon[0], polygon[idx - 1], polygon[idx]))<< '\n';
        if(fabs(area(polygon[0], polygon[idx - 1], polygon[idx]) - tmp_area) <= EPS) ans++;
    }
    return ans;
}

bool cmp(point a, point b){
    if(a.X != b.X) return a.X < b.X;
    return a.Y < b.Y;
}

void remove_duplicate(vector<point> &v){
    sort(v.begin(), v.end(), cmp);
    vector<point> tmp;
    tmp.push_back(v[0]);
    for(int i = 1; i < v.size(); i++){
        if(v[i] == v[i - 1]) continue;
        tmp.push_back(v[i]);
    }
    swap(tmp, v);
}

bool is_collinear(point a, point b, point c) {
    return fabs( cp(b-a, c-a) ) < EPS;
}

vector<point> remove_collinear(vector<point> &v){
    int n = v.size();
    vector<int> ans(n, 0);
    for(int i = 1; i + 1 < n; i++){
        if(is_collinear(v[i - 1], v[i], v[i + 1])) ans[i] = 1;
    }
    vector<point> tmp;
    for(int i = 0; i < n; i++){
        if(ans[i] == 1) continue;
        tmp.push_back(v[i]);
    }
    return tmp;
}



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("curling.in", "r", stdin);
    freopen("curling.out", "w", stdout);
    int n;
    cin >> n;
    vector<point> v(n), v2(n);
    for(int i = 0; i < n; i++){
        ld x, y;
        cin >> x >> y;
        v[i] = point(x, y);
    }
    remove_duplicate(v);
    for(int i = 0; i < n; i++){
        ld x, y;
        cin >> x >> y;
        v2[i] = point(x, y);
    }
    remove_duplicate(v2);
    auto ch1 = convex_hull(v);
    ch1 = remove_collinear(ch1);
    auto ch2 = convex_hull(v2);
    ch2 = remove_collinear(ch2);
    int ans1 = solve(ch1, v2);
    tmam = 1;
    int ans2 = solve(ch2, v);
    cout << ans1 << ' ' << ans2 << '\n';


    return 0;
}
