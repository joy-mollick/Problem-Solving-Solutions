#include<bits/stdc++.h>

using namespace std;

const int mx= 1e6+5;

int parent[mx];
bool vis[mx];
int disc[mx];
int low[mx];
map <int,int> bridge;
vector<pair<int,int>>adj[mx];

void apufind(int u)
{
     static int time =0;
     disc[u]=low[u]=time++;
     vis[u]=true;
     for(int i=0;i<(int)adj[u].size();i++)
     {
         int v=adj[u][i].first;
         int id=adj[u][i].second;
         if(!vis[v])
         {
             parent[v]=u;
             apufind(v);
             low[u]=min(low[u],low[v]);

             if(low[v]>disc[u])
             {
                 bridge[id]=1;
             }
         }
         else if( v!=parent[u])
         {
             low[u]=min(disc[v],low[u]);
         }
     }
}

int main()

{
    int n,m,id,k;
    scanf("%d%d%d",&n,&m,&k);
    int u,v;
    int i=1;
    while(m--)
    {
        scanf("%d%d%d",&u,&v,&id);
        adj[u].push_back(make_pair(v,id));
        adj[v].push_back(make_pair(u,id));
    }
    for(int i=1;i<=n;i++)
    {
        parent[i]=-1;
        vis[i]=false;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            apufind(i);
        }
    }
    int p,g;
    while(k--)
    {
        scanf("%d",&g);
        if(bridge[g]==0)
        {
           printf("no\n");
        }
        else
        {
             printf("YES\n");
        }
    }

    return 0;
}
