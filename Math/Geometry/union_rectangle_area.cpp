#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const int N = 3e5 + 5, mod = 1e9 + 7;


struct event{
    int idx;
    /// 0 -> entry, 1 -> exit
    bool type;
    event() {};
    event(int idx, bool type) : idx(idx), type(type) {};
};


struct point{
    int x, y;
};

point rect[N][2];

bool cmp_x(event a, event b){
    return rect[a.idx][a.type].x < rect[b.idx][b.type].x;
}

bool cmp_y(event a, event b){
    return rect[a.idx][a.type].y < rect[b.idx][b.type].y;
}

/// n -> #events
int union_area(vector<event> &event_v, vector<event> &event_h, int n){
    sort(event_v.begin(), event_v.end(), cmp_x);
    sort(event_h.begin(), event_h.end(), cmp_y);
    vector<bool> in_set(n, 0);
    in_set[event_v[0].idx] = 1;
    int area = 0;
    for(int i = 1; i < n; i++){
        event c = event_v[i], p = event_v[i - 1];
        int delta_x = rect[c.idx][c.type].x - rect[p.idx][p.type].x;
        if(delta_x == 0){
            in_set[c.idx] = (c.type == 0);
            continue;
        }
        int cnt = 0, first_h;
        for(int j = 0; j < n; j++){
            event c_h = event_h[j];
            if(in_set[c_h.idx] == 0) continue;
            if(c_h.type == 0){
                if(cnt == 0) first_h = rect[c_h.idx][0].y;
                cnt++;
            }
            else{
                cnt--;
                if(cnt == 0){
                    int delta_y = rect[c_h.idx][1].y - first_h;
                    area += (delta_x * delta_y);
                }
            }
        }
        in_set[c.idx] = (c.type == 0);
    }
    return area;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<event> event_v, event_h;
    for(int i = 0; i < n; i++){
        cin >> rect[i][0].x >> rect[i][0].y >> rect[i][1].x >> rect[i][1].y;
        event_v.push_back(event(i, 0));
        event_h.push_back(event(i, 0));
        event_v.push_back(event(i, 1));
        event_h.push_back(event(i, 1));
    }
    cout << union_area(event_v, event_h, n * 2);
    
    
    return 0;
}
