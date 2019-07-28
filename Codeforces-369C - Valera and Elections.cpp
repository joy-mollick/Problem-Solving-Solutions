#include<bits/stdc++.h>

using namespace std;

const int mx=1e5+1;

vector<pair<int,int> >adj[mx];
bool vis[mx];
vector<int>ans;
stack<int>s;
int parent[mx];

void dfs(int u)
{
   vis[u]=true;
   for(int i=0;i<adj[u].size();i++)
   {
       int v=adj[u][i].first;
       int id=adj[u][i].second;
       if(!vis[v])
       {
           if(id==2)
           {
               s.push(v);
           }
           parent[v]=u;
           dfs(v);
       }
   }
}

void dfs2(int u)
{
    if(vis[u]) return;
     vis[u]=true;
     int v=parent[u];
     if(v==u)
        return;// root node(1) comes

     dfs2(v);
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
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
    }
    dfs(1);// from one to all subtree
    memset(vis,false,sizeof(vis));
    vis[1]=true;
    while(!s.empty())
    {
        int k=s.top();
        if(!vis[k])
        {
            dfs2(k);
            ans.push_back(k);
        }
        s.pop();
    }
    cout<<ans.size()<<endl;
    for(int l=0;l<ans.size();l++)
    {
        if(l) cout<<" ";
        cout<<ans[l];
    }
    return 0;
}
