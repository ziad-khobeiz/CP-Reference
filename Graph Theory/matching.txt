#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;
int left_m[M], right_m[N];
vector<int> adj[N];

bool can(int node){
    if(vis[node]) return 0;
    vis[node] = 1;
    for(auto i: adj[node]){
        if(left_m[i] == -1 || can(left_m[i])){
            left_m[i] = node;
            right_m[node] = i;
            return 1;
        }
    }
    return 0;
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) vis[j] = 0;
        if(can(i)) c++;
    }
    
    return 0;
}
