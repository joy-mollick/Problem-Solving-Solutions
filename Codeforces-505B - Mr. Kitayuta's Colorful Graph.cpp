#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pi;

vector<pi>adj[101];
bool vis[101];

bool dfs(int u,int dest,int clr)
{
    vis[u]=true;
    if(u==dest)
    {
        return true;
    }
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i].first;
        int cr=adj[u][i].second;
        if(!vis[v] && cr==clr)
        {
            if(dfs(v,dest,clr))
            {
                return true;
            }
        }
    }
    return false;
}


int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,x,y,c,u,v;
    cin>>n;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>c;
        adj[x].push_back(make_pair(y,c));
        adj[y].push_back(make_pair(x,c));
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>u>>v;
        int ans=0;
        for(int i=1;i<=100;i++)
        {
            memset(vis,false,sizeof(vis));
            if(dfs(u,v,i))
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}

