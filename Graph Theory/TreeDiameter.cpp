// pair<diameter of the current subtree, longest path from current node to a leaf>

pair<int,int> dfs(int node, int par)
{
    int mx[3]={0,0,0};
    int ans=0;
    for(auto it:v[node])
    {
        if(it!=par)
        {
            auto x=dfs(it,node);
                ans=max(ans,x.first);
                mx[0]=x.second+1;
                sort(mx,mx+3);
        }
    }
    ans=max(ans,mx[2]+mx[1]);
    return {ans,mx[2]};
}
