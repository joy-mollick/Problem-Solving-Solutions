
/// Codeforces : D - Chemical table.
/// Category : graph theory +greedy.


/// (r1,c1) , (r1,c2) , (r2,c1) & (r2,c2)
/// if three of them has been given ,then another one can be automatically drawn on the grid
/// now ,if we treat row and column as two different nodes
/// then when (r2,c2) is equal like (2,2) / (3,3) ....
/// (2,2) doesn't make sense.
/// So avoiding this self loops, we will add n every time to c1 to avoid (r,c).[ where r=c ]
/// After doing this , if three of these given can be added then another one will be in connected components.
/// So , count the number of connected components.
/// It can be solved using dsu also 


#include<bits/stdc++.h>


using namespace std;

const int mx=300005;

vector<int>adj[mx];
bool vis[mx];

int connected_components;

void dfs(int u)
{
    connected_components++;
    int sz=adj[u].size();
    for(int i=0;i<sz;i++)
    {
        int v=adj[u][i];
        if(!vis[v])
        {
            vis[v]=true;
            dfs(v);
        }
    }
}


int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,q,u,v;
    cin>>n>>m>>q;

    while(q--)
    {
        cin>>u>>v;
        adj[u].push_back(v+n);
        adj[v+n].push_back(u);
    }

    /// so, the ranges of edges are 1 to (n+m)

    int ans=0;
    memset(vis,false,sizeof(vis));

    for(int i=1;i<=n+m;i++)
    {
        if(!vis[i]) ans++,dfs(i);
    }

    cout<<(ans-1)<<endl;

	return 0;
}
