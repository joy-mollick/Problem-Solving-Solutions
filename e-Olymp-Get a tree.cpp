#include<bits/stdc++.h>

using namespace std;


const int mx=101;
vector<int>adj[mx];
bool vis[mx];
bool cycle=false;
vector<pair<int,int> >edge;
set<pair<int,int> >remove_edge;

void dfs(int u,int parent)
{
    vis[u]=true;
    vector<int>::iterator it;
    for(it=adj[u].begin();it!=adj[u].end();it++)
    {
        if(!vis[(*it)])
        {
            dfs((*it),u);
        }
        else if((*it)!=parent)
        {
            remove_edge.insert(make_pair((*it),u));
            remove_edge.insert(make_pair(u,(*it)));
        }
    }
}


int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,u,v;
    cin>>n>>m;
    memset(vis,false,sizeof(vis));
    while(m--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge.push_back(make_pair(u,v));
    }
    dfs(1,-1);
    for(int i=0;i<edge.size();i++)
    {
        int u=edge[i].first;
        int v=edge[i].second;
        if(!remove_edge.count(make_pair(u,v))) cout<<u<<" "<<v<<endl;
    }
}
