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
#define length(a) (hypot((a).imag(), (a).real()))


bool cmp_x(pair<point, int> &a, pair<point, int> &b){
    if(a.first.real() != b.first.real()) return a.first.real() < b.first.real();
    if(a.first.imag() != b.first.imag()) return a.first.imag() < b.first.imag();
    return a.second < b.second;
}

struct cmp_y{
    bool operator () (const pair<point, int> &a, const pair<point, int> &b){
        if(a.first.imag() != b.first.imag()) return a.first.imag() < b.first.imag();
        if(a.first.imag() != b.first.imag()) return a.first.imag() < b.first.imag();
        return a.second < b.second;
    }
};

void closest_pair(vector<pair<point, int>> &v){
    ld d = length(v[0].first - v[1].first);
    int ans1 = 0, ans2 = 1;
    sort(v.begin(), v.end(), cmp_x);
    set<pair<point, int>, cmp_y> st;
    int left = 0, n = v.size();
    for(int i = 0; i < n; i++){
        while(left < i && v[i].first.real() - v[left].first.real() > d){
            st.erase(st.find(v[left]));
            left++;
        }
        pair<point, int> tmp = make_pair(point(-1e9, v[i].first.imag() - d), 0);
        auto it = st.lower_bound(tmp);
        for(; it != st.end() && v[i].first.imag() + d >= (*it).first.imag(); it++){
            ld tmp_dis = length(v[i].first - (*it).first);
            if(tmp_dis < d){
                d = tmp_dis;
                ans1 = v[i].second;
                ans2 = (*it).second;
            }
        }
        st.insert(v[i]);
    }
    if(ans1 > ans2) swap(ans1, ans2);
    cout << ans1 << ' ' << ans2 << ' ';
    cout << fixed << setprecision(6) << d;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector< pair<point, int> > v;
    for(int i = 0; i < n; i++){
        ld x, y;
        cin >> x >> y;
        v.push_back({point(x, y), i});
    }
    closest_pair(v);

    return 0;
}
