#include<bits/stdc++.h>

using namespace std;

const int mx= 1e5+1;

int parent[mx];
bool vis[mx];
int disc[mx];
int low[mx];
bool apu[mx];
map < int, pair<int,int> >edges;
map < pair<int,int> , int> bridge;
vector<int>adj[mx];
set<pair<int,int>>s;

void apufind(int u)
{
     static int time =0;
     disc[u]=low[u]=time++;
     vis[u]=true;
     for(int i=0;i<(int)adj[u].size();i++)
     {
         int v=adj[u][i];
         if(!vis[v])
         {
             parent[v]=u;
             apufind(v);
             low[u]=min(low[u],low[v]);

             if(low[v]>disc[u])
             {
                 pair<int,int>p = make_pair(min(u,v),max(v,u));
                 bridge[p]=1;
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
    int n,m;
    cin>>n>>m;
    int u,v;
    int i=1;
    while(m--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i++]=make_pair(min(u,v),max(v,u));
    }
    for(int i=1;i<=n;i++)
    {
        parent[i]=-1;
        vis[i]=false;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]){
        apufind(i);}
    }
    int p,g;
    cin>>p;
    while(p--)
    {
        cin>>g;
        if(bridge[edges[g]]==1)
        {
            cout<<"Unhappy"<<endl;
        }
        else
        {
            cout<<"Happy"<<endl;
        }
    }

    return 0;
}
