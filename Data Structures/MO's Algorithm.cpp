#include <bits/stdc++.h>

int n, qq, arr[N], sz = 1000; // sz  is the log 
int co[N],ans = 0, ansq[N];
int cul = 1, cur = 1;

void add(int x) {
    co[arr[x]]++;
    if (co[arr[x]] == 1)
        ans++;
    else if (co[arr[x]] == 2)
        ans--;
}

void remove(int x) {
    co[arr[x]]--;
    if (co[arr[x]] == 1)
        ans++;
    else if (co[arr[x]] == 0)
        ans--;
}

void solve(int l, int r,int ind) {
    r+=1;
    while (cul < l) remove(cul++);
    while (cul > l) add(--cul);
    while (cur < r) add(cur++);
    while (cur > r) remove(--cur);
    ansq[ind] = ans;
}


int main() {
    FIO
    cin >> qq;
   //                       {l/sz,r},     { l , ind} 
   priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<pair<pair<int, int>, pair<int, int>>>> q;
    for (int i = 0; i < qq; i++) {
        int l, r;
        cin >> l >> r;
        q.push({{l / sz, r},{l,i}});
    }
    while (q.size()) {
        int ind=q.top().second.second,l=q.top().second.first,r=q.top().first.second;
        solve(l, r,ind);
        q.pop();
    }
    for (int i = 0; i < qq; i++)
        cout << ansq[i] << endl;


    return 0;
}
