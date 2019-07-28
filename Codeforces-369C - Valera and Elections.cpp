#include<bits/stdc++.h>

using namespace std;

const int mx=1e5+1;

vector<pair<int,int> >adj[mx];
bool vis[mx];
vector<int>ans;

void dfs(int u,int prev)
{
   for(int i=0;i<adj[u].size();i++)
   {
       int v=adj[u][i].first;
       int id=adj[u][i].second;
       if(v==prev)
       {
           continue; // for tree traversal , no need to use vis array , there is no back edge or cross edge
       }
       dfs(v,u);
       if(id==2)
       {
           if(!vis[v])
           {
               ans.push_back(v);
               vis[v]=1;
           }
       }
       vis[u]=vis[u]|| vis[v];
   }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,u,v,w;
    cin>>n;
    int m=n-1;
    while(m--)
    {
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    memset(vis,false,sizeof(vis));
    dfs(1,-1);// for 1 there is no prev node
    cout<<ans.size()<<endl;
    for(int l=0;l<ans.size();l++)
    {
        if(l) cout<<" ";
        cout<<ans[l];
    }
    return 0;
}
