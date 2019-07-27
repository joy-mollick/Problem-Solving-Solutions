#include<bits/stdc++.h>

using namespace std;

const int mx=1e3+1;
bool vis[mx];
vector<int>adj[mx];
int count_connected=0;
int total_connected=0;
int max_connected=0;
int total_pair_edges=0;

void dfs(int u)
{
    count_connected++;
    vis[u]=true;
    for(int i=0;i<adj[u].size();i++)
    {
        if(!vis[adj[u][i]])
        {
            dfs(adj[u][i]);
        }
    }
}

int main()

{
    int n,m,k,u,v;
    cin>>n>>m>>k;
    int special[k];
    for(int i=0;i<k;i++)
    {
        cin>>special[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int j=0;j<=n;j++)
    {
        vis[j]=false;
    }
    for(int i=0;i<k;i++)
    {
        count_connected=0;
        dfs(special[i]);
        max_connected=max(count_connected,max_connected);
        total_connected+=count_connected; // total summation of connected components
        total_pair_edges+=(count_connected*(count_connected-1))/2;// summation of every coonected components pairs edges
    }
    n=n-total_connected+max_connected; // all nodes with max_connected_size of special nodes and other disconnected non_special nodes
    total_pair_edges=total_pair_edges-((max_connected*(max_connected-1))/2)+(n*(n-1))/2;// n and max_connected will be connected with edges of every pair,that's why remove previously added only max_connected pairs
    total_pair_edges=total_pair_edges-m; // m edges are given before , so remove this
    cout<<total_pair_edges<<endl;
}
